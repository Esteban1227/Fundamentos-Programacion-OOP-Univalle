#include <iostream>
#include <string>
using namespace std;

class class_validacion{
	public: 
		bool met_validar_divisor(int var_n2);
};

bool class_validacion::met_validar_divisor(int var_n2){
	bool var_es_valido = true;
	
	if(var_n2 == 0){
		var_es_valido = false;
	}
	
	return var_es_valido;
}

class class_calculadora{
	private:
		int atr_n1;
		int atr_n2;
	public:
		class_calculadora(int,int);
		void met_sumar();
		void met_restar();
		void met_multiplicar();
		void met_dividir();
};


class_calculadora::class_calculadora(int var_n1, int var_n2){
	atr_n1= var_n1;
	atr_n2= var_n2;
}

void class_calculadora::met_sumar(){
	cout << "El resultado de la suma es: " << atr_n1+ atr_n2 << endl;
}

void class_calculadora::met_restar(){
	cout << "El resultado de la resta es: " << atr_n1 - atr_n2 << endl;
}

void class_calculadora::met_multiplicar(){
	cout << "El resultado de la multiplicacion es: " << atr_n1 * atr_n2 << endl;
}

void class_calculadora::met_dividir(){
	
	string var_mensaje;

	class_validacion obj_validacion = class_validacion();

	if(obj_validacion.met_validar_divisor(atr_n2)){
		var_mensaje = "El resultado de la division es: " + to_string(atr_n1 / atr_n2);
	}else{
		var_mensaje = "No se puede diviir por 0";
	}
	
	cout << var_mensaje << endl;
}

int main() {
	class_calculadora obj_c1 = class_calculadora(12,2);

	obj_c1.met_sumar();
	obj_c1.met_restar();
	obj_c1.met_multiplicar();
	obj_c1.met_dividir();

	return 0;
}