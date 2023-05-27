// pry_busqueda.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;



class class_buscar_vector {
    public:
        float met_pedir_dato();
        void met_buscar_elemento(float[5]);
};
float class_buscar_vector::met_pedir_dato()
{
    float var_numero_buscado;
    cout << "Entre el numero a buscar" << endl;
    cin >> var_numero_buscado;
    return var_numero_buscado;
}
void class_buscar_vector::met_buscar_elemento(float var_array[5])
{
    bool var_resultado_busqueda = false;
    float var_numero_buscado = this->met_pedir_dato();
    int var_posicion;


    for (int i = 0; i < 5; i++)
    {
        if (var_array[i] == var_numero_buscado) {
            var_resultado_busqueda = true;
            var_posicion = i;
            break;

        }
    }

    if (var_resultado_busqueda) {
        cout << "El numero existe y esta en la posicion: [" << var_posicion << "]" << endl;
        return;
    }

    cout << "El numero no existe" << endl;

}

int main()
{
    float var_array[5] = {2,3,4,1,5};
    class_buscar_vector obj_buscar_vector;
    obj_buscar_vector.met_buscar_elemento(var_array);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

