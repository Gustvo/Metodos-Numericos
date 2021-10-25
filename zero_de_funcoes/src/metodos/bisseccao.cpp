#include "zero_de_funcoes.hpp"

std::pair<double, int> bisseccao(Intervalo intervalo, const double eps, Funcao f) {
  double xmed;
  int iteracoes = 0;
  while (std::abs(intervalo.b - intervalo.a) > eps) {
    double y1 = f(intervalo.a);
    xmed = (intervalo.a + intervalo.b) / 2;
    double ymed = f(xmed);

    if (y1 * ymed < 0)
      intervalo.b = xmed;
    else
      intervalo.a = xmed;
    iteracoes++;
  }
  return { xmed, iteracoes };
}
