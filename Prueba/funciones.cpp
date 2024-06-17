#include <iostream>
#include <string.h>
#include "variables.h"
#include <locale.h>

using namespace std;

PARTIDO partidos[MAX_REG];

int pos = 0;

// CRUD Functions
int obtPos(int id);
void agregar(PARTIDO *p);
void editar(PARTIDO *p, int id);
void eliminar(int id);
PARTIDO buscar(int id);
int menu();
void principal();
void pedirDatos();
void mostrarDatos();
void showData(PARTIDO &p);
void buscarxID();
void editarDatos();
void eliminarDato();

void agregar(PARTIDO *p)
{
    partidos[pos] = *p;
    pos++;
}

PARTIDO buscar(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (id == partidos[i].id)
        {
            return partidos[i];
        }
    }
    PARTIDO p;
    return p;
}

int obtPos(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (partidos[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void editar(PARTIDO *p, int id)
{
    int posi = obtPos(id);
    partidos[posi] = *p;
}

void eliminar(int id)
{
    int posi = obtPos(id);

    for (int i = posi; i < pos - 1; i++)
    {
        partidos[i] = partidos[i + 1];
    }
    pos--;
}

int menu()
{
    int op;
    cout << "Menu \n";
    cout << "1. Agregar \n";
    cout << "2. Editar \n";
    cout << "3. Eliminar \n";
    cout << "4. Buscar \n";
    cout << "5. Mostrar todo \n";
    cout << "6. Salir \n";
    cout << "Digite la opcion \n";
    cin >> op;
    return op;
}

void principal()
{
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 1:
            pedirDatos();
            break;
        case 2:
            editarDatos();
            break;
        case 3:
            eliminarDato();
            break;
        case 4:
            buscarxID();
            break;
        case 5:
            mostrarDatos();
            break;
        case 6:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "No existe esa opcion...\n";
            break;
        }
    } while (op != 6);
}

void pedirDatos()
{
    PARTIDO partido;
    cout << "Datos del partido de voleibol\n";
    cout << "id de juego: ";
    cin >> partido.id;
    if (obtPos(partido.id) != -1)
    {
        cout << "EL JUEGO YA EXISTE... \n";
        return;
    }
    cout << "Puntos anotados: ";
    cin >> partido.ptsNoted;
    cout << "Puntos en contra: ";
    cin >> partido.ptsContra;
    cout << "Saques efectivos: ";
    cin >> partido.aceMatches;
    cout << "Numero de partido: ";
    cin >> partido.numParties;
    cout << "Bloqueo efectivos: ";
    cin >> partido.successBlock;
    cout << "Efectividad de ataque: ";
    cin >> partido.recSuccessful;
    cout << "Efectividad de defensa: ";
    cin >> partido.effectiveDefense;
    agregar(&partido);
    cout << "Registro agregado...\n";
}

void mostrarDatos()
{
    if (pos == 0)
    {
        cout << "SIN DATOS...";
        return;
    }

    for (int i = 0; i < pos; i++)
    {
        showData(partidos[i]);
    }
}

void buscarxID()
{
    int id;
    cout << "Dime el id del partido a buscar: ";
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "No se encontro el registro...\n";
        return;
    }

    PARTIDO p = buscar(id);
    showData(p);
}

void showData(PARTIDO &p)
{
    cout << "===================================" << endl;
    cout << "#: " << p.id << endl;
    cout << "Puntos anotados: " << p.ptsNoted << endl;
    cout << "Puntos en contra: " << p.ptsContra << endl;
    cout << "Efectividad de saques: " << p.aceMatches << endl;
    cout << "Numero de partido: " << p.numParties << endl;
    cout << "Bloqueo efectivos: " << p.successBlock << endl;
    cout << "Efectividad de ataque: " << p.recSuccessful << endl;
    cout << "Efectividad de defensa: " << p.effectiveDefense << endl;
    cout << "===================================" << endl;
}

void editarDatos()
{
    int id;
    cout << "Escribe el # del partido a editar: " << endl;
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "No se encontro el registro...\n";
        return;
    }
    PARTIDO p = buscar(id);
    cout << "Datos actuales: \n";
    showData(p);
    cout << "Nuevos datos: \n";
    cout << "Puntos anotado: ";
    cin >> p.ptsNoted;
    cout << "Puntos en contra: ";
    cin >> p.ptsContra;
    cout << "Efectividad de saques: ";
    cin >> p.aceMatches;
    cout << "Numero de partido: ";
    cin >> p.numParties;
    cout << "Bloqueos efectivos: ";
    cin >> p.successBlock;
    cout << "Efectividad de ataque: ";
    cin >> p.recSuccessful;
    cout << "Efectividad de defensa: ";
    cin >> p.effectiveDefense;
    editar(&p, id);
    cout << "Registro actualizado...\n";
}

void eliminarDato()
{
    int id;
    cout << "Partido - Eliminar\n";
    cout << "#: ";
    cin >> id;
    if (obtPos(id) == -1)
    {
        cout << "No se encontro el registro...\n";
        return;
    }
    eliminar(id);
    cout << "Registro eliminado...\n";
}