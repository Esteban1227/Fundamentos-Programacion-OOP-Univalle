#pragma region include
    #include <iostream>
    #include <string>
    #include <vector>
#pragma endregion

#pragma region namespace
    using namespace std;    
#pragma endregion

#pragma region class_lista_usuario
    class class_lista_usuario {
        public:
            vector<string> atr_lista_usuario;
            vector<string> atr_lista_contrasena_usuario;

            void met_usuarios_base();
            void met_agregar_usuario(string, string);

    };

    void class_lista_usuario::met_usuarios_base() {
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
    }
    void class_lista_usuario::met_agregar_usuario(string var_nombre_usuario , string var_contrasena_usuario) {
        atr_lista_usuario.push_back(var_nombre_usuario);
        atr_lista_contrasena_usuario.push_back(var_contrasena_usuario);
    }
#pragma endregion

#pragma region class_crear_usuario
    class class_crear_usuario {
        public:
            string atr_nombre_usuario;
            string atr_contrasena_usuario;
            class_lista_usuario atr_obj_listas;
        
            class_crear_usuario(string, string, class_lista_usuario);
        
            class_lista_usuario met_crear_usuario();
    };

    class_crear_usuario::class_crear_usuario(string var_nombre_usuario, string var_contrasena_usuario, class_lista_usuario var_listas) {
        atr_nombre_usuario = var_nombre_usuario;
        atr_contrasena_usuario = var_contrasena_usuario;
        atr_obj_listas = var_listas;
    }

    class_lista_usuario class_crear_usuario::met_crear_usuario() {
        atr_obj_listas.met_agregar_usuario(atr_nombre_usuario, atr_contrasena_usuario);
        return atr_obj_listas;
    }
#pragma endregion

#pragma region class_validacion_usuario
    
    class class_validacion_usuario {
        public:
            string atr_nombre_usuario;
            string atr_contrasena_usuario;
            class_lista_usuario atr_obj_listas;

            bool met_validar_usuario();

            class_validacion_usuario(string, string, class_lista_usuario);

    };

    // constructor
    class_validacion_usuario::class_validacion_usuario(string var_nombre_usuario, string var_contrasena_usuario, class_lista_usuario var_listas) {
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
    class class_interfaz_iniciar_sesion {
        public:
            string atr_nombre_usuario;
            string atr_contrasena_usuario;

            void met_interfaz_iniciar_sesion(class_lista_usuario);
    };

    void class_interfaz_iniciar_sesion::met_interfaz_iniciar_sesion(class_lista_usuario var_listas){
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
            cout << "Bienvenido" << endl;
        }
        else {
            cout << "Error al ingresar" << endl;
        }

    }
#pragma endregion

#pragma region class_interfaz_crear_usuario

class class_interfaz_crear_usuario{
    public:
        string atr_nombre_usuario;
        string atr_contrasena_usuario;
        
        void met_interfaz_crear_usuario(class_lista_usuario);
};

void class_interfaz_crear_usuario::met_interfaz_crear_usuario(class_lista_usuario var_listas) {
    system("cls");
    cout << "\t\t\tCREAR USUARIO" << endl;
    cout << "\t\t\t--------------" << endl;
    cout << "\n\tNombre de usuario: ";
    cin >> atr_nombre_usuario;
    cout << "\n\tContrasena: ";
    cin >> atr_contrasena_usuario;

    class_crear_usuario obj_crear_usuario = class_crear_usuario(atr_nombre_usuario, atr_contrasena_usuario, var_listas);

    var_listas = obj_crear_usuario.met_crear_usuario();
    for (int i = 0; i < var_listas.atr_lista_usuario.size(); i++)
    {
        cout << var_listas.atr_lista_usuario.at(i) << endl;
    }
    class_interfaz_iniciar_sesion obj_interfaz_iniciar_sesion;
    obj_interfaz_iniciar_sesion.met_interfaz_iniciar_sesion(var_listas);
}
#pragma endregion

#pragma region class_interfaz_principal
    class class_interfaz_principal {
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
        }
}
#pragma endregion

#pragma region main

    int main()
{
    class_interfaz_principal obj_principal;
    obj_principal.met_interfaz_principal();

    return 0;
}   

#pragma endregion