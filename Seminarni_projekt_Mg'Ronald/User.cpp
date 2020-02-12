#include "pch.h"
#include "User.h"


User::User(int v_id, string v_login, string v_password, ushort v_opravneni)
{
	id = v_id;
	login = v_login;
	password = v_password;
	opravneni = v_opravneni;
}

User::User(ushort v_opravneni)
{
	id = 0;
	login = "";
	password = "";
	opravneni = v_opravneni;
}

void User::GetUdaje(string &log, string &pass, ushort &oprav) const
{
	log = login;
	pass = password;
	oprav = opravneni;
}

int User::GetId() const
{
	return id;
}

string User::GetLogin() const
{
	return login;
}
string User::GetPass() const
{
	return password;
}
ushort User::GetOprav() const
{
	return opravneni;
}

void User::ChangePass(string pass)
{
	password = pass;
}
void User::ChangeOprav(ushort oprav)
{
	opravneni = oprav;
}