#include "contador.h"

Contador Contador::operator= (int x) {
    valor_ = x;
    RangeValue();

    hist_.push_back(valor_);

    return *this;
}

Contador Contador::operator= (const Contador &c) {
    valor_ = c.get();
    setMin(c.getMin());
    setMax(c.getMax());

    hist_.push_back(valor_);

    return *this;
}

Contador Contador::operator++ (void) {
    valor_++;
    RangeValue();

    hist_.push_back(valor_);

    return *this;
}

Contador Contador::operator++ (int) {
    Contador aux = *this;

    valor_++;
    RangeValue();
    hist_.push_back(valor_);

    return aux;
}

Contador Contador::operator-- (void) {
    valor_--;
    RangeValue();

    hist_.push_back(valor_);

    return *this;
}

Contador Contador::operator-- (int) {
    Contador aux = *this;

    valor_--;
    RangeValue();
    hist_.push_back(valor_);

    return aux;
}

Contador Contador::operator+ (int x) {
    valor_ += x;
    RangeValue();

    hist_.push_back(valor_);

    return *this;
}

Contador operator+ (int x, const Contador &c) {
    Contador aux(c);

    int res = x + aux.get();
    aux = res;
    return aux;
}

Contador Contador::operator- (int x) {
    valor_ -= x;
    RangeValue();

    hist_.push_back(valor_);

    return *this;
}

Contador operator- (int x, const Contador &c) {
    Contador aux(c);

    int res = x - aux.get();
    aux = res;
    return aux;
}

