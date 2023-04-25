#pragma region include

#include <iostream>

#pragma endregion

#pragma region namespace

using namespace std;

#pragma endregion

#pragma region class_numero_aleatorio
class class_numero_aleatorio {
	public:
		void met_generar_lista_de_numeros(double[5]);
};
void class_numero_aleatorio::met_generar_lista_de_numeros(double var_lista_numeros[5])
{
	for (int i = 0; i < 5; i++) {
		var_lista_numeros[i] = (rand() % 751) / 10.0;
	}
}

#pragma endregion

#pragma region class_ordenamiento_quicksort

class class_ordenamiento_quicksort {
public:
	void met_ordenar(double var_lista_numeros[5], int var_valor_inicial, int var_valor_final);
	int met_dividir(double var_lista_numeros[5], int var_valor_inicial, int var_valor_final);
};

int class_ordenamiento_quicksort::met_dividir(double var_lista_numeros[5], int var_valor_inicial, int var_valor_final) {
	double var_pivote = var_lista_numeros[var_valor_final];

	int var_iterador = var_valor_inicial;

	for (int i = var_valor_inicial; i < var_valor_final; i++)
	{
		if (var_lista_numeros[i] <= var_pivote)
		{
			swap(var_lista_numeros[i], var_lista_numeros[var_iterador]);
			var_iterador++;
		}
	}

	swap(var_lista_numeros[var_iterador], var_lista_numeros[var_valor_final]);

	return var_iterador;
}

void class_ordenamiento_quicksort::met_ordenar(double var_lista_numeros[5], int var_valor_inicial, int var_valor_final) {
	if (var_valor_inicial >= var_valor_final) {
		return;
	}

	int var_pivote = this->met_dividir(var_lista_numeros, var_valor_inicial, var_valor_final);

	this->met_ordenar(var_lista_numeros, var_valor_inicial, var_pivote - 1);

	this->met_ordenar(var_lista_numeros, var_pivote + 1, var_valor_final);
}

#pragma endregion

#pragma region class_ordenamiento_burbuja

class class_ordenamiento_burbuja {
public:
	void met_ordenar(double var_lista_numeros[5]);
};

void class_ordenamiento_burbuja::met_ordenar(double var_lista_numeros[5]) {
	double var_aux = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (var_lista_numeros[i] < var_lista_numeros[j]) {
				var_aux = var_lista_numeros[i];
				var_lista_numeros[i] = var_lista_numeros[j];
				var_lista_numeros[j] = var_aux;
			}
		}
	}
}

#pragma endregion

#pragma region class_menu

class class_menu {
	public:
		int atr_opcion_menu_opcions = 1;
		double atr_lista_numeros[5] = {0,0,0,0,0};
		int var_longitud =  0;
		void met_abrir_menu();
		void met_mostrar_lista();

};

void class_menu::met_mostrar_lista(){
	cout << "array = [ ";
	for (int i = 0; i < 5; ++i) {
		cout << atr_lista_numeros[i] << ", ";
	}
	cout << "]" << endl;
}

void class_menu::met_abrir_menu(){
	class_numero_aleatorio obj_generador_aleatorio;
	obj_generador_aleatorio.met_generar_lista_de_numeros(atr_lista_numeros);
	while (atr_opcion_menu_opcions != 0)
	{	
		cout << "\nMenu de Opciones" << endl;
		this->met_mostrar_lista();
		cout << "0. Salir" << endl;
		cout << "1. Ordenar por el metodo burbuja" << endl;
		cout << "2. Ordenar por el metodo quicksort" << endl;
		cout << "3. desordenar lista" << endl;
		cout << "\nIngrese una opcion: ";
		cin >> atr_opcion_menu_opcions;
		switch (atr_opcion_menu_opcions){
			case 0:
				cout << "Chau :)" << endl;
				break;
			case 1:
                class_ordenamiento_burbuja obj_ordamiento_burbuja;
                obj_ordamiento_burbuja.met_ordenar(atr_lista_numeros);
				break;
            case 2:
				var_longitud = sizeof(atr_lista_numeros) / sizeof(atr_lista_numeros[0]);
				class_ordenamiento_quicksort obj_ordenamineto_quicksort;
				obj_ordenamineto_quicksort.met_ordenar(atr_lista_numeros, 0, var_longitud - 1);
                break;
			case 3:
				obj_generador_aleatorio.met_generar_lista_de_numeros(atr_lista_numeros);
			default:
				break;
		}
	}
}

#pragma endregion

#pragma region main

int main()
{
    class_menu obj_menu;
    obj_menu.met_abrir_menu();
    return 0;
}

#pragma endregion


