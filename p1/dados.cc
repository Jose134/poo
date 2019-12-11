#include "dados.h"
#include <ctime>
#include <cstdlib>
//dados.cc
//Contains the bodies of the Dados class' methods

Dados::Dados () {
  srand(time(NULL));
  d1_ = 1;
  d2_ = 1;

  lanz1_ = 0;
  lanz2_ = 0;

  sum1_ = 0;
  sum2_ = 0;

  int a =5;

  hist1 = std::vector<int>(5, 0);
  hist2 = std::vector<int>(5, 0);
}

void Dados::lanzamiento () {
  d1_ = rand() % 5 + 1;
  d2_ = rand() % 5 + 1;

  lanz1_++;
  lanz2_++;

  sum1_ += d1_;
  sum2_ += d2_;

  hist1.push_back(d1_);
  hist1.erase(hist1.begin());

  hist2.push_back(d2_);
  hist2.erase(hist2.begin());
}

int Dados::getDado1 () {
  return d1_;
}

int Dados::getDado2 () {
  return d2_;
}

bool Dados::setDado1 (int n) {
  if (n >= 1 && n <= 6) {
    d1_ = n;

    lanz1_++;
    sum1_ += n;
    hist1.push_back(d1_);
    hist1.erase(hist1.begin());

    return true;
  }

  return false;
}

bool Dados::setDado2 (int n) {
  if (n >= 1 && n <= 6) {
    d2_ = n;

    lanz2_++;
    sum2_ += n;
    hist2.push_back(d2_);
    hist2.erase(hist2.begin());

    return true;
  }

  return false;
}

int Dados::getLanzamientos1 () {
  return lanz1_;
}

int Dados::getLanzamientos2 () {
  return lanz2_;
}

int Dados::getSuma () {
  return (d1_ + d2_);
}

int Dados::getDiferencia () {
  return abs(d1_ - d2_);
}

float Dados::getMedia1 () {
  if (lanz1_ == 0) { return 0; }
  return (float)sum1_ / lanz1_;
}

float Dados::getMedia2 () {
  if (lanz2_ == 0) { return 0; }
  return (float)sum2_ / lanz2_;
}

void Dados::getUltimos1 (int v[]) {
  for (int i = 0; i < 5; i++) {
    v[i] = hist1[hist1.size() - 1 - i];
  }
}

void Dados::getUltimos2 (int v[]) {
  for (int i = 0; i < 5; i++) {
    v[i] = hist2[hist2.size() - 1 - i];
  }
}
