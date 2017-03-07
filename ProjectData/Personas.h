#include<iostream>
#include<string>

#ifndef PERSONAS_H
#define PERSONAS_H

using namespace std;

class Personas {
	private:
		int id;
		string name;
		string lastName;
	public:
		Personas();
		Personas(int _id, string _name, string _lastName);
		
		int getId();
		string getName();
		string getLastName();
		void setId(int _id);
		void setName(string _name);
		void setLastName(string _lastName);
		
};

#endif
