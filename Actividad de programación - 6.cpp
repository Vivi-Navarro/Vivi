/*Presentacíon 
Viviana Navarro Plascencia 
20/02/2024
Nombre: Actividad de programación - 6
Centro Universitario De los Altos 
Ing en computacion/2do semestre 
Profesor: Sergio Franco Casillas 
Descripcion: Suma de un vector*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> miVector; // Crear un vector vacío, en este caso tiene capacidad vector<int> miVector(10);

    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Ingresar valor en una posicion\n";
        cout << "2. Mostrar lista de valores\n";
        cout << "3. Mostrar sumatoria de todos los elementos\n";
        cout << "4. Borrar elemento en una posicion\n";
        cout << "5. Editar elemento en una posicion\n";
        cout << "6. Vaciar el vector\n";
        cout << "0. Salir\n";
        cout << "Elije una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int valor;
                cout << "Ingresa el valor: ";
                cin >> valor;
                miVector.push_back(valor); //Agrega el valor ingresado al final del vector miVector
                                           //.push_back es una función miembro de la clase std::vector.
                break;
                //el break, el programa seguiría ejecutando los bloques de código de los case siguientes
           }
           case 2:
               cout << "Lista de valores:\n";
               for (int i = 0; i < miVector.size(); ++i) {
                   cout << miVector[i] << " ";
               }
               cout << endl;
               break;
               /*int i = 0: Inicializa una variable i con el valor 0, i < miVector.size(): La condición del
               bucle verifica si i es menor que el tamaño del vector miVector. ++i: Incrementa el valor de i
               en cada iteración, cout << miVector[i] << " ";: Muestra el valor del elemento en la posición i del
               vector*/
           case 3: {
               int sumatoria = 0;
               for (int i = 0; i < miVector.size(); ++i) {
                   sumatoria += miVector[i];
               }
               cout << "Sumatoria de elementos: " << sumatoria << endl;
               break;
           }
           /*int sumatoria = 0;: Declara e inicializa una variable llamada sumatoria de tipo entero con el valor 0.
           Esta variable se usará para almacenar la suma de todos los elementos del vector, sumatoria += miVector[i];:
           Suma el valor del elemento en la posición i del vector a la variable sumatoria*/
           case 4: {
               int posicion;
               cout << "Ingresa la posicion a borrar: ";
               cin >> posicion;
               if (posicion >= 0 && posicion < miVector.size()) {
                   miVector.erase(miVector.begin() + posicion);
               } else {
                   cout << "Posicion invalida\n";
               }
               break;
           }
           /*en el if esta línea verifica si la posición ingresada es válida, posicion >= 0: Verifica si la posición es mayor o igual a cero.
           posicion < miVector.size(): Verifica si la posición es menor que el tamaño actual del vector miVector.
           miVector.erase(miVector.begin() + posicion);: Si la posición es válida, se elimina el elemento en esa posición utilizando
           la función erase(). miVector.begin() + posicion se refiere al iterador que apunta al elemento en la posición especificada.
           el else es si la posición no es válida, se muestra un mensaje de error.*/
           case 5: {
               int posicion, valor;
               cout << "Ingresa la posicion a editar: ";
               cin >> posicion;
               cout << "Ingresa el nuevo valor: ";
               cin >> valor;
               if (posicion >= 0 && posicion < miVector.size()) {
                   miVector[posicion] = valor;
               } else {
                   cout << "Posicion invalida\n";
               }
               break;
           }
           /*en el cin >> valor;: Lee el valor ingresado por el usuario y lo almacena en la variable valor, con el if
            solo ve si la posicion es valida*/
           case 6:
               miVector.clear();
               cout << "El vector ha sido vaciado.\n";
               break;
               //solo .clear solo limpia el vector
           case 0:
               cout << "Hasta luego, ten un lindo dia!\n";
               break;
           default:
               cout << "Opcion invalida. Intentalo de nuevo.\n";
       }
       /*default:: Esto establece un caso por defecto. Si el valor de opcion no coincide con ninguno de los casos anteriores,
       se ejecutará el bloque de código dentro de este caso, cout << "Opcion invalida. Intentalo de nuevo.\n";: Muestra un
       mensaje de error en la consola*/
   } while (opcion != 0);
    /*Esta línea cierra el bucle do-while que contiene al switch. La condición del bucle verifica si opcion es diferente de 0.
     Si es así, se repite el bucle y se vuelve a mostrar el menú. Si no, se termina el bucle y el programa*/

   return 0;
}
