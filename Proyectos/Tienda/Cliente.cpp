#include "Cliente.h"

Cliente::Cliente(){
	
}

Cliente::Cliente(int _ID, string _name, long long int _nPhone)
{
	ID = _ID;
	name = _name;
	nPhone = _nPhone;
}

void Cliente::setID(int _ID)
{
	ID = _ID;
}

void Cliente::setName(string _Name)
{
	name = _Name;
}

void Cliente::setNPhone(long long int _nPhone)
{
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

long long int Cliente::getNphone()
{
	return nPhone;
}
