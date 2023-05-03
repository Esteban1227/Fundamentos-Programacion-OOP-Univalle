#include <iostream>
#include <iomanip>
using namespace std;

class class_calcular_precio_libro {
public:
    double atr_precio_formato_libro;
    double atr_precio_dias_prestamo;
    double atr_lista_precio_total[10];
    void met_calcular_precio(int[10], int[10]);
};

void class_calcular_precio_libro::met_calcular_precio(int var_lista_memorias[10], int var_lista_tipo_disco[10]) {
    for (int i = 0; i < 10; i++)
    {
        if (var_lista_memorias[i] == 2 && var_lista_tipo_disco[i] == 1) {
            atr_precio_formato_libro = 5000;
            atr_precio_dias_prestamo = 2000;
        }
        else if (var_lista_memorias[i] == 2 && var_lista_tipo_disco[i] == 2) {
            atr_precio_formato_libro = 5000;
            atr_precio_dias_prestamo = 1000;
        }
        else if (var_lista_memorias[i] == 4 && var_lista_tipo_disco[i] == 1) {
            atr_precio_formato_libro = 7000;
            atr_precio_dias_prestamo = 2000;
        }
        else if (var_lista_memorias[i] == 4 && var_lista_tipo_disco[i] == 2) {
            atr_precio_formato_libro = 7000;
            atr_precio_dias_prestamo = 1000;
        }

        atr_lista_precio_total[i] = atr_precio_dias_prestamo + atr_precio_formato_libro;

    }
}

class class_pedir_dato {
public:
    int atr_lista_codigos[10];
    int atr_lista_tipo_bicicleta[10];
    int atr_lista_estilo_bicicleta[10];
    void met_pedir_datos();
};

void class_pedir_dato::met_pedir_datos() {
    for (int i = 0; i < 10; i++) {
        cout << "Ingrese el codigo del libro " << i + 1 << ": ";
        cin >> atr_lista_codigos[i];
        cout << "Ingrese el año de publicacion " << i + 1 << endl;
        cin >> atr_lista_tipo_bicicleta[i];
        cout << "Ingrese el formato del libro " << i + 1 << " | (1) De lujo | (2) Normal |: ";
        cin >> atr_lista_estilo_bicicleta[i];
        cout << "Ingrese el formato del libro " << i + 1 << " | (1) De lujo | (2) Normal |: ";
        cin >> atr_lista_estilo_bicicleta[i];
    }
}

class class_mostrar_dato {
public:
    void met_mostrar_datos();
};

void class_mostrar_dato::met_mostrar_datos() {
    class_pedir_dato obj_datos;
    obj_datos.met_pedir_datos();
    class_calcular_precio_libro obj_calcular_precio;
    obj_calcular_precio.met_calcular_precio(obj_datos.atr_lista_tipo_bicicleta, obj_datos.atr_lista_estilo_bicicleta);
    for (int i = 0; i < 10; i++) {
        cout << "Código de la bicicleta " << i + 1 << ": " << obj_datos.atr_lista_codigos[i] << endl;
        cout << "tipo de bicicleta |  (1) Pedal | (2) Electrica |  " << i + 1 << ": " << obj_datos.atr_lista_tipo_bicicleta[i] << endl;
        cout << "estilo de la bicicleta | (1) Deportiva | (2) Clasica) | " << i + 1 << ": " << obj_datos.atr_lista_estilo_bicicleta[i] << endl;
        cout << "Precio del alquiler de la bicicleta " << i + 1 << ": $" << std::fixed << std::setprecision(0) << obj_calcular_precio.atr_lista_precio_total[i] << endl;
        cout << endl;
    }
}


int main()
{
    class_mostrar_dato obj_mostrar_datos;
    obj_mostrar_datos.met_mostrar_datos();

    return 0;
}
