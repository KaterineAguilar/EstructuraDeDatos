#include "Producto.h"

Producto::Producto(int _Code, string _Desc, int _Price)
{
	Code = _Code;
	Desc = _Desc;
	Price = _Price;
}

int Producto::getCode()
{
	return Code;	
}

string Producto::getDesc()
{
	return Desc;
}

int Producto::getPrice()
{
	return Price;
}
