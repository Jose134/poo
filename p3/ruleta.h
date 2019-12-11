#ifndef RULETA_H
#define RULETA_H

#include "jugador.h"
#include "crupier.h"

#include <list>
#include <string>

#include <cstdlib>
#include <ctime>

class Ruleta {
    private:
        int banca_;
        int bola_;
        std::list<Jugador> jugadores_;
        Crupier crupier_;

        std::string getColor(int bola);
    public:
        Ruleta (Crupier crupier) : crupier_(crupier) {
            srand(time(NULL));
            banca_ = 1000000;
            bola_ = -1;
        }

        int getBanca () const { return banca_; }
        bool setBanca (int banca) { 
            if (banca >= 0) {
                banca_ = banca;
                return true;
            }
            return false;
        } 
        
        int getBola () const { return bola_; }
        bool setBola (int bola) {
            if (bola >= 0 && bola <= 36) {
                bola_ = bola;
                return true;
            }
            return false;
        }

        Crupier getCrupier () const { return crupier_; }
        void setCrupier (Crupier crupier) { crupier_ = crupier; }

        std::list<Jugador> getJugadores () const { return jugadores_; }
        bool addJugador(Jugador jugador);
        int deleteJugador(std::string dni);
        int deleteJugador(Jugador jugador);
        void escribeJugadores() const;
        void leeJugadores();
    
        void giraRuleta () { bola_ = rand() % 37; }

        void getPremios();
};

#endif