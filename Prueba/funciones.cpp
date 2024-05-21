#include <iostream> 
using namespace std; 

//Pedir al usuario partidos jugados, puntos en cada partidos y set y puntos recibidos, devolver puntos totales,
//promedio de puntos por partido y promedio de puntos recibidos por partido
void pedirDatos(int& partidos, int& puntos, int& puntosRecibidos){
    cout << "Ingrese la cantidad de partidos jugados: ";
    cin >> partidos;
    for(int i = 0; i < partidos; i++){
        cout << "Ingrese la cantidad de puntos obtenidos en el partido " << i + 1 << ": ";
        cin >> puntos; 
        cout << "Ingrese la cantidad de puntos recibidos en el partido " << i + 1 << ": ";
        cin >> puntosRecibidos;
    }

}
void calcularPuntos(int partidos, int puntos, int puntosRecibidos, int& puntosTotales, float& promedioPuntos, float& promedioPuntosRecibidos){
    puntosTotales = puntos;
    promedioPuntos = puntos / partidos;
    promedioPuntosRecibidos = puntosRecibidos / partidos;
}

void mostrarResultados(int puntosTotales, float promedioPuntos, float promedioPuntosRecibidos){
    cout << "Puntos totales: " << puntosTotales << endl;
    cout << "Promedio de puntos por partido: " << promedioPuntos << endl;
    cout << "Promedio de puntos recibidos por partido: " << promedioPuntosRecibidos << endl;
}

int main() {
    int partidos, puntos, puntosRecibidos, puntosTotales;
    float promedioPuntos, promedioPuntosRecibidos;

    pedirDatos(partidos, puntos, puntosRecibidos);
    calcularPuntos(partidos, puntos, puntosRecibidos, puntosTotales, promedioPuntos, promedioPuntosRecibidos);
    mostrarResultados(puntosTotales, promedioPuntos, promedioPuntosRecibidos);

    return 0;
}