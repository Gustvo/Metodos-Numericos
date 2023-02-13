#include "integracao.hpp"

double trapezioRepetida(Funcao func, double limiteInferior,
                        double limiteSuperior, int divisoes) {
  double h = (limiteSuperior - limiteInferior) / divisoes;
  double resultado = 0;

  for (auto i = 0; i <= divisoes; ++i) {
    if (i == 0 || i == divisoes) {
      resultado += func(limiteInferior + i * h);
      continue;
    }

    resultado += 2 * func(limiteInferior + i * h);
  }

  return resultado * h / 2;
}
