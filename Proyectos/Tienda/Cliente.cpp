#include "Cliente.h"

Cliente::Cliente(int _ID, string _name, int _nPhone)
{
	ID = _ID;
	name = _name;
	nPhone = _nPhone;
}

int Cliente::getID()
{
	return ID;
}

string Cliente::getName()
{
	return name;	
}

string Cliente::getNphone()
{
	return nPhone;
}
