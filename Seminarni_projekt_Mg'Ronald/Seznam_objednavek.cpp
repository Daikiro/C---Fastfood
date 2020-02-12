#include "pch.h"
#include "Seznam_objednavek.h"
#include "Polozka.h"


Seznam::Seznam()
{
	pHead = NULL;
}

Seznam::~Seznam()
{
	while (pHead != NULL)
	{
		Polozka *pTmp = pHead;
		pHead = pHead->pNext;
		delete pTmp; pTmp = NULL;
	}
}


void Seznam::Tisk() const
{
	Polozka *pTmp = pHead;
	if (pTmp == NULL)
	{
		cout << "Zadne objednavky nejsou prijaty\n\n";
		return;
	}
	while (pTmp != NULL)
	{
		cout << "ID objednavky: "<< pTmp->id_v_seznamu << " Nazev polozky: " << pTmp->nazev << " Cena: " << pTmp->cena << " Stav vyrizeni: " << pTmp->stav << endl;
		pTmp = pTmp->pNext;
	}
	cout << endl;
}

void Seznam::Add(int v_ID, ushort v_id, string v_nazev, ushort v_cena, ushort v_stav = 1)	//pridani na konec seznamu
{
	Polozka *pNew = new Polozka(v_ID,v_id, v_nazev, v_cena, v_stav);
	Polozka *pTmp = pHead;


	if (pHead == NULL)
		pHead = pNew;
	else
	{
		while (pTmp->pNext != NULL)
			pTmp = pTmp->pNext;

		pTmp->pNext = pNew;
	}
}


bool Seznam::Remove(int value)
{
	Polozka *pPrev = NULL;
	Polozka *pRemove = pHead;

	if (pRemove != NULL)
	{
		while (pRemove != NULL)
		{
			if (pRemove->id_v_seznamu == value)
			{
				if (pPrev == NULL)					//pokud je prvek první
					pHead = pRemove->pNext;
				else
					pPrev->pNext = pRemove->pNext;
				delete pRemove;						//Odstranìní prvku
				return true;
			}

			pPrev = pRemove;
			pRemove = pRemove->pNext;
		}
	}
	return false;
}

bool Seznam::Contains(int value)
{
	Polozka *pTmp = pHead;

	if (pTmp == NULL)
	{
		cout << "Zadne objednavky nejsou prijaty\n\n";
		return false;
	}

	else
	{
		do
		{
			if (pTmp->id_v_seznamu == value)
			{
				cout << "ID objednavky: " << pTmp->id_v_seznamu << " ID polozky: " << pTmp->id << " Nazev polozky: " << pTmp->nazev << " Cena: " << pTmp->cena << " Stav vyrizeni: " << pTmp->stav << endl;
				return true;
			}
			pTmp = pTmp->pNext;

		} while (pTmp != NULL);
	}
	return false;
}

int Seznam::SumaCisel()
{
	int soucet = 0;
	Polozka *pTmp = pHead;

	if (pTmp != NULL)
	{
		do
		{
			soucet += (int)pTmp->cena;
			pTmp = pTmp->pNext;
		} while (pTmp != NULL);
	}

	return soucet;
}

void Seznam::Update(int value,Seznam &x,Seznam &y)
{
	Polozka *pTmp = pHead;

	int temp_id_v_seznamu;
	ushort temp_id;
	string temp_nazev;
	ushort temp_cena;
	ushort temp_stav;
	bool povoleni_ke_zmene = false;


	if (pTmp == NULL)
	{
		cout << "Objednavku neni mozne vyridit\n\n";
	}
	else 
	{
		do
		{
			if (pTmp->id_v_seznamu == value)
			{
				temp_id_v_seznamu = pTmp->id_v_seznamu;
				temp_id = pTmp->id;
				temp_nazev = pTmp->nazev;
				temp_cena = pTmp->cena;
				temp_stav = 2;
				povoleni_ke_zmene = true;
			}
			pTmp = pTmp->pNext;

		} while (pTmp != NULL);

		if (povoleni_ke_zmene == true)
		{
			x.Remove(value);
			y.Add(temp_id_v_seznamu, temp_id, temp_nazev, temp_cena, temp_stav);
		}
		else
		{
			cout << "Objednavka jiz byla vyrizena\n\n";
		}
	}


}

void Seznam::Celkovy_cas(int pocet_polozek)
{
	int ic = 0,c = 1;
	Polozka *pTmp = pHead;
	Polozka *nabidka = new Polozka[pocet_polozek]();
	

	if (pHead == NULL)
	{
		cout << "Nejsou v poradi zadne objednavky\n\n";
	}
	else
	{
		// naplní pole
		while (pTmp != NULL)
		{
			nabidka[ic] = *pTmp;
			pTmp = pTmp->pNext;
			ic++;
		}

		// setøídí pole
		for (int i = 0; i < pocet_polozek - 1; i++)
			for (int j = i + 1; j < pocet_polozek; j++)
				if (nabidka[i].GetTime() < nabidka[j].GetTime())
				{
					Polozka tmp = nabidka[i];
					nabidka[i] = nabidka[j];
					nabidka[j] = tmp;
				}

		// kategorizuje pole
		do
		{
			if (c == 1)
				cout << "\nObjednavky co budou trvat 1 minutu.\n";
			else
				cout << "\nObjednavky co budou trvat " << c << " minut.\n";

			for (int l = 0; l < pocet_polozek - 1; l++)
			{
				if (nabidka[l].GetTime() == c)
				{
					nabidka[l].GetPolozka();
				}
					
			}
			c++;
		} while (c!=6);
		
		cout << endl << endl;
	}

}
