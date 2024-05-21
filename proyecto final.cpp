#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

// Variables
int lineaModificar;
string nuevoValor;
int dato;
vector<string>linea2;
int t,  idBuscar;
bool encontrado = false;
string linea, grupoBuscar,estatus;
string materiabuscar;
int eleccion,respuesta, res;
string materias[5]={"111 matematicas", "222 mecanica", "333 espanol", "444 geografia", "555 sexualidad"};// Materia con su id
string regmat[5]={"111","222","333","444","555"};
// Estructura
struct escuela{
    int id;
    char grupo[50];
    char nomstudent[100];
    char numstudent[15];
    char nomfam[100];
    char numfam[15];
    float calificaciones[5];
    float promedio;
}alumno;


int main() {

    cout << "Buenos dias" << endl;
    do {
        int a;// Variable de control para el bucle de validación de entrad
        do {
            cout
                    << "Puedes decirme que es lo, que quieres hacer el dia de hoy?\n"// Primer pregunta para el primer switch
                       "1.Registrar estudiante.\n2.Modificar datos.\n3.Ver datos. \n Dame tu respuesta: ";// Opciones de primer switch
            cin >> eleccion;// Se pide la opcion de lo que quiere hacer
            cout << endl;// Salto de linea
            if (eleccion >= 1 and eleccion <= 4) {// Hacemos una validacion de la opcion que quiere tomar el usuario
                cout << "Muy bien" << endl;
                a = 0;// Salir del bucle de validación
            } else {
                cout << "ERROR. Puedes decirme de nuevo tu opcion." << endl;// Error de respuesta
                a = 5;// Mantenerse en el bucle de validación

            }
        } while (a == 5);// Repetir mientras la entrada no sea válida
        // Fin de validacion



        // Abrir archivo 1
        ofstream archivo1("C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos de registro.txt",
                          fstream::app/*Funcion para escribir al final del documento */);
        // Abrir archivo 2
        ofstream archivo2("C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos de materias.txt",
                          fstream::app/*Funcion para escribir al final del documento */);
        // Abrir archivo 3
        ofstream archivo3("C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos de id.txt",
                          fstream::app/*Funcion para escribir al final del documento */);
        // Verificar si se abrió correctamente archivo 1
        if (!archivo1) {
            cout << "Error al abrir el archivo1." << endl;
            return 1;// Terminar el programa si no se pudo abrir el archivo
        }
        // Verificar si se abrió correctamente archivo 2
        if (!archivo2) {
            cout << "Error al abrir el archivo2." << endl;
            return 1;// Terminar el programa si no se pudo abrir el archivo
        }
        // Verificar si se abrió correctamente archivo 2
        if (!archivo3) {
            cout << "Error al abrir el archivo3." << endl;
            return 1;// Terminar el programa si no se pudo abrir el archivo
        }


        // Comenzamos con el primer switch
        switch (eleccion) {
            int b;// Uso de while en case
            case 1: { // Ingresar datos
                int f;
                do {
                    int op, cp;
                    // Solicitar datos del estudiante
                    cout << "Empezaremos por los datos del estudiante" << endl;
                    cout << "dame un ID para el estudiante, el id debe ser por orden en la secuencia(001,002,003,...)"
                         << endl;//ingresa el id
                    cout << "sabes que id es el siguiente o quieres ver el historial de id 1.si o 2.no" << endl;
                    cin >> cp;
                    if (cp = 1) {//se muestra el historial de id


                        // Abrir el archivo en modo de lectura
                        ifstream archivo_lectura("C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos de id.txt");
                        if (!archivo_lectura) {
                            cout << "Error al abrir el archivo para lectura." << endl;
                            return 1;
                        }

                        // Leer el contenido del archivo línea por línea y mostrarlo en la consola
                        while (getline(archivo_lectura, linea)) {
                            cout << linea << endl;
                        }
                    } else if (cp = 2) {
                        cout << "muy bien" << endl;
                    }
                    // Solicitar el ID del estudiante
                    cout << "ahora si dame el id" << endl;
                    cin >> alumno.id;
                    cin.ignore();// Ignorar el '\n' que queda en el búfer después de la entrada del ID
                    do {
                        // Solicitar la carrera del estudiante
                        cout << "Dime la carrera del estudiante, puede ser alguna que ya tengamos o puede ser una nueva"
                                "de las que ya tenemos"
                             << endl;
                        cout << "1.Nueva.\n"
                                "2.Existente" << endl;
                        cin >> op;
                        // Validar la opción seleccionada
                        if (op > 0 && op < 3) {
                            cout << "muy bien" << endl;
                            f = 0;// Entrada válida, salir del bucle
                        } else {
                            cout << "error" << endl;
                            f = 5;
                        }
                    } while (f == 5);// Repetir mientras la entrada no sea válida
                    switch (op) {
                        case 1: {//nueva
                            cout << "Dame el nombre de la carrera o grupo: " << endl;
                            cin.ignore();
                            fgets(reinterpret_cast<char *>(alumno.grupo ), 50, stdin);
                            break;
                        }
                        case 2: {
                            int ap;
                            cout
                                    << "Tenemos las siguientes carreras: \n1. Ingenieria en computacion\n2. Medicina\n3. Psicologia"
                                    << endl;
                            cout << "Selecciona una carrera: ";
                            cin >> ap;
                            if (ap == 1) {
                                strcpy(alumno.grupo, "Ingenieria en computacion");
                            } else if (ap == 2) {
                                strcpy(alumno.grupo, "Medicina");
                            } else if (ap == 3) {
                                strcpy(alumno.grupo, "Psicologia");
                            } else {
                                cout << "Opción no válida." << endl;
                            }
                            break;
                        }
                    }

//datos del estudiante
                    cout << "Dame el nombre del estudiante,empezando por los apellidos."
                         << endl;//ingresar nombre de estudiante
                    cin.ignore();
                    fgets(reinterpret_cast<char *>(alumno.nomstudent), 50, stdin);
                    cout << "dame el numero del telefono" << endl;//ingrresar numero de telefono del estuidiante
                    fgets(reinterpret_cast<char *>(alumno.numstudent), 15, stdin);
                    cout << "Dame las calificaciones de la siguiente materia del alumno" << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << "dame la calificacion de: " << materias[i] << endl;     //calificaciones del estudiante
                        cin >> alumno.calificaciones[i];

                    }
                    for (int j = 0; j < 5; j++) {
                        alumno.promedio = alumno.calificaciones[j] + alumno.promedio;

                    }
                    alumno.promedio = alumno.promedio / 5;
                    if (alumno.promedio <= 59) {
                        estatus = "REPROBADO";
                    } else if (alumno.promedio >= 60 && alumno.promedio <= 79) {
                        estatus = "REGULAR";
                    } else if (alumno.promedio >= 80 && alumno.promedio <= 89) {
                        estatus = "MUY BIEN";
                    } else if (alumno.promedio >= 90 && alumno.promedio <= 100) {
                        estatus = "EXCELENTE";
                    }
                    cin.ignore();
                    cout << "FAMILIAR" << endl;             //datos del familiar
                    cout << "Dame el nombre del familiar,empezando por los apellidos."
                         << endl; //ingresar nombre del familiar
                    fgets(reinterpret_cast<char *>(alumno.nomfam), 50, stdin);
                    cout << "dame el numero del telefono" << endl; //ingresar numero de telefono
                    fgets(reinterpret_cast<char *>(alumno.numfam), 15, stdin);

                    cout << "los datos son correctos" << endl;
                    cout << "CARRERA: " << alumno.grupo << endl;
                    cout << "ID: " << alumno.id << endl;
                    cout << "NOMBRE: " << alumno.nomstudent << endl;
                    cout << "NUMERO DE TELEFONO: " << alumno.numstudent << endl;
                    cout << "PROMEDIO: " << alumno.promedio << ": " << estatus << endl;
                    cout << "NOMBRE DE FAMILIAR: " << alumno.nomstudent << endl;
                    cout << "NUMERO DE TELEFNO DE FAMILIAR: " << alumno.numfam << endl;
                    cout << "ESTAS SON LAS CALIFICACIONES DEL ESTUDIANTE: " << endl;
                    for (int i = 0; i < 5; i++) {
                        cout << materias[i] << ": " << *alumno.calificaciones << endl;
                    }
                    cout << "son correectos los datos 1.si o 2.no: " << endl;//se imprime un prelimniar de los datos

                    cin >> respuesta;


                    if (respuesta == 2) {
                        b = 5; // Si la respuesta es 2, establecer b en 5 y se repiteel proceso
                    } else {
                        if (respuesta == 1) {
                            //archivo 1
                            archivo1 << "ID: " << alumno.id
                                     << endl; // Si la respuesta es 1, escribir el ID en el archivo

                            archivo1 << "ESTUDIANTE........" << endl;
                            archivo1 << "GRUPO: " << alumno.grupo << endl;
                            archivo1 << "NOMBRE: " << alumno.nomstudent
                                     << endl;//se guarda el nombre en el dopcumento
                            archivo1 << "NUMERO TELEFONICO: " << alumno.numstudent
                                     << endl;//se guarda el numero del estudiante


                            archivo1 << "FAMILIAR........." << endl;
                            archivo1 << "NOMBRE: " << alumno.nomstudent << endl;//se guarda el nombre del familiar
                            archivo1 << "NUMERO TELEFONICO: " << alumno.numfam
                                     << endl;//se guarda el numero del familiar
                            for (int i = 0; i < 6; i++) {
                                archivo1 << materias[i] << ": " << alumno.calificaciones[i]
                                         << endl;//calificaciones de las meterias
                            }
                            archivo1 << "PROMEDIO: " << alumno.promedio << ": " << estatus << endl;

                            //guardar datos en archivo 2
                            for (int i = 0; i < 5; i++) {
                                archivo2 << "ID: " << alumno.id << ": " << materias[i] << ": " << alumno.calificaciones
                                         << endl;
                            }
                            //guardar datos en archivo 3
                            archivo3 << alumno.id << alumno.nomstudent << endl;
                            b = 0;
                        } else {
                            cout << "ERROR, respuesta inválida"
                                 << endl; // Si la respuesta no es ni 1 ni 2, mostrar un mensaje de error
                            b = 5;
                        }
                    }

                } while (b == 5);
                break;
            }//registrar datos
            case 2: {//modificacion del documento
                int c;
                do {
                    cout << "Que te gustaria hacer?\n"
                            "1.Modificar datos. \n"
                            "2.Eliminar al estudiante.\n"
                            "Dame tu respuesta: "; //opciones de segundo switch
                    cin.ignore();
                    cin >> res;//se pide la opcion de lo que quiere hacer
                    cout << endl;//salto de linea
                    if (res >= 1 and res <= 3) {//hacemos una validacion de la opcion que quiere tomar el usuario
                        cout << "Muy bien" << endl;
                        c = 0;
                    } else {
                        cout << "ERROR. Puedes decirme de nuevo tu opcion." << endl;//error de respuesta
                        c = 5;

                    }
                } while (c == 5);
                //fin de validacion

                switch (res) {
                    case 1: { //modificar datos
                        string modificar;
                        bool encontrado = false;
                        vector<string> linea2;
                        int idBuscar;

                        // Pedir al usuario el ID del estudiante a buscar
                        cout << "Dame el ID del estudiante que deseas buscar: ";
                        cin >> idBuscar;

                        // Abrir el archivo de lectura
                        ifstream archivoLectura(
                                "C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos de registro.txt");
                        if (!archivoLectura) {
                            cout << "Error al abrir el archivo." << endl;
                            return 1;
                        }

                        // Leer el archivo línea por línea
                        string linea;
                        while (getline(archivoLectura, linea)) {
                            int idActual = stoi(linea.substr(4)); // Extraer el ID de la línea
                            if (idActual == idBuscar) {
                                encontrado = true;
                                // Mostrar datos del estudiante encontrado
                                cout << "Datos del estudiante encontrado:" << endl;
                                cout << linea << endl;
                                linea2.push_back(linea); // Agregar la línea al vector

                                // Leer el resto de las líneas y agregarlas al vector
                                for (int i = 0; i < 14; ++i) {
                                    getline(archivoLectura, linea);
                                    cout << linea << endl;
                                    linea2.push_back(linea);
                                }
                                break; // Salir del bucle una vez que se haya encontrado el estudiante
                            }
                        }
                        // Cerrar el archivo de lectura
                        archivoLectura.close();

                        if (!encontrado) {
                            cout << "No se encontró ningún estudiante con el ID proporcionado." << endl;
                            return 1;
                        }

                        // Preguntar al usuario qué campo desea modificar
                        int p;
                        do{
                        cout << "Ingrese el dato que va a modificar: "
                                "1.Grupo."
                                "2.Nombre de estudinate.\n"
                                "3.Numero de estudiante.\n"
                                "4.Nombre del familiar.\n"
                                "5.Numero del familiar.\n"
                                "6.calificacion de matematicas\n"
                                "7.calificacion de mecanica.\n"
                                "8.calificacion de español\n"
                                "9.calificacion de geografia\n"
                                "10.calificacion de sexualidad\n"
                                "\n";
                        cin >> dato;
                        if (dato = 1) {
                            lineaModificar = 3;
                        } else if (dato = 2) {
                            lineaModificar = 4;
                        } else if (dato = 3) {
                            lineaModificar = 6;
                        } else if (dato = 4) {
                            lineaModificar = 9;
                        } else if (dato = 5) {
                            lineaModificar = 11;
                        } else if (dato = 6) {
                            lineaModificar = 13;
                        } else if (dato = 7) {
                            lineaModificar = 14;
                        } else if (dato = 8) {
                            lineaModificar = 15;
                        } else if (dato = 9) {
                            lineaModificar = 16;
                        } else if (dato = 10) {
                            lineaModificar = 17;
                        }


                        if (lineaModificar < 0 || lineaModificar > 14) {
                            cout << "Número de línea inválido." << endl;
                            p=5;
                        }else{
                            p=0;
                        }
                    }while (p == 5);//fin de validacion
                        cin.ignore(); // Limpiar el buffer de entrada
                        cout << "Ingrese el nuevo valor: ";
                        getline(cin, nuevoValor);

                        // Modificar el valor en el vector
                        linea2[lineaModificar] = nuevoValor;

                        // Abrir archivo temporal para escritura
                        ofstream archivoTemporal(
                                "C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos temporales.txt");
                        if (!archivoTemporal) {
                            cout << "Error al abrir el archivo temporal." << endl;
                            return 1;
                        }

                        for (const auto &linea: linea2) {
                            archivoTemporal << linea << endl;
                        }
                        archivoTemporal.close();

                        // Leer los datos modificados desde el archivo temporal y actualizar el archivo original
                        ifstream archivoLecturaTemporal(
                                "C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos temporales.txt");
                        if (!archivoLecturaTemporal) {
                            cout << "Error al abrir el archivo temporal para lectura." << endl;
                            return 1;
                        }

                        vector<string> datosModificados;
                        while (getline(archivoLecturaTemporal, linea)) {
                            datosModificados.push_back(linea);
                        }
                        archivoLecturaTemporal.close();

                        // Abrir el archivo original para escritura
                        ofstream archivoEscritura(
                                "C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos de registro.txt");
                        if (!archivoEscritura) {
                            cout << "Error al abrir el archivo para escritura." << endl;
                            return 1;
                        }

                        for (const auto &linea: datosModificados) {
                            archivoEscritura << linea << endl;
                        }
                        archivoEscritura.close();

                        cout << "Datos modificados y guardados con éxito." << endl;


                        break;
                }
                //fin de caso 1
                case 2: {//eliminar estudiante
                    break;
                }

                break;
            }
                //modificar datos
            case 3: {//imprimir datos de alumno
                int op, k;
                do {

                    cout << "1. Imprimir todos los datos.\n "
                            "2. estudiantes por grupo.\n"
                            "3.Calificaciones del estudiante.\n"
                            "4. estudiantes por materia.\n"
                            "5.Estudiante.\n "
                            "Dame tu respuesta: ";
                    cin.ignore();
                    cin >> op;
                    //validacion
                    if (op > 0 && op < 6) {
                        cout << "Muy bien" << endl;
                        k = 0;
                    } else {
                        cout << "Error" << endl;
                        k = 5;
                    }
                } while (k == 5);//fin de validacion
                switch (op) {


                    case 1: {//todos los datos para imprimir
                        // Cerrar el archivo de escritura antes de abrirlo para lectura
                        archivo1.close();

                        // Abrir el archivo en modo de lectura
                        ifstream archivo_lectura(
                                "C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos de registro.txt");
                        if (!archivo_lectura) {
                            cout << "Error al abrir el archivo para lectura." << endl;
                            return 1;
                        }

                        // Leer el contenido del archivo línea por línea y mostrarlo en la consola
                        while (getline(archivo_lectura, linea)) {
                            cout << linea << endl;
                        }

                        // Cerrar el archivo de lectura
                        archivo_lectura.close();
                        cin.ignore();
                        break;
                    }//imrimir todos los datos
                    case 2: {//estudiantes por grupo

                        cout << "Ingrese el grupo a buscar: ";
                        cin.ignore();
                        getline(cin, grupoBuscar);

                        ifstream archivoLectura(
                                "C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos de registro.txt");
                        if (!archivoLectura) {
                            cout << "Error al abrir el archivo para lectura." << endl;
                            return 1;
                        }

                        bool encontrado = false;
                        while (getline(archivoLectura, linea)) {
                            if (linea.find("GRUPO: " + grupoBuscar) != string::npos) {
                                encontrado = true;
                                cout << "Datos del estudiante encontrado:" << endl;
                                cout << linea << endl;
                                for (int i = 0; i < 17; ++i) {
                                    getline(archivoLectura, linea);
                                    cout << linea << endl;
                                }
                            }
                        }

                        archivoLectura.close();

                        if (!encontrado) {
                            cout << "No se encontraron estudiantes en el grupo especificado." << endl;
                        }
                        break;
                    }//imprimir estudiantes por grupo
                    case 3: {//calificacines del alumno
                        cout << "Dame el ID del estudiante que deseas buscar: ";
                        cin >> idBuscar;
                        ifstream archivoLectura(
                                "C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos de registro.txt");
                        if (!archivoLectura) {
                            cout << "Error al abrir el archivo." << endl;
                            return 1;
                        }

                        while (getline(archivoLectura, linea)) {
                            int idActual = stoi(linea.substr(4)); // Extraer el ID de la línea
                            if (idActual == idBuscar) {
                                encontrado = true;
                                // Mostrar datos del estudiante encontrado
                                cout << "Datos del estudiante encontrado:" << endl;
                                cout << linea << endl;
                                // Leer el resto de las líneas y mostrar las calificaciones
                                for (int i = 0; i < 5; ++i) {
                                    getline(archivoLectura, linea);
                                    if (linea.find(materias[i]) != string::npos) {
                                        cout << linea << endl;
                                    }
                                }
                                // Salir del bucle una vez que se han mostrado las calificaciones
                                break;
                            }
                        }

                        archivoLectura.close();

                        if (!encontrado) {
                            cout << "No se encontró ningún estudiante con el ID proporcionado." << endl;
                        }

                        break;
                    }//imprimir calificaciones del estudiante
                    case 4: {//estudiantes por materia
                        cout << "Ingrese la materia a buscar: ";
                        cout
                                << "debes poner el numero de registro que tiene cada materia, son los 33 numeros que estan al principio"
                                << endl;
                        for (int i = 0; i < 5; i++) {
                            cout << materias[i] << endl;
                        }
                        cin.ignore();
                        getline(cin, materiabuscar);

                        ifstream archivoLectura(
                                "C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos de materias.txt");//se busca en el archivo 2
                        if (!archivoLectura) {
                            cout << "Error al abrir el archivo para lectura." << endl;
                            return 1;
                        }

                        bool encontrado = false;
                        while (getline(archivoLectura, linea)) {
                            if (linea.find("#: " + materiabuscar) != string::npos) {
                                encontrado = true;
                                cout << "Datos de estudiantes en esta materia encontrados" << endl;
                                cout << linea << endl;

                                getline(archivoLectura, linea);
                                cout << linea << endl;

                            }
                        }

                        archivoLectura.close();

                        if (!encontrado) {
                            cout << "No se encontraron estudiantes en el grupo especificado." << endl;
                        }
                        break;
                    }//imprimir estudiantes por materia
                    case 5: {

                        cout << "Dame el ID del estudiante que deseas buscar: ";
                        cin >> idBuscar;
                        ifstream archivoLectura(
                                "C:\\Users\\andre\\Documents\\GitHub\\proyectotexto\\datos de registro.txt");
                        if (!archivoLectura) {
                            cout << "Error al abrir el archivo." << endl;
                            return 1;
                        }

                        while (getline(archivoLectura, linea)) {
                            int idActual = stoi(linea.substr(4)); // Extraer el ID de la línea
                            if (idActual == idBuscar) {
                                encontrado = true;
                                // Mostrar datos del estudiante encontrado
                                cout << "Datos del estudiante encontrado:" << endl;
                                cout << linea << endl;
                                // Leer el resto de las líneas y mostrarlas
                                for (int i = 0; i < 14; ++i) {
                                    getline(archivoLectura, linea);
                                    cout << linea << endl;
                                }
                                break; // Salir del bucle una vez que se haya encontrado el estudiante
                            }
                        }

                        archivoLectura.close();

                        if (!encontrado) {
                            cout << "No se encontró ningún estudiante con el ID proporcionado." << endl;
                        }
                        break;
                    }//immprimir estudiante

                }
                break;
            }//ver datos
        }//fin de switch
        cout << "Quieres hacer algo mas en el sistema, presiona el numero 5" << endl;
        cin >> t;
    }
}
        while (t == 5);

        return 0;


}
