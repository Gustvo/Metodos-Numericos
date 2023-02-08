#include "aproximacao_de_funcoes.hpp"
#include "gauss.hpp"

#include <cmath>
#include <iostream>
#include <vector>

void minimos_quadrados(int ordem, int numeroDePontos, double *c_pontosx,
                       double *c_pontosy, double *out_resultados) {
  std::vector<double> pontosx(c_pontosx, c_pontosx + numeroDePontos);
  std::vector<double> pontosy(c_pontosy, c_pontosy + numeroDePontos);
  std::vector<double> matrizA;
  std::vector<double> matrizY;

  // Inicializa a matriz A
  for (auto i = 0; i <= ordem; ++i) {
    for (auto j = 0; j <= ordem; ++j)
      matrizA.push_back(0);
  }

  // Inicializa a matriz Y
  for (auto i = 0; i <= ordem; ++i)
    matrizY.push_back(0);

  for (auto i = 0; i <= ordem; ++i) {
    for (auto j = 0; j <= ordem; ++j) {
      for (auto k = 0; k < numeroDePontos; ++k)
        matrizA[i * (ordem + 1) + j] +=
            std::pow(pontosx[k], i) * std::pow(pontosx[k], j);
    }
    for (auto j = 0; j < numeroDePontos; ++j)
      matrizY[i] += pontosy[j] * std::pow(pontosx[j], i);
  }

  std::vector<double> matrizExtendida;

  for (auto i = 0; i <= ordem; ++i) {
    for (auto j = 0; j <= ordem; ++j) {
      matrizExtendida.push_back(matrizA[i * (ordem + 1) + j]);
    }
    matrizExtendida.push_back(matrizY[i]);
  }
  auto resultado = gauss(matrizExtendida, ordem + 1);

  for (auto i = 0; i <= ordem; ++i)
    out_resultados[i] = resultado[i];
}

