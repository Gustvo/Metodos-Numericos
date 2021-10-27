#include "zero_de_polinomios.hpp"

ResultadoHorner horner(Polinomio polinomio, const double x) {
  double resultado = polinomio.front();
  double derivada, anterior;
  derivada = anterior = resultado;
  for (int i = 1; i < polinomio.size(); ++i) {
    resultado = polinomio[i] + resultado * x;
    if (polinomio.data() + i == &polinomio.back()) [[unlikely]]
      derivada = anterior + derivada * x;
    anterior = resultado;
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
