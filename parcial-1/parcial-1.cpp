#include <iostream>
#include <iomanip>
using namespace std;

class class_calcular_precio_portatil {
    public:
        double atr_precio_base = 200000.0;
        double atr_precio_memoria;
        double atr_precio_disco;
        double atr_lista_precio_total[10];
        void met_calcular_precio(int[10], int[10]);
};

void class_calcular_precio_portatil::met_calcular_precio(int var_lista_memorias[10], int var_lista_tipo_disco[10]){
    for (int i = 0; i < 10; i++)
    {
        if (var_lista_memorias[i] == 2 && var_lista_tipo_disco[i] == 1) {
            atr_precio_memoria = 400000.0;
            atr_precio_disco = 500000.0;
        }
        else if (var_lista_memorias[i] == 2 && var_lista_tipo_disco[i] == 2) {
            atr_precio_memoria = 400000.0;
            atr_precio_disco = 800000.0;
        }
        else if (var_lista_memorias[i] == 4 && var_lista_tipo_disco[i] == 1) {
            atr_precio_memoria = 500000.0;
            atr_precio_disco = 500000.0;
        }
        else if (var_lista_memorias[i] == 4 && var_lista_tipo_disco[i] == 2) {
            atr_precio_memoria = 500000.0;
            atr_precio_disco = 800000.0;
        }
            
        atr_lista_precio_total[i] = atr_precio_base + atr_precio_disco + atr_precio_memoria;

    }
}

class class_pedir_dato{
    public:
        int atr_lista_codigos[10];
        int atr_lista_memorias[10];
        int atr_lista_tipo_disco[10];
        void met_pedir_datos();
};

void class_pedir_dato::met_pedir_datos(){
    for (int i = 0; i < 10; i++){
        cout << "Ingrese el codigo del portatil " << i + 1 << ": ";
        cin >> atr_lista_codigos[i];
        cout << "Ingrese la memoria en GB del portatil " << i + 1 << " |  (2 GB) | (4 GB) |: ";
        cin >> atr_lista_memorias[i];
        cout << "Ingrese el tipo de disco duro del portatil " << i + 1 << " | (1) mecanico | (2) solido) |: ";
        cin >> atr_lista_tipo_disco[i];
    }
}

class class_mostrar_dato {
public:
    void met_mostrar_datos();
};

void class_mostrar_dato::met_mostrar_datos() {
    class_pedir_dato obj_datos;
    obj_datos.met_pedir_datos();
    class_calcular_precio_portatil obj_calcular_precio;
    obj_calcular_precio.met_calcular_precio(obj_datos.atr_lista_memorias, obj_datos.atr_lista_tipo_disco);
    for (int i = 0; i < 10; i++) {
        cout << "Codigo del portatil " << i + 1 << ": " << obj_datos.atr_lista_codigos[i] << endl;
        cout << "Memoria en GB del portatil " << i + 1 << ": " << obj_datos.atr_lista_memorias[i] << endl;
        cout << "Tipo de disco duro del portatil " << i + 1 << ": " << obj_datos.atr_lista_tipo_disco[i] << endl;
        cout << "Precio total del portatil " << i + 1 << ": $" << std::fixed << std::setprecision(0) << obj_calcular_precio.atr_lista_precio_total[i] << endl;
        cout << endl;
    }
}


int main()
{
    class_mostrar_dato obj_mostrar_datos;
    obj_mostrar_datos.met_mostrar_datos();

    return 0;
}

