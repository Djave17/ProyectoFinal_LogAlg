#include <iostream>
#include <string>
#include "VariablesProyecto.h"

using namespace std;


void menuPrincipal();
void subMenu();
void agregarPartido(Partido *partido, int &numPartidos);
void promedios(Partido *partido, Promedios promedio, int numPartidos);
void mostrarPromedios(Promedios promedio, int numPartidos);
void mostrarPartidos(Partido partido, int numPartidos);


void menuPrincipal(){
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
            agregarPartido(partido, numPartidos);
            
            break;
        case 2:
            mostrarPromedios(promedio[MAX_PARTIDOS], numPartidos);
            break;

        case 3:
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



//sub menu de elecion de estadisticas a agreagar 
void agregarPartido(Partido *partido, int &numPartidos){
    int op2;
    int contador = 0;
    
    
    
    do
    {
        cout << "Introduzca el nombre del equipo enfrentado: ";
        cin >> partido[numPartidos].namepartido; 
        
        cout << "1. Puntos" << endl;
        cout << "2. Puntos en contra" << endl;
        cout << "3. Sets ganados" << endl;
        cout << "4. Sets perdidos" << endl;
        cout << "5. Aces" << endl;
        cout << "6. Errores" << endl;
        cout << "7. Recepciones exitosas" << endl;
        cout << "8. Ataques exitosos" << endl;
        cout << "9. Bloqueos" << endl;
        cout << "10. Faltas" << endl;
        cout << "11. Salir" << endl;
        cout << "Elija una opcion: ";
        cin>>op2; 
        switch (op2)
        {
            case 1:
                for (contador = 0; contador < numPartidos; contador++)
                {
                    cout << "Ingrese los puntos del partido Jaguares vs : "<< partido[numPartidos]. namepartido << endl;
                    cin >> partido[contador].pts[numPartidos];
                }
                
                

                break;
            case 2:
                for (contador = 0; contador < numPartidos; contador++)
                {
                    cout << "Ingrese los puntos en contra del partido: ";
                    cin >> partido[contador].ptsAgainst[numPartidos];
                }
                
                break;
            case 3:
                for (contador = 0; contador < numPartidos; contador++)
                {  
                    cout << "Ingrese los sets ganados del partido: ";
                    cin >> partido[contador].setsWon[numPartidos];
                    
                }
                break;

            case 4:
                for (contador = 0; contador < numPartidos; contador++)
                {
                    cout << "Ingrese los sets perdidos del partido: ";
                    cin >> partido[contador].setsLost[numPartidos];
                }
                break;
            
            case 5:
                for (contador = 0; contador < numPartidos; contador++)
                {
                    cout << "Ingrese los aces del partido: ";
                    cin >> partido[contador].ace[numPartidos];
                }

                break;
            
            case 6:
                for(contador = 0; contador < numPartidos; contador++)
                {
                    cout << "Ingrese los errores del partido: ";
                    cin >> partido[contador].errors[numPartidos];
                }
                break;
            
            case 7:
                for (contador = 0; contador < numPartidos; contador++)
                {
                    cout << "Ingrese las recepciones exitosas del partido: ";
                    cin >> partido[contador].sucessfulRecep[numPartidos];
                }

                break;
            
            case 8:
                for(contador = 0; contador < numPartidos; contador++)
                {
                    cout << "Ingrese los ataques exitosos del partido: ";
                    cin >> partido[contador].succesfulAtacks[numPartidos];
                }
                break;
            
            case 9:
                for(contador = 0; contador < numPartidos; contador++)
                {
                    cout << "Ingrese los bloqueos del partido: ";
                    cin >> partido[contador].blocks[numPartidos];
                }

                break;
            
            case 10:
                for(contador = 0; contador< numPartidos; contador++)
                {
                    cout << "Ingrese las faltas del partido: ";
                    cin >> partido[contador].faults[numPartidos];
                }
                break;
            
            case 11:
                cout << "Saliendo..." << endl;
                return menuPrincipal();
                break;
            numPartidos++;
            
            default:
                cout<<"Opcion no valida, vuelva a intentarlo..."<<endl; 
                break;
            }
        
     } while (op2 != 12);
        
}
  

void promedios(Partido *partido, Promedios promedio, int numPartidos){
   int suma;
   
    

}
void mostrarPromedios(Promedios promedio, int numPartidos){
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