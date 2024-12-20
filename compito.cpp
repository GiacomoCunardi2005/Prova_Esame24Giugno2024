//
// Created by Giacomo Cunardi on 18/12/2024.
//

#include "compito.h"
#include <cstring>
#include <iostream>

using namespace std;

Wordle::Wordle(int n, int max_t) {
    if (n <= 0) {
        this->n = 5;
    }else{this->n = n;}

    if (max_t <= 0) {
        this->max_t = 6;
    }else{this->max_t = max_t;}

    this->t = max_t;
}

bool Wordle::avvia_gioco(char* sequenza) {
    if (!gioco_avviato) {
        gioco_avviato = true;
        const int n  = strlen(sequenza);
        for (int i = 0; i < n; i++) {
            toupper(sequenza[i]);
        }
        strcpy(this->parola, sequenza);
        return true;
    }else {
        return false;
    }
}

bool Wordle::indovina(char* tentativo) {
    if (gioco_avviato) {
        if (strlen(tentativo) > n) {
//////////////////////////////////////////////////////////////////////
            return false;
        }else{
            if (strlen(tentativo) == n) {
                for (int i = 0; i < n; i++) {
                    toupper(tentativo[i]);
                }
                --t;
                if ((strcmp(tentativo, parola) == 0) && t >= 0) {
                    gioco_avviato = false;
                }
                ultima_parola = tentativo;
            }
            else {
                return false;
            }
        }
        return true;
    }else{
        return false;
    }
}

ostream& operator<<(ostream& juj, const Wordle& w){
    if (w.t != w.max_t) {
        cout << "Ultima parola indovinata: ";
        for (int i = 0; i < w.n; i++) {
            cout << w.ultima_parola[i];
        }
        cout << endl;


        if (w.ultima_parola == w.parola || w.t <= 0) {
            if (w.ultima_parola == w.parola) {
                cout << "Hai vinto" << endl;
            }if (w.t <= 0){
                cout << "Hai perso, tentativi finiti" << endl;
            }
        }

        cout << "Risultato: ";
        for (int i = 0; i < w.n; i++) {
            if (w.ultima_parola[i]== w.parola[i] ) {
                cout << "S";
            }
            else
            {
                bool lettera_trovata = false;
                for (int j = 0; j < w.n; j++)
                {
                    if (w.ultima_parola[i] == w.parola[j])
                    {
                        cout << "?";
                        lettera_trovata = true;
                        break;
                    }
                }
                if (!lettera_trovata) {
                    cout << "N";
                }
            }
        }
        cout << endl;
        cout << "Tentativi rimasti: " << w.t << endl;
    }else{
        cout << "Nessun Tentativo" << endl;
    }
    return juj;
}
