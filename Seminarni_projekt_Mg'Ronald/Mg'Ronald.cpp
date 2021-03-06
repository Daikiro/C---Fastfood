#include "pch.h"	// base-file soubor
#include "User.h"	// uzivatel
#include "Polozka.h" // objednavka x menickova polozka
#include "Seznam_objednavek.h"	// spojovy seznam objednavek
#include "Seznam_uzivatelu.h"	// spojovy seznam uzivatelu
#include "Menu.h"	// dynamicke menu
#include <string>	// string
#include <iostream>	// vstup a vystup
#include <cstdio>	// tisk
#include <fstream>	// filestream
#include <sstream>  // stringstream
#include <vector>   // vectory
#include <algorithm> // matika
using namespace std;


//globalni promenna
int cislo_objednavky = 1;

//kontrola vstupu
int input_check()
{
	int option = 0;
	if (!(cin >> option)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return option;
}

// parsing stringu
void tokenize(string const &str, const char delim, vector<string> &out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}
}


int main()
{
	// import dat pro zapoceti
	
	Seznam_user uzivatelu;		// stream pro čtení
	ifstream user_stream;		// stream pro zápis	
	string data, parts[4]; // parsovací údaje
	int l = 0, login; // data pro přihlášení
	const char delim = ';'; // parsovací údaj
	vector<string> out; // vector pro parsování
	
	user_stream.open("Ucet.txt");
	
	if (user_stream.is_open())	// pokud je otevřen
	{
		while (!user_stream.eof())	// dokonce souboru
		{
			getline(user_stream, data);	// získej po řádku

			tokenize(data, delim, out);	// parsuj

			for (auto &s : out) {	// rozděl
				parts[l] = s;
				l++;
			}
			l = 0;
			out.clear();	// vyčisti vector
			
			uzivatelu.Add(stoi(parts[0]), parts[1], parts[2], stoi(parts[3]));	// přidej do seznamu uživatelů
		}
	}
	user_stream.close(); // zavři stream
	
	//uzivatelu.Tisk();				Test na seřazený seznam uživatelů
	
	bool propustka = false;	// pojistka na zadávání loginu a hesla
	int pokus = 0;	// druhá pojistka na zadávání loginu a hesla
	string name = "", pass = "";	// proměnné pro jméno a heslo

	// Pŕihlašovací část
	do
	{
		
		system("CLS");	// Vyčištění obrazovky

		printf("Pokud se chcete prihlasit pouze do samoobsluhy, zadejte jako jmeno slovo Automat\n\n"); // nadpis při loginu
		
		if (pokus != 0)
			printf("Zadali jste spatne jmeno nebo heslo. Muzete to zkusit jeste %d x\n\n", 3 - pokus);
		else
			printf("Zadejte sve jmeno a heslo pro prihlaseni\n\n");

		printf("\033[1;31mZadejte jmeno: \033[0m\n");
		cin >> name;	// zadávání loginu
		if (name == "Automat")	// výjimka
		{
			propustka = true;
			pass = "666";	// umělé heslo pro automat
			break;
		}
		printf("\033[1;33mZadejte heslo: \033[0m\n");
		cin >> pass;	// zadávání hesla

		if (uzivatelu.Contains(name, pass) == true)	// check jmena a hesla se seznamem
		{
			propustka = true;
		}
		else
			pokus++;
		
	} while (propustka != true && pokus != 3);	// dokud nebude heslo potvrzeno nebo uživatel nevyčerpá pokusy


	if (propustka == false)	// rozloučení s neúspěsným řešitelem
	{
		system("CLS");
		printf("Vycerpali jste volny pocet pokusu. Nashledanou\n");
		return 0;
	}
	
	else // pro úspěšné řešitele
	{
		system("CLS");	// čiśtění
		login = uzivatelu.GetOprav(name, pass);	// základ pro menu
		Menu menu(login, name);	// dynamicky tvořené menu


		Polozka *nabidka = new Polozka[10]();	// základ pro menu
		Seznam seznam_objednavek;				// spojový seznam pro nevyřízené objednávky
		Seznam seznam_objednavek_hotovych;		// spojový seznam pro vyřízené objednávky
		int option = 0, ending = 0;				// proměnné pro fungování menu
		int moznost = 0; // omezení pro objednávky

		// import polozek do jidelniho menu
		user_stream.open("Polozky_menu.txt");	// otevři soubor
		{
			l = 0;
			int j = 0;
			out.clear();	// použijeme staré proměnné z prvního čtení

			if (user_stream.is_open())	// pokud je otevřen
			{
				while (!user_stream.eof())	// tak do konce souboru
				{
					getline(user_stream, data);	// přečti řádek

					tokenize(data, delim, out); // parsuj

					for (auto &s : out) {	// třiď
						parts[l] = s;
						l++;
					}
					l = 0;
					out.clear();
					nabidka[j].SetPolozka((ushort)stoi(parts[0]), parts[1], (ushort)stoi(parts[2])); // přidej data do pole 
					j++;
				}
			}
			user_stream.close();
		}

		//menu aplikace
		while (ending != 666)
		{
			menu.ZobrazMenu();
			printf("Zadejte vasi volbu\n");
		
			option = input_check(); // Kontrola proti zadávání nevhodných hodnot či znaků	
			system("CLS"); // Vyčištění obrazovky

			ending = menu.GetMenu(option);

			switch (ending) // engine pro dynamické menu
			{
			case 1:
				printf("Zadejte objednavku, kterou si chcete objednat\nPokud se chcete vratit zpet do menu, zadejte 0\n");
				moznost = input_check();

				if (moznost > -1 && moznost < 11)
				{
					if (moznost != 0)
					{
						moznost = moznost - 1;
						seznam_objednavek.Add(cislo_objednavky,nabidka[moznost].GetId(), nabidka[moznost].GetNazev(), nabidka[moznost].GetCena(),1);
						cislo_objednavky++;
					}
				}
				
				break;	//Zadat objednavku

			case 2:

				for (int i = 0; i < 10; i++)
				{
					cout << nabidka[i].GetId() << "    " << nabidka[i].GetNazev() << "   " << nabidka[i].GetCena() << " Kc\n\n\n";
				}
				break;	//Zobrazit menu

			case 3:
				seznam_objednavek.Tisk();
				break;	//Zobrazit objednavky
			
			case 4:
				printf("Zadejte ID objednavky, kterou si chcete nechat vyhledat\nPokud se chcete vratit zpet do menu, zadejte 0\n");
				moznost = input_check();
				seznam_objednavek.Contains(moznost);
				break;	//Vyhledat objednavku
			
			case 5:
				printf("Zadejte ID objednavky, kterou chcete vydat\nPokud se chcete vratit zpet do menu, zadejte 0\n");
				moznost = input_check();
				seznam_objednavek.Update(moznost,seznam_objednavek,seznam_objednavek_hotovych);
				break;	//Vydat objednavku
			
			case 6:
				printf("Zadejte ID objednavky, kterou chcete odstranit\nPokud se chcete vratit zpet do menu, zadejte 0\n");
				moznost = input_check();
				if (seznam_objednavek.Remove(moznost) == true)
				{
					system("CLS");
					printf("Objednavka byla radne odstranena\n\n");
				}
				else
				{
					system("CLS");
					printf("Objednavka nemohla byt odstranena\n\n");
				}
				break;	//Odstranit objednavku (stornovani)
			
			case 7:
				if (seznam_objednavek_hotovych.SumaCisel() != 0)
					printf("Denni obrat teto pobocky je: %d Kc\n\n", seznam_objednavek_hotovych.SumaCisel());
				else
					printf("Dnes jsme jeste nevyridili zadnou objednavku x(\n\n");
				break;	//Vypocitat denni obrat

			case 8:		
				seznam_objednavek.Celkovy_cas(cislo_objednavky);
				break;
			
			case 666:
				system("CLS");
				printf("Diky za vyuziti nasich sluzeb. \033[1;32mMejte pekny den x)\033[0m\n\n");
				
				break;	//Konec
			
			case -1:
				break;	//Nemožná chyba
			
			default:
				break;	//Nemožná chyba
			}
		}
		cin.get(); // vyćištení vstupu
	}
	
	return 0;
}
