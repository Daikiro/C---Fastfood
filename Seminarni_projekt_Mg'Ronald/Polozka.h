#pragma once
#include <iostream>
#include <string>

typedef unsigned short ushort;
using namespace std;

class Polozka
{
private:
	int id_v_seznamu = 0;
	ushort id = 0;
	string nazev = "";
	ushort cena = 0;
	ushort stav = 0;
	ushort time = 0;
	Polozka *pNext = NULL;
public:
	Polozka() { ; }
	Polozka(int v_id_seznamu, ushort v_id, string v_nazev, ushort v_cena, ushort v_stav);
	~Polozka() {};
	
	void GetPolozka() const;
	void SetPolozka(ushort idcko, string name, ushort price);

	ushort GetId() const { return id; }
	string GetNazev() const { return nazev; }
	ushort GetCena() const { return cena; }
	ushort GetTime() const { return time; }

	void ChangeNazev(string name);
	void ChangeCena(ushort price);

	friend class Seznam;
	
};
