#include "zero_de_funcoes.hpp"

_func_sig bisseccao(Intervalo intervalo, const double eps, Funcao f) {
  double xmed = (intervalo.a + intervalo.b)/2;
  int iteracoes = 0;
  while (std::abs(intervalo.b - intervalo.a) > eps) {
    // Esta função assume que existe raiz no intervalo dado, e que a
    // afirmação "f(a)*f(b) < 0" seja verdadeira para os parâmetros iniciais.
    xmed = (intervalo.a + intervalo.b) / 2;
    double y1 = f(intervalo.a);
    double ymed = f(xmed);

    if (y1 * ymed < 0)
      intervalo.b = xmed;
    else
      intervalo.a = xmed;
    iteracoes++;
  }
  return {xmed, iteracoes};
}
