/*Presentacíon
Viviana Navarro Plascencia
13/02/2024
Nombre: Actividad de programación - 5
Centro Universitario De los Altos
Ing en computacion/2do semestre
Profesor: Sergio Franco Casillas
Descripcion: Suma de un arreglo*/
#include <iostream>
using namespace std;


const int maximo = 10; //Una constante es un valor que no puede ser alterado o modificado

void mi_arreglo(int arr[], int tamaño) {
    cout << "Lista de valores:" << endl;
    for (int i = 0; i < tamaño; ++i) {
        cout << "Posicion " << i << ": " << arr[i] << endl;
    }
}
/*void especifica que la función no devuelve ningún valor, mi_arreglo muestra los valores almacenados
en un arreglo,en el cout imprime la posición actual (i) y el valor almacenado en esa posición
del arreglo (arr[i])*/

int calcularSuma(int arr[], int tamaño) {
    int suma = 0;
    for (int i = 0; i < tamaño; ++i) {
        suma += arr[i];
    }
    return suma;
}
/*se declara una variable llamada suma e inicializa con cero (0), En cada iteración del bucle:
Se suma el valor del elemento actual (arr[i]) al valor acumulado en la variable suma
el return suma; indica que el valor almacenado en suma debe ser devuelto como resultado de la función*/

int main() {
    int arreglo[maximo] = {0};
    //Todos los elementos del arreglo se inicializan con cero (0)

    int opcion;
    do {
        cout << "\nOpciones:" << endl;
        cout << "1. Ingresar valor en una posicion" << endl;
        cout << "2. Mostrar lista de valores" << endl;
        cout << "3. Calcular suma de elementos" << endl;
        cout << "4. Editar elemento en una posicion" << endl;
        cout << "5. Borrar elemento en una posicion" << endl;
        cout << "6. Vaciar el arreglo" << endl;
        cout << "7. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        /*El bloque de código dentro del do se ejecuta primero,
        y luego se verifica la condición en el while
        Opciones en nuestro caso seria nuestro menu*/

        switch (opcion) {
            case 1:
                int posicion, valor;
                cout << "Ingresa la posicion (0-" << maximo - 1 << "): ";
                cin >> posicion;
                cout << "Ingresa el valor: ";
                cin >> valor;
                if (posicion >= 0 && posicion < maximo) {
                    arreglo[posicion] = valor;
                    cout << "Valor ingresado correctamente." << endl;
                    /*Cada case dentro del switch representa un valor específico
                    que se compara con el valor de opcion, se ejecutará el bloque
                    de código dentro del case 1, Se le pide al usuario que ingrese una posición
                    (un índice) dentro del rango válido del arreglo (de 0 a maximo - 1).
                    si la posición ingresada está dentro del rango válido, se asigna el valor
                    ingresado a esa posición en el arreglo (arreglo[posicion] = valor;).
                    la condición if (posicion >= 0 && posicion < MAX_SIZE) verifica que la posición
                    ingresada esté dentro del rango válido. si la posición no es válida (por ejemplo,
                    si es negativa o mayor que MAX_SIZE - 1), el valor no se asigna al arreglo*/
                } else {
                    cout << "Posición invalida" << endl;
                }
                //el valor no se asigna al arreglo porque la posición es invalida
            case 2:
                mi_arreglo(arreglo, maximo);
                break;
                //esta función muestra cada valor almacenado en el arreglo junto con su posición
            case 3:
                cout << "Suma de elementos: " << calcularSuma(arreglo, maximo) << endl;
                break;
                //esta función suma todos los valores almacenados en el arreglo y devuelve el resultado
            case 4:
                break;
               /*el break, el programa seguiría ejecutando los bloques de código de los case siguientes.
               El break asegura que solo se ejecute el bloque correspondiente al case seleccionado*/
            case 5:
                break;
            case 6:
                for (int i = 0; i < maximo; ++i) {
                    arreglo[i] = 0;
                }
                cout << "Arreglo vaciado" << endl;
                break;
                /*La variable i se inicializa en 0.
                El bucle se ejecuta mientras i sea menor que maximo.
                En cada iteración, se realiza lo siguiente:
                Se asigna el valor 0 al elemento en la posición i del arreglo
                (arreglo[i] = 0;), Después de ejecutar este bucle, todos los elementos del
                arreglo se establecen en 0. Esto significa que el arreglo queda “vacío” en el
                sentido de que todos sus valores son cero*/
            case 7:
                cout << "Adios, ten un lindo dia" << endl;
                break;
            default:
                cout << "Opcion invalida. Intentalo de nuevo" << endl;
                /*Si el usuario ingresa una opción que no coincide con ningún case (por ejemplo,
                una opción fuera del rango válido), se ejecuta el bloque de código dentro del default.
                En este caso: Se muestra en pantalla el mensaje “Opcion inválida. Intentalo de nuevo”*/
        }
    } while (opcion != 7);
    /*El bucle do contiene todo el código entre las llaves { ... }.
    La condición que se verifica es opcion != 7.
    Esto significa que el bucle se repetirá mientras opcion no sea igual a 7, Cuando el usuario selecciona
    la opción 7, la condición opcion != 7 se vuelve falsa. En ese momento, el bucle do...while finaliza y
    el programa continúa con la siguiente instrucción después del bucle*/

    return 0;
    /*return 0; indica que el programa finalizó correctamente y devuelve el valor 0.
    Un valor de retorno diferente de cero podría indicar un error o una terminación anormal
    del programa*/
}









