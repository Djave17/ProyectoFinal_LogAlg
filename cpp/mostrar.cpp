#include <iostream>
using namespace std;

void menu() {
    cout << "Porcentaje de partidos jugados por los jaguares \n";
    cout << "---------------------------\n";
    cout << "1. Partido Jaguares vs Leonas : 45 votos\n";
    cout << "2. Partido Jaguares vs UNANM: 30 votos\n";
    cout << "3. Partido Jaguares vs Panteras : 20 votos\n";
    cout << "4. Partido Jaguares vs UNI : 12 votos\n";
    cout << "5. Salir del programa\n";
}

void calcularPorcentaje(int votos, int total) {
    float porcentaje = (float)votos / total * 100;
    cout << "Porcentaje: " << porcentaje << "%" << endl;
}

int main() {
    int eleccion, totalVotos = 107; // nota: la suma de los votos es 107, no 100
    do {
        menu();
        cout << "Ingrese su opción: ";
        cin >> eleccion;

        switch (eleccion) {
            case 1:
                calcularPorcentaje(45, totalVotos);
                break;
            case 2:
                calcularPorcentaje(30, totalVotos);
                break;
            case 3:
                calcularPorcentaje(20, totalVotos);
                break;
            case 4:
                calcularPorcentaje(12, totalVotos);
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción incorrecta. Intente de nuevo." << endl;
        }
    } while (eleccion != 5);

    return 0;
}