#include "aproximacao_de_funcoes.hpp"
#include "exemplos.hpp"
#include "sistemas_lineares.hpp"
#include "zero_de_funcoes.hpp"
#include "zero_de_polinomios.hpp"
#include <cmath>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>

template <typename T> std::pair<std::vector<T>, int> lerEntrada() {
  int tamanhoMatriz;
  std::vector<T> mtr;
  T entrada;
  std::cin >> tamanhoMatriz;
  std::cin.ignore();
  for (int i = 0; i < tamanhoMatriz; ++i) {
    for (int j = 0; j < tamanhoMatriz + 1; ++j) {
      std::cin >> entrada;
      mtr.push_back(entrada);
    }
    std::cin.ignore();
  }

  return {mtr, tamanhoMatriz};
}

void testaGauss(std::pair<std::vector<double>, int> entrada) {
  int tamanhoMatriz = entrada.second;
  std::vector<double> matrizExtendida = entrada.first;

  try {
    std::vector<double> resultado(tamanhoMatriz);
    gauss(matrizExtendida.data(), tamanhoMatriz, resultado.data());
    std::cout << "Gauss: { ";
    for (auto x : resultado)
      std::cout << x << " ";
    std::cout << "}ᵀ\n";
  } catch (std::exception &e) {
    std::cerr << "Erro: " << e.what() << std::endl;
  }
}

void testaLU(std::pair<std::vector<double>, int> entrada) {
  int tamanhoMatriz = entrada.second;
  auto matrizExtendida = entrada.first;

  try {
    std::vector<double> resultado(tamanhoMatriz);
    lu(matrizExtendida.data(), tamanhoMatriz, resultado.data());
    std::cout << "LU: { ";
    for (auto x : resultado)
      std::cout << x << " ";
    std::cout << "}ᵀ\n";
  } catch (std::exception &e) {
    std::cerr << "Erro: " << e.what() << std::endl;
  }
}

int main(int nargs, char **cargs) {
  Configuracao config = {.unidadeDeTempo = microsegundos,
                         .numeroDeCasasDecimais = 14,
                         .numeroDeRepeticoesParaCronometragem = 10000};

  if (nargs > 1)
    config.numeroDeCasasDecimais = std::stoi(cargs[1]);

  std::cout << std::setprecision(config.numeroDeCasasDecimais);

  // calculaEImprimeExemplos(config);

  auto entrada = lerEntrada<double>();

  // testaLU(entrada); // { 4 2 4 }ᵀ
  //  testaGauss(entrada);
  //
  std::vector<double> x = {1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<double> y = {0.5, 0.6, 0.9, 0.8, 1.2, 1.5, 1.7, 2.0};
  const auto ordem = 2;
  std::vector<double> resultado(ordem + 1);
  minimos_quadrados(ordem, x.size(), x.data(), y.data(), resultado.data());

  for (auto i : resultado)
    std::cout << i << std::endl;

  return EXIT_SUCCESS;
}
