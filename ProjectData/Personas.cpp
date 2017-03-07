#include "Personas.h"

Personas::Personas(){
	
}

Personas::Personas(int _id, string _name, string _lastName) {
	this->id = _id;
	this->name = _name;
	this->lastName = _lastName;
}

int Personas::getId(){
	return id;
}

string Personas::getName() {
	return name;	
}

string Personas::getLastName() {
	return lastName;	
}

void Personas::setId(int _id){
	this->id = _id;
}

void Personas::setName(string _name){
	this->name = _name;
}

void Personas::setLastName(string _lastname){
	this->lastName = _lastname;
}
	

