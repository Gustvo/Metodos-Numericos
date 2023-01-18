#include "exemplos.hpp"
#include "zero_de_funcoes.hpp"
#include "zero_de_polinomios.hpp"
#include "gauss.hpp"
#include "lu.hpp"
#include <exception>
#include <iomanip>
#include <iostream>
#include <fstream>


std::pair<std::vector<float>, int> lerEntrada() {
  int tamanhoMatriz;
  std::vector<float> mtr;
  float entrada;
  std::cin >> tamanhoMatriz; std::cin.ignore();
  for (int i = 0; i < tamanhoMatriz; ++i) {
    for (int j = 0; j < tamanhoMatriz+1; ++j) {
      std::cin >> entrada;
      mtr.push_back(entrada);
    }
    std::cin.ignore();
  }

  return {mtr, tamanhoMatriz};
}

void testaGauss() {
  auto entrada = lerEntrada();

  int tamanhoMatriz = entrada.second;
  std::vector<float> matrizExtendida = entrada.first;

  try{
    auto resultado = gauss(matrizExtendida, tamanhoMatriz);
    std::cout << "{ ";
    for (auto x : resultado)
      std::cout << x << " ";
    std::cout << "}\n";
  } catch (std::exception& e) {
    std::cerr << "Erro: " << e.what() << std::endl;
  }
  
}

void testaLU() {
  auto entrada = lerEntrada();

  int tamanhoMatriz = entrada.second;
  std::vector<float> matrizExtendida = entrada.first;

  try{
    auto resultado = lu(matrizExtendida, tamanhoMatriz);
    // std::cout << "{ ";
    // for (auto x : resultado)
    //   std::cout << x << " ";
    // std::cout << "}\n";
  } catch (std::exception& e) {
    std::cerr << "Erro: " << e.what() << std::endl;
  }

}

int main(int nargs, char **cargs) {
  Configuracao config = {.unidadeDeTempo = microsegundos,
                         .numeroDeCasasDecimais = 7,
                         .numeroDeRepeticoesParaCronometragem = 10000};

  if (nargs > 1)
    config.numeroDeCasasDecimais = std::stoi(cargs[1]);

  std::cout << std::setprecision(8) << std::fixed;
  // testaGauss();
  testaLU();
  //calculaEImprimeExemplos(config);

  return EXIT_SUCCESS;
}
