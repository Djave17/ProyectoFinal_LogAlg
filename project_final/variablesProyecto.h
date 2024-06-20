#include <iostream>

#include <string> 

using namespace std; 


#define MAX_PARTIDOS 100

typedef struct StatsGames{
    char rival[25];
    char day[20];
    char month[20];
    char year[20];
    int date; 
    int id; 
    int gamesPlayed;
    int pts;
    int ptsAgainst;
    int setsWon;
    int setsLost;
    int ace;
    int errors;
    int sucessfulRecep;
    int succesfulAtacks;
    int blocks;
    int faults;
};

//estructura para promedios de un equipo 
struct Promedios{
    float promPts;
    float pptsAgainst;
    float promSetsWon;
    float promSetsLost;
    float promAce;
    float promErrors;
    float promSucessfulRecep;
    float promSuccesfulAtacks;
    float promBlocks;
    float promFaults;
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





