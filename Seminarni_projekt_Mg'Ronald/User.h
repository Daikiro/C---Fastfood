#pragma once
#include <string>
#include <iostream>
typedef unsigned short ushort;
using namespace std;

class User
{
private:
	int id;
	string login;
	string password;
	ushort opravneni;
	User *pNext = NULL;

public:
	User() { ; }
	User(int v_id, string v_login, string v_password, ushort v_opravneni);
	User(ushort v_opravneni);
	~User(){};

	void GetUdaje(string &log, string &pass, ushort &oprav) const;

	int GetId() const;
	string GetLogin() const;
	string GetPass() const;
	ushort GetOprav() const;

	void ChangePass(string pass);
	void ChangeOprav(ushort oprav);

	friend class Seznam_user;
};