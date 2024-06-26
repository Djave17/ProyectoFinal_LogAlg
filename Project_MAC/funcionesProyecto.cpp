#include <iostream>
#include <string.h>
#include <ctime>
#include <unistd.h>
#include <fstream> 
#include <stdlib.h> 

#include "variablesProyecto.h"
#define MAX_SETS 3
#define CURRENT_YEAR 2024
using namespace std;
/*Programa para pedir estadisticas de volleyball, promediar, mostrar promedios y estadisticas,
buscar, eliminar y editar estadisticas. */

//Variables globales 
StatsGames stats[MAX_PARTIDOS];
Promedios prom;
int pos = 0; 

//Declaracion de funcionesde manejo de archivos
int loadData();
void writeData(const StatsGames &stadistics);
void loadPromedio(); 
void writePromedio(const Promedios &promedio);

//Declaracion de funciones de manejo de datos
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
void validateUser();



//Funciones de salidas
void menu();
void submenu();
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


void clearstdin(){
    fflush(stdin);
    fflush(stdout);
}


//funcion para agregar un partido

void addGame(StatsGames *game){
    stats[pos] = *game;	
    pos++;
   
}	

//funcion para buscar un partido
int findID(int id){
   for(int i = 0; i < pos; i++){
       if(stats[i].id == id){
        return i; 
       }
   }
   return -1;
}
StatsGames findGames(int id){
    StatsGames game;
    for(int i = 0; i < pos; i++){
        if(stats[i].id == id){
            return stats[i];
        }
    }
    return game;
}

//funcion para actualizar un partido
void uppdateGame(StatsGames *game, int id){
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
    writeData(*game);
    
    

}

//funcion para eliminar un partido
void deleteGame(int id){
    int position = findID(id);
    for (int i = position; i < pos; i++){
        stats[i] = stats[i+1];
    }
    StatsGames g;
    stats[pos -1] = g;
    pos--;
    writeData(stats[position]);
 
}


//MENU
void menu(){
    char f; 
    cout << "Bienvenido al sistema de estadisticas de volleyball" << endl;
    pos = loadData();
    
    int option;
    
    do{
        
        cin.get();
        getchar();
        system("clear || cls");
        
        cout << "=================Menu=================" << endl;
        cout << "1. Ingresar estadisticas" << endl;
        cout << "2. Mostrar todas las estadisticas" << endl;
        cout << "3. Buscar partido " << endl;
        cout << "4. Promedio de estadisticas del equipo" << endl;
        cout << "5. Editar estadisticas" << endl;
        cout << "6. Eliminar partido" << endl;
        cout << "7. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> option;
        switch(option){
            case 1:
                system("clear || cls");
                getStats();
                
                
                
                break;
            case 2:
                system("clear || cls");
                show_All_Stats();
                

                
                break;
            case 3:
                system("clear || cls");
                findGame();
                
                
                break;
            case 4:
                system("clear || cls");
                loadPromedio();
                showPromedios();
                
                
                break;
            case 5:
                system("clear || cls");
                editGame();
                
                
                break;
            case 6:
                system("clear || cls");
                delete_Game_Data();
                

                break;
            case 7:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }while(option != 7);
}
//agregar estadisticas
void getStats(){
    
    StatsGames game;

    cout << "Estadisticas del partido" << endl;
    cout << "Ingrese el rival: ";
    cin >> game.rival;


    cout << "Ingrese la fecha en la que se jugo el partido\n";
    cout << "Dia: ";
    cin >> game.day;
    if (game.day > 31 || game.day < 1){
        cout << "Ingrese un dia valido" << endl;
        return getStats();
    }
    cout << "Mes: ";
    cin >> game.month;
    if (game.month > 12 || game.month < 1)
    {
        cout << "Ingrese un mes valido" << endl;
        return getStats();
    }
    
    cout << "Año(xxxx): ";
    cin >> game.year;
    if(game.year > 2024 && game.year < 2000){
        cout << "Ingrese un año valido" << endl;
        return getStats();
    }
    


    cout << "Ingrese un id para guardar(maximo 4 caracteres): ";
    cin>> game.id; // Funcion para obtener el id con maximo de caracteres, ver "fectch.cpp"
    if (findID(game.id) != -1){
        cout << "El id ya existe" << endl;
        return getStats();
    }
    cout << "Ingrese las estadisticas de Jaguares vs " << game. rival << endl;
    cout << "Puntos anotados: ";
    cin >> game.pts;
    
    cout << "Puntos en contra: ";
    cin >> game.ptsAgainst;
    
    cout << "Sets ganados: ";
    cin >> game.setsWon;
    if (game.setsWon > MAX_SETS){
        cout << "Ingrese un valor valido" << endl;
        return getStats();
    }
    cout << "Sets perdidos: ";
    cin >> game.setsLost;
    if (game.setsLost > MAX_SETS){
        cout << "Ingrese un valor valido" << endl;
        return getStats();
    }
    
    cout << "Aces: ";
    cin >> game.ace;
    
    cout << "Errores: ";
    cin >> game.errors;
    
    cout << "Recepciones exitosas: ";
    cin >> game.sucessfulRecep;
    
    cout << "Recepciones fallidas: ";
    cin >> game.failedRecep;

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

//mostrar estadisticas del partido 
void show_All_Stats(){
    for(int i = 0; i < pos; i++){
        cout << "Estadisticas del partido Jaguares vs " << stats[i].rival<< endl;
        showData(stats[i]);
        cout << "=================================" << endl;
    }
}

void findGame(){
    int id = 0;
    cout << "Ingrese el ID del partido: ";
    cin >> id;
    if (findID(id) == -1){
        cout << ANSI_COLOR_RED "No se encontro el partido" << ANSI_COLOR_RESET << endl;
        return;
    }
    else{ 
           
        StatsGames game = findGames(id);
        int x = findID(id);
        system("clear || cls");
        cout<< ANSI_COLOR_GREEN << "Partido encontrado" << ANSI_COLOR_RESET << endl; 
        cout << "Estadisticas del partido Jaguares vs " << stats[x].rival<< endl;
        showData(game);
    }
        
    
    
}

void showData(StatsGames &game){
    if (pos == 0){
        cout << ANSI_COLOR_RED "No hay datos"<< ANSI_COLOR_RESET << endl;

        return;
    }
    cout << "ID: " << game.id << endl;
    cout << "Rival: " << game.rival << endl;
    cout << "Fecha: " << game.day << "/" << game.month << "/" << game.year << endl;
    cout << "Puntos anotados: " << game.pts << endl;
    cout << "Puntos en contra: " << game.ptsAgainst << endl;
    cout << "Sets ganados: " << game.setsWon << endl;
    cout << "Sets perdidos: " << game.setsLost << endl;
    cout << "Aces: " << game.ace << endl;
    cout << "Errores: " << game.errors << endl;
    cout << "Recepciones exitosas: " << game.sucessfulRecep << endl;
    cout << "Ataques exitosos: " << game.succesfulAtacks << endl;
    cout << "Bloqueos: " << game.blocks << endl;
    cout << "Faltas: " << game.faults << endl;
}

void editGame(){
    StatsGames game;
    int id;
    int optionEdit;
    cout << "Ingrese el ID del partido a editar: ";
    cin >> id;
    clearstdin();
    if (findID(id) == -1){
        cout << "No se encontro el partido" << endl;
        return;
    }
    cout<<"Datos del partido"<<endl;     
    cout << "Estadisticas del partido" << endl;
    showData(stats[findID(id)]);
    cout << "Desea Editar el partido? 1. Si 2. No: ";
    cin >> optionEdit;
    if (optionEdit == 2){
        return;
    }
    clearstdin();
    system("clear || cls");
    cout << "Ingrese el rival: ";
    cin >> game.rival;
    cout << "Ingrese la fecha en la que se jugo el partido\n";
    cout << "Dia: ";
    if(game.day > 31 || game.day < 1){
        cout << "Ingrese un dia valido" << endl;
        return getStats();
    }
    cin >> game.day;
    cout << "Mes: ";
    if(game.month > 12 || game.month < 1){
        cout << "Ingrese un mes valido" << endl;
        return getStats();
    }

    cin >> game.month;
    cout << "Año: ";
    if(game.year > 2025 && game.year < 2000){
        cout << "Ingrese un año valido" << endl;
        return getStats();
    }
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
    cout << ANSI_COLOR_GREEN "Estadisticas actualizadas..." << ANSI_COLOR_RESET<< endl;
    writeData(game);
}

void delete_Game_Data(){
    int id = 0;
    if (pos == 0){
        cout << "No hay partidos para eliminar" << endl;
        return;
    }
    cout << "Ingrese el id del partido a eliminar: ";
    cin >> id;
    if (findID(id) == -1){
        cout << ANSI_COLOR_RED"No se encontro el partido"  << ANSI_COLOR_RESET << endl;
        return;
    }
    deleteGame(id);
    cout << ANSI_COLOR_GREEN "Partido eliminado correctamente..." <<ANSI_COLOR_RESET << endl;
    
}

void getPromedios(){
    
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

    for(int i = 0; i < pos; i++){
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

    writePromedio(prom);

}

void showPromedios(){

    if (pos == 0){
        cout <<ANSI_COLOR_RED << "No hay partidos para promediar" << ANSI_COLOR_RESET<< endl;
        return;
    }

    getPromedios();
    cout << "Promedio de puntos anotados: " << prom.promPts << "%"<< endl;
    cout << "Promedio de puntos en contra: " << prom.pptsAgainst<< "%" << endl;
    cout << "Promedio de sets ganados: " << prom.promSetsWon<< "%" << endl;
    cout << "Promedio de sets perdidos: " << prom.promSetsLost<< "%" << endl;
    cout << "Promedio de aces: " << prom.promAce << "%" << endl;
    cout << "Promedio de errores: " << prom.promErrors << "%" << endl;
    cout << "Promedio de recepciones exitosas: " << prom.promSucessfulRecep<< "%"  << endl;
    cout << "Promedio de ataques exitosos: " << prom.promSuccesfulAtacks << "%" << endl;
    cout << "Promedio de bloqueos: " << prom.promBlocks << "%" << endl;
    cout << "Promedio de faltas: " << prom.promFaults << "%" << endl;


}
//Funcion para validar usuario 
int getUsuario(int usuario, int password){
}

int loadData(){ 
    ifstream fileStats("VolleyMetricStats.txt");
    if (!fileStats.is_open()){
        cout << ANSI_COLOR_RED "No se pudo abrir el archivo, porque no hay datos que mostrar..."<< ANSI_COLOR_RESET<< endl;
        cout << ANSI_COLOR_YELLOW "Ingrese estadisticas para mostrar"<< ANSI_COLOR_RESET << endl;
        return 0;
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

void writeData(const StatsGames &stadistics){ 
    ofstream fileStats("VolleyMetricStats.txt", ios::app);
    if (!fileStats.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
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

void loadPromedio(){ 
    ifstream filePromedio("VolleyMetricPromedio.txt");
    if (!filePromedio.is_open()){
        cout << ANSI_COLOR_RED "No se pudo abrir el archivo" << ANSI_COLOR_RESET<< endl;
   
    }
    while(filePromedio >> prom.sumPts){
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

void writePromedio(const Promedios &promedio){ 
    ofstream filePromedio("VolleyMetricPromedio.txt");
    if (!filePromedio.is_open()){
        cout << ANSI_COLOR_RED "No se pudo abrir el archivo" << ANSI_COLOR_RESET<< endl;
        exit(1);
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