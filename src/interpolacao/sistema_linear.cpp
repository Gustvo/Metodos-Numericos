#include "interpolacao.hpp"
#include "sistemas_lineares.hpp"

#include <cmath>
#include <vector>

void interpolacaoSistemaLinear(const unsigned int numeroDePontos,
                               double *c_abscissas, double *c_ordenadas,
                               double *out_resultado) {
  std::vector<double> abscissas(c_abscissas, c_abscissas + numeroDePontos);
  std::vector<double> ordenadas(c_ordenadas, c_ordenadas + numeroDePontos);

  std::vector<double> matrizExtendida;

  for (auto i = 0; i < numeroDePontos; ++i) {
    for (auto j = 0; j < numeroDePontos; ++j)
      matrizExtendida.push_back(std::pow(abscissas[i], j));

    matrizExtendida.push_back(ordenadas[i]);
  }

  gauss(matrizExtendida.data(), numeroDePontos, out_resultado);
}
