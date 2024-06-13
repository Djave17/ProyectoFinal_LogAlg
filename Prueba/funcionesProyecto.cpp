#include <iostream>
#include <string>
#include "VariablesProyecto.h"

using namespace std;

void menuPrincipal();
void subMenu();
void agregarPartido1(Partido *partido, int &numPartidos);
void agregarPartido(Partido *partido, int &numPartidos);
void editarEstadisticas(Partido *partido, int numPartidos);
void promedios(Partido *partido, Promedios promedio, int numPartidos);
void mostrarPromedios(Promedios promedio, int numPartidos);
void mostrarPartidos(Partido partido, int numPartidos);

void menuPrincipal()
{
    int op;
    Partido partido[MAX_PARTIDOS];
    Promedios promedio[MAX_PARTIDOS];
    int numPartidos = 0;

    do
    {
        cout << "1. Agregar partido" << endl;
        cout << "2. Mostrar promedios" << endl;
        cout << "3. Mostrar partidos" << endl;
        cout << "4. Editar estadisticas" << endl;
        cout << "5. Eliminar estadisticas" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> op;

        switch (op)
        {
        case 1:
            system("cls");
            agregarPartido1(partido, numPartidos);
            system("pause");

            break;
        case 2:
            mostrarPromedios(promedio[MAX_PARTIDOS], numPartidos);
            break;

        case 3:
            mostrarPartidos(partido[MAX_PARTIDOS], numPartidos);
            break;

        case 4:

            break;

        case 5:
            break;

        default:
            break;
        }

    } while (op != 5);
}

// sub menu de elecion de estadisticas a agreagar
void agregarPartido1(Partido *partido, int &numPartidos)
{
    int opcion2;
    int contador = 0;

    do
    {
        //NOMBRE DEL EQUIPO CONTRARIO
        cout << "Introduzca el nombre del equipo enfrentado: ";
        cin >> partido[numPartidos].namepartido;
        fflush(stdin);
        //FECHA DEL PARTIDO
        cout << "Introduzca la fecha del partido: ";
        cin >> partido[numPartidos].date;
        cout << endl;
        fflush(stdin);

        //PUNTOS ANOTADOS
        cout << "Puntos del partido Jaguares vs : " << partido[numPartidos].namepartido << endl;
        cout << "Ingrese los puntos anotados del partido: ";
        cin >> partido[contador].pts[numPartidos];
        cout << endl;
        fflush(stdin);

        //PUNTOS EN CONTRA
        cout << "Puntos en contra del partido Jaguares vs : " << partido[numPartidos].namepartido << endl;
        cout << "Ingrese los puntos en contra del partido: ";
        cin >> partido[contador].ptsAgainst[numPartidos];
        cout << endl;
        fflush(stdin);

        //SETS GANADOS
        cout << "Sets ganados del partido Jaguares vs : " << partido[numPartidos].namepartido << endl;
        cout << "Ingrese los sets ganados del partido: ";
        cin >> partido[contador].setsWon[numPartidos];
        cout << endl;
        fflush(stdin);
        
        //SETS PERDIDOS
        cout << "Sets perdidos del partido Jaguares vs : " << partido[numPartidos].namepartido << endl;
        cout << "Ingrese los sets perdidos del partido: ";
        cin >> partido[contador].setsLost[numPartidos];
        cout << endl;
        fflush(stdin);

        //ACES
        cout << "Aces del partido Jaguares vs : " << partido[numPartidos].namepartido << endl;
        cout << "Ingrese los aces del partido: ";
        cin >> partido[contador].ace[numPartidos];
        cout << endl;
        fflush(stdin);

        //ERRORES
        cout << "Errores del partido Jaguares vs : " << partido[numPartidos].namepartido << endl;
        cout << "Ingrese los errores del partido: ";
        cin >> partido[contador].errors[numPartidos];
        cout << endl;
        fflush(stdin);
       

        //RECEPCIONES EXITOSAS
        cout << "Recepciones exitosas del partido Jaguares vs : " << partido[numPartidos].namepartido << endl;
        cout << "Ingrese las recepciones exitosas del partido: ";
        cin >> partido[contador].sucessfulRecep[numPartidos];
        cout << endl;
        fflush(stdin);
        

        //ATAQUES EXITOSOS
        cout << "Ataques exitosos del partido Jaguares vs : " << partido[numPartidos].namepartido << endl;
        cout << "Ingrese los ataques exitosos del partido: ";
        cin >> partido[contador].succesfulAtacks[numPartidos];
        cout << endl;
        fflush(stdin);
        

        //BLOQUEOS
        cout << "Bloqueos del partido Jaguares vs : " << partido[numPartidos].namepartido << endl;
        cout << "Ingrese los bloqueos del partido: ";
        cin >> partido[contador].blocks[numPartidos];
        cout << endl;
        fflush(stdin);
       
        
        //FALTAS
        
        cout << "Faltas del partido Jaguares vs : " << partido[numPartidos].namepartido << endl;
        cout << "Ingrese las faltas del partido: ";
        cin >> partido[contador].faults[numPartidos];
        cout << endl;
        fflush(stdin);
       
        
        //PREGUNTA PARA AGREGAR OTRO PARTIDO
        cout << "Desea agregar otro partido? 1. Si 2. No" << endl;
        cin >> opcion2;
        if (opcion2 == 1)
        {
            numPartidos++;
        }
        else
        {
            break;
        }

    } while (opcion2 != 12);
}

void promedios(Partido *partido, Promedios promedio, int numPartidos)
{
    int suma;
}
void mostrarPromedios(Promedios promedio, int numPartidos)
{
    for (int i = 0; i < numPartidos; i++)
    {
        cout << "Promedio de puntos: " << promedio.promPts[i] << endl;
        cout << "Promedio de puntos en contra: " << promedio.pptsAgainst[i] << endl;
        cout << "Promedio de sets ganados: " << promedio.promSetsWon[i] << endl;
        cout << "Promedio de sets perdidos: " << promedio.promSetsLost[i] << endl;
        cout << "Promedio de aces: " << promedio.promAce[i] << endl;
        cout << "Promedio de errores: " << promedio.promErrors[i] << endl;
        cout << "Promedio de recepciones exitosas: " << promedio.promSucessfulRecep[i] << endl;
        cout << "Promedio de ataques exitosos: " << promedio.promSuccesfulAtacks[i] << endl;
        cout << "Promedio de bloqueos: " << promedio.promBlocks[i] << endl;
        cout << "Promedio de faltas: " << promedio.promFaults[i] << endl;
    }
}

void mostrarPartidos(Partido partido, int numPartidos)
{
    for (int i = 0; i < numPartidos; i++)
    {
        cout << "Jaguares vs " << partido.namepartido << endl;
        cout << "Partido: " << partido.namepartido << endl;
        cout << "Puntos: " << partido.pts[i] << endl;
        cout << "Puntos en contra: " << partido.ptsAgainst[i] << endl;
        cout << "Sets ganados: " << partido.setsWon[i] << endl;
        cout << "Sets perdidos: " << partido.setsLost[i] << endl;
        cout << "Aces: " << partido.ace[i] << endl;
        cout << "Errores: " << partido.errors[i] << endl;
        cout << "Recepciones exitosas: " << partido.sucessfulRecep[i] << endl;
        cout << "Ataques exitosos: " << partido.succesfulAtacks[i] << endl;
        cout << "Bloqueos: " << partido.blocks[i] << endl;
        cout << "Faltas: " << partido.faults[i] << endl;
    }
}