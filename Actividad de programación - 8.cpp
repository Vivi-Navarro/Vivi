    /*Presentacíon
    Viviana Navarro Plascencia
    26/02/2024
    Nombre: Actividad de programación - 8
    Centro Universitario De los Altos
    Ing en computacion/2do semestre
    Profesor: Sergio Franco Casillas
    Descripcion: Operaciones de dos conjuntos*/
    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    // Función para insertar elementos en un conjunto
    void insertarElementos(vector<int>& conjunto) {
        int elemento;
        char continuar;
        do {
            cout << "Ingrese un elemento: ";
            cin >> elemento;
            conjunto.push_back(elemento); // Agrega el elemento al final del vector
            cout << "Desea ingresar otro elemento? (s/n): ";
            cin >> continuar;
        } while (continuar == 's' || continuar == 'S');
    }

    // Función para borrar un elemento de un conjunto
    void borrarElemento(vector<int>& conjunto, int elemento) {
        auto it = find(conjunto.begin(), conjunto.end(), elemento); /*La función find busca un elemento en el vector
        y devuelve un iterador que apunta a la posición del primer elemento encontrado, o al final del vector si el elemento no se encuentra*/
        if (it != conjunto.end()) { // Si el elemento se encontró
            conjunto.erase(it); // Borra el elemento del vector
            cout << "Elemento borrado exitosamente" << endl;
        } else {
            cout << "El elemento no existe en el conjunto" << endl;
        }
    }

    // Función para vaciar un conjunto
    void vaciarConjunto(vector<int>& conjunto) {
        conjunto.clear(); // Borra todos los elementos del vector
        cout << "El conjunto ha sido vaciado" << endl;
    }

    // Función para realizar la unión de dos conjuntos
    vector<int> unionConjuntos(const vector<int>& conjunto1, const vector<int>& conjunto2) {
        vector<int> resultado = conjunto1; // Copia el primer conjunto en el resultado
        for (int elemento : conjunto2) { // Itera sobre los elementos del segundo conjunto
            if (find(resultado.begin(), resultado.end(), elemento) == resultado.end()) { // Si el elemento no está en el resultado
                resultado.push_back(elemento); // Agrega el elemento al resultado
            }
        }
        return resultado;
    }

    // Función para realizar la intersección de dos conjuntos
    vector<int> interseccionConjuntos(const vector<int>& conjunto1, const vector<int>& conjunto2) {
        vector<int> resultado;
        for (int elemento : conjunto1) { // Itera sobre los elementos del primer conjunto
            if (find(conjunto2.begin(), conjunto2.end(), elemento) != conjunto2.end()) { // Si el elemento está en el segundo conjunto
                resultado.push_back(elemento); // Agrega el elemento al resultado
            }
        }
        return resultado;
    }

    // Función para realizar la diferencia de dos conjuntos (A - B)
    vector<int> diferenciaConjuntos(const vector<int>& conjunto1, const vector<int>& conjunto2) {
        vector<int> resultado;
        for (int elemento : conjunto1) { // Itera sobre los elementos del primer conjunto
            if (find(conjunto2.begin(), conjunto2.end(), elemento) == conjunto2.end()) { // Si el elemento no está en el segundo conjunto
                resultado.push_back(elemento); // Agrega el elemento al resultado
            }
        }
        return resultado;
    }

    // Función para imprimir un conjunto
    void imprimirConjunto(const vector<int>& conjunto) {
        cout << "Conjunto: { ";
        for (int elemento : conjunto) { // Itera sobre los elementos del conjunto
            cout << elemento << " "; // Imprime cada elemento
        }
        cout << "}" << endl;
    }

    int main() {
        vector<int> conjunto1, conjunto2;
        int opcion;

        do {
            cout << "\nOperaciones de Conjuntos\n";
            cout << "1. Insertar elementos en conjunto 1\n";
            cout << "2. Insertar elementos en conjunto 2\n";
            cout << "3. Borrar elemento de conjunto 1\n";
            cout << "4. Borrar elemento de conjunto 2\n";
            cout << "5. Vaciar conjunto 1\n";
            cout << "6. Vaciar conjunto 2\n";
            cout << "7. Realizar la union de los conjuntos\n";
            cout << "8. Realizar la interseccion de los conjuntos\n";
            cout << "9. Realizar la diferencia entre los conjuntos (Conjunto 1 - Conjunto 2)\n";
            cout << "10. Realizar la diferencia entre los conjuntos (Conjunto 2 - Conjunto 1)\n";
            cout << "11. Salir\n";
            cout << "Ingrese su opcion: ";
            cin >> opcion;

            switch (opcion) {
                case 1:
                    insertarElementos(conjunto1); // Llama a la función para insertar elementos en el conjunto 1
                    break;
                case 2:
                    insertarElementos(conjunto2); // Llama a la función para insertar elementos en el conjunto 2
                    break;
                case 3:
                    if (!conjunto1.empty()) { // Verifica si el conjunto 1 no está vacío
                        int elemento;
                        cout << "Ingrese el elemento a borrar de conjunto 1: ";
                        cin >> elemento;
                        borrarElemento(conjunto1, elemento); // Llama a la función para borrar un elemento del conjunto 1
                    } else {
                        cout << "El conjunto 1 está vacio" << endl;
                    }
                    break;
                case 4:
                    if (!conjunto2.empty()) { // Verifica si el conjunto 2 no está vacío
                        int elemento;
                        cout << "Ingrese el elemento a borrar de conjunto 2: ";
                        cin >> elemento;
                        borrarElemento(conjunto2, elemento); // Llama a la función para borrar un elemento del conjunto 2
                    } else {
                        cout << "El conjunto 2 esta vacio" << endl;
                    }
                    break;
                case 5:
                    vaciarConjunto(conjunto1); // Llama a la función para vaciar el conjunto 1
                    break;
                case 6:
                    vaciarConjunto(conjunto2); // Llama a la función para vaciar el conjunto 2
                    break;
                case 7:
                    imprimirConjunto(unionConjuntos(conjunto1, conjunto2)); // Llama a la función para imprimir la unión de los conjuntos
                    break;
                case 8:
                    imprimirConjunto(interseccionConjuntos(conjunto1, conjunto2)); /*Llama a la función para imprimir
                                                                                           la intersección de los conjuntos*/
                    break;
                case 9:
                    imprimirConjunto(diferenciaConjuntos(conjunto1, conjunto2)); /*Llama a la función para imprimir la
                                                                                          diferencia entre los conjuntos 1 y 2*/
                    break;
                case 10:
                    imprimirConjunto(diferenciaConjuntos(conjunto2, conjunto1)); /*Llama a la función para
                                                                                                           imprimir la diferencia entre los
                                                                                                           conjuntos 2 y 1*/
                    break;
                case 11:
                    cout << "Adios, gracias por correr mi programa, ten un lindo dia!" << endl;
                    break;

                default:
                    cout << "Opcion no valida" << endl;
                    break;
            }
        } while (opcion != 11);

        return 0;
    }
