#pragma once

#include "intervalo.hpp"

extern "C" {
struct _func_sig {
  double x;
  int iteracoes;
};

typedef double (*Funcao)(double);

_func_sig bisseccao(Intervalo i, const double eps, Funcao f);

_func_sig newton_raphson(const double eps1, const double eps2, double x,
                         Funcao f, Funcao derivada);

_func_sig posicao_falsa(Intervalo i, const double eps1, const double eps2,
                        Funcao f);

_func_sig secante(const double eps1, const double eps2, double x0, double x1,
                  Funcao f);
}
