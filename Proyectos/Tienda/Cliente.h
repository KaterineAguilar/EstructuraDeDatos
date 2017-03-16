#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>

using namespace std;

class Cliente
{
	int ID;
 	long long int nPhone;
	string name;
	public:
		Cliente();
		Cliente(int _ID, string _name, long long int _nPhone);
		void setID(int _ID);
		void setName(string _Name);
		void setNPhone(long long int _nPhone);
		int getID();
		string getName();
		long long int getNphone();
	
};

#endif
