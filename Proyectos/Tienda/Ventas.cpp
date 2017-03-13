#include "Ventas.h"

Ventas::Ventas(int _ID, int _Code)
{
	ID = _ID;
	Code = _Code;
}

int Ventas::getID()
{
	return ID;
}

int Ventas::getCode()
{
	return Code;
}
