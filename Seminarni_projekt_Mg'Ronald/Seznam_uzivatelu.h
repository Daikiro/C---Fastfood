#pragma once
#include "User.h"

typedef unsigned short ushort;
using namespace std;

class Seznam_user
{
private:
	User *pHead = new User();

public:
	Seznam_user();	
	~Seznam_user();

	// vytiskne seznam na standardni vystup
	void Tisk() const;

	// prida prvek s hodnou value na konec seznamu a vrati ukazatel zacatku seznamu
	void Add(int v_id, string v_login, string v_password, ushort v_opravneni);

	// otestuje, jestli existuje prvek s hodnotou value
	bool Contains(string name, string pass);

	// vrati pocet uzivatelu v sezamu
	int Count();

	// vrati opravneni polozky
	int GetOprav(string name, string pass);
};
