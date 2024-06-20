#include <iostream>
#include <conio.h>

using namespace std;

int main() {
    char password[8]; 
    int i = 0;
    cout << "Bienvenido a la plataforma de control de partidos de los jaguares UAM" << endl;
    cout << "Ingrese su usuario: ";
    string usuario;
    cin >> usuario;
    cout << "Usuario: " << usuario << endl;
    cout << "Ingrese su contraseña: ";
    while ((password[i] = getch())!= '\r') { 
        if (password[i] == '\b') { 
            if (i > 0) {
                i--; 
                cout << "\b \b"; 
            }
        } else {
            cout << "*"; 
            i++;
        }
    }
    password[i] = '\0'; 
    return 0;
}