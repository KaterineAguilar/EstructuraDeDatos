#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>

using namespace std;

class Producto
{
	int Code;
	string Desc;
	float Price;
	
	public:
		Producto(int _Code, string _Desc, float _Price);
		int getCode();
		string getDesc();
		float getPrice();
	
};

#endif
