#include <iostream>
#include <conio.h>
#include <string>

#define max_integer_length 4
#define min_string_length 4
#define max_string_length 10
#define max_float_length 30
#define max_date_length 2
#define max_year_length 4


// fetch_input(string) es la mas basica de todas, deja poner cualquier letra al usuario:
void fetch_input(std::string &input_string, char mask = ' ') {

    // Estos son los codigos ASCII de BACKSPACE y ENTER (Return) que usaremos para distintas cosas
    const char BACKSPACE = 8;
    const char RETURN = 13;
    //const char ESCAPE = 27;

    input_string = "";
    const char allowed_characters[] = {' '}; // Un arreglo de caracteres permitidos, que en nuestro caso son todos
    const char disallowed_characters[] = {'>','<'}; // Esto lo he agregado para no confundir al LOAD & SAVE system
    
    // Esto se usara para determinar si un caracter esta permitido
    bool is_allowed;

    // El caracter que vamos a conseguir
    unsigned char ch = 0;

    // getch() obtiene un solo caracter del usuario y devuelve el codigo ASCII, viene incluido en <conio.h>
    ch = getch();

    // Acabamos el bucle para que el usuario introduzca datos cuando 
    while(ch != RETURN || input_string.length() <= 0) {

        if(ch == BACKSPACE) { // Si el usuario presiono BACKSPACE, hay que hacer lo siguiente:

            // Si el tamaño del string es mayor a 0
            if(input_string.length() != 0) {

                // Retrocedemos un espacio, imprimimos espacio para borrar la ultima letra,\ y regresamos de nuevo
                std::cout<<"\b \b";

                // Resizeamos el string a uno menos de su tamaño actual
                input_string.resize(input_string.length()-1);

            }

        } else if(ch == 0 || ch == 9) { // Si el caracter es vacio o TAB, usamos otro getch para ignorarlo

            ch = getch();
            continue;

        } else {

            if(allowed_characters[0] != ' ') {

                is_allowed = false;
                for(int i = 0; i < (int) (sizeof(allowed_characters) / sizeof(allowed_characters[0])); i++) { if(ch == allowed_characters[i]) { is_allowed = true; break; }}

            } else is_allowed = true;

            for(int i = 0; i < (int) (sizeof(disallowed_characters) / sizeof(disallowed_characters[0])); i++) { if(ch == disallowed_characters[i]) { is_allowed = false; break; }}
            // ^ ^ ^ Esto lo he añadido por lo que he puesto arriba lean

            if(input_string.length() >= max_string_length) is_allowed = false;
            // Poner un limite de cuantas letras se pueden poner

            if(is_allowed) {

                input_string += ch;

                if(input_string.length() != 0) {
                    if(mask == ' ') std::cout<<input_string[input_string.length()-1];
                    else std::cout<<mask;
                }

            }

        }

        // Al terminar, pasamos a que el usuario digite el siguiente caracter
        ch = getch();

    }

    // Al terminar todo esto, usamos un \n para saltar de linea como cin y scanf()
    std::cout<<"\n";

}
// fetch_input(int) tiene parametros mas estrictos como el solo permitir numeros y solo poder poner un solo caracter - al principio
void fetch_input(int &target, char mask = ' ') {

    const char BACKSPACE = 8;
    const char RETURN = 13;
    //const char ESCAPE = 27;

    const char allowed_characters[] = {'0','1','2','3','4','5','6','7','8','9','-'};
    bool is_allowed;

    std::string input_string;

    unsigned char ch = 0;

    ch = getch();
    while( ch != RETURN) {

        if(ch == BACKSPACE) {

            if(input_string.length() != 0) {

                std::cout<<"\b \b";
                input_string.resize(input_string.length()-1);

            }

        } else if(ch==0 || ch == 9) {

            ch = getch();
            continue;

        } else {

            is_allowed = false;
            for(int i = 0; i < (int) (sizeof(allowed_characters) / sizeof(allowed_characters[0])); i++) { if(ch == allowed_characters[i]) { is_allowed = true; break; }}
            if(ch == '-' && input_string.length() != 0) is_allowed = false;

            if(input_string.length() >= max_integer_length) is_allowed = false;
            // Poner un limite de cuantas letras se pueden poner

            if(is_allowed) {

                input_string += ch;

                if(input_string.length() != 0) {
                    if(mask == ' ') std::cout<<input_string[input_string.length()-1];
                    else std::cout<<mask;
                }

            }

        }

        ch = getch();

    }

    target = (input_string == "") ? 0 : stof(input_string);
    std::cout<<"\n";

}

// fetch_input(float) y fetch_input(double) son casi lo mismo si no es que verdaderamente el mismo codigo, aqui los requerimentos:
// - Solo se pueden introducir numeros, '-' y '.'
// - Solo puede introducirse el punto UNA vez
// - El caracter '-' solo puede introducirse una vez y debe ser al principio

void fetch_input_day(int &target, char mask = ' ') {

    const char BACKSPACE = 8;
    const char RETURN = 13;
    //const char ESCAPE = 27;

    const char allowed_characters[] = {'0','1','2','3','4','5','6','7','8','9','-'};
    bool is_allowed;

    std::string input_string;

    unsigned char ch = 0;

    ch = getch();
    while( ch != RETURN) {

        if(ch == BACKSPACE) {

            if(input_string.length() != 0) {

                std::cout<<"\b \b";
                input_string.resize(input_string.length()-1);

            }

        } else if(ch==0 || ch == 9) {

            ch = getch();
            continue;

        } else {

            is_allowed = false;
            for(int i = 0; i < (int) (sizeof(allowed_characters) / sizeof(allowed_characters[0])); i++) { if(ch == allowed_characters[i]) { is_allowed = true; break; }}
            if(ch == '-' && input_string.length() != 0) is_allowed = false;

            if(input_string.length() >= max_date_length) is_allowed = false;
            // Poner un limite de cuantas letras se pueden poner

            if(is_allowed) {

                input_string += ch;

                if(input_string.length() != 0) {
                    if(mask == ' ') std::cout<<input_string[input_string.length()-1];
                    else std::cout<<mask;
                }

            }

        }

        ch = getch();

    }

    target = (input_string == "") ? 0 : stof(input_string);
    std::cout<<"\n";

}
void fetch_input_year(int &target, char mask = ' ') {

    const char BACKSPACE = 8;
    const char RETURN = 13;
    //const char ESCAPE = 27;

    const char allowed_characters[] = {'0','1','2','3','4','5','6','7','8','9','-'};
    bool is_allowed;

    std::string input_string;

    unsigned char ch = 0;

    ch = getch();
    while( ch != RETURN) {

        if(ch == BACKSPACE) {

            if(input_string.length() != 0) {

                std::cout<<"\b \b";
                input_string.resize(input_string.length()-1);

            }

        } else if(ch==0 || ch == 9) {

            ch = getch();
            continue;

        } else {

            is_allowed = false;
            for(int i = 0; i < (int) (sizeof(allowed_characters) / sizeof(allowed_characters[0])); i++) { if(ch == allowed_characters[i]) { is_allowed = true; break; }}
            if(ch == '-' && input_string.length() != 0) is_allowed = false;

            if(input_string.length() >= max_year_length) is_allowed = false;
            // Poner un limite de cuantas letras se pueden poner

            if(is_allowed) {

                input_string += ch;

                if(input_string.length() != 0) {
                    if(mask == ' ') std::cout<<input_string[input_string.length()-1];
                    else std::cout<<mask;
                }

            }

        }

        ch = getch();

    }

    target = (input_string == "") ? 0 : stof(input_string);
    std::cout<<"\n";

}

void fetch_input_password(std::string &input_string, char mask = '*') {

    // Estos son los codigos ASCII de BACKSPACE y ENTER (Return) que usaremos para distintas cosas
    const char BACKSPACE = 8;
    const char RETURN = 13;
    //const char ESCAPE = 27;

    input_string = "";
    const char allowed_characters[] = {' '}; // Un arreglo de caracteres permitidos, que en nuestro caso son todos
    const char disallowed_characters[] = {'>','<'}; // Esto lo he agregado para no confundir al LOAD & SAVE system
    
    // Esto se usara para determinar si un caracter esta permitido
    bool is_allowed;

    // El caracter que vamos a conseguir
    unsigned char ch = '*';

    // getch() obtiene un solo caracter del usuario y devuelve el codigo ASCII, viene incluido en <conio.h>
    ch = getch();

    // Acabamos el bucle para que el usuario introduzca datos cuando 
    while(ch != RETURN || input_string.length() <= 0) {

        if(ch == BACKSPACE) { // Si el usuario presiono BACKSPACE, hay que hacer lo siguiente:

            // Si el tamaño del string es mayor a 0
            if(input_string.length() != 0) {

                // Retrocedemos un espacio, imprimimos espacio para borrar la ultima letra,\ y regresamos de nuevo
                std::cout<<"\b \b";

                // Resizeamos el string a uno menos de su tamaño actual
                input_string.resize(input_string.length()-1);

            }

        } else if(ch == 0 || ch == 9) { // Si el caracter es vacio o TAB, usamos otro getch para ignorarlo

            ch = getch();
            continue;

        } else {

            if(allowed_characters[0] != ' ') {

                is_allowed = false;
                for(int i = 0; i < (int) (sizeof(allowed_characters) / sizeof(allowed_characters[0])); i++) { if(ch == allowed_characters[i]) { is_allowed = true; break; }}

            } else is_allowed = true;

            for(int i = 0; i < (int) (sizeof(disallowed_characters) / sizeof(disallowed_characters[0])); i++) { if(ch == disallowed_characters[i]) { is_allowed = false; break; }}
            // ^ ^ ^ Esto lo he añadido por lo que he puesto arriba lean

            if(input_string.length() >= max_string_length) is_allowed = false;
            // Poner un limite de cuantas letras se pueden poner

            if(is_allowed) {

                input_string += ch;

                if(input_string.length() != 0) {
                    if(mask == ' ') std::cout<<input_string[input_string.length()-1];
                    else std::cout<<mask;
                }

            }

        }

        // Al terminar, pasamos a que el usuario digite el siguiente caracter
        ch = getch();

    }

    // Al terminar todo esto, usamos un \n para saltar de linea como cin y scanf()
    std::cout<<"\n";

}
// fetch_input(int) tiene parametros mas estrictos como el solo permitir numeros y solo poder poner un solo caracter - al principio
