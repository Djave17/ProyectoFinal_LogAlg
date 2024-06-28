#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h> // Para getch en Windows

void clearScreen() {
    // Limpiar la pantalla dependiendo del sistema operativo
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printTitle(const std::string& title, int delay) {
    std::string whitespace(title.length(), ' ');
    for (int i = 0; i < title.length(); ++i) {
        std::cout << "\r" << title.substr(0, i + 1) << whitespace.substr(i + 1);
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    std::cout << std::endl;
}

void printWelcomeAnimation() {
    std::string welcomeTitle = "Bienvenido a VolleyMetrics";
    std::string welcomeSubtitle = "Presiona cualquier tecla para continuar";

    int delay = 100; // Milisegundos

    // Imprimir el título animado
    while (!kbhit()) { // Esperar hasta que se presione una tecla
        clearScreen();

        printTitle(welcomeTitle, delay);
        printTitle(welcomeSubtitle, delay);

        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    // Limpiar la pantalla al finalizar
    clearScreen();
}
