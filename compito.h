//
// Created by Giacomo Cunardi on 18/12/2024.
//

#ifndef COMPITO_H
#define COMPITO_H
#include <iostream>

using namespace std;

class Wordle {
    int n;
    int max_t;
    int t;
    char* parola;
    char* ultima_parola;
    bool gioco_avviato = false;
public:
    Wordle(int n, int max_t);
    bool avvia_gioco(char* sequenza);
    bool indovina(char* tentativo);
    friend ostream& operator<<(ostream&, const Wordle&);
    /*
    ~Wordle();
    bool stampa_storico(os);
    friend ostream& operator-=(ostream&, const Wordle&);
    friend ostream& operator=(ostream&, const Wordle&);
    */
};



#endif //COMPITO_H
