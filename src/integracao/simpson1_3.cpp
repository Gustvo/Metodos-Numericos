#include "integracao.hpp"

double simpson13Repetida(Funcao func, double limiteInferior,
                         double limiteSuperior, int divisoes) {
  double resultado = 0;
  double h = (limiteSuperior - limiteInferior) / divisoes;

  for (auto i = 0; i <= divisoes; ++i) {
    if (i == 0 || i == divisoes) {
      resultado += func(limiteInferior + i * h);
      continue;
    }
    if (i % 2 == 0)
      resultado += 2 * func(limiteInferior + i * h);
    else
      resultado += 4 * func(limiteInferior + i * h);
  }
  return h / 3 * resultado;
}
