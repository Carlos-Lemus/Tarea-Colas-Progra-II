//Hecho por Carlos Alfonso Lemus Rodezno

//programa que toma las coordenadas en los puntos x, y, z

#include <iostream> //libreria estandar necesaria para todo programa en consola en c/c++
#include <queue> //libreria que contiene funciones y plantillas para la utilizacion de colas
#include <stdio.h> //libreria que contiene funciones que utilizaremos
#include <windows.h> //libreria que contiene funciones que utilizaremos
#include <iomanip> //libreria que contiene funciones que utilizaremos

using namespace std; //espacion a usar estandar, nos permite abreviar el codigo

void gotoxy(int x, int y); //declaracion de funcion que que mueve un texto a cualquier lugar de la pantalla
void error(); //funcion que evita errores de ingreso de datos

class Coord //clase coord servira para crear, manipular y mostrar los datos de la cola
{
    private:

        struct coor //estructura de datos de coor que contiene las coordenadas de x, y, z
        {
            //declaracion de vector con 3 elementos que servira para almacenar las coordenadas de x, y, z
            int vector[3];

        };

        //declaracion de variables con accesos privados para solo utilizarlos dentro de la clase
        int opcion;
        int seguir;
        int MemoriaBytes;
        int ColaBytes;
        double PromX = 0.00;
        double PromY = 0.00;
        double PromZ = 0.00;
        double n = 0.00;

    public: 

        //metodos o funciones de la clase Coord se utilizara para manejar la cola
        Coord();
        ~Coord();
        void menu();
        void ingresar();
        void mostrar();
        void datos();

        coor aux; //variable auxiliar de tipo aux
        coor *ptr; /*Varaible puntero de tipo coor nos permitira almacenar la direccion de los datos de la cola para
                     para poder imprimirlos*/
        queue<coor> colas; //nodo de tipo de tipo coor
};

Coord::Coord() //constructor que sera usado para reservar espacio en la memoria para los nodos de la cola
{

}

Coord::~Coord() //destructor que sera usado para liberar espacio en la memoria
{

}

void Coord::menu() //metodo de la clase Coord este contendra el menu del programa
{

    system("color 4D"); //funcion que agrega color al fondo y letra de la consola de comandos

    Coord *obj = new Coord(); //se reserva espacion en la memoria

    do { //ciclo do - while permite seguir en el programa y evita errores de ingreso de datos

        do { // do - while evita errores de ingreso de datos

            system("cls"); //funcion que limpia el texto de la consola

            //Menu de l programa
            gotoxy(50, 4); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "=========================" << endl;
            gotoxy(50, 5); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "*                       *" << endl;
            gotoxy(50, 6); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "*         Menu          *" << endl;
            gotoxy(50, 7); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "*                       *" << endl;
            gotoxy(50, 8); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "=========================" << endl;

            gotoxy(50, 10); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "Opciones" << endl;
            gotoxy(50, 11); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "1.Agregar" << endl;
            gotoxy(50, 12); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "2.Mostrar" << endl;
            gotoxy(50, 13); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "3.Mostrar datos" << endl;
            gotoxy(50, 14); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "4.Salir" << endl;

            gotoxy(50, 16); //funcion que mueve un texto a cualquier lugar de la pantalla
            fflush(stdin); //funcion que limpia el buffer
            cout << "Ingrese una opcion: ";
            cin >> opcion;
            error(); //funcion que evita la entrada de datos incorrectos

        } while(opcion < 1 || opcion > 4 || opcion == cin.fail());

        switch(opcion) //setencia switch que evalua la opcion ingresada
        {
            case 1:

                obj->ingresar(); //objeto que accede al metodo ingresar mediante el operador de seleccion
                break;
            case 2:

                obj->mostrar(); //objeto que accede al metodo mostrar mediante el operador de seleccion
                break;
            case 3:

                obj->datos(); //objeto que accede al metodo datos mediante el operador de seleccion
                break;
            case 4:

                system("cls"); //funcion que limpia el texto de la consola

                gotoxy(48, 8); //funcion que mueve un texto a cualquier lugar de la pantalla
                cout << "Gracias por usar el programa" << endl;
                break;
        }
    } while(opcion == 1 || opcion == 2 || opcion == 3);
}

void Coord::ingresar() //metodo de la clase Coord en este meotdo se ingresaran las coordenadas
{

    do { // do - while evita errores de ingreso de datos
        do { // do - while evita errores de ingreso de datos

            system("cls"); //funcion que limpia el texto de la consola

            gotoxy(50, 6); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "Ingresa datos";

            gotoxy(50, 10); //funcion que mueve un texto a cualquier lugar de la pantalla
            fflush(stdin); //funcion que limpia el buffer
            cout << "Ingrese x; ";
            cin >> aux.vector[0];
            error(); //funcion que evita entradas de datos incorrectos

            gotoxy(50, 12); //funcion que mueve un texto a cualquier lugar de la pantalla
            fflush(stdin); // funcion que limpia el buffer
            cout << "Ingrese y; ";
            cin >> aux.vector[1];
            error(); //funcion que evita entradas de datos incorrectos

            gotoxy(50, 14); //funcion que mueve un texto a cualquier lugar de la pantalla
            fflush(stdin); //funcion que limpia el buffer
            cout << "Ingrese z; ";
            cin >> aux.vector[2];
            error(); //funcion que evita entradas de datos incorrectos

            gotoxy(50, 16); //funcion que mueve un texto a cualquier lugar de la pantalla
            cout << "Desea continuar agregando (S1 = 1, No = 2): ";
            fflush(stdin);
            cin >> seguir;
            error(); //funcion que evita entradas de datos incorrectos

            //Se acumulan los datos ingresados de x, y ,z de forma individual
            PromX +=  aux.vector[0];
            PromY += aux.vector[1];
            PromZ += aux.vector[2];

        } while (aux.vector[0] == cin.fail() || aux.vector[1] == cin.fail() || aux.vector[2] == cin.fail());

        colas.push(aux);//se ingresa los datos de aux al nodo colo por medio del metodo push

        n++; //contador que servira para saber el numero de datos total ingresados de x, y, z

    } while(seguir == 1 || seguir != 2 || seguir == cin.fail());

    system("pause");

}

void Coord::mostrar() //metodo que mostrara los datos de la cola
{
    system("cls");//funcion que limpia el texto de la consola

    ptr = &colas.front(); //puntero de tipo coor almacena la direccion del primer nodo

    if(colas.empty()) //si no se encuentrar datos en la cola no se podra mostrar los datos de dicha cola
    {
        gotoxy(55, 10); //funcion que mueve un texto a cualquier lugar de la pantalla
        cout << "No hay regitros!" << endl;
    }

    else {

        for(int i = 1; i <= colas.size(); i++) //el ciclo while se repitira segun la cantidad de nodos en la cola
        {
            aux = *ptr; //varialbe aux de tipo coor este almacena la direccion del puntero ptr

            cout << "\n\n\t\t\t\t\t\tNumero de dato " << i << endl << endl;
            cout << "\t\t\t\t\t\tLa coordenada en x es: " << aux.vector[0] << endl;
            cout << "\t\t\t\t\t\tLa coordenada en y es: " << aux.vector[1] << endl;
            cout << "\t\t\t\t\t\tLa coordenada en z es: " << aux.vector[2] << endl;

            ptr++;/* el puntero se incrementa, esto debido al que el puntero almacena la
                     nodo de la cola al incrementarse este avanza ahasta al siguiente nodo
                     hasta el final del ciclo*/
            }
    }

    system("pause");
}

void Coord::datos() //metodo que muestra tales como el promedio de x, y, z y el numero de bytes de la cola
{

    system("cls"); //funcion que limpia el texto de la consola

    if(colas.empty()) //si no se encuentrar datos en la cola no se podra mostrar los datos de dicha cola
    {
        gotoxy(55, 10); //funcion que mueve un texto a cualquier lugar de la pantalla
        cout << "No hay datos" << endl;
    }
    else {

        MemoriaBytes = sizeof(struct coor); //almacena el numero de bytes de la estructura
        ColaBytes = MemoriaBytes + (n * MemoriaBytes); //Este varaiable calcula el numero de bytes de la cola

        //se imprime las coordenas
        gotoxy(40, 5); //funcion que mueve un texto a cualquier lugar de la pantalla
        cout << "Promedio de los datos " << endl << endl;
        gotoxy(40, 7); //funcion que mueve un texto a cualquier lugar de la pantalla
        cout << "El promedio de las coordenadas en x es: "  << fixed << setprecision(2) << PromX / n << endl;
        gotoxy(40, 9); //funcion que mueve un texto a cualquier lugar de la pantalla
        cout << "El promedio de las coordenadas en y es: "  << fixed << setprecision(2) << PromY / n << endl;
        gotoxy(40, 11); //funcion que mueve un texto a cualquier lugar de la pantalla
        cout << "El promedio de las coordenadas en z es: "  << fixed << setprecision(2) << PromZ / n << endl;

        gotoxy(40, 14); //funcion que mueve un texto a cualquier lugar de la pantalla
        //Se imprimi el total de bytes tuilizados en la memoria
        cout << "El total de bytes que utiliza la cola en la memoria es: " << ColaBytes << " bytes" << endl;

    }

    system("pause");

}


/*Funcion principal
===================
*/
int main()
{
    Coord obj; //objeto de tipo Coord

    obj.menu(); //metodo menu de la clase Coord

    system("pause");
    return 0;
}

/*Funcion gotoxy permite colocar los texto a cualquier lugar de la pantalla contiene dos parametros enteros
y es de tipo void por lo que no retorna ningun valor
*/
void gotoxy(int x, int y)
{
    //Estas instrucciones permiticra ubicar un texto en el lugar que se desee en la pantalla
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
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
