#include <iostream>
#include <string>

#pragma region namespace

using namespace std;

#pragma endregion

#pragma region class_calculo

class class_calculo{
    public:
        int atr_numero_dias_trbajo_mes;
        int atr_numero_hijos;
        float atr_salario_mensual;
        
        float atr_salario_dia = 0;
        float atr_salario_neto = 0;
        float atr_subsidio_familiar = 0;
        float atr_total_recibido = 0;


        class_calculo(int, int, float);

        void met_salario_dia();
        void met_salario_neto();
        void met_subsidio_familiar();
        void met_total_recibido();
        void met_calcular();

};

class_calculo:: class_calculo(int var_numero_dias_trbajo_mes, int var_numero_hijos, float var_salario_mensual){
    atr_numero_dias_trbajo_mes = var_numero_dias_trbajo_mes;
    atr_numero_hijos = var_numero_hijos;
    atr_salario_mensual = var_salario_mensual;
}

void class_calculo::met_salario_dia(){
    atr_salario_dia = atr_salario_mensual / 30;
}

void class_calculo::met_salario_neto(){
    atr_salario_neto = atr_salario_dia * atr_numero_dias_trbajo_mes;
}

void class_calculo::met_subsidio_familiar(){
    atr_subsidio_familiar = atr_numero_hijos * 70000;
}

void class_calculo::met_total_recibido(){
    atr_total_recibido = atr_salario_neto + atr_subsidio_familiar;
}

void class_calculo::met_calcular() {
    this->met_salario_dia();
    this->met_salario_neto();
    this->met_subsidio_familiar();
    this->met_total_recibido();
}

#pragma endregion

#pragma region class_validacion

class class_validacion {
public:
    bool met_validar_numero_dias_trbajo_mes(int);
    bool met_validar_numero_hijo(int);
    bool met_validar_salario_mensual(int);
};

bool class_validacion::met_validar_numero_dias_trbajo_mes(int var_numero_dias_trbajo_mes) {
    if (var_numero_dias_trbajo_mes >= 0 && var_numero_dias_trbajo_mes <= 30) {
        return true;
    }
    return false;
}

bool class_validacion::met_validar_numero_hijo(int var_numero_de_hijo) {
    if (var_numero_de_hijo >= 0 && var_numero_de_hijo <= 10) {
        return true;
    }
    return false;
}

bool class_validacion::met_validar_salario_mensual(int var_salario_mensual) {
    if (var_salario_mensual >= 0 && var_salario_mensual <= 5000000) {
        return true;
    }
    return false;
}

#pragma endregion

#pragma region class_lectura_dato

class class_lectura_dato {
    public:
        int atr_identifiacion = 0;
        string atr_nombre = "";
        int atr_numero_dias_trbajo_mes = 0;
        int atr_numero_hijos = 0;
        float atr_salario_mensual = 0;

        void met_pedir_dato();
        void met_mostrar_dato();

};


void class_lectura_dato::met_pedir_dato() {

    class_validacion obj_validador = class_validacion();

    cout << "Digite su identificacion" << std::endl;
    std::cin >> atr_identifiacion;
    
    std::cout << "Digite su nombre" << std::endl;
    std::cin >> atr_nombre;
    
    std::cout << "Digite el numero de dias del mes que trabajo (Max 30 - Min 0)" << std::endl;
    std::cin >> atr_numero_dias_trbajo_mes;
    if(!obj_validador.met_validar_numero_dias_trbajo_mes(atr_numero_dias_trbajo_mes)) {
        std::cout << "[Error] El numero de dias ingresado es invalido" << std::endl;
        
        return;
    }
    
    std::cout << "Digite el numero de hijos que tiene (Max 9 - Min 0)" << std::endl;
    std::cin >> atr_numero_hijos;
    if (!obj_validador.met_validar_numero_hijo(atr_numero_hijos)) {
        std::cout << "[Error] El numero de hijos es invalido" << std::endl;
        
        return;
    }

    std::cout << "Digite su salario mensual" << std::endl;
    std::cin >> atr_salario_mensual;
    if (!obj_validador.met_validar_salario_mensual(atr_salario_mensual)) {
        std::cout << "[Error] Su salario es invalido" << std::endl;

        return;
    }

    met_mostrar_dato();
}

void class_lectura_dato::met_mostrar_dato() {
    class_calculo obj_calculo = class_calculo(atr_numero_dias_trbajo_mes, atr_numero_hijos, atr_salario_mensual);
    obj_calculo.met_calcular();

    std::cout << "---Estos son sus datos---" << std::endl;
    std::cout << "Identificacion : " << atr_identifiacion << std::endl;
    std::cout << "Nombre : " << atr_nombre << std::endl;
    std::cout << "Numero de dias que trabaja al mes: " << atr_numero_dias_trbajo_mes << std::endl;
    std::cout << "Numero de hijos que tiene: " << atr_numero_hijos << std::endl;
    std::cout << "Su salario mensual es: $" << atr_salario_mensual << std::endl;
    std::cout << "---Estos son los resultados---:" << std::endl;
    std::cout << "El salario por dia es: $" << obj_calculo.atr_salario_dia << std::endl;
    std::cout << "El salario neto es: $" << obj_calculo.atr_salario_neto << std::endl;
    std::cout << "El subsidio familiar es: $" << obj_calculo.atr_subsidio_familiar << std::endl;
    std::cout << "El salario total recibido es: $" << obj_calculo.atr_total_recibido << std::endl;
}

#pragma endregion

#pragma region main

int main() {

    class_lectura_dato obj_lectura;

    obj_lectura.met_pedir_dato();

    return 0;
}

#pragma endregion