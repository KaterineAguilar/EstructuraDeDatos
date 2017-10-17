#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <cstring>
class Producto {
	private:
		int cod;
		char  des[45];
		float pre;
		int cant;
		int cant_aux;
	public:
		Producto() { }
		Producto (int co, char *v1, float v2, int c) { cod = co; strcpy(des,v1); pre = v2; cant = c; cant_aux = 0; }
		char *get_des() { return des; }
		float get_pre() { return pre; }
		int get_cod() { return cod; }
		int get_cant() { return cant; }
		int get_cant_aux() { return cant_aux; }
		void set_cant(int _cant) { cant = _cant; }
		void dec_cant(int _cant) { cant-=_cant; }
		void set_cant_aux(int _cant) { cant_aux = _cant; }
		bool operator <( Producto c ) { return this->cod < c.cod; }
		bool operator==( Producto c ) { return strcmpi(this->des,c.des)==0; }
		friend ostream & operator<<(  ostream &os, Producto  c ) { 
			os<< c.cod << " " << c.des << " " << c.cant << " " << c.pre; 
			return os;
		} 
		void imprimir() {
			cout << cod << " " << des << " " << cant << " " << pre << endl;
		}
};

#endif
