#include <iostream>
#include <string.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <chrono>
#include <fstream> // Add this line
#include "fectch.cpp"
#include "titles.cpp"
#include "variablesProyecto.h"

#define CURRENT_YEAR 2024
using namespace std;
/*Programa para pedir estadisticas de volleyball, promediar, mostrar promedios y estadisticas,
buscar, eliminar y editar estadisticas. */

// Variables gloables
StatsGames stats[MAX_PARTIDOS];
USERS users[MAX_USERS];
Promedios prom;
int pos = 0;
int positionUser = 0; 
// Declaracion de funcionesde manejo de archivos
int loadData();
int loadUser();
void writeData(const StatsGames &stadistics);
void saveAll();
void loadPromedio();
void writePromedio(const Promedios &promedio);

// Declaracion de funciones de manejo de datos
void addGame(StatsGames *game);
void uppdateGame(StatsGames *game, int id);
int findID(int id);
StatsGames findGames(int id);
void deleteGame(int id);
void showData(StatsGames &game);
void userMenu();
void principal();
void showDate(StatsGames *game);
void getDate(StatsGames *game);
void findDate(StatsGames *game);

void getUsers(USERS *users);
void validateUser();

// Funciones de salidas
void usersMenu();
void menu();
void getStats();
void findGame();
void show_All_Stats();
void getPromedios();
void showStats();
void showPromedios();
void showGame();
void editGame();
void delete_Game_Data();
int getUsuario(int usuario, int password);

void clearstdin()
{
    fflush(stdin);
    fflush(stdout);
}

// funcion para agregar un partido

void addGame(StatsGames *game)
{
    stats[pos] = *game;
    pos++;
}

// funcion para buscar un partido
int findID(int id)
{
    for (int i = 0; i < pos; i++)
    {
        if (stats[i].id == id)
        {
            return i;
        }
    }
    return -1;
}
StatsGames findGames(int id)
{
    StatsGames game;
    for (int i = 0; i < pos; i++)
    {
        if (stats[i].id == id)
        {
            return stats[i];
        }
    }
    return game;
}

// funcion para actualizar un partido
void uppdateGame(StatsGames *game, int id)
{
    int position = findID(id);
    stats[position].rival = game->rival;
    stats[position].day = game->day;
    stats[position].month = game->month;
    stats[position].year = game->year;
    stats[position].pts = game->pts;
    stats[position].ptsAgainst = game->ptsAgainst;
    stats[position].setsWon = game->setsWon;
    stats[position].setsLost = game->setsLost;
    stats[position].ace = game->ace;
    stats[position].errors = game->errors;
    stats[position].sucessfulRecep = game->sucessfulRecep;
    stats[position].succesfulAtacks = game->succesfulAtacks;
    stats[position].blocks = game->blocks;
    stats[position].faults = game->faults;
}

// funcion para eliminar un partido
void deleteGame(int id)// funcion para eliminar un partido mediante el id y la creacion de un nuevo fichero temporal
{
    ofstream fileStats("VolleyMetricStats.txt");
    if (!fileStats.is_open())
    {
        cout << ANSI_COLOR_RED "No se pudo abrir el archivo" << ANSI_COLOR_RESET << endl;
        exit(1);
    }
    for (int i = 0; i < pos; i++)
    {
        if (stats[i].id != id)
        {
            fileStats << stats[i].id << endl;
            fileStats << stats[i].rival << endl;
            fileStats << stats[i].day << endl;
            fileStats << stats[i].month << endl;
            fileStats << stats[i].year << endl;
            fileStats << stats[i].pts << endl;
            fileStats << stats[i].ptsAgainst << endl;
            fileStats << stats[i].setsWon << endl;
            fileStats << stats[i].setsLost << endl;
            fileStats << stats[i].ace << endl;
            fileStats << stats[i].errors << endl;
            fileStats << stats[i].sucessfulRecep << endl;
            fileStats << stats[i].succesfulAtacks << endl;
            fileStats << stats[i].blocks << endl;
            fileStats << stats[i].faults << endl;
        }
    }
    fileStats.close();
    pos--;
}

// MENU
void menu()
{
    
    

    int option;
    do
    {
        system("clear || cls");
        
        pos = loadData();
        cout << "=================Menu=================" << endl;
        cout << "1. Ingresar estadisticas" << endl;
        cout << "2. Mostrar todas las estadisticas" << endl;
        cout << "3. Buscar partido " << endl;
        cout << "4. Promedio de estadisticas del equipo" << endl;
        cout << "5. Editar estadisticas" << endl;
        cout << "6. Eliminar partido" << endl;
        cout << "7. Cerrar sesion" << endl;
    
        cout << "Ingrese una opcion: ";
        cin >> option;
        switch (option)
        {
        case 1:
            system("clear || cls");
            getStats();
            system("pause");

            break;
        case 2:
            system("clear || cls");
            show_All_Stats();
            system("pause");

            break;
        case 3:
            system("clear || cls");
            findGame();
            system("pause");

            break;
        case 4:
            loadPromedio();
            system("clear || cls");
            showPromedios();
            system("pause");

            break;
        case 5:
            system("clear || cls");
            editGame();
            system("pause");

            break;
        case 6:
            system("clear || cls");
            delete_Game_Data();
            system("pause");
            break;
        case 7:
            cout << "Cerrando sesión..." << endl;

            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (option != 7);
}
// agregar estadisticas
void getStats()
{

    StatsGames game;
    cout << "Estadisticas del partido" << endl;
    cout << "Ingrese el rival: ";
    cin >> game.rival;
    cout << "Ingrese la fecha en la que se jugo el partido\n";
    cout << "Dia: ";
    fetch_input_day(game.day);
    if (game.day > 31 || game.day < 1)
    {
        cout << "Ingrese un dia valido" << endl;
        return getStats();
    }
    cout << "Mes: ";
    fetch_input_day(game.month);
    if (game.month > 12 || game.month < 1)
    {
        cout << "Ingrese un mes valido" << endl;
        return getStats();
    }

    cout << "Año(xxxx): ";
    fetch_input_year(game.year);
    if (game.year > 2025 && game.year < 2000)
    {
        cout << "Ingrese un año valido" << endl;
        return getStats();
    }

    cout << "Ingrese un id para guardar(maximo 4 caracteres): ";
    fetch_input(game.id); // Funcion para obtener el id con maximo de caracteres, ver "fectch.cpp"

    if (findID(game.id) != -1)
    {
        cout << "El id ya existe" << endl;
        return getStats();
    }
    cout << "Ingrese las estadisticas de Jaguares vs " << game.rival << endl;
    cout << "Puntos anotados: ";
    cin >> game.pts;

    cout << "Puntos en contra: ";
    cin >> game.ptsAgainst;

    cout << "Sets ganados: ";
    cin >> game.setsWon;

    cout << "Sets perdidos: ";
    cin >> game.setsLost;

    cout << "Aces: ";
    cin >> game.ace;

    cout << "Errores: ";
    cin >> game.errors;

    cout << "Recepciones exitosas: ";
    cin >> game.sucessfulRecep;

    cout << "Ataques exitosos: ";
    cin >> game.succesfulAtacks;

    cout << "Bloqueos: ";
    cin >> game.blocks;

    cout << "Faltas: ";
    cin >> game.faults;
    cout << endl;
    addGame(&game);
    cout << ANSI_COLOR_GREEN "Estadisticas guardadas correctamente..." << ANSI_COLOR_RESET << endl;
    writeData(game);
}

// mostrar estadisticas del partido
void show_All_Stats()
{
    for (int i = 0; i < pos; i++)
    {
        cout << "Estadisticas del partido Jaguares vs " << stats[i].rival << endl;
        showData(stats[i]);
        cout << "=================================" << endl;
    }
}

void findGame()
{
    int id = 0;
    cout << "Ingrese el ID del partido: ";
    cin >> id;
    if (findID(id) == -1)
    {
        cout << ANSI_COLOR_RED "No se encontro el partido" << ANSI_COLOR_RESET << endl;
        ;
        return;
    }
    else
    {

        StatsGames game = findGames(id);
        int x = findID(id);
        system("clear || cls");
        cout << ANSI_COLOR_GREEN << "Partido encontrado" << ANSI_COLOR_RESET << endl;
        cout << "Estadisticas del partido Jaguares vs " << stats[x].rival << endl;
        showData(game);
    }
}

void showData(StatsGames &game)
{
    if (game.id == 0)
    {
        cout << "No hay datos" << endl;
        return;
    }
    cout << "ID: " << game.id << endl;
    if(game.pts < 60){
        cout << ANSI_COLOR_RED << "Puntos anotados: " << game.pts << ANSI_COLOR_RESET << endl;
    }
    else if(game.pts >= 60 && game.pts >= 70){
        cout << ANSI_COLOR_YELLOW<< "Puntos anotados: " << game.pts << ANSI_COLOR_RESET << endl;
    }
    else if (game.pts > 70){
        cout << ANSI_COLOR_GREEN << "Puntos anotados: " << game.pts << ANSI_COLOR_RESET << endl;
    }

    if(game.ptsAgainst < 60){
        cout << ANSI_COLOR_GREEN << "Puntos en contra: " << game.ptsAgainst << ANSI_COLOR_RESET << endl;
    }
    else if(game.ptsAgainst >= 60 && game.ptsAgainst >= 70){
        cout << ANSI_COLOR_YELLOW << "Puntos en contra: " << game.ptsAgainst << ANSI_COLOR_RESET << endl;
    }
    else if (game.ptsAgainst > 70){
        cout << ANSI_COLOR_RED << "Puntos en contra: " << game.ptsAgainst << ANSI_COLOR_RESET << endl;
    }


    if(game.setsWon <= 2){
        cout << ANSI_COLOR_RED << "Sets ganados: " << game.setsWon << ANSI_COLOR_RESET << endl;
    }
    else if (game.setsWon >= 3){
        cout << ANSI_COLOR_GREEN << "Sets ganados: " << game.setsWon << ANSI_COLOR_RESET << endl;
    }

    if(game.setsLost <= 2){
        cout << ANSI_COLOR_GREEN << "Sets perdidos: " << game.setsLost << ANSI_COLOR_RESET << endl;
    }
    else if (game.setsLost >= 3){
        cout << ANSI_COLOR_RED << "Sets perdidos: " << game.setsLost << ANSI_COLOR_RESET << endl;
    }

    if(game.ace < 5){
        cout << ANSI_COLOR_RED << "Aces: " << game.ace << ANSI_COLOR_RESET << endl;
    }
    else if (game.ace >= 5 && game.ace <= 10){
        cout << ANSI_COLOR_YELLOW << "Aces: " << game.ace << ANSI_COLOR_RESET << endl;
    }
    else if (game.ace > 10){
        cout << ANSI_COLOR_GREEN << "Aces: " << game.ace << ANSI_COLOR_RESET << endl;
    }

    if(game.errors < 5){
        cout << ANSI_COLOR_GREEN << "Errores: " << game.errors << ANSI_COLOR_RESET << endl;
    }
    else if (game.errors >= 5 && game.errors <= 10){
        cout << ANSI_COLOR_YELLOW << "Errores: " << game.errors << ANSI_COLOR_RESET << endl;
    }
    else if (game.errors > 10){
        cout << ANSI_COLOR_RED << "Errores: " << game.errors << ANSI_COLOR_RESET << endl;
    }

    if(game.sucessfulRecep < 50){
        cout << ANSI_COLOR_RED << "Recepciones exitosas: " << game.sucessfulRecep << ANSI_COLOR_RESET << endl;
    }
    else if (game.sucessfulRecep >= 50 && game.sucessfulRecep <= 70){
        cout << ANSI_COLOR_YELLOW << "Recepciones exitosas: " << game.sucessfulRecep << ANSI_COLOR_RESET << endl;
    }
    else if (game.sucessfulRecep > 70){
        cout << ANSI_COLOR_GREEN << "Recepciones exitosas: " << game.sucessfulRecep << ANSI_COLOR_RESET << endl;
    }

    if(game.succesfulAtacks < 50){
        cout << ANSI_COLOR_RED << "Ataques exitosos: " << game.succesfulAtacks << ANSI_COLOR_RESET << endl;
    }
    else if (game.succesfulAtacks >= 50 && game.succesfulAtacks <= 70){
        cout << ANSI_COLOR_YELLOW << "Ataques exitosos: " << game.succesfulAtacks << ANSI_COLOR_RESET << endl;
    }
    else if (game.succesfulAtacks > 70){
        cout << ANSI_COLOR_GREEN << "Ataques exitosos: " << game.succesfulAtacks << ANSI_COLOR_RESET << endl;
    }

    if(game.blocks < 5){
        cout << ANSI_COLOR_RED << "Bloqueos: " << game.blocks << ANSI_COLOR_RESET << endl;
    }
    else if (game.blocks > 5){
        cout << ANSI_COLOR_GREEN << "Bloqueos: " << game.blocks << ANSI_COLOR_RESET << endl;
    }

    if(game.faults < 5){
        cout << ANSI_COLOR_GREEN << "Faltas: " << game.faults << ANSI_COLOR_RESET << endl;
    }
    else if (game.faults >= 5 && game.faults <= 8){
        cout << ANSI_COLOR_YELLOW << "Faltas: " << game.faults << ANSI_COLOR_RESET << endl;
    }
    else if (game.faults > 8){
        cout << ANSI_COLOR_RED << "Faltas: " << game.faults << ANSI_COLOR_RESET << endl;
    }

}

void editGame()
{
    StatsGames game;
    int id;
    int optionEdit;
    cout << "Ingrese el ID del partido a editar: ";
    cin >> id;
    clearstdin();
    if (findID(id) == -1)
    {
        cout << "No se encontro el partido" << endl;
        return;
    }
    cout << "Datos del partido" << endl;
    cout << "Estadisticas del partido" << endl;
    showData(stats[findID(id)]);
    cout << "Desea Editar el partido? 1. Si 2. No: ";
    cin >> optionEdit;
    if (optionEdit == 2)
    {
        return;
    }
    clearstdin();
    system("clear || cls");
    cout << "Ingrese el rival: ";
    cin >> game.rival;
    cout << "Ingrese la fecha en la que se jugo el partido\n";
    cout << "Dia: ";
    cin >> game.day;
    cout << "Mes: ";
    cin >> game.month;
    cout << "Año: ";
    cin >> game.year;
    cout << "Puntos anotados: ";
    cin >> game.pts;
    clearstdin();
    cout << "Puntos en contra: ";
    cin >> game.ptsAgainst;

    cout << "Sets ganados: ";
    cin >> game.setsWon;

    cout << "Sets perdidos: ";
    cin >> game.setsLost;

    cout << "Aces: ";
    cin >> game.ace;
    clearstdin();
    cout << "Errores: ";
    cin >> game.errors;

    cout << "Recepciones exitosas: ";
    cin >> game.sucessfulRecep;

    cout << "Ataques exitosos: ";
    cin >> game.succesfulAtacks;

    cout << "Bloqueos: ";
    cin >> game.blocks;

    cout << "Faltas: ";
    cin >> game.faults;
    cout << endl;
    uppdateGame(&game, id);
    cout << ANSI_COLOR_GREEN "Estadisticas actualizadas..." << ANSI_COLOR_RESET << endl;
    writeData(game);
}

void delete_Game_Data()
{
    int id = 0;
    int option_Eliminar;
    
    if (pos == 0)
    {
        cout << "No hay partidos para eliminar" << endl;
        return;
    }
    
    cout << "Ingrese el id del partido a eliminar: ";
    cin >> id;
    showData(stats[findID(id)]);
    if (findID(id) == -1)
    {
        cout << ANSI_COLOR_RED "No se encontro el partido" << ANSI_COLOR_RESET << endl;
        return;
    }
    cout << "Desea eliminar el partido? 1. Si 2. No: ";
    cin >> option_Eliminar;
    
    deleteGame(id);
}

void getPromedios()
{
    if (pos == 0)
    {
        cout << ANSI_COLOR_RED << "No hay partidos para promediar" << ANSI_COLOR_RESET << endl;
        return;
    }
    prom.sumPts = 0;
    prom.sumPtsAgainst = 0;
    prom.sumSetsWon = 0;
    prom.sumSetsLost = 0;
    prom.sumAce = 0;
    prom.sumErrors = 0;
    prom.sumSucessfulRecep = 0;
    prom.sumSuccesfulAtacks = 0;
    prom.sumBlocks = 0;
    prom.sumFaults = 0;

    for (int i = 0; i < pos; i++)
    {
        prom.sumPts += stats[i].pts;
        prom.sumPtsAgainst += stats[i].ptsAgainst;
        prom.sumSetsWon += stats[i].setsWon;
        prom.sumSetsLost += stats[i].setsLost;
        prom.sumAce += stats[i].ace;
        prom.sumErrors += stats[i].errors;
        prom.sumSucessfulRecep += stats[i].sucessfulRecep;
        prom.sumSuccesfulAtacks += stats[i].succesfulAtacks;
        prom.sumBlocks += stats[i].blocks;
        prom.sumFaults += stats[i].faults;
    }

    prom.promPts = prom.sumPts / pos;
    prom.pptsAgainst = prom.sumPtsAgainst / pos;
    prom.promSetsWon = prom.sumSetsWon / pos;
    prom.promSetsLost = prom.sumSetsLost / pos;
    prom.promAce = prom.sumAce / pos;
    prom.promErrors = prom.sumErrors / pos;
    prom.promSucessfulRecep = prom.sumSucessfulRecep / pos;
    prom.promSuccesfulAtacks = prom.sumSuccesfulAtacks / pos;
    prom.promBlocks = prom.sumBlocks / pos;
    prom.promFaults = prom.sumFaults / pos;
}

void showPromedios()
{

    getPromedios();
    cout << "Promedio de estadisticas del equipo" << endl;
    //Promedio de puntos anotados 
    if(prom.promPts < 60){
        cout << ANSI_COLOR_RED << "Promedio de puntos anotados: " << prom.promPts <<"%" ANSI_COLOR_RESET << endl;
    }
    else if(prom.promPts >= 60 && prom.promPts >= 70){
        cout << ANSI_COLOR_YELLOW<< "Promedio de puntos anotados: " << prom.promPts << "%"ANSI_COLOR_RESET << endl;
    }
    else if (prom.promPts > 70){
        cout << ANSI_COLOR_GREEN << "Promedio de puntos anotados: " << prom.promPts << "%" ANSI_COLOR_RESET << endl;
    }
    //Promedio de puntos en contra
    if(prom.pptsAgainst < 60){
        cout << ANSI_COLOR_GREEN << "Promedio de puntos en contra: " << prom.pptsAgainst << "%" ANSI_COLOR_RESET << endl;
    }
    else if(prom.pptsAgainst >= 60 && prom.pptsAgainst >= 70){
        cout << ANSI_COLOR_YELLOW << "Promedio de puntos en contra: " << prom.pptsAgainst << "%" ANSI_COLOR_RESET << endl;
    }
    else if (prom.pptsAgainst > 70){
        cout << ANSI_COLOR_RED << "Promedio de puntos en contra: " << prom.pptsAgainst <<"%"  ANSI_COLOR_RESET << endl;
    }
    //Promedio de sets ganados
    if(prom.promSetsWon <= 2){
        cout << ANSI_COLOR_RED << "Promedio de sets ganados: " << prom.promSetsWon << "%" ANSI_COLOR_RESET << endl;
    }
    else if (prom.promSetsWon >= 3){
        cout << ANSI_COLOR_GREEN << "Promedio de sets ganados: " << prom.promSetsWon << "%" ANSI_COLOR_RESET << endl;
    }
    //Promedio de sets perdidos
    if(prom.promSetsLost <= 2){
        cout << ANSI_COLOR_GREEN << "Promedio de sets perdidos: " << prom.promSetsLost << "%" ANSI_COLOR_RESET << endl;
    }
    else if (prom.promSetsLost >= 3){
        cout << ANSI_COLOR_RED << "Promedio de sets perdidos: " << prom.promSetsLost << "%"ANSI_COLOR_RESET << endl;
    }
    //Promedio de aces
    if(prom.promAce < 5){
        cout << ANSI_COLOR_RED << "Promedio de aces: " << prom.promAce << "%" ANSI_COLOR_RESET << endl;
    }
    else if (prom.promAce >= 5 && prom.promAce <= 10){
        cout << ANSI_COLOR_YELLOW << "Promedio de aces: " << prom.promAce <<"%" ANSI_COLOR_RESET << endl;
    }
    else if (prom.promAce > 10){
        cout << ANSI_COLOR_GREEN << "Promedio de aces: " << prom.promAce << "%" ANSI_COLOR_RESET << endl;
    }
    //Promedio de errores
    if(prom.promErrors < 5){
        cout << ANSI_COLOR_GREEN << "Promedio de errores: " << prom.promErrors << ANSI_COLOR_RESET << endl;
    }
    else if (prom.promErrors >= 5 && prom.promErrors <= 10){
        cout << ANSI_COLOR_YELLOW << "Promedio de errores: " << prom.promErrors << ANSI_COLOR_RESET << endl;
    }
    else if (prom.promErrors >= 10){
        cout << ANSI_COLOR_RED << "Promedio de errores: " << prom.promErrors << ANSI_COLOR_RESET << endl;
    }
    //Promedio de recepciones exitosas
    if(prom.promSucessfulRecep < 50){
        cout << ANSI_COLOR_RED << "Promedio de recepciones exitosas: " << prom.promSucessfulRecep << ANSI_COLOR_RESET << endl;
    }
    else if (prom.promSucessfulRecep >= 50 && prom.promSucessfulRecep <= 70){
        cout << ANSI_COLOR_YELLOW << "Promedio de recepciones exitosas: " << prom.promSucessfulRecep << ANSI_COLOR_RESET << endl;
    }
    else if (prom.promSucessfulRecep > 70){
        cout << ANSI_COLOR_GREEN << "Promedio de recepciones exitosas: " << prom.promSucessfulRecep << ANSI_COLOR_RESET << endl;
    }
    //Promedio de ataques exitosos
    if(prom.promSuccesfulAtacks < 50){
        cout << ANSI_COLOR_RED << "Promedio de ataques exitosos: " << prom.promSuccesfulAtacks << ANSI_COLOR_RESET << endl;
    }
    else if (prom.promSuccesfulAtacks >= 50 && prom.promSuccesfulAtacks <= 70){
        cout << ANSI_COLOR_YELLOW << "Promedio de ataques exitosos: " << prom.promSuccesfulAtacks << ANSI_COLOR_RESET << endl;
    }
    else if (prom.promSuccesfulAtacks > 70){
        cout << ANSI_COLOR_GREEN << "Promedio de ataques exitosos: " << prom.promSuccesfulAtacks << ANSI_COLOR_RESET << endl;
    }
    //Promedio de bloqueos
    if(prom.promBlocks < 5){
        cout << ANSI_COLOR_RED << "Promedio de bloqueos: " << prom.promBlocks << ANSI_COLOR_RESET << endl;
    }
    else if (prom.promBlocks >= 5){
        cout << ANSI_COLOR_GREEN << "Promedio de bloqueos: " << prom.promBlocks << ANSI_COLOR_RESET << endl;
    }
    //Promedio de faltas
    if(prom.promFaults <= 3){
        cout << ANSI_COLOR_GREEN << "Promedio de faltas: " << prom.promFaults << ANSI_COLOR_RESET << endl;
    }
    else if (prom.promFaults >= 5 && prom.promFaults <= 10){
        cout << ANSI_COLOR_YELLOW << "Promedio de faltas: " << prom.promFaults << ANSI_COLOR_RESET << endl;
    }
    else if (prom.promFaults > 10){
        cout << ANSI_COLOR_RED << "Promedio de faltas: " << prom.promFaults << ANSI_COLOR_RESET << endl;
    }

}

int loadData()
{
    ifstream fileStats("VolleyMetricStats.txt");
    if (!fileStats)
    {
        ofstream fileStats("VolleyMetricPromedio.txt", ios::out);
    }else{
        cout<< ANSI_COLOR_GREEN "Cargando datos..." ANSI_COLOR_RESET << endl; 
    }

    int i = 0;
    while (fileStats >> stats[i].id)
    {
        fileStats.ignore();
        getline(fileStats, stats[i].rival);
        fileStats >> stats[i].day;
        fileStats >> stats[i].month;
        fileStats >> stats[i].year;
        fileStats >> stats[i].pts;
        fileStats >> stats[i].ptsAgainst;
        fileStats >> stats[i].setsWon;
        fileStats >> stats[i].setsLost;
        fileStats >> stats[i].ace;
        fileStats >> stats[i].errors;
        fileStats >> stats[i].sucessfulRecep;
        fileStats >> stats[i].succesfulAtacks;
        fileStats >> stats[i].blocks;
        fileStats >> stats[i].faults;
        i++;
    }
    fileStats.close();
    return i;
}

void writeData(const StatsGames &stadistics)
{
    ofstream fileStats("VolleyMetricStats.txt", ios::app);
    if (!fileStats.is_open())
    {
        cout << ANSI_COLOR_RED "No se pudo abrir el archivo" << ANSI_COLOR_RESET << endl;
        exit(1);
    }

    fileStats << stadistics.id << endl;
    fileStats << stadistics.rival << endl;
    fileStats << stadistics.day << endl;
    fileStats << stadistics.month << endl;
    fileStats << stadistics.year << endl;
    fileStats << stadistics.pts << endl;
    fileStats << stadistics.ptsAgainst << endl;
    fileStats << stadistics.setsWon << endl;
    fileStats << stadistics.setsLost << endl;
    fileStats << stadistics.ace << endl;
    fileStats << stadistics.errors << endl;
    fileStats << stadistics.sucessfulRecep << endl;
    fileStats << stadistics.succesfulAtacks << endl;
    fileStats << stadistics.blocks << endl;
    fileStats << stadistics.faults << endl;

    fileStats.close();
}

void loadPromedio()
{

    ifstream filePromedio("VolleyMetricPromedio.txt");
    if (!filePromedio)
    {
        ofstream filepromedio("VolleyMetricPromedio.txt");
    }else{
        cout<< ANSI_COLOR_GREEN "Cargando datos..." ANSI_COLOR_RESET << endl; 
    }
    while (filePromedio >> prom.sumPts)
    {
        filePromedio >> prom.promPts;
        filePromedio >> prom.pptsAgainst;
        filePromedio >> prom.promSetsWon;
        filePromedio >> prom.promSetsLost;
        filePromedio >> prom.promErrors;
        filePromedio >> prom.promSuccesfulAtacks;
        filePromedio >> prom.promSucessfulRecep;
        filePromedio >> prom.promBlocks;
        filePromedio >> prom.promFaults;
    }

    filePromedio.close();
}

void writePromedio(const Promedios &promedio)
{
    ofstream filePromedio("VolleyMetricPromedio.txt");
    if (!filePromedio.is_open())
    {
        cout << ANSI_COLOR_RED "No se pudo abrir el archivo" << ANSI_COLOR_RESET << endl;
        
    }

    filePromedio << promedio.sumPts << endl;
    filePromedio << promedio.sumPtsAgainst << endl;
    filePromedio << promedio.sumSetsWon << endl;
    filePromedio << promedio.sumSetsLost << endl;
    filePromedio << promedio.sumAce << endl;
    filePromedio << promedio.sumErrors << endl;
    filePromedio << promedio.sumSucessfulRecep << endl;
    filePromedio << promedio.sumSuccesfulAtacks << endl;
    filePromedio << promedio.sumBlocks << endl;
    filePromedio << promedio.sumFaults << endl;

    filePromedio.close();
}
void saveAll()
{
    ofstream fileStats("VolleyMetricStats.txt", ios::app);
    if (!fileStats.is_open())
    {
        cout << ANSI_COLOR_RED "No se pudo abrir el archivo" << ANSI_COLOR_RESET << endl;
        exit(1);
    }

    for (int i = 0; i < pos; i++)
    {

        fileStats << stats[i].id << endl;
        fileStats << stats[i].rival << endl;
        fileStats << stats[i].day << endl;
        fileStats << stats[i].month << endl;
        fileStats << stats[i].year << endl;
        fileStats << stats[i].pts << endl;
        fileStats << stats[i].ptsAgainst << endl;
        fileStats << stats[i].setsWon << endl;
        fileStats << stats[i].setsLost << endl;
        fileStats << stats[i].ace << endl;
        fileStats << stats[i].errors << endl;
        fileStats << stats[i].sucessfulRecep << endl;
        fileStats << stats[i].succesfulAtacks << endl;
        fileStats << stats[i].blocks << endl;
        fileStats << stats[i].faults << endl;
    }
    fileStats.close();
}

int loadUser(USERS *users, int &positionUser) {
    ifstream fileUsers("users.txt");
    
    if (!fileUsers)
    {
        cout <<  "Creando archivo..." << endl;
        ofstream fileUsers("users.txt", ios::out);
    }
    

    if (!fileUsers.is_open()) {
        cout << "No se pudo abrir el archivo de usuarios" << endl;
        return 0; // Retornar un valor de error o manejar de otra manera
    }
    
   
    cout << "Archivo de usuarios cargado correctamente" << endl;

    int i = 0;
    while (fileUsers >> users[i].usernameP >> users[i].passwordP) {
        i++;
    }

    fileUsers.close();
    return i;
}

void addUser(USERS *users, int &positionUser) {
    ofstream fileUsers("users.txt", ios::app);

    if (!fileUsers.is_open() || !fileUsers) {
        cout << "El archivo no existe o hubo un problema..." << endl;
        exit(1);
    }

    fileUsers << users[positionUser].usernameP << " " << users[positionUser].passwordP << endl;

    positionUser++;

    fileUsers.close();
}

void getUser(USERS *users, int &positionUser) {
    cout << "Ingrese un nuevo usuario..." << endl;
    cout << "Ingrese su usuario: ";
    fetch_input(users[positionUser].usernameP);
    cout << "Ingrese su contraseña: ";
    fetch_input_password(users[positionUser].passwordP);
    addUser(users, positionUser);
}

void validateUser(USERS *users, int &positionUser) {
    string usernameInput, passwordInput;

    cout << "Ingrese su usuario: ";
    fetch_input(usernameInput);
    cout << "Ingrese su contraseña: ";
    fetch_input_password(passwordInput);
    

    for (int i = 0; i < positionUser; i++) {
        if (users[i].usernameP == usernameInput && users[i].passwordP == passwordInput) {
            cout << "Usuario validado correctamente" << endl;
            cout << "Ingresando..." << endl;
            Sleep(4000);
            menu();
            return;
        }
    }

    cout << "Usuario o contraseña incorrectos" << endl;
}

void usersMenu() {
    int option;
    positionUser = loadUser(users, positionUser);
    printWelcomeAnimation();
    
    loadUser(users, positionUser);
    do {
        system("cls"); 
        cout << "1. Ingresar usuario" << endl;
        cout << "2. Nuevo Usuario" << endl;
        cout << "3. Salir"<< endl;
        cout << "Ingrese una opcion: ";
        cin >> option;

        switch (option) {
            case 1:
                if(positionUser == 0){
                    cout << "No hay usuarios registrados" << endl;
                    getUser(users, positionUser);
                    Sleep(2000);
                }
                else{
                    validateUser(users, positionUser);
                    
                }
                break;
            case 2:
                getUser(users, positionUser);

                Sleep(2000);
                break;
            case 3: 
                cout << "Adios, mi tierno <3"; 
                break;
           
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    } while (option != 3);
}