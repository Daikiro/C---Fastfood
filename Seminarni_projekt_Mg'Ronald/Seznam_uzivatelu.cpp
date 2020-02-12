#include "pch.h"
#include "Seznam_uzivatelu.h"
#include "User.h"


Seznam_user::Seznam_user()
{
	pHead = NULL;
}

Seznam_user::~Seznam_user()
{
	while (pHead != NULL)
	{
		User *pTmp = pHead;
		pHead = pHead->pNext;
		delete pTmp; pTmp = NULL;
	}
}


void Seznam_user::Tisk() const
{
	User *pTmp = pHead;
	int uroven = 0;
	//Není tøeba øešit otázka prázdnosti
	while (pTmp != NULL)
	{
		cout << "ID uzivatele: " << pTmp->id << " Login: " << pTmp->login << " Heslo: " << pTmp->password << " Uroven opravneni: " << pTmp->opravneni << endl;
		
		pTmp = pTmp->pNext;
		if (uroven != pTmp->opravneni)
		{
			cout << endl;
			uroven++;
		}
	}
	cout << endl;
}

void Seznam_user::Add(int v_id, string v_login, string v_password, ushort v_opravneni)	//pridani na konec seznamu
{
	User *pNew = new User(v_id, v_login, v_password, v_opravneni);
	User *pTmp = pHead;
	

	// zde bude id pro 0 tudiz ji pak neni treba resit - automat bude vzdy prvni a bude ho mit jen jeden
	if (pHead == NULL)
		pHead = pNew;
	else
	{
		User *pNext_ret = pHead->pNext;


		while (pTmp->pNext != NULL)
		{
			if (pNext_ret->opravneni  == v_opravneni +1 )
			{
				break;
			}
			pTmp = pTmp->pNext;
			pNext_ret = pNext_ret->pNext;	
		}

		pTmp->pNext = pNew;
		pNew->pNext = pNext_ret;
			
	}
}


bool Seznam_user::Contains(string name, string pass)
{
	User *pTmp = pHead;

	if (pTmp != NULL)
	{
		do
		{
			if (name == pTmp->login && pass == pTmp->password)
			return true;
			pTmp = pTmp->pNext;

		} while (pTmp != NULL);
	}
	return false;
}

int Seznam_user::Count()
{
	int counting = 0;
	User *pTmp = pHead;

	if (pTmp != NULL)
	{
		do
		{
			counting++;
			pTmp = pTmp->pNext;

		} while (pTmp != NULL);
	}

	return counting;
}

int Seznam_user::GetOprav(string name, string pass)
{
	User *pTmp = pHead;

	if (pTmp != NULL)
	{
		do
		{
			if (name == pTmp->login && pass == pTmp->password)
				return pTmp->GetOprav();
			pTmp = pTmp->pNext;

		} while (pTmp != NULL);
	}
	return -1;
}
