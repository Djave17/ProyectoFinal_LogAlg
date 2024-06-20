#include <iostream>
#include <string.h>
#include <ctime> 
#include <curses.h>
#include "variablesProyecto.h"

using namespace std;
/*Programa para pedir estadisticas de volleyball, promediar, mostrar promedios y estadisticas,
buscar, eliminar y editar estadisticas. */

StatsGames stats[MAX_PARTIDOS];
Promedios prom;
int pos = 0; 
//Declaracion de funciones de comodidad
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
    strcpy(stats[position].rival, game->rival);
    strcpy(stats[position].day, game->day);
    strcpy(stats[position].month, game->month);
    strcpy(stats[position].year, game->year);
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

//funcion para eliminar un partido
void deleteGame(int id){
    int position = findID(id);
    for (int i = position; i < pos; i++){
        stats[i] = stats[i+1];
    }
    StatsGames g;
    stats[pos -1] = g;
    pos--;
}


//MENU
void menu(){
    int option;
    do{
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
    /*cout << endl;
    cout << "Ingrese la fecha: ";
    scanf(" %[^\n]", game. date);*/
    cout << "Ingrese la fecha en la que se jugo el partido\n";
    cout << "Dia: ";
    cin >> game.day;
    cout << "Mes: ";
    cin >> game.month;
    cout << "Año: ";
    cin >> game.year;
   
    cout << "Ingrese un id para guardar(maximo 8 caracteres): ";
    cin >> game.id;
    
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
    cout << "Estadisticas guardadas..." << endl;
    
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
        cout << "No se encontro el partido" << endl;
        return;
    }
    StatsGames game = findGames(id);
    int x = findID(id);
    cout << "Estadisticas del partido Jaguares vs " << stats[x].rival<< endl;
    showData(game);
    
}

void showData(StatsGames &game){
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
    cout << "Ingrese el id del partido a editar: ";
    cin >> id;
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
    system("clear || cls");
    cout << "Ingrese las estadisticas de Jaguares vs " << game. rival << endl;
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
    uppdateGame(&game, id);
    cout << "Estadisticas actualizadas..." << endl;
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
        cout << "No se encontro el partido" << endl;
        return;
    }
    deleteGame(id);
    cout << "Partido eliminado..." << endl;
}

void getPromedios(){

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
    
    
}

void showPromedios(){

    getPromedios();
    cout << "Promedio de puntos anotados: " << prom.promPts << endl;
    cout << "Promedio de puntos en contra: " << prom.pptsAgainst << endl;
    cout << "Promedio de sets ganados: " << prom.promSetsWon << endl;
    cout << "Promedio de sets perdidos: " << prom.promSetsLost << endl;
    cout << "Promedio de aces: " << prom.promAce << endl;
    cout << "Promedio de errores: " << prom.promErrors << endl;
    cout << "Promedio de recepciones exitosas: " << prom.promSucessfulRecep << endl;
    cout << "Promedio de ataques exitosos: " << prom.promSuccesfulAtacks << endl;
    cout << "Promedio de bloqueos: " << prom.promBlocks << endl;
    cout << "Promedio de faltas: " << prom.promFaults << endl;
}
//Funcion para introducir fecha en la que se jugó el partido

