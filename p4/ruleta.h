#ifndef RULETA_H
#define RULETA_H

#include "jugador.h"
#include "crupier.h"

#include <list>
#include <string>

#include <cstdlib>
#include <ctime>

//Represents a casino roulette
class Ruleta {
    private:
        int banca_;
        int bola_;
        std::list<Jugador> jugadores_;
        Crupier crupier_;

        std::string getColor(int bola); //Helper: Gets the color associated to the given number

        //State Tracking
        int lanzamientos_;

    public:
        //Constructor
        Ruleta (const Crupier& crupier) : crupier_(crupier) {
            srand(time(NULL));
            banca_ = 1000000;
            bola_ = -1;
            lanzamientos_ = 0;
        }

        int getBanca () const { return banca_; } //Returns bank's money
        bool setBanca (int banca) {              //Sets bank's money (checks if the given amount is >= 0)
            if (banca >= 0) {
                banca_ = banca;
                return true;
            }
            return false;
        } 
        
        int getBola () const { return bola_; } //Returns ball's number
        bool setBola (int bola) {              //Sets ball's number (checks for valid range)
            if (bola >= 0 && bola <= 36) {
                bola_ = bola;
                lanzamientos_++;
                return true;
            }
            return false;
        }

        Crupier getCrupier () const { return crupier_; }          //Returns roulette's croupier
        void setCrupier (Crupier crupier) { crupier_ = crupier; } //Sets roulette's croupier

        std::list<Jugador> getJugadores () const { return jugadores_; } //Returns a list of all players
        bool addJugador(Jugador jugador);   //Adds a player to the list
        int deleteJugador(std::string dni); //Removes a player from the list (given player's DNI)
        int deleteJugador(Jugador jugador); //Removes a player from the list (given player's instance)
        void escribeJugadores() const;      //Saves all player's into a text file named "jugadores.txt"
        void leeJugadores();                //Loads all the players from the file "jugadores.txt"
    
        void giraRuleta () { //Randomizes ball's number
            bola_ = rand() % 37;
            lanzamientos_++;
        } 

        void getPremios(); //Reads all the bets done by the players and updates player's and bank's money

        void getEstado(int& jugadores, int& dinero, int& lanzamientos, int& beneficio) const; //Returns information about the roulette's current state
};

#endif