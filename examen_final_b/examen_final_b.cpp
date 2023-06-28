#include <iostream>

class class_servicios {
protected:
    int atr_lista_servicios[4];
};

class clas_mostrar {
public:
    void met_mostrar(int[4], int);
};

void clas_mostrar::met_mostrar(int var_lista[4], int var_total) {

    std::cout << "Valor de la lavada: " << var_lista[0] << std::endl;
    std::cout << "Valor de la aspirada: " << var_lista[1] << std::endl;
    std::cout << "Valor de la encerada: " << var_lista[2] << std::endl;
    std::cout << "Valor de la desmanchada: " << var_lista[3] << std::endl;

    std::cout << "Valor total: " << var_total << std::endl;
}

class class_calculo : public class_servicios {
public:
    class_calculo(int[4]);

    int atr_lista_servicios_precio[4] = { 10000, 5000, 15000, 15000 };

    int atr_valor_total = 0;

    int atr_lista_servicios_total[4];

    void met_calcular();
};

class_calculo::class_calculo(int var_lista_requerimientos[4]) {
    atr_lista_servicios[0] = var_lista_requerimientos[0];
    atr_lista_servicios[1] = var_lista_requerimientos[1];
    atr_lista_servicios[2] = var_lista_requerimientos[2];
    atr_lista_servicios[3] = var_lista_requerimientos[3];
}

void class_calculo::met_calcular() {
    for (int i = 0; i < 4; i++) {
        atr_lista_servicios_total[i] = atr_lista_servicios[i] * atr_lista_servicios_precio[i];

        atr_valor_total = atr_valor_total + atr_lista_servicios_total[i];
    }
}

class class_validacion {
public:
    bool met_validar(int);
};

bool class_validacion::met_validar(int var_valor)
{
    if (var_valor == 1 || var_valor == 0) {
        return true;
    }
    return false;
}

class class_menu :public class_servicios {
public:
    void met_menu();
};

void class_menu::met_menu() {
    int var_opcion = 1;
    int var_opcion_error = 1;
    class_validacion obj_validar;
    while (var_opcion != 0)
    {
        std::cout << "Lavadero de carros" << std::endl;
        std::cout << "------------------" << std::endl;
        std::cout << "¿Desea lavar el vehiculo? (1) si (0) no: " << std::endl;
        std::cin >> atr_lista_servicios[0];
        while (var_opcion_error !=0){
            if (atr_lista_servicios[0] == 1 || atr_lista_servicios[0] == 0) {
                var_opcion_error = 0;
            }
            else
                std::cout << atr_lista_servicios[0] << " No es una respuesta valida ¿Desea lavar el vehiculo? (1) si (0) no: " << std::endl;
                std::cin >> atr_lista_servicios[0];
            {
            }
        }
        std::cout << "¿Desea aspirar el vehiculo?: (1) si (0) no: " << std::endl;
        std::cin >> atr_lista_servicios[1];
        var_opcion_error = 1;
        while (var_opcion_error != 0) {
            if (!obj_validar.met_validar(atr_lista_servicios[1])) {
                std::cout << atr_lista_servicios[1] << " No es una respuesta valida ¿Desea aspirar el vehiculo?: (1) si (0) no: " << std::endl;
                std::cin >> atr_lista_servicios[1];
            }
            else
            {
                var_opcion_error = 0;
            }
        }
        std::cout << "¿Desea encerar el vehiculo? (1) si (0) no: " << std::endl;
        std::cin >> atr_lista_servicios[2];
        var_opcion_error = 1;
        while (var_opcion_error != 0) {
            if (!obj_validar.met_validar(atr_lista_servicios[2])) {
                std::cout << atr_lista_servicios[2] << " No es una respuesta valida ¿Desea encerar el vehiculo?: (1) si (0) no: " << std::endl;
                std::cin >> atr_lista_servicios[2];
            }
            else
            {
                var_opcion_error = 0;
            }
        }
        std::cout << "¿Desea desmanchar el vehiculo? (1) si (0) no: " << std::endl;
        std::cin >> atr_lista_servicios[3];
        var_opcion_error = 1;
        while (var_opcion_error != 0) {
            if (!obj_validar.met_validar(atr_lista_servicios[0])) {
                std::cout << atr_lista_servicios[3] << " No es una respuesta valida ¿Desea desmanchar el vehiculo?: (1) si (0) no: " << std::endl;
                std::cin >> atr_lista_servicios[3];
            }
            else
            {
                var_opcion_error = 0;
            }
        }

        class_calculo obj_calcular = class_calculo(atr_lista_servicios);
        obj_calcular.met_calcular();

        clas_mostrar obj_mostrar;
        obj_mostrar.met_mostrar(obj_calcular.atr_lista_servicios_total, obj_calcular.atr_valor_total);

        std::cout << "(0) Salir (1) Hacer otra consulta" << std::endl;
        std::cin >> var_opcion;

        if (var_opcion == 1) {
            system("cls");
        }


    }
}

int main() {
    class_menu obj_menu;
    obj_menu.met_menu();

    return 0;
}
