#ifndef REGISTRO_H
#define REGISTRO_H
#include <string>
using namespace std;

class Registro {
	
		int dato_int;
		char dato_char;
		string dato_string;
	public:
		Registro(){};
		Registro(int i, char c, string s) : dato_int(i), dato_char(c), dato_string(s) {};
		void setDato_int(int i) { dato_int = i; }
		void setDato_char(char c) { dato_char = c; }
		void setDato_string(string s) { dato_string = s; }
		bool operator<(Registro& r) { return dato_int < r.dato_int; }
		bool operator>(Registro& r) { return dato_int > r.dato_int; }
		bool operator<=(Registro& r) { return dato_int <= r.dato_int; }
		friend ostream& operator<<(ostream& os, const Registro& dt) {  
	    os << dt.dato_int << " " << dt.dato_char << " " << dt.dato_string << endl;
		    return os;  
		} 
};

#endif
