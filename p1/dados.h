#ifndef DADOS_H
#define DADOS_H
//dados.h
//Declares the Dados class

#include <vector>

class Dados {
  private:
    int d1_;
    int d2_;

    int lanz1_;
    int lanz2_;

    int sum1_;
    int sum2_;

    std::vector<int> hist1;
    std::vector<int> hist2;

  public:
    Dados();
    void lanzamiento();
    int getDado1();
    int getDado2();
    bool setDado1(int n);
    bool setDado2(int n);
    int getLanzamientos1();
    int getLanzamientos2();
    int getSuma();
    int getDiferencia();
    float getMedia1();
    float getMedia2();
    void getUltimos1(int v[]);
    void getUltimos2(int v[]);
};

#endif
