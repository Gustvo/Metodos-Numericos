#include "interpolacao.hpp"
#include <iostream>
#include <vector>

std::vector<double> diferencaDividida(std::vector<double> x,
                                      std::vector<double> y) {
  std::vector<double> fs;
  fs.push_back(y[0]);

  while (y.size() != 1) {
    std::vector<double> novoY = {};
    for (auto i = 0; i < y.size() - 1; ++i) {

      novoY.push_back((y[i + 1] - y[i]) /
                      (x[i + x.size() - y.size() + 1] - x[i]));
    }
    fs.push_back(novoY[0]);
    y = novoY;
  }
  return fs;
}

double interpolacaoNewton(const unsigned int numeroDePontos,
                          double *c_abscissas, double *c_ordenadas,
                          double pontoAInterpolar) {
  std::vector<double> abscissas(c_abscissas, c_abscissas + numeroDePontos);
  std::vector<double> ordenadas(c_ordenadas, c_ordenadas + numeroDePontos);

  auto fs = diferencaDividida(abscissas, ordenadas);

  double resultado = 0;
  for (auto i = 0; i < fs.size(); ++i) {
    double termo = fs[i];
    for (auto j = 0; j < i; ++j)
      termo *= pontoAInterpolar - abscissas[j];

    resultado += termo;
  }

  return resultado;
}
