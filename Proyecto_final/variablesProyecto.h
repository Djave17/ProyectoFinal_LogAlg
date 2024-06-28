#include <iostream>

#include <string> 

using namespace std; 

// Definiciones de códigos de escape ANSI para colores de texto

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_WHITE   "\x1b[37m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BOLD    "\x1b[1m"
#define ANSI_COLOR_UNDERLINE "\x1b[4m"
#define ANSI_COLOR_BACKGROUND_RED "\x1b[41m"
#define ANSI_COLOR_BACKGROUND_GREEN "\x1b[42m"
#define ANSI_COLOR_BACKGROUND_YELLOW "\x1b[43m"
#define ANSI_COLOR_BACKGROUND_BLUE "\x1b[44m"
#define ANSI_COLOR_BACKGROUND_MAGENTA "\x1b[45m"
#define ANSI_COLOR_BACKGROUND_CYAN "\x1b[46m"
#define ANSI_COLOR_BACKGROUND_WHITE "\x1b[47m"

#define MAX_PARTIDOS 100
#define MAX_USERS 100

typedef struct StatsGames{
    string rival;
    int day;
    int month;
    int year;
    int id; 
    string date;
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



struct USERS{
    string usernameP;
    string passwordP;
    string username;
    string password;

};

