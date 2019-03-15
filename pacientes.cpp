//Hecho por Carlos Alfonso Lemus Rodezno

//Programa que almacena los datos de los pacientes

#include <iostream> //libreria estandar obligatoria para hacer programas en consola en c/c++
#include <stdio.h> //libreria necesaria para utilizar sus funciones
#include <conio.h> //libreria necesaria para utilizar sus funciones
#include <windows.h> //libreria necesaria para utilizar sus funciones

using namespace std; //espacion de nombre a usar estandar, nos ayuda a abreviar el codigo

void error(); //funcion que evita errores de ingreso de datos

class Paciente { //clase paciente necesaria para ingresar y mostrar los datos del paciente

    private:
            //declaracion de datos con acceso privado
             int cor;
             char nom[20];
             char ape[20];
             int edad;
             char s[2];
             char ec[50];
    public:
          //Declaracion de constructor
          Paciente();
          //declaracion de metodos de acceso publico
          void Mostrar();
          void Pedir();
          //declracion de destructor
          ~Paciente();

};

Paciente::Paciente() //Constructor de la clase paciente
{

}
Paciente::~Paciente() //destructor de la clase paciente
{

}
void Paciente::Mostrar() //metodo mostrar de la clase paciente, utilizado para mostrar los datos de los pacientes
{
   cout << "\n\n\t\t\t\t\t-------" << endl;
   cout << "\t\t\t\t\tCorrelativo: " << cor << endl;
   cout << "\t\t\t\t\tNombre: " << nom << endl;
   cout << "\t\t\t\t\tApellido: " << ape<<endl;
   cout << "\t\t\t\t\tEdad: " << edad<<endl;
   cout << "\t\t\t\t\tSexo: " << s << endl;
   cout << "\t\t\t\t\tEnfermedad Cronica: " << ec << endl;
}
void Paciente::Pedir() //metodo pedir de la clase paciente, utilizado para ingresar los datos de los pacientes
{
    do { // do - while evita errores de ingreso de datos

        cout << "\n\n\t\t\t\t\tIngrese el Correlativo: ";
        fflush(stdin); //funcion que limpia el buffer
        cin>>cor;
        error(); //funcion que evita la entrada de datos incorrectos

        cout << "\t\t\t\t\tIngrese el Nombre: ";
        fflush(stdin); //funcion que limpia el buffer
        cin >> nom;
        error(); //funcion que evita la entrada de datos incorrectos

        cout << "\t\t\t\t\tIngrese el Apllidoe: ";
        fflush(stdin); //funcion que limpia el buffer
        cin>>ape;
        error(); //funcion que evita la entrada de datos incorrectos

        cout << "\t\t\t\t\tIngrese la Edad: ";
        fflush(stdin); //funcion que limpia el buffer
        cin >> edad;
        error(); //funcion que evita la entrada de datos incorrectos

        cout << "\t\t\t\t\tIngrese el Sexo: ";
        fflush(stdin); //funcion que limpia el buffer
        cin >> s;
        error(); //funcion que evita la entrada de datos incorrectos

        cout << "\t\t\t\t\tIngrese el Enfermedad Cronica: ";
        fflush(stdin); //funcion que limpia el buffer
        cin >> ec;
        error(); //funcion que evita la entrada de datos incorrectos

        if(cor == cin.fail() || edad == cin.fail()) //si ocurre un error de ingreso de datos mostrara un mensaje
        {

            cout << "\n\n\t\t\t\tSe ha ingresado un dato incorrecto, vuelva a ingresarlos" << endl;

        }

    } while(cor == cin.fail() || edad == cin.fail());

}

int main() {
    //declaracion de variables
    int opcion;
    int seguir;
    bool verificar = true;

    Paciente *p1; //objeto puntero de tipo Paciente
    Paciente *p2; //objeto puntero de tipo Paciente

    system("color 3A");

    do { //ciclo do - while permite seguir en el programa y evita errores de ingreso de datos

           do { // do - while evita errores de ingreso de datos

               system("cls"); //funcion que limpia el texto de la consola

               //Menu de l programa
               cout << "\n\n\n\n\t\t\t\t\t\t=========================" << endl;
               cout << "\t\t\t\t\t\t*                       *" << endl;
               cout << "\t\t\t\t\t\t*    Datos Pacientes    *" << endl;
               cout << "\t\t\t\t\t\t*                       *" << endl;
               cout << "\t\t\t\t\t\t=========================" << endl;

               cout << "\n\n\t\t\t\t\t\tOpciones" << endl;
               cout << "\t\t\t\t\t\t1.Agregar paciente" << endl;
               cout << "\t\t\t\t\t\t2.Mostrar pacientes" << endl;
               cout << "\t\t\t\t\t\t3.Salir" << endl;

               cout << "\t\t\t\t\t\tIngrese una opcion: ";
               fflush(stdin); //funcion que limpia el buffer
               cin >> opcion;
               error(); //funcion que evita la entrada de datos incorrectos


               if(opcion == cin.fail()) //si ocurre un error de ingreso de datos mostrara un mensaje
               {

                   cout << "\n\n\t\t\t\tSe ha ingresado un dato incorrecto, vuelva a ingresarlo" << endl;

                   getch();

               }

           } while(opcion < 1 || opcion > 3 || opcion == cin.fail());

            switch(opcion)
            {
                case 1:

                    do {

                        system("cls"); //funcion que limpia el texto de la consola

                        cout << "\n\n\n\n\t\t\t\t\t\t=========================" << endl;
                        cout << "\t\t\t\t\t\t*                       *" << endl;
                        cout << "\t\t\t\t\t\t*   Ingresa los datos   *" << endl;
                        cout << "\t\t\t\t\t\t*                       *" << endl;
                        cout << "\t\t\t\t\t\t=========================" << endl;

                        p1 = new Paciente(); //se asigna una porcion de memoria al objeto por medio del constructor
                        p1 -> Pedir(); //el objeto llema al metodo perdir por medio del operador de seleccion

                        p2 = new Paciente(); //se asigna una porcion de memoria al objeto por medio del constructor
                        p2 -> Pedir(); //el objeto llema al metodo perdir por medio del operador de seleccion

                        cout << "\n\n\t\t\t\t\tDesea seguir ingresando pacientes (Si = 1, No = 2): ";
                        fflush(stdin); //funcion que limpia el buffer
                        cin >> seguir;
                        error(); //funcion que evita la entrada de datos incorrectos

                        if(seguir == cin.fail()) //si ocurre un error de ingreso de datos mostrara un mensaje
                        {

                            cout << "\n\n\t\t\t\tSe ha ingresado un dato incorrecto, vuelva a ingresarlos" << endl;

                            getch();

                        }

                    } while(seguir == 1 || seguir != 2 || seguir == cin.fail());

                    verificar = false; //si se ingresan datos el valor de varificar cambia a false

                    getch();

                    break;

                case 2:

                //si no se ha ingresados datos verificar vale true por lo que mostrara un mensaje

                if(verificar){

                    system("cls"); //funcion que limpia el texto de la consola

                    cout << "\n\n\n\n\t\t\t\t\t\t=========================" << endl;
                    cout << "\t\t\t\t\t\t*                       *" << endl;
                    cout << "\t\t\t\t\t\t*     Mostrar Datos     *" << endl;
                    cout << "\t\t\t\t\t\t*                       *" << endl;
                    cout << "\t\t\t\t\t\t=========================" << endl;

                    cout << "\n\n\t\t\t\t\t\tNo hay registros de pacientes" << endl;

                    getch();

                }

                else {

                        system("cls"); //funcion que limpia el texto de la consola

                        cout << "\n\n\n\n\t\t\t\t\t\t=========================" << endl;
                        cout << "\t\t\t\t\t\t*                       *" << endl;
                        cout << "\t\t\t\t\t\t*     Mostrar Datos     *" << endl;
                        cout << "\t\t\t\t\t\t*                       *" << endl;
                        cout << "\t\t\t\t\t\t=========================" << endl;

                        p1->Mostrar(); //el objeto llema al metodo Mostrar por medio del operador de seleccion

                        cout << endl;

                        p2->Mostrar(); //el objeto llema al metodo Mostrar por medio del operador de seleccion

                        getch();
                    }

                    break;

                case 3:
                    system("cls"); //funcion que limpia el texto de la consola

                    cout << "\n\n\n\n\t\t\t\t\t\tGracias por usar el programa" << endl;

                    break;

            }

    } while(opcion == 1 || opcion == 2);

    getch();
    return 0;
}

void error() //funcion que evita que se ingrese datos incorrectos
{
    //Ciclo while paraevitar datos incorrectos
    while(cin.fail()){

    //Limpia el buffer de los datos ingresados
    cin.clear();

    //Ignora los primeros 1000 caracteres o en este caso los numeros
    cin.ignore(1000,'\n');

     }
}
