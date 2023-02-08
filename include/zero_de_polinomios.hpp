#pragma once

#include "zero_de_funcoes.hpp"
#include <cstddef>

extern "C" {
struct Polinomio {
  double *addr;
  size_t size;
};

struct ResultadoHorner {
  double polinomio, derivada;
};

ResultadoHorner horner(Polinomio, const double x);

_func_sig birgeVieta(const int nIteracoes, double x, Polinomio polinomio);
}
