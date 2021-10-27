#include "exemplos.hpp"
#include "zero_de_funcoes.hpp"
#include "zero_de_polinomios.hpp"

int main(int nargs, char **cargs) {
  Configuracao config = {.unidadeDeTempo = microsegundos,
                         .numeroDeCasasDecimais = 7,
                         .numeroDeRepeticoesParaCronometragem = 10000};

  if (nargs > 1)
    config.numeroDeCasasDecimais = std::stoi(cargs[1]);

  calculaEImprimeExemplos(config);

  return EXIT_SUCCESS;
}
