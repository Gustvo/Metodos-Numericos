#include "integracao.hpp"

double simpson38Repetida(Funcao func, double limiteInferior,
                         double limiteSuperior, int divisoes) {
  double h = (limiteSuperior - limiteInferior) / divisoes;

  double resultado = 0;

  for (auto i = 0; i <= divisoes; ++i) {
    if (i == 0 || i == divisoes) {
      resultado += func(limiteInferior + i * h);
      continue;
    }
    if (i % 3 == 0)
      resultado += 2 * func(limiteInferior + i * h);
    else
      resultado += 3 * func(limiteInferior + i * h);
  }

  return 3 * h / 8 * resultado;
}
