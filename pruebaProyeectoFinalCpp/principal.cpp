#include <iostream>
#include <locale.h>
#include "funciones.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "spanish");
    principal();
    return 0;
}
