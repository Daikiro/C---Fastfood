#pragma once
#include "Polozka.h"

typedef unsigned short ushort;
using namespace std;

class Seznam
{
private:
	Polozka *pHead = new Polozka();

public:
	Seznam();
	~Seznam();

	// vytiskne seznam na standardni vystup
	void Tisk() const;

	// prida prvek s hodnou value na konec seznamu a vrati ukazatel zacatku seznamu
	void Add(int v_ID, ushort v_id, string v_nazev, ushort v_cena, ushort v_stav);

	// odstrani prvek seznamu s hodnotou value
	bool Remove(int value);

	// otestuje, jestli existuje prvek s hodnotou value
	bool Contains(int value);

	// vrati soucet prvku seznamu
	int SumaCisel();

	// presun do seznamu vyrizenych
	void Update(int value,Seznam &x,Seznam &y);

	// roztridi polozky do jednotlivych casovych kategorii
	void Celkovy_cas(int pocet_polozek);
};
