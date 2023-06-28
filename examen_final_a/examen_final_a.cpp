#include <iostream>



class class_configuracion {
    protected:
        int atr_lista_requerimientos[4];
};

class clas_mostrar {
    public:
        void met_mostrar(int[4], int);
};

void clas_mostrar::met_mostrar(int var_lista[4], int var_total){
    
    std::cout << "Valor del espacio: " << var_lista[0] << std::endl;
    std::cout << "Valor de los correos: " << var_lista[1] << std::endl;
    std::cout << "Valor de las bases de datos: " << var_lista[2] << std::endl;
    std::cout << "Valor del ancho de banda: " << var_lista[3] << std::endl;

    std::cout << "Valor total: " << var_total << std::endl;
}

class class_calculo: public class_configuracion {
    public:
        class_calculo(int[4]);

        int atr_lista_requerimiento_precio[4] = { 2000, 1000, 3000, 500 };

        int atr_valor_total = 0;

        int atr_lista_requerimiento_total[4];

        void met_calcular();
};

class_calculo::class_calculo(int var_lista_requerimientos[4]) {
    atr_lista_requerimientos[0] = var_lista_requerimientos[0];
    atr_lista_requerimientos[1] = var_lista_requerimientos[1];
    atr_lista_requerimientos[2] = var_lista_requerimientos[2];
    atr_lista_requerimientos[3] = var_lista_requerimientos[3];
}

void class_calculo::met_calcular(){
    for (int i = 0; i < 4; i++){
        atr_lista_requerimiento_total[i] = atr_lista_requerimientos[i] * atr_lista_requerimiento_precio[i];

        atr_valor_total = atr_valor_total + atr_lista_requerimiento_total[i];
    }
}

class class_validacion {
    public:
        bool met_validar_espacio(int);
        bool met_validar_correo(int);
        bool met_validar_bases(int);
        bool met_validar_ancho_banda(int);
};

bool class_validacion::met_validar_espacio(int var_valor)
{
    return var_valor <= 100;
}

bool class_validacion::met_validar_correo(int var_valor)
{
    return var_valor <= 500;
}

bool class_validacion::met_validar_bases(int var_valor)
{
    return var_valor <= 50;
}

bool class_validacion::met_validar_ancho_banda(int var_valor)
{
    return var_valor <= 500;
}

class class_menu:public class_configuracion{
    public:
        void met_menu();
};

void class_menu::met_menu(){
    int var_opcion = 1;
    class_validacion obj_validacion;
    while (var_opcion !=0)
    {
        std::cout << "Configuración del espacio en la nube" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << "¿Cuanto espacio en GB requiere? (MAX 100GB): " << std::endl;
        std::cin >> atr_lista_requerimientos[0];
        if (!obj_validacion.met_validar_espacio(atr_lista_requerimientos[0])) {
            std::cout << "Pasaste el limite" << std::endl;
            break;
        }
        std::cout << "¿Cuanto correos coorporativos requiere? (MAX 500): " << std::endl;
        std::cin >> atr_lista_requerimientos[1];

        if (!obj_validacion.met_validar_correo(atr_lista_requerimientos[1])) {
            std::cout << "Pasaste el limite" << std::endl;
            break;
        }

        std::cout << "¿Cuantas bases de datos requiere? (MAX 50): " << std::endl;
        std::cin >> atr_lista_requerimientos[2];
        if (!obj_validacion.met_validar_bases(atr_lista_requerimientos[2])) {
            std::cout << "Pasaste el limite" << std::endl;
            break;
        }
        std::cout << "¿Cuanta ancho de banda en GB requiere? (MAX 500): " << std::endl;
        std::cin >> atr_lista_requerimientos[3];
        if (!obj_validacion.met_validar_ancho_banda(atr_lista_requerimientos[3])) {
            std::cout << "Pasaste el limite" << std::endl;
            break;
        }

        class_calculo obj_calcular = class_calculo(atr_lista_requerimientos);
        obj_calcular.met_calcular();

        clas_mostrar obj_mostrar;
        obj_mostrar.met_mostrar(obj_calcular.atr_lista_requerimiento_total, obj_calcular.atr_valor_total);

        std::cout << "(0) Salir (1) Hacer otra consulta" << std::endl;
        std::cin >> var_opcion;

        if (var_opcion == 1) {
            system("cls");
        }


    }
}

int main(){
    class_menu obj_menu;
    obj_menu.met_menu();

    return 0;
}

