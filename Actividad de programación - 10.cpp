/*Presentacíon
Viviana Navarro Plascencia
23/02/2024
Nombre: Actividad de programación - 10
Centro Universitario De los Altos
Ing en computacion/2do semestre
Profesor: Sergio Franco Casillas
Descripcion: Calculadora de matrices cuadradas*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Clase que representa una matriz cuadrada
class Matriz {
private: //private: se utiliza para ocultar la implementación interna de la clase y proteger sus datos y funciones de acceso no autorizado
    int n; // Tamaño de la matriz
    int **m; // Vector dinámico bidimensional que almacena los elementos de la matriz
public: /*Colocar los miembros privados al principio de la clase ayuda a encapsular la implementación interna de la clase. Esto significa que los detalles de implementación están
        ocultos fuera de la clase y solo los miembros públicos pueden interactuar con ellos*/
    // Constructor que recibe el tamaño de la matriz y reserva memoria para el vector
    Matriz(int n) {
        this->n = n; //se refiere al miembro n de la instancia actual de la clase Matriz
        m = new int*[n]; //nuevo entero en el heap y devuelve un puntero a esa ubicación de memoria
        for (int i = 0; i < n; i++) {
            m[i] = new int[n];
        }
    }

    // Destructor que libera la memoria del vector
    ~Matriz() {
        for (int i = 0; i < n; i++) {
            delete[] m[i];
        }
        delete[] m;
    }
    //get: Este método te permite obtener el valor de un atributo de la clase desde fuera de la misma.
    // Método que devuelve el tamaño de la matriz
    int getN() {
        return n;
    }

    // Método que devuelve el elemento de la matriz en la posición (i, j)
    int get(int i, int j) {
        return m[i][j];
    }
    //set: Por otro lado, el método set te permite establecer o cambiar el valor de un atributo de la clase desde fuera de la misma
    // Método que asigna el valor v al elemento de la matriz en la posición (i, j)
    void set(int i, int j, int v) {
        m[i][j] = v;
    }

    // Método que muestra la matriz por pantalla
    void mostrar() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Método que rellena la matriz con valores aleatorios entre -200 y 400
    void llenar_aleatorio() {
        srand(time(NULL)); // Inicializa la semilla para generar números aleatorios
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = rand() % 601 - 200; // Genera un número aleatorio entre -200 y 400
            }
        }
    }

    // Método que borra el elemento de la matriz en la posición (i, j) y lo sustituye por un cero
    void borrar(int i, int j) {
        m[i][j] = 0;
    }

    // Método que cambia el valor del elemento de la matriz en la posición (i, j) por el valor v
    void editar(int i, int j, int v) {
        m[i][j] = v;
    }

    // Método que vacía la matriz y la rellena con ceros
    void vaciar() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = 0;
            }
        }
    }

    // Operador sobrecargado que devuelve la suma de dos matrices
    Matriz operator+(Matriz &M) {
        // Se comprueba que las matrices tengan el mismo tamaño
        if (this->n != M.n) {
            cout << "No se pueden sumar matrices de distinto tamano" << endl;
            return *this; // Se devuelve la matriz original sin modificar
        }
        // Se crea una matriz auxiliar del mismo tamaño que las matrices originales
        Matriz R(this->n);
        // Se recorren los elementos de las matrices y se suman
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->n; j++) {
                R.m[i][j] = this->m[i][j] + M.m[i][j];
            }
        }
        // Se devuelve la matriz resultante
        return R;
    }

    // Operador sobrecargado que devuelve la resta de dos matrices
    Matriz operator-(Matriz &M) {
        // Se comprueba que las matrices tengan el mismo tamaño
        if (this->n != M.n) {
            cout << "No se pueden restar matrices de distinto tamano" << endl;
            return *this; // Se devuelve la matriz original sin modificar
        }
        // Se crea una matriz auxiliar del mismo tamaño que las matrices originales
        Matriz R(this->n);
        // Se recorren los elementos de las matrices y se restan
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->n; j++) {
                R.m[i][j] = this->m[i][j] - M.m[i][j];
            }
        }
        // Se devuelve la matriz resultante
        return R;
    }

    // Operador sobrecargado que devuelve la multiplicación de dos matrices
    Matriz operator*(Matriz &M) {
        // Se comprueba que las matrices tengan el mismo tamaño
        if (this->n != M.n) {
            cout << "No se pueden multiplicar matrices de distinto tamano" << endl;
            return *this; // Se devuelve la matriz original sin modificar
        }
        // Se crea una matriz auxiliar del mismo tamaño que las matrices originales
        Matriz R(this->n);
        // Se recorren los elementos de la matriz resultante y se calculan
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->n; j++) {
                R.m[i][j] = 0; // Se inicializa el elemento a cero
                for (int k = 0; k < this->n; k++) {
                    // Se suma el producto de los elementos correspondientes de las matrices originales
                    R.m[i][j] += this->m[i][k] * M.m[k][j];
                }
            }
        }
        // Se devuelve la matriz resultante
        return R;
    }

    // Operador sobrecargado que devuelve la división de dos matrices
    Matriz operator/(Matriz &M) {
        // Se comprueba que las matrices tengan el mismo tamaño
        if (this->n != M.n) {
            cout << "No se pueden dividir matrices de distinto tamano" << endl;
            return *this; // Se devuelve la matriz original sin modificar
        }
        // Se crea una matriz auxiliar del mismo tamaño que las matrices originales
        Matriz R(this->n);
        // Se recorren los elementos de las matrices y se realiza la división
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->n; j++) {
                // Se comprueba si el divisor es cero para evitar divisiones por cero
                if (M.m[i][j] != 0) {
                    R.m[i][j] = this->m[i][j] / M.m[i][j];
                } else {
                    cout << "Error: Division por cero" << endl;
                    return *this; // Se devuelve la matriz original sin modificar
                }
            }
        }
        // Se devuelve la matriz resultante
        return R;
    }
};

// Función que muestra el menú de opciones y devuelve la elección del usuario
int menu() {
    int opcion; // Variable que almacena la opción elegida por el usuario
    cout << "Calculadora de matrices cuadradas" << endl;
    cout << "1. Rellenar matrices con valores introducidos por el usuario" << endl;
    cout << "2. Rellenar matrices con valores aleatorios" << endl;
    cout << "3. Mostrar matrices" << endl;
    cout << "4. Sumar matrices" << endl;
    cout << "5. Restar matrices" << endl;
    cout << "6. Multiplicar matrices" << endl;
    cout << "7. Dividir matrices" << endl;
    cout << "8. Borrar elemento de una matriz" << endl;
    cout << "9. Editar elemento de una matriz" << endl;
    cout << "10. Vaciar matrices" << endl;
    cout << "11. Salir" << endl;
    do { // Se repite el bucle hasta que el usuario introduzca una opción válida
        cout << "Introduce tu opcion: ";
        cin >> opcion; // Se lee la opción del usuario
        if (opcion < 1 || opcion > 11) { // Se verifica que la opción sea válida
            cout << "Opcion invalida. Introduce un numero entre 1 y 11." << endl;
        }
    } while (opcion < 1 || opcion > 11); // Se verifica la condición de salida del bucle
    return opcion; // Se devuelve la opción
}

// Función principal del programa
int main() {
    int n; // Variable que almacena el tamaño de las matrices
    int i, j, v; // Variables que almacenan el índice y el valor de un elemento de una matriz
    Matriz *A, *B, *C; // Punteros a objetos de tipo Matriz
    int opcion; // Variable que almacena la opción elegida por el usuario
    bool salir = false; // Variable que indica si el usuario quiere salir del programa

    cout << "Introduce el tamano de las matrices (entre 2 y 15): ";
    cin >> n; // Se lee el tamaño de las matrices
    // Se comprueba que el tamaño sea válido
    if (n < 2 || n > 15) {
        cout << "Tamano invalido" << endl;
        return 0; // Se termina el programa
    }
    // Se crean los objetos de tipo Matriz
    A = new Matriz(n);
    B = new Matriz(n);
    C = new Matriz(n);

    // Se muestra el menú de opciones y se ejecuta la opción elegida por el usuario
    while (!salir) { // Se repite el bucle hasta que el usuario quiera salir
        opcion = menu(); // Se llama a la función que muestra el menú y devuelve la opción
        switch (opcion) { // Se ejecuta el caso correspondiente a la opción
            case 1: // Rellenar matrices con valores introducidos por el usuario
                // Se recorren las filas de la matriz A
                for (int i = 0; i < n; i++) {
                    // Se recorren las columnas de la matriz A
                    for (int j = 0; j < n; j++) {
                        // Se pide al usuario que introduzca el valor del elemento (i, j) de la matriz A
                        cout << "Introduce el valor del elemento (" << i << ", " << j << ") de la matriz A: ";
                        cin >> v; // Se lee el valor
                        A->set(i, j, v); // Se asigna el valor al elemento
                    }
                }
                // Se recorren las filas de la matriz B
                for (int i = 0; i < n; i++) {
                    // Se recorren las columnas de la matriz B
                    for (int j = 0; j < n; j++) {
                        // Se pide al usuario que introduzca el valor del elemento (i, j) de la matriz B
                        cout << "Introduce el valor del elemento (" << i << ", " << j << ") de la matriz B: ";
                        cin >> v; // Se lee el valor
                        B->set(i, j, v); // Se asigna el valor al elemento
                    }
                }
                break;
            case 2: //Rellena matrices con valores aleatorios
                // Se llama al método llenar_aleatorio de la matriz A
                A->llenar_aleatorio();
                // Se llama al método llenar_aleatorio de la matriz B
                B->llenar_aleatorio();
                break;
            case 3: //Mostrar matrices
                // Se llama al método mostrar de la matriz A
                cout << "Matriz A:" << endl;
                A->mostrar();
                // Se llama al método mostrar de la matriz B
                cout << "Matriz B:" << endl;
                B->mostrar();
                // Se llama al método mostrar de la matriz C
                cout << "Matriz C:" << endl;
                C->mostrar();
                break;
            case 4: //sumar matrices
                // Se llama al operador sobrecargado + para sumar las matrices A y B y asignar el resultado a la matriz C
                *C = *A + *B;
                // Se llama al método mostrar de la matriz C
                cout << "La suma de las matrices A y B es:" << endl;
                C->mostrar();
                break;
            case 5: //resta de matrices
                // Se llama al operador sobrecargado - para restar las matrices A y B y asignar el resultado a la matriz C
                *C = *A - *B;
                // Se llama al método mostrar de la matriz C
                cout << "La resta de las matrices A y B es:" << endl;
                C->mostrar();
                break;
            case 6: //multiplicar matrices
                // Se llama al operador sobrecargado * para multiplicar las matrices A y B y asignar el resultado a la matriz C
                *C = *A * *B;
                // Se llama al método mostrar de la matriz C
                cout << "La multiplicacion de las matrices A y B es:" << endl;
                C->mostrar();
                break;
            case 7: //dividir matrices
                // Se pide al usuario que elija cuál matriz es el numerador
                cout << "Elige cual matriz es el numerador (1 para A, 2 para B): ";
                cin >> v;
                if (v == 1) {
                    // Se llama al operador sobrecargado / para dividir la matriz A por la matriz B y asignar el resultado a la matriz C
                    *C = *A / *B;
                } else if (v == 2) {
                    // Se llama al operador sobrecargado / para dividir la matriz B por la matriz A y asignar el resultado a la matriz C
                    *C = *B / *A;
                } else {
                    cout << "Opción invalida." << endl;
                }
                // Se llama al método mostrar de la matriz C
                cout << "La division de las matrices es:" << endl;
                C->mostrar();
                break;
            case 8: //borrar elemento de una matriz
                // Se pide al usuario que introduzca el índice (i, j) y el número de la matriz (1, 2 o 3) del elemento que quiere borrar
                cout << "Introduce el indice (i, j) del elemento que quieres borrar: ";
                cin >> i >> j; // Se leen los índices
                cout << "Introduce el numero de la matriz (1, 2 o 3) donde se encuentra el elemento: ";
                cin >> v; // Se lee el número de la matriz
                // Se comprueba que el índice y el número de la matriz sean válidos
                if (i < 0 || i >= n || j < 0 || j >= n || v < 1 || v > 3) {
                    cout << "Indice o número de matriz invalido" << endl;
                }
                else {
                    // Se usa el método borrar de la matriz correspondiente para eliminar el elemento y sustituirlo por un cero
                    switch (v) {
                        case 1: // Matriz A
                            A->borrar(i, j);
                            break;
                        case 2: // Matriz B
                            B->borrar(i, j);
                            break;
                        case 3: // Matriz C
                            C->borrar(i, j);
                            break;
                    }
                    // Se muestra la matriz modificada por pantalla
                    cout << "La matriz " << v << " despues de borrar el elemento (" << i << ", " << j << ") es:" << endl;
                    switch (v) {
                        case 1: // Matriz A
                            A->mostrar();
                            break;
                        case 2: // Matriz B
                            B->mostrar();
                            break;
                        case 3: // Matriz C
                            C->mostrar();
                            break;
                    }
                }
                break;
            case 9: //editar elemento de la matriz
                // Se pide al usuario que introduzca el índice (i, j), el valor v y el número de la matriz (1, 2 o 3) del elemento que quiere editar
                cout << "Introduce el indice (i, j) del elemento que quieres editar: ";
                cin >> i >> j; // Se leen los índices
                cout << "Introduce el valor que quieres asignar al elemento: ";
                cin >> v; // Se lee el valor
                cout << "Introduce el numero de la matriz (1, 2 o 3) donde se encuentra el elemento: ";
                cin >> n; // Se lee el número de la matriz
                // Se comprueba que el índice, el valor y el número de la matriz sean válidos
                if (i < 0 || i >= n || j < 0 || j >= n || v < -200 || v > 400 || n < 1 || n > 3) {
                    cout << "Indice, valor o numero de matriz invalido" << endl;
                }
                else {
                    // Se usa el método editar de la matriz correspondiente para cambiar el valor del elemento
                    switch (n) {
                        case 1: // Matriz A
                            A->editar(i, j, v);
                            break;
                        case 2: // Matriz B
                            B->editar(i, j, v);
                            break;
                        case 3: // Matriz C
                            C->editar(i, j, v);
                            break;
                    }
                    // Se muestra la matriz modificada por pantalla
                    cout << "La matriz " << n << " despues de editar el elemento (" << i << ", " << j << ") es:" << endl;
                    switch (n) {
                        case 1: // Matriz A
                            A->mostrar();
                            break;
                        case 2: // Matriz B
                            B->mostrar();
                            break;
                        case 3: // Matriz C
                            C->mostrar();
                            break;
                    }
                }
                break;
            case 10: //vaciar matrices
                // Se llama al método vaciar de la matriz A
                A->vaciar();
                // Se llama al método vaciar de la matriz B
                B->vaciar();
                // Se llama al método vaciar de la matriz C
                C->vaciar();
                cout << "Las matrices se han vaciado" << endl;
                break;
            case 11: //Salir
                salir = true; // Se cambia el valor de la variable salir para salir del bucle
                break;
        }
    }

    // Se libera la memoria reservada para los objetos de tipo Matriz
    delete A;
    delete B;
    delete C;

    return 0; // Se termina el programa
}
