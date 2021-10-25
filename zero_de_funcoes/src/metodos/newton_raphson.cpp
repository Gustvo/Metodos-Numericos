#include "zero_de_funcoes.hpp"
#include <cmath>

std::pair<double, int> newton_raphson(const double eps1, const double eps2,
                                      double x, Funcao f, Funcao derivada) {
  double xAnterior;
  int iteracoes = 0;
  if (std::abs(f(x)) < eps2)
    return {x, iteracoes};

  do {
    xAnterior = x;
    x = xAnterior - f(xAnterior) / derivada(xAnterior);
    iteracoes++;
  } while (std::abs(x - xAnterior) >= eps2 && std::abs(f(x)) >= eps1);

  return {x, iteracoes};
}
