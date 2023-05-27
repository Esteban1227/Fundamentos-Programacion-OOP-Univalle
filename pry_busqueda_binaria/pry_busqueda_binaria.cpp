#include <iostream>
using namespace std;

class class_buscar_binario {
    public:
        void met_mostrar_arreglo(int[], int);
        int met_busqueda_binaria(int[], int, int);
        void met_ordenar_arreglo(int[], int);
        void met_intercambio(int, int);
        void met_mostrar_resultado(int);
        void met_leer_valor_buscar(int[], int);
};
void class_buscar_binario::met_mostrar_arreglo(int var_arreglo[], int tamano)
{
    for (int i = 0; i < tamano; i++)
    {
        cout << "Arreglo[" << i << "]=" << var_arreglo[i] << endl;
    }
}

int class_buscar_binario::met_busqueda_binaria(int var_arreglo[], int var_tamano, int var_clave)
{
    this->met_ordenar_arreglo(var_arreglo, var_tamano);

    int var_i_arriba = var_tamano - 1;
    int var_i_abajo = 0;
    int var_i_centro;
    while (var_i_abajo <= var_i_arriba)
    {
        var_i_centro = (var_i_arriba + var_i_abajo) / 2;
        if (var_arreglo[var_i_centro] == var_clave) {
            return var_i_centro;
        }
        else if (var_clave < var_arreglo[var_i_centro]) {
            var_i_arriba = var_i_centro - 1;
        }
        else {
            var_i_abajo = var_i_centro + 1;
        }
    }
    return -1;
}

void class_buscar_binario::met_ordenar_arreglo(int var_arreglo[], int tamano)
{
    for (int i = 0; i < tamano-1; i++)
    {
        for (int j = 0; i < tamano - 1; i++) {
            if (var_arreglo[j] > var_arreglo[j+1])
            {
                this->met_intercambio(var_arreglo[j], var_arreglo[j + 1]);
            }
        }
    }
}

void class_buscar_binario::met_intercambio(int var_a, int var_b)
{
    int var_aux = var_b;
    var_b = var_a;
    var_a = var_aux;
}

void class_buscar_binario::met_mostrar_resultado(int var_r)
{
    if (var_r >=1){
        cout << "si " << endl;
    }
    else {
        cout << "no"<< endl;
    }
}

void class_buscar_binario::met_leer_valor_buscar(int var_arreglo[], int var_tamano)
{
    int var_clave;
    cout << "Escriba el valor a buscar en el arreglo: " << endl;
    cin >> var_clave;

    int var_resultado = this->met_busqueda_binaria(var_arreglo, var_tamano, var_clave);
    this->met_mostrar_resultado(var_resultado);
}

class class_leer_dato {
public:
    void met_leer_datos(int[]);
};

void class_leer_dato::met_leer_datos(int var_arreglo[])
{
    int var_clave;

    class_buscar_binario obj_buscar_vector_binario;
    cout << "Escriba el valor a buscar en el arreglo: " << endl;
    cin >> var_clave;

    int var_res;
    int var_tamano = 15;

    var_res = obj_buscar_vector_binario.met_busqueda_binaria(var_arreglo, var_tamano, var_clave);
    obj_buscar_vector_binario.met_mostrar_resultado(var_res);
}



int main()
{
    const int var_tamano = 15;
    int var_arreglo[var_tamano] = { 25,17,13,16,41,32,12,115,95,84,54,63,78,21,10};

    class_buscar_binario obj_busqueda_binaria;

    class_leer_dato obj_leer_Dato;

    obj_busqueda_binaria.met_ordenar_arreglo(var_arreglo, var_tamano);
    obj_busqueda_binaria.met_mostrar_arreglo(var_arreglo, var_tamano);

    obj_leer_Dato.met_leer_datos(var_arreglo);


    return 0;
}

