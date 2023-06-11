#include <iostream>

#pragma region class_figura
    class class_figura {
        protected:
            double atr_base;
            double atr_altura;
            double atr_area;
        public:
            virtual void met_calcular_area(int, int);
            virtual void met_mostrar_area();
    };

    void class_figura::met_calcular_area(int var_base, int var_altura){
    }

    void class_figura::met_mostrar_area(){
    }
#pragma endregion

#pragma region class_area_triangulo
    class class_area_triangulo: public class_figura {
        public:
            void met_cacular_area(int, int);
            void met_mostrar_area();
    };

    void class_area_triangulo::met_cacular_area(int var_base, int var_altura){
        atr_area = (var_base * var_altura) / 2;
        this->met_mostrar_area();
    }

    void class_area_triangulo::met_mostrar_area()
    {
        std::cout << "El area del triangulo es: " << atr_area << "\n";
    }
#pragma endregion

#pragma region class_area_rectangulo
    class class_area_rectangulo : public class_figura {
    public:
        void met_cacular_area(int, int);
        void met_mostrar_area();
    };
    void class_area_rectangulo::met_cacular_area(int var_base, int var_altura){
        atr_area = var_base * var_altura;
        this->met_mostrar_area();
    }
    void class_area_rectangulo::met_mostrar_area(){
        std::cout << "El area del cuadrado es: " << atr_area << "\n";
    }
#pragma endregion

#pragma region class_area_trapecio

    class class_area_trapecio: public class_figura{
        public:
            void met_cacular_area(int, int, int);
            void met_mostrar_area();
    };

    void class_area_trapecio::met_cacular_area(int var_base, int var_altura, int var_base_mayor)
    {
        atr_area = ((var_base_mayor + var_base) / 2) * var_altura;
        this->met_mostrar_area();
    }
    void class_area_trapecio::met_mostrar_area()
    {
        std::cout << "El area del trapecio es: " << atr_area << "\n";
    }
#pragma endregion

#pragma region class_menu
    class class_menu {
        public:
            int atr_opcion = 0;
            void met_menu();
    };
    void class_menu::met_menu(){
        class_area_triangulo obj_area_triangulo;
        class_area_rectangulo obj_area_rectangulo;
        class_area_trapecio obj_area_trapecio;
        

        while (atr_opcion != 4)
        {
        std::cout << "Calcular area de (1) triangulo (2) rectangulo (3) trapecio (4) Salir: ";
        std::cin >> atr_opcion;
            switch (atr_opcion){
                case 1:
                    obj_area_triangulo.met_cacular_area(2, 2);
                    break;
                case 2:
                    obj_area_rectangulo.met_cacular_area(2, 2);
                    break;
                case 3: 
                    obj_area_trapecio.met_cacular_area(2, 2, 2);
                    break;
            default:
                break;
            }
        }
    }
#pragma endregion

int main()
{
    class_menu obj_menu;
    obj_menu.met_menu();
}

