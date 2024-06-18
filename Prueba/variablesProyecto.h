#include <iostream>

#include <string> 

using namespace std; 


#define MAX_PARTIDOS 100

struct Partido{
    string namepartido;
    string date; 
    int gamesPlayed;
    int pts[MAX_PARTIDOS];
    int ptsAgainst[MAX_PARTIDOS];
    int setsWon[MAX_PARTIDOS];
    int setsLost[MAX_PARTIDOS];
    int ace[MAX_PARTIDOS];
    int errors[MAX_PARTIDOS];
    int sucessfulRecep[MAX_PARTIDOS];
    int succesfulAtacks[MAX_PARTIDOS];
    int blocks[MAX_PARTIDOS];
    int faults[MAX_PARTIDOS];
};

//estructura para promedios de un equipo 
struct Promedios{
    float promPts[MAX_PARTIDOS];
    float pptsAgainst[ MAX_PARTIDOS];
    float promSetsWon[ MAX_PARTIDOS];
    float promSetsLost[ MAX_PARTIDOS];
    float promAce[ MAX_PARTIDOS];
    float promErrors[ MAX_PARTIDOS];
    float promSucessfulRecep[MAX_PARTIDOS];
    float promSuccesfulAtacks[MAX_PARTIDOS];
    float promBlocks[MAX_PARTIDOS];
    float promFaults[MAX_PARTIDOS];
    float sumPts;
    float sumPtsAgainst;
    float sumSetsWon;
    float sumSetsLost;
    float sumAce;
    float sumErrors;
    float sumSucessfulRecep;
    float sumSuccesfulAtacks;
    float sumBlocks;
    float sumFaults;
    float promedioPts;
}; 





