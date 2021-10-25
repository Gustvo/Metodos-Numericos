#include "zero_de_funcoes.hpp"
#include <cmath>

std::pair<double, int> posicao_falsa(Intervalo intervalo, const double eps1, const double eps2,
                     Funcao f) {
  int iteracoes = 0;
  double xmed;
  while (std::abs(intervalo.b - intervalo.a) >= eps1 &&
         std::abs(f(xmed)) >= eps2) {
    double y1 = f(intervalo.a);
    double y2 = f(intervalo.b);
    double y1abs = std::abs(y1);
    double y2abs = std::abs(y2);
    xmed = (intervalo.a * y2abs + intervalo.b * y1abs) / (y1abs + y2abs);
    double ymed = f(xmed);
    if (y1 * ymed < 0)
      intervalo.b = xmed;
    else
      intervalo.a = xmed;
    iteracoes++;
  }
  return { xmed, iteracoes };
}
