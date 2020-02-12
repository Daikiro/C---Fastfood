#include "pch.h"
#include "Menu.h"


Menu::Menu(int opravneni, string v_jmeno)
{
	Pozdrav();
	uroven_menu = opravneni;
	jmeno = v_jmeno;
	switch (uroven_menu)
	{
	case 0:
		pozice = "Automat";
		break;
	case 1:
		pozice = "Pokladni";
		break;
	case 2:
		pozice = "Obsluha";
		break;
	case 3:
		pozice = "Manazer";
		break;
	case 4:
		pozice = "Tester";
		break;
	default:
		break;
	}
}

void Menu::WhosSelling()
{
	printf("Prihlaseny uzivatel: %s\t\t Pozice uzivatele: %s\n\n", jmeno.c_str(), pozice.c_str());
}

int Menu::GetMenu(int vstup)
{
	switch (uroven_menu)
	{
	case 0:	//samoobsluha
		switch (vstup)
		{
		case 1:
			return 1;	//Zadat objednavku
			break;
		case 2:
			return 2;	//Zobrazit menu
			break;
		case 3:
			return 666;	//Konec
			break;
		default:
			printf("Spatny znak\n");
			return -1;
			break;
		}
		break;
	case 1:	//prodavaè
		switch (vstup)
		{
		case 1:
			return 1;	//Zadat objednavku
			break;
		case 2:
			return 2;	//Zobrazit menu
			break;
		case 3:
			return 3;	//Zobrazit objednavky
			break;
		case 4:
			return 4;	//Vyhledat objednavku
			break;
		case 5:
			return 5;	//Vydat objednavku
			break;
		case 6:
			return 666;	//Konec
			break;
		default:
			printf("Spatny znak\n");
			return -1;
			break;
		}
		break;
	case 2:	//obsluha
		switch (vstup)
		{
		case 1:
			return 1;	//Zadat objednavku
			break;
		case 2:		
			return 2;	//Zobrazit menu
			break;
		case 3:
			return 3;	//Zobrazit objednavky
			break;
		case 4:
			return 4;	//Vyhledat objednavku
			break;
		case 5:
			return 8;	//Vypocitani doby
			break;
		case 6:
			return 666;	//Konec
			break;
		default:
			printf("Spatny znak\n");
			return -1;
			break;
		}
		break;
	case 3:	//manažer
		switch (vstup)
		{
		case 1:
			return 1;	//Zadat objednavku
			break;
		case 2:
			return 2;	//Zobrazit menu
			break;
		case 3:
			return 3;	//Zobrazit objednavky
			break;
		case 4:
			return 6;	//Odstranit objednavku
			break;
		case 5:
			return 5;	//Vydat objednavku
			break;
		case 6:
			return 7;	//Vypocitat denni obrat
			break;
		case 7:
			return 666;	//Konec
			break;
		default:
			printf("Spatny znak\n");
			return -1;
			break;
		}
		break;
	case 4: //tester
		switch (vstup)
		{
		case 1:
			return 1;	//Zadat objednavku
			break;
		case 2:
			return 2;	//Zobrazit menu
			break;
		case 3:
			return 3;	//Zobrazit objednavky
			break;
		case 4:
			return 4;	//Vyhledat objednavku
			break;
		case 5:
			return 5;	//Vydat objednavku
			break;
		case 6:
			return 6;	//Odstranit objednavku
			break;
		case 7:
			return 7;	//Vypocitat denni obrat
			break;
		case 8:
			return 8;	//Vypocitani doby
			break;
		case 9:
			return 666;	//Konec
			break;
		default:
			printf("Spatny znak\n");
			return -1;
			break;
		}
		break;
	default:
		//Kill.AllKittens();
		return -1;
		break;
	}
	return -1;
}

void Menu::ZobrazMenu()
{
	WhosSelling();

	switch (uroven_menu)
	{
	case 0:	//samoobsluha
		printf("\n************************************\n");
		printf("Volba 1 --- Zadat objednavku\n");
		printf("Volba 2 --- Zobrazit menu\n");
		printf("Volba 3 --- Konec\n");
		printf("\n************************************\n");
		break;
	case 1:	//prodavaè
		printf("\n************************************\n");
		printf("Volba 1 --- Zadat objednavku\n");
		printf("Volba 2 --- Zobrazit menu\n");
		printf("Volba 3 --- Zobrazit objednavky\n");
		printf("Volba 4 --- Vyhledat objednavku\n");
		printf("Volba 5 --- Vydat objednavku\n");
		printf("Volba 6 --- Konec\n");
		printf("\n************************************\n");
		break;
	case 2:	//obsluha
		printf("\n************************************\n");
		printf("Volba 1 --- Zadat objednavku\n");
		printf("Volba 2 --- Zobrazit menu\n");
		printf("Volba 3 --- Zobrazit objednavky\n");
		printf("Volba 4 --- Vyhledat objednavku\n");
		printf("Volba 5 --- Roztrid objednavky dle doby trvani\n");
		printf("Volba 6 --- Konec\n");
		printf("\n************************************\n");
		break;
	case 3:	//manažer
		printf("\n************************************\n");
		printf("Volba 1 --- Zadat objednavku\n");
		printf("Volba 2 --- Zobrazit menu\n");
		printf("Volba 3 --- Zobrazit objednavky\n");
		printf("Volba 4 --- Odstranit objednavku\n");
		printf("Volba 5 --- Vydat objednavku\n");
		printf("Volba 6 --- Vypocitat denni obrat\n");
		printf("Volba 7 --- Konec\n");
		printf("\n************************************\n");
		break;
	case 4: //tester
		printf("\n************************************\n");
		printf("Volba 1 --- Zadat objednavku\n");
		printf("Volba 2 --- Zobrazit menu\n");
		printf("Volba 3 --- Zobrazit objednavky\n");
		printf("Volba 4 --- Vyhledat objednavku\n");
		printf("Volba 5 --- Vydat objednavku\n");
		printf("Volba 6 --- Odstranit objednavku\n");
		printf("Volba 7 --- Vypocitat denni obrat\n");
		printf("Volba 8 --- Roztrid objednavky dle doby trvani\n");
		printf("Volba 9 --- Konec\n");
		printf("\n************************************\n");
		break;
	default:
		//Destroy.AllPuppies();
		break;
	}
}

