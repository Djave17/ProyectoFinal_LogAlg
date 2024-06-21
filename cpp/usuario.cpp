#include <iostream>
#include <conio.h>

using namespace std;

#define MIN 4
#define MAX 16

int main(int argc, char const *argv[])
{
    /* code */
    char password[MAX + 1]; 
    int i = 0;
    cout << "Bienvenido a la plataforma de control de partidos de los jaguares UAM" << endl;
    cout << "Ingrese su usuario: ";
    string usuario;
    cin >> usuario;
    cout << "Usuario: " << usuario << endl;
    cout << "Ingrese su contraseña: ";
    while ((password[i] = getch()) != '\r') { 
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

    // Verificar longitud de contraseña
    if (i < MIN) {
        cout << "La contraseña debe tener al menos " << MIN << " caracteres." << endl;
        return 1;
    }

    if (i > 0) {
        cout << "Contraseña válida. Bienvenido!" << endl;
    } else {
        cout << "Contraseña inválida. Intente nuevamente." << endl;
        return 1;
    }

    return 0;
}
