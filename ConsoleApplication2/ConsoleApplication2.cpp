#include <iostream>
using namespace std;


class class_datos
{
protected:
    int atr_b;
    int atr_h;
    int atr_B;
    int atr_resultado;
public:
    void met_areab();
    void met_areah();
    void met_areaB();
    void met_resultado();
};

void class_datos::met_areab()
{
    cout << "Ingrese el valor de la base: ";
    cin >> atr_b;
}

void class_datos::met_areah()
{
    cout << "Ingrese el valor de la altura: ";
    cin >> atr_h;
}

void class_datos::met_areaB()
{
    cout << "ingrese el valor de base mayor: ";
    cin >> atr_B;
}
void class_datos::met_resultado()
{
    cout << atr_resultado << "\n";
}

class class_triangulo : public class_datos
{
public:
    void met_areaT();
};

void class_triangulo::met_areaT()
{
    atr_resultado = (atr_b * atr_h) / 2;
}

class class_rectangulo : public class_datos
{
public:
    void met_areaR();
};

void class_rectangulo::met_areaR()
{
    atr_resultado = (atr_b * atr_h);
}

class class_validar
{
public:
    bool met_validar(int, int);
};

bool class_validar::met_validar(int var_B, int var_b)
{
    if (var_B > var_b)
    {
        return true;
    }
    else
    {
        return false;
    }

}


class class_trapecio : public class_datos
{
public:
    void met_areaTR();
};

void class_trapecio::met_areaTR()
{
    class_validar obj_Validar;
    
    if (obj_Validar.met_validar(atr_B, atr_b)) {
        atr_resultado = ((atr_b + atr_B) / 2) * atr_h;
        cout << "El area del trapecio es: ";
        this->met_resultado();
    }
    else
    {
        cout << "error" << endl;
    }
}







class class_menu
{
public:

    void met_navegar();
};


void class_menu::met_navegar()
{
    int opcion = -1;
    while (opcion != 0)
    {

        cout << "\t Menu" << endl;
        cout << "-----------" << endl;
        cout << "1- Calcular Triangulo" << endl;
        cout << "2- Calcular Rectangulo" << endl;
        cout << "3- Calcular Trapecio" << endl;
        cout << "0- Salir." << endl;
        cin >> opcion;

        switch (opcion)
        {

        case 1:
            class_triangulo obj_triangulo1;
            obj_triangulo1.met_areab();
            obj_triangulo1.met_areah();
            obj_triangulo1.met_areaT();
            cout << "El area del triangulo es: ";
            obj_triangulo1.met_resultado();
            break;

        case 2:
            class_rectangulo obj_rectangulo1;
            obj_rectangulo1.met_areab();
            obj_rectangulo1.met_areah();
            obj_rectangulo1.met_areaR();
            cout << "El area del rectangulo es: ";
            obj_rectangulo1.met_resultado();
            break;

        case 3:
            class_trapecio obj_trapecio1;
            obj_trapecio1.met_areab();
            obj_trapecio1.met_areah();
            obj_trapecio1.met_areaB();
            obj_trapecio1.met_areaTR();
            break;
        }




    }

}

int main()
{
    class_menu obj_menu1;
    obj_menu1.met_navegar();

    return 0;
}
