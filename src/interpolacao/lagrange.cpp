#include "interpolacao.hpp"

#include <vector>

double interpolacaoLagrange(const unsigned int numeroDePontos,
                            double *c_abscissas, double *c_ordenadas,
                            double pontoAInterpolar) {
  std::vector<double> abscissas(c_abscissas, c_abscissas + numeroDePontos);
  std::vector<double> ordenadas(c_ordenadas, c_ordenadas + numeroDePontos);

  double resultado = 0;

  for (auto i = 0; i < numeroDePontos; ++i) {
    double l = 1;
    for (auto j = 0; j < numeroDePontos; ++j) {
      if (i == j)
        continue;

      l *= (pontoAInterpolar - abscissas[j]) / (abscissas[i] - abscissas[j]);
    }
    resultado += l * ordenadas[i];
  }

  return resultado;
}
