#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int numero;
    int operaciones = 0;

    char pregunta;

    do {
        cout << "Ingresa un numero: ";
        cin >> numero;

        if (numero > 0 && numero < 500)
        {
            for (int i = 0; i < 100; ++i)
            {
                numero += 5;
                operaciones++;
            }
        }
        else if (numero >= 500 && numero < 1000)
        {
            for (int i = 0; i < 50; ++i)
            {
                numero += 10;
                operaciones++;
            }
        }
        else
        {
            cout << "No se puede calcular el valor" << endl;
        }

        cout << "Quieres continuar? (s/n): ";
        cin >> pregunta;
    }
    while (pregunta == 's' || pregunta == 'S');

    cout << "Operaciones realizadas: " << operaciones << endl;

    return 0;
}
