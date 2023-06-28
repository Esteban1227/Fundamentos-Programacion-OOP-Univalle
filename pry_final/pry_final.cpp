#pragma region include
    #include <iostream>
    #include <string>
    #include <stdlib.h>
    #include <time.h>
    #include <vector>
#pragma endregion

#pragma region namespace
    using namespace std;    
#pragma endregion

#pragma region class_usuario
    class class_usuario
    {
        protected:
            string atr_nombre_usuario;
            string atr_contrasena_usuario;
    };
#pragma endregion

#pragma region class_numero_random
    class class_numero_random {
        public:
            double atr_numero_random;
            double met_generar_numero_random();

            class_numero_random();
    };

    class_numero_random::class_numero_random() {
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    double class_numero_random::met_generar_numero_random()
    {
        return 1 + rand() % 5000000;;
    }
#pragma endregion

#pragma region class_lista_usuario
    class class_lista_usuario {
        public:
            vector<string> atr_lista_usuario;
            vector<string> atr_lista_contrasena_usuario;
            vector<double> atr_lista_saldo;
            void met_usuarios_base();
            void met_agregar_usuario(string, string);
            void met_retirar_dinero(int, int);
            void met_ingresar_dinero(int, int);
        };

    void class_lista_usuario::met_usuarios_base() {

        class_numero_random obj_numero_random;

        //Usuarios de vector
        atr_lista_usuario.push_back("luis");
        atr_lista_usuario.push_back("jorge");
        atr_lista_usuario.push_back("james");
        atr_lista_usuario.push_back("johan");
        atr_lista_usuario.push_back("kevin");

        //claves al vector
        atr_lista_contrasena_usuario.push_back("123");
        atr_lista_contrasena_usuario.push_back("456");
        atr_lista_contrasena_usuario.push_back("789");
        atr_lista_contrasena_usuario.push_back("abc");
        atr_lista_contrasena_usuario.push_back("efg");

        //Saldo
        atr_lista_saldo.push_back(obj_numero_random.met_generar_numero_random());
        atr_lista_saldo.push_back(obj_numero_random.met_generar_numero_random());
        atr_lista_saldo.push_back(obj_numero_random.met_generar_numero_random());
        atr_lista_saldo.push_back(obj_numero_random.met_generar_numero_random());
        atr_lista_saldo.push_back(obj_numero_random.met_generar_numero_random());
    }

    void class_lista_usuario::met_agregar_usuario(string var_nombre_usuario, string var_contrasena_usuario) {
        atr_lista_usuario.push_back(var_nombre_usuario);
        atr_lista_contrasena_usuario.push_back(var_contrasena_usuario);
        atr_lista_saldo.push_back(0.0);
    }
    
    void class_lista_usuario::met_retirar_dinero(int var_posicion, int var_cantidad_dinero){
        atr_lista_saldo.at(var_posicion) = atr_lista_saldo.at(var_posicion) - var_cantidad_dinero;
    }

    void class_lista_usuario::met_ingresar_dinero(int var_posicion, int var_cantidad_dinero){
        atr_lista_saldo.at(var_posicion) = atr_lista_saldo.at(var_posicion) + var_cantidad_dinero;
    }
#pragma endregion

#pragma region class_buscar_usuario
    class class_buscar_usuario{
        public:
            int met_buscar_usuario(class_lista_usuario&, string);
    };
    int class_buscar_usuario::met_buscar_usuario(class_lista_usuario& var_lista, string var_nombre_usuario){
        for (int i = 0; i < var_lista.atr_lista_usuario.size(); i++) {
            if (var_lista.atr_lista_usuario.at(i) == var_nombre_usuario) {
                return i;
            }
        }
        return 404;
    }
#pragma endregion

#pragma region class_transferir_dinero
    class class_transferir_dinero {
        public:
            void met_tranferir_dinero(class_lista_usuario&, string, string, int);      
    };

    void class_transferir_dinero::met_tranferir_dinero(class_lista_usuario& var_listas, string var_nombre_usuario_receptor, string var_nombre_usuario_emisor, int var_cantidad_dinero){
        class_buscar_usuario obj_buscar_usuario;
        int var_numero_usuario_receptor = obj_buscar_usuario.met_buscar_usuario(var_listas, var_nombre_usuario_receptor);
        int var_numero_usuario_emisor = obj_buscar_usuario.met_buscar_usuario(var_listas, var_nombre_usuario_emisor);

        var_listas.met_retirar_dinero(var_numero_usuario_emisor, var_cantidad_dinero);
        var_listas.met_ingresar_dinero(var_numero_usuario_receptor, var_cantidad_dinero);
    }
#pragma endregion

#pragma region class_validacion_existencia_usuario
    class class_validacion_existencia_usuario {
        public:
            bool met_validar_existencia_usuario(class_lista_usuario&, string);
    };

    bool class_validacion_existencia_usuario::met_validar_existencia_usuario(class_lista_usuario& var_lista, string var_nombre_usuario_receptor){
        class_buscar_usuario obj_buscar_usuario;
        int var_posicion_usuario = obj_buscar_usuario.met_buscar_usuario(var_lista, var_nombre_usuario_receptor);

        if (var_posicion_usuario != 404){
            return true;
        }
        return false;
    }
#pragma endregion

#pragma region class_validacion_saldo
    class class_validacion_saldo {
    public:
        bool met_validar_saldo(class_lista_usuario&, string, int);
    };

    bool class_validacion_saldo::met_validar_saldo(class_lista_usuario& var_lista, string var_nombre_usuario_emisor, int var_cantidad_dinero){
        class_buscar_usuario obj_buscar_usuario;
        int var_posicion_usuario = obj_buscar_usuario.met_buscar_usuario(var_lista, var_nombre_usuario_emisor);

        if (var_cantidad_dinero <= var_lista.atr_lista_saldo.at(var_posicion_usuario)){
            return true;
        }
        return false;
    }
#pragma endregion

#pragma region class_interfaz_ingresar_dinero
    class class_interfaz_ingresar_dinero {
    public:
        int atr_cantidad_dinero;
        void met_interfaz_ingresar_dinero(class_lista_usuario&, string);
    };

    void class_interfaz_ingresar_dinero::met_interfaz_ingresar_dinero(class_lista_usuario& var_listas, string var_nombre_usuario) {
        system("cls");
        cout << "\t\t\tMENU INGRESAR DINERO" << endl;
        cout << "\t\t\t-------------------" << endl;
        cout << "\n\tDigite la cantidad de dinero que sea ingresar: " << endl;
        cout << "\n\t> ";
        cin >> atr_cantidad_dinero;

        class_buscar_usuario obj_buscar_usuario;
        int var_posicion_usuario = obj_buscar_usuario.met_buscar_usuario(var_listas, var_nombre_usuario);

        string var_salir;
        var_listas.met_ingresar_dinero(var_posicion_usuario, atr_cantidad_dinero);
        cout << "Su ingreso de dinero fue exitoso" << endl;
        cout << "Oprime cualquier tecla para volver al menu" << endl;
        cout << ">";
        cin >> var_salir;
    }
#pragma endregion

#pragma region class_interfaz_reirar_dinero
    class class_interfaz_retirar_dinero {
        public:
            int atr_cantidad_dinero;
            void met_interfaz_retirar_dinero(class_lista_usuario&, string);
    };

    void class_interfaz_retirar_dinero::met_interfaz_retirar_dinero(class_lista_usuario& var_listas, string var_nombre_usuario){
        system("cls");
        cout << "\t\t\tMENU RETIRAR DINERO" << endl;
        cout << "\t\t\t-------------------" << endl;
        cout << "\n\tDigite la cantidad de dinero que sea retirar: " << endl;
        cout << "\n\t> ";
        cin >> atr_cantidad_dinero;

        class_validacion_saldo obj_validar_saldo;
        bool var_saldo = obj_validar_saldo.met_validar_saldo(var_listas, var_nombre_usuario, atr_cantidad_dinero);
        
        class_buscar_usuario obj_buscar_usuario;
        int var_posicion_usuario = obj_buscar_usuario.met_buscar_usuario(var_listas, var_nombre_usuario);
        
        string var_salir;

        if (var_saldo == true) {
            var_listas.met_retirar_dinero(var_posicion_usuario, atr_cantidad_dinero);
            cout << "Su retiro fue exitoso"<< endl;
            cout << "Oprime cualquier tecla para volver al menu" << endl;
            cout << ">";
            cin >> var_salir;
        }
    }
#pragma endregion

#pragma region class_interfaz_transferecia
    class class_interfaz_transferencia {
        public:
            string atr_nombre_usuario_receptor;
            int atr_cantidad_dinero;
            void met_interfaz_transferencia(class_lista_usuario&, string);
    };

    void class_interfaz_transferencia::met_interfaz_transferencia(class_lista_usuario& var_lista, string var_nombre_usuario_emisor){
        system("cls");
        cout << "\t\t\tMENU TRANSFERENCIA" << endl;
        cout << "\t\t\t------------------" << endl;
        cout << "\n\tDigite el nombre de Usuario: " << endl;
        cout << "\n\t> ";
        cin >> atr_nombre_usuario_receptor;
        cout << "\n\tDigite la Cantidad de dinero: ";
        cout << "\n\t> ";
        cin >> atr_cantidad_dinero;

        class_validacion_saldo obj_validar_saldo;

        class_validacion_existencia_usuario obj_validar_usuario;
        
        bool var_saldo_valido = obj_validar_saldo.met_validar_saldo(var_lista, var_nombre_usuario_emisor, atr_cantidad_dinero);
        bool var_usuario_valido = obj_validar_usuario.met_validar_existencia_usuario(var_lista, atr_nombre_usuario_receptor);
        
        string var_salir;

        if (var_usuario_valido == true && var_saldo_valido == true) {
            class_transferir_dinero obj_trasferencia;
            obj_trasferencia.met_tranferir_dinero(var_lista, atr_nombre_usuario_receptor, var_nombre_usuario_emisor, atr_cantidad_dinero);
            cout << "Transferencia exitosa" << endl;
            cout << "Oprime cualquier tecla para volver al menu" << endl;
            cout << ">";
            cin >> var_salir;
        }
        else{
            cout << "Transferencia no exitosa" << endl;
            cout << "Oprime cualquier tecla para volver al menu" << endl;
            cout << ">";
            cin >> var_salir;
        }
    }
#pragma endregion
    
#pragma region class_revisar_saldo
    class class_revisar_saldo {
        public:
            void met_revisar_saldo(class_lista_usuario&,string);
    };

    void class_revisar_saldo::met_revisar_saldo(class_lista_usuario& var_lista, string var_nombre_usuario){
        class_buscar_usuario obj_buscar;
        int var_posicion_usuario = obj_buscar.met_buscar_usuario(var_lista, var_nombre_usuario);
        string var_salir;
        system("cls");
        cout << "Su saldo es: $" << var_lista.atr_lista_saldo.at(var_posicion_usuario) << endl;
        cout << "Oprime cualquier tecla para volver al menu" << endl;
        cout << ">";
        cin >> var_salir;
    }


#pragma endregion

#pragma region class_interfaz_menu
    class class_interfaz_menu {
    public:
        void met_interfaz_menu(class_lista_usuario&, string);
    };

    void class_interfaz_menu::met_interfaz_menu(class_lista_usuario& var_listas, string var_nombre_usuario) {
        class_revisar_saldo obj_revisar_saldo;
        class_interfaz_transferencia obj_transferencia;
        class_interfaz_retirar_dinero obj_retirar;
        class_interfaz_ingresar_dinero obj_ingresar;
        int var_opcion = 1;
        
        while (var_opcion != 5)
        {
            system("cls");
            cout << "\t\t\tMENU" << endl;
            cout << "\t\t\t----" << endl;
            cout << "\n\tHola, " << var_nombre_usuario << endl;
            cout << "\n\t¿Que deseas hacer?" << endl;
            cout << "\n\t1) Saldo de la cuenta";
            cout << "\n\t2) Transferir dinero";
            cout << "\n\t3) Retirar dinero";
            cout << "\n\t4) Depositar dinero";
            cout << "\n\t5) Salir" << endl;
            cout << "\n\t> ";
            cin >> var_opcion;

            switch (var_opcion) {
            case 1:
                obj_revisar_saldo.met_revisar_saldo(var_listas, var_nombre_usuario);
                break;
            case 2:
                obj_transferencia.met_interfaz_transferencia(var_listas, var_nombre_usuario);
                break;
            case 3:
                obj_retirar.met_interfaz_retirar_dinero(var_listas, var_nombre_usuario);
                break;
            case 4:
                obj_ingresar.met_interfaz_ingresar_dinero(var_listas, var_nombre_usuario);
                break;
            case 5:
                break;
            }
        }
    }
    
#pragma endregion

#pragma region class_crear_usuario
    class class_crear_usuario {
        public:
            bool met_crear_usuario(string, string, class_lista_usuario&);
    };

    bool class_crear_usuario::met_crear_usuario(string var_nombre_usuario, string var_contrasena_usuario, class_lista_usuario& var_listas) {
        var_listas.met_agregar_usuario(var_nombre_usuario, var_contrasena_usuario);
        return true;
    }
#pragma endregion

#pragma region class_validacion_usuario
    
    class class_validacion_usuario:public class_usuario {
        public:
            class_lista_usuario atr_obj_listas;

            bool met_validar_usuario();

            class_validacion_usuario(string, string, class_lista_usuario&);

    };

    // constructor
    class_validacion_usuario::class_validacion_usuario(string var_nombre_usuario, string var_contrasena_usuario, class_lista_usuario& var_listas) {
        atr_nombre_usuario = var_nombre_usuario;
        atr_contrasena_usuario = var_contrasena_usuario;
        atr_obj_listas = var_listas;
    }

    bool class_validacion_usuario::met_validar_usuario() {
        bool var_resultado = false;
        for (int i = 0; i < atr_obj_listas.atr_lista_usuario.size(); i++){
            if (atr_nombre_usuario == atr_obj_listas.atr_lista_usuario.at(i) && atr_contrasena_usuario == atr_obj_listas.atr_lista_contrasena_usuario.at(i)){
                var_resultado = true;
                break;
            }
        }
        return var_resultado;
    }
#pragma endregion

#pragma region class_interfaz_iniciar_sesion
    class class_interfaz_iniciar_sesion:public class_usuario {
        public:
            void met_interfaz_iniciar_sesion(class_lista_usuario&);
    };

    void class_interfaz_iniciar_sesion::met_interfaz_iniciar_sesion(class_lista_usuario& var_listas){
        system("cls");
        cout << "\t\t\tINICIAR SESION" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\tNombre de usuario: ";
        cin >> atr_nombre_usuario;
        cout << "\n\tContrasena: ";
        cin >> atr_contrasena_usuario;

        class_validacion_usuario obj_validar = class_validacion_usuario(atr_nombre_usuario, atr_contrasena_usuario, var_listas);

        bool var_resultado = obj_validar.met_validar_usuario();

        if (var_resultado == true) {
            class_interfaz_menu obj_interfaz_menu;
            obj_interfaz_menu.met_interfaz_menu(var_listas, atr_nombre_usuario);
        }
        else {
            cout << "Error al ingresar" << endl;
        }

    }
#pragma endregion

#pragma region class_interfaz_crear_usuario

class class_interfaz_crear_usuario:public class_usuario{
    public:      
        void met_interfaz_crear_usuario(class_lista_usuario&);
};

void class_interfaz_crear_usuario::met_interfaz_crear_usuario(class_lista_usuario& var_listas) {
    system("cls");
    cout << "\t\t\tCREAR USUARIO" << endl;
    cout << "\t\t\t--------------" << endl;
    cout << "\n\tNombre de usuario: ";
    cin >> atr_nombre_usuario;
    cout << "\n\tContrasena: ";
    cin >> atr_contrasena_usuario;

    class_crear_usuario obj_crear_usuario;
    bool var_resulado = obj_crear_usuario.met_crear_usuario(atr_nombre_usuario, atr_contrasena_usuario, var_listas);
    if (var_resulado == true){
        class_interfaz_iniciar_sesion obj_interfaz_iniciar_sesion;
        obj_interfaz_iniciar_sesion.met_interfaz_iniciar_sesion(var_listas);
    }
}
#pragma endregion

#pragma region class_interfaz_principal
    class class_interfaz_principal{
        public:
            void met_interfaz_principal();
    };

    void class_interfaz_principal::met_interfaz_principal() {

        class_interfaz_iniciar_sesion obj_interfaz_iniciar_sesion;
    
        class_interfaz_crear_usuario obj_crear_usuario;
    
        class_lista_usuario obj_lista_usuarios;
        obj_lista_usuarios.met_usuarios_base();

        

        system("cls");
        cout << "\t\t\tMENU PRINCIPAL" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t1) Iniciar Sesion";
        cout << "\n\t2) Crear Usuario";
        cout << "\n\t3) Salir";
        cout << "\n\t> ";
        int var_opcion;
        cin >> var_opcion;

        switch (var_opcion) {
            case 1:
                obj_interfaz_iniciar_sesion.met_interfaz_iniciar_sesion(obj_lista_usuarios);
                break;
            case 2:
                obj_crear_usuario.met_interfaz_crear_usuario(obj_lista_usuarios);
                break;
            default:
                break;
        }
    }
#pragma endregion

#pragma region main
    int main(){
        class_interfaz_principal obj_principal;
        obj_principal.met_interfaz_principal();

        return 0;
    }   
#pragma endregion