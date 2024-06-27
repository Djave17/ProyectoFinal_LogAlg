#include <iostream>
#include <conio.h>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

int main() {
    char password[17]; 
    int i = 0;
    cout << "Bienvenido a la plataforma de control de partidos de los jaguares UAM" << endl;
    cout << "Ingrese su usuario: ";
    string usuario;
    cin >> usuario;
    cout << "Usuario: " << usuario << endl;
    cout << "Ingrese su contraseña: ";
    while (true) { 
        password[i] = getch(); 
        if (password[i] == '\r') { 
            password[i] = '\0'; 
            break; 
        } else if (password[i] == '\b') { 
            if (i > 0) {
                i--; 
                cout << "\b \b"; 
            }
        } else {
            cout << "*"; 
            i++;
        }
    }

    int len = strlen(password);
    if (len < 4) {
        cout << "La contraseña debe tener al menos 4 caracteres." << endl;
        return 1;
        
    } else if (len > 16) {
        cout << "La contraseña debe tener menos de 16 caracteres." << endl;
        return 1;
    }

    /*Crear un archivo para el usuario*/

    string archivo_usuario = usuario + ".txt";
    ofstream archivo(archivo_usuario.c_str());
    
    if (archivo.is_open()) {
        cout << "Archivo creado con éxito para el usuario " << usuario << endl;
        archivo << "Bienvenido " << usuario << "!" << endl;
        archivo.close();
    } else {
        cout << "Error al crear el archivo para el usuario " << usuario << endl;
    }

    return 0;
}