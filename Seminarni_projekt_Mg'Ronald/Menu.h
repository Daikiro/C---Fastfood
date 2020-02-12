#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Menu
{
private:
	int uroven_menu;
	string jmeno;
	string pozice;
public:
	Menu(int opravneni, string v_jmeno);
	~Menu() {};

	void Pozdrav() {printf("\033[1;32mVitejte v aplikaci Mg'Ronald\033[0m\n\n");}
	void WhosSelling();

	int GetMenu(int vstup);
	void ZobrazMenu();
};