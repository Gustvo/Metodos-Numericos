#pragma once

#include "zero_de_funcoes.hpp"

#include <string>
#include <vector>

using Polinomio = std::vector<double>;

struct ResultadoHorner {
  double polinomio, derivada;
};

ResultadoHorner horner(Polinomio, const double x);

_func_sig birgeVieta(const double eps1, const double eps2, double x, Polinomio polinomio);
