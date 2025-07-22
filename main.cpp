#include <iostream>
#include <locale>
#include <clocale>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Lista.h"

using namespace std;

int main() {
    // 1) Forzar UTF-8 en todo el programa
    std::setlocale(LC_ALL, "");  // usa la localización del SO (idealmente UTF-8)

#ifdef _WIN32
    // en Windows, pide a la consola que use UTF-8 para entrada/salida
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    // 2) También podemos imbue para streams C++
    try {
        locale::global(locale(""));
        cout.imbue(locale());
    } catch (const runtime_error&) {
        cout << "No se pudo establecer la localización, usando predeterminada.\n";
    }

    Lista lista;
    int opcion, valor;
    Nodo* nodo;

    do {
        cout << "\n=== Menú de Operaciones con Lista ===\n";
        cout << "1. Crear lista\n";
        cout << "2. Insertar al inicio\n";
        cout << "3. Insertar al final\n";
        cout << "4. Insertar después de un valor\n";
        cout << "5. Buscar valor\n";
        cout << "6. Visualizar lista\n";
        cout << "7. Eliminar valor\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                lista.crearLista();
                cout << "Lista creada.\n";
                break;
            case 2:
                cout << "Ingrese valor: ";
                cin >> valor;
                lista.insertarCabeza(valor);
                cout << "Valor insertado al inicio.\n";
                break;
            case 3:
                cout << "Ingrese valor: ";
                cin >> valor;
                lista.insertarFinal(valor);
                cout << "Valor insertado al final.\n";
                break;
            case 4:
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
                nodo = lista.buscar(valor);
                if (nodo) {
                    cout << "Ingrese valor a insertar: ";
                    cin >> valor;
                    lista.insertarDespues(nodo, valor);
                    cout << "Valor insertado después.\n";
                } else {
                    cout << "Valor no encontrado.\n";
                }
                break;
            case 5:
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
                nodo = lista.buscar(valor);
                cout << (nodo ? "Valor encontrado.\n" : "Valor no encontrado.\n");
                break;
            case 6:
                lista.visualizar();
                break;
            case 7:
                cout << "Ingrese valor a eliminar: ";
                cin >> valor;
                lista.eliminar(valor);
                cout << "Valor eliminado (si existía).\n";
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 0);

    return 0;
}
