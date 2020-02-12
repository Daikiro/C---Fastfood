#include "pch.h"
#include "Polozka.h"

Polozka::Polozka(int v_id_seznamu, ushort v_id, string v_nazev, ushort v_cena, ushort v_stav)
{
	switch (v_id)
	{
	case 1:
		time = 2;
		break;
	case 2:
		time = 2;
		break;
	case 3:
		time = 1;
		break;
	case 4:
		time = 1;
		break;
	case 5:
		time = 1;
		break;
	case 6:
		time = 5;
		break;
	case 7:
		time = 3;
		break;
	case 8:
		time = 3;
		break;
	case 9:
		time = 2;
		break;
	case 10:
		time = 4;
		break;
	default:
		break;
	}

	id_v_seznamu = v_id_seznamu;
	id = v_id;
	nazev = v_nazev;
	cena = v_cena;
	this->pNext = NULL;
	stav = v_stav;
}

void Polozka::GetPolozka() const
{
	cout << "Objednavka: " << id_v_seznamu << " s nazvem: " << nazev <<  endl;
}

void Polozka::SetPolozka(ushort idcko, string name, ushort price)
{
	id = idcko;
	nazev = name;
	cena = price;
}

void Polozka::ChangeNazev(string name)
{
	nazev = name;
}

void Polozka::ChangeCena(ushort price)
{
	cena = price;
}


