#include<iostream>
using namespace std;
int partidosTotales=0;

main(){
    
}

void promedioBuenospuntos(){
    float promedioPuntos;
    
    int puntosTotales = 0;
    int puntosPorPartido = 0;
    cout << "Ingresa el numero de partidos totales : ";
    cin >> partidosTotales;
    for (int i = 0; i < partidosTotales; i++)
    {
        cout << "Numero de puntos en el partido numero"<<(i+1)<< ":";
        cin >>puntosPorPartido;
        puntosTotales += puntosPorPartido;
    }
    cout << "Los puntos totales sumados por todos los partidos ingresados es : "<< puntosTotales<< endl;
    promedioPuntos=puntosTotales/partidosTotales;
    cout << "El promedio de los puntos del equipo es: " <<promedioPuntos ;    
}

void promedyBadpoints (){
    float badPointspromedy ;
    int puntosEncontra;
    int bdPointsPerGame , totalBdPoints =0;
    if (partidosTotales=0)
    {
        /* code */
    }
    
    cout <<"Ingresa los puntos anotados encontra de tu equipo";
    cin >> puntosEncontra;
}

// Menu de calculos no tocar hast al final del alculo

int menu(){
    int opcion;
    cout <<"1. Calcular promedio de puntos anotados por partido\n";
    cout <<"2. Calcuar promedio de puntos encontra por partido\n";
    cout <<"3. Calcular porcentaje de de efectividad de saque (aces)\n";
    cout <<"4. Calcular efectividad de bloqueos por partido\n";
    cout <<"5. Calcular promedio de errores no forzados por partido\n";
    cout <<"6. Calcular promedio de ataques exitosos\n";
    cout <<"7. Calcular el promedio y la efectividad de la defensa\n";
    cout <<"8. Salir\n";
    cin >> opcion;
    return opcion;
}

void principal(){
    int opcion;
    do
    {
        opcion = menu();
        switch (opcion)
    {
    case 1:
    promedioBuenospuntos();
        break;
    
    default:
    cout <<" Esa opcion no esta dentro del menu!! ";
        break;
    }
    } while (opcion=!7);
    
}