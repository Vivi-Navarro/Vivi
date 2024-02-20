/*Presentacíon
Viviana Navarro Plascencia
09/02/2024
Nombre: Actividad de programación - 4
Centro Universitario De los Altos
Ing en computacion/2do semestre
Profesor: Sergio Franco Casillas
Descripcion: Elaborar la serie Fibonacci utilizando los 3 ciclos básicos (for, while y do-while)*/
#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int op;
    bool rep = true;

    do {
        system("cls");
        int num, a = 0, b = 1, c;
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Ciclo for" << endl;
        cout << "2. Ciclo while" << endl;
        cout << "3. Ciclo do-while" << endl;
        cout << "0. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> op;

        switch (op) {
            case 0:
                rep = false;
                break;
            case 1:
                cout << "Ingrese un valor: ";
                cin >> num;
                for (int i = 0; i <= num; i++) {
                    cout << a << endl;
                    c = a + b;
                    a = b;
                    b = c;
                }
                break;
            case 2:
                cout << "Ingrese el numero de terminos: ";
                cin >> num;
                cout << "La serie de Fibonacci es:\n";
                while (c <= num) {
                    cout << a << endl;
                    c = a + b;
                    a = b;
                    b = c;
                }
                break;
            case 3:
                cout << "Ingrese el numero de terminos: ";
                cin >> num;
                cout << "La serie de Fibonacci es:\n";
                do {
                    cout << a << endl;
                    c = a + b;
                    a = b;
                    b = c;
                    num--;
                } while (num > 0);
                break;
            default:
                cout << "Opcion invalida. Intentalo nuevamente" << endl;
        }
    } while (rep);

    return 0;
}

