/* 
 * File:   main.cpp
 * Author: Fernando
 *
 * Created on 27 de mayo de 2020, 16:14
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <unordered_map>

struct contacto {
    char nombre[10];
    char apellido[20];
    char tiponumerotelefonico[9];
    int numerodetelefono;
    char tipocorreoelectronico[9];
    char direcciondecorreo[20];
    contacto* siguiente;
} *primero, *ultimo;


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int respuestaBusqueda;
    contacto* actual;
    contacto* buscar;
    int numeroTemporal = 0;
    bool encontrado = false;
    string nombreTemporal, nombreBusqueda, nombreEliminar;
    char opcion1 = ' ';
    int respuesta;
    int exit = 0;
    do {
        cout << "Bienvenido al menu " << endl;
        cout << endl;
        cout << "seleccione una opcion" << endl;
        cout << "1. Agregar Contacto." << endl;
        cout << "2. Buscar contacto." << endl;
        cout << "3. Lista de contactos." << endl;
        cout << "0. Salir del programa." << endl;
        cin >> respuesta;
        switch (respuesta) {
            case 0:
                system("clear");
                cout << "Gracias Vuelva pronto." << endl;
                exit = 0;
                break;
            case 1:
            {
                while (true) {

                    system("clear");


                    contacto* nuevo = new contacto();
                    cout << "Ingresa nombre:" << endl;
                    cin >> nuevo->nombre;
                    cout << "Ingresa apellido:" << endl;
                    cin >> nuevo->apellido;
                    cout << "Cual es la clasificacion del numero de telefono si es: Casa, Movil, Oficina, Trabajo o Personal" << endl;
                    cin >> nuevo->tiponumerotelefonico;
                    cout << "Ingresa numero de telefono" << endl;
                    cin >> nuevo->numerodetelefono;
                    cout << "Ingresa direccion de correo electronico" << endl;
                    cin >> nuevo->direcciondecorreo;


                    if (primero == NULL) {
                        primero = nuevo;
                        primero->siguiente = NULL;
                        ultimo = nuevo;
                    } else {
                        ultimo->siguiente = nuevo;
                        nuevo->siguiente = NULL;
                        ultimo = nuevo;
                    }
                    cout << " " << endl;
                    cout << "Deseas guardar los datos a tu agenda? s/n ";
                    cin >> opcion1;
                    if (opcion1 == 's') {
                        cout << "Datos guardados..." << endl;
                        break;
                    } else {
                        cout << "Datos no guardados..." << endl;
                        break;
                    }
                }
            }
                break;
            case 2:
                system("clear");
                do {
                    cout << "Menu de busqueda" << endl;
                    cout << "1. Buscar por nombre" << endl;
                    cout << "2. Buscar por apellido" << endl;
                    cout << "3. Buscar por telefono" << endl;
                    cout << "4. Regresar" << endl;
                    cout << "Ingrese una opcion: ";
                    cin >> respuestaBusqueda;
                    if (respuestaBusqueda == 1) {
                        buscar = new contacto();
                        buscar = primero;
                        cout << "Ingrese el nombre : ";
                        cin >> nombreTemporal;
                        if (primero != NULL) {
                            while (buscar != NULL && encontrado != true) {
                                if (buscar->nombre == nombreTemporal) {
                                    cout << "Contacto con el nombre " << nombreTemporal << " encontrado" << endl;
                                    cout << buscar->nombre;
                                    cout << " " << buscar->apellido;
                                    cout << " " << buscar->tiponumerotelefonico;
                                    cout << " " << buscar->numerodetelefono;
                                    cout << " " << buscar->direcciondecorreo << endl;
                                    cout << endl;
                                    encontrado = true;
                                }

                                buscar = buscar->siguiente;
                            }
                            if (!encontrado) {
                                cout << "El nombre no fue encontrado" << endl;
                            }

                        } else {
                            cout << "La lista esta vacia" << endl;
                        }
                        break;
                    }
                    if (respuestaBusqueda == 2) {
                        buscar = new contacto();
                        buscar = primero;
                        cout << "Ingrese el apellido : ";
                        cin >> nombreTemporal;
                        if (primero != NULL) {
                            while (buscar != NULL && encontrado != true) {
                                if (buscar->apellido == nombreTemporal) {
                                    cout << "Contacto con el apellido " << nombreTemporal << " encontrado" << endl;
                                    cout << buscar->nombre;
                                    cout << " " << buscar->apellido;
                                    cout << " " << buscar->tiponumerotelefonico;
                                    cout << " " << buscar->numerodetelefono;
                                    cout << " " << buscar->direcciondecorreo << endl;
                                    cout << endl;
                                    encontrado = true;
                                }

                                buscar = buscar->siguiente;
                            }
                            if (!encontrado) {
                                cout << "El dato ingresado no fue encontrado." << endl;
                            }

                        } else {
                            cout << "La lista esta vacia." << endl;
                        }
                        break;
                    }
                    if (respuestaBusqueda == 3) {
                        buscar = new contacto();
                        buscar = primero;
                        cout << "Ingrese el numero de telefono : ";
                        cin >> numeroTemporal;
                        if (primero != NULL) {
                            while (buscar != NULL && encontrado != true) {
                                if (buscar->numerodetelefono == numeroTemporal) {
                                    cout << "Contacto con el telefono " << numeroTemporal << " encontrado" << endl;
                                    cout << buscar->nombre;
                                    cout << " " << buscar->apellido;
                                    cout << " " << buscar->tiponumerotelefonico;
                                    cout << " " << buscar->numerodetelefono;
                                    cout << " " << buscar->direcciondecorreo << endl;
                                    cout << endl;
                                    encontrado = true;
                                }

                                buscar = buscar->siguiente;
                            }
                            if (!encontrado) {
                                cout << "El telefono no fue encontrado" << endl;
                            }

                        } else {
                            cout << "La lista esta vacia" << endl;
                        }
                        break;
                    }
                } while (respuestaBusqueda < 4 && encontrado != false);


                int opcion;
                cout << "1. Desea eliminar el contacto" << endl;
                cout << "2. Desea modificar el contacto" << endl;
                cout << "0. Regresar" << endl;
                cout << "Ingrese una opcion : ";
                cin>>opcion;
                if (opcion == 1) {


                    contacto* eliminar = new contacto();
                    eliminar = primero;
                    contacto* anterior = new contacto();
                    anterior = NULL;
                    bool nombreEncontrado = false;
                    cout << "Ingrese el nombre del contacto a eliminar: ";
                    cin >> nombreEliminar;
                    if (primero != NULL) {
                        while (eliminar != NULL && nombreEncontrado != true) {
                            if (eliminar->nombre == nombreEliminar) {
                                cout << "Contacto con el nombre " << nombreEliminar << " encontrado" << endl;


                                if (eliminar == primero) {
                                    cout << "Ingrese if" << endl;
                                    primero = primero->siguiente;
                                } else if (eliminar == ultimo) {

                                    cout << "Ingrese if" << endl;
                                    anterior->siguiente = NULL;
                                    ultimo = anterior;
                                } else {

                                    cout << "Ingrese if" << endl;
                                    anterior->siguiente = eliminar->siguiente;
                                }
                                cout << "Contacto eliminado con exito" << endl;
                                nombreEncontrado = true;
                            }
                            anterior = eliminar;
                            eliminar = eliminar->siguiente;
                        }
                        if (!nombreEncontrado) {
                            cout << "El nombre no fue encontrado" << endl;
                        }

                    } else {
                        cout << "La lista esta vacia" << endl;
                    }
                    break;
                }
                if (opcion == 2) {
                    contacto* modificar = new contacto();
                    modificar = primero;
                    bool mod = false;
                    cout << "Ingrese el dato que quiere modificar : ";
                    cin >> nombreBusqueda;
                    if (primero != NULL) {
                        while (modificar != NULL && mod != true) {
                            if (modificar->nombre == nombreBusqueda) {
                                cout << "Datos del contacto " << nombreBusqueda << " a modificar" << endl;
                                cout << "Ingresa el nuevo nombre:" << endl;
                                cin >> modificar->nombre;
                                mod = true;
                                break;
                            }
                            if (modificar->apellido == nombreBusqueda) {
                                cout << "Datos del contacto " << nombreBusqueda << " a modificar" << endl;
                                cout << "Ingresa el nuevo apellido:" << endl;
                                cin >> modificar->apellido;
                                mod = true;
                                break;
                            }
                            if (modificar->tiponumerotelefonico == nombreBusqueda) {
                                cout << "Datos del contacto " << nombreBusqueda << " a modificar" << endl;
                                cout << "Cual es la clasificacion del numero de telefono si es: Casa, Movil, Oficina, Trabajo o Personal" << endl;
                                cin >> modificar->tiponumerotelefonico;
                                mod = true;
                                break;
                            }
                            if (modificar->numerodetelefono == stoi(nombreBusqueda)) {
                                cout << "Datos del contacto " << nombreBusqueda << " a modificar" << endl;
                                cout << "Ingresa el nuevo numero de telefono:" << endl;
                                cin >> modificar->numerodetelefono;
                                mod = true;
                                break;
                            }
                            if (modificar->direcciondecorreo == nombreBusqueda) {
                                cout << "Datos del contacto " << nombreBusqueda << " a modificar" << endl;
                                cout << "Ingresa la nueva direccion de correo electronico" << endl;
                                cin >> modificar->direcciondecorreo;
                                mod = true;
                                break;
                            }

                            modificar = modificar->siguiente;
                        }
                        if (!mod) {
                            cout << "El registro no fue encontrado" << endl;
                        }
                    } else {
                        cout << "La lista esta vacia" << endl;
                    }
                    cout << "Registro modificado con exito." << endl;
                    break;
                }
                if (opcion == 0) {
                    cout << "Regresando al menu" << endl;
                    cout << endl;
                    break;
                }
                break;
            case 3:
                system("clear");
                actual = new contacto();
                actual = primero;
                if (primero != NULL) {
                    while (actual != NULL) {
                        cout << actual->nombre;
                        cout << " " << actual->apellido;
                        cout << " " << actual->tiponumerotelefonico;
                        cout << " " << actual->numerodetelefono;
                        cout << " " << actual->direcciondecorreo << endl;
                        actual = actual->siguiente;
                    }

                } else {
                    cout << "La lista esta vacia" << endl;
                }
                break;
            default:
                system("clear");
                cout << "El numero que ingreso no es valido." << endl;
                break;
        }
    } while (true && respuesta != 0);
    return 0;
}

