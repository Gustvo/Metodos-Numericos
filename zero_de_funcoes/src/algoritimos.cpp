#include "exemplos.hpp"
#include "metodo.hpp"
#include "zero_de_funcoes.hpp"

int main(int nargs, char **cargs) {
  Configuracao config;
  config.numeroDeCasasDecimais = (nargs > 1 ? std::stoi(cargs[1]) : 4);

  calculaEImprimeExemplos(config);

  return EXIT_SUCCESS;
}
