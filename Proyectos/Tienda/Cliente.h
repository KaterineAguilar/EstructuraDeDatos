#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

using namespace std;

class Cliente
{
	int ID;
	int nPhone;
	string name;
	public:
		Cliente(int _ID, string _name, int _nPhone);
		int getID();
		string getName();
		string getNphone();
	
};

#endif
