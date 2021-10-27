#include "cronometragem.hpp"
#include "exemplos.hpp"
#include "metodo.hpp"
#include "zero_de_funcoes.hpp"

int main(int nargs, char **cargs) {
  Configuracao config = {.unidadeDeTempo = microsegundos,
                         .numeroDeCasasDecimais = 4,
                         .numeroDeRepeticoesParaCronometragem = 10000};

  if (nargs > 1)
    config.numeroDeCasasDecimais = std::stoi(cargs[1]);

  calculaEImprimeExemplos(config);

  return EXIT_SUCCESS;
}
