#include "zero_de_polinomios.hpp"

ResultadoHorner horner(Polinomio coeficientes, const double x) {
  double resultado, derivada;
  resultado = derivada = coeficientes[0];
  for (int i = 1; i < coeficientes.size(); ++i) {
    resultado = coeficientes[i] + resultado * x;
    if (&coeficientes[i] != &coeficientes.back()) [[likely]]
      derivada = resultado + derivada * x;
  }

  return {resultado, derivada};
}

_func_sig birgeVieta(const double eps1, const double eps2, double x,
                     Polinomio polinomio) {
  double xAnterior;
  int iteracoes = 0;
  auto resultado = horner(polinomio, x);
  if (std::abs(resultado.polinomio) < eps2)
    return {x, iteracoes};

  do {
    xAnterior = x;
    resultado = horner(polinomio, x);
    x = xAnterior - resultado.polinomio / resultado.derivada;
    iteracoes++;
  } while (std::abs(x - xAnterior) >= eps2 &&
           std::abs(resultado.polinomio) >= eps1);

  return {x, iteracoes};
}

_func_sig birgeVieta(const int nIteracoes, double x,
                     Polinomio polinomio) {
  double xAnterior;
  auto resultado = horner(polinomio, x);

  for (int i = 0; i < nIteracoes; ++i) {
    xAnterior = x;
    resultado = horner(polinomio, x);
    x = xAnterior - resultado.polinomio / resultado.derivada;
  }
  return {x, nIteracoes};
}
