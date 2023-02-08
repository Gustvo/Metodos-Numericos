#include "zero_de_funcoes.hpp"

#include <cmath>

_func_sig secante(const double eps1, const double eps2, double x0, double x1,
                  Funcao f) {
  double x, xAnterior, xAnterior2;
  int iteracoes = 0;

  if (std::abs(f(x0)) < eps2)
    return {x0, iteracoes};

  if (std::abs(f(x1)) < eps2)
    return {x1, iteracoes};

  if (std::abs(x1 - x0) < eps1)
    return {x1, iteracoes};

  x = x1;
  xAnterior = x0;
  do {
    xAnterior2 = xAnterior;
    xAnterior = x;
    x = (xAnterior2 * f(xAnterior) - xAnterior * f(xAnterior2)) /
        (f(xAnterior) - f(xAnterior2));
    iteracoes++;
  } while (std::abs(x - xAnterior) >= eps2 && std::abs(f(x)) >= eps1);

  return {x, iteracoes};
}

_func_sig secante(const int maxIteracoes, double x0, double x1, Funcao f) {
  double x, xAnterior, xAnterior2;
  int iteracoes = 0;

  x = x1;
  xAnterior = x0;
  do {
    xAnterior2 = xAnterior;
    xAnterior = x;
    x = (xAnterior2 * f(xAnterior) - xAnterior * f(xAnterior2)) /
        (f(xAnterior) - f(xAnterior2));
    iteracoes++;
  } while (iteracoes < maxIteracoes);

  return {x, iteracoes};
}
