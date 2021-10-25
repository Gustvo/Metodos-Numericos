#include "exemplos.hpp"
#include "metodo.hpp"
#include "zero_de_funcoes.hpp"

int main(int nargs, char **cargs) {
  const int numeroDeCasasDecimais = (nargs > 1 ? std::stoi(cargs[1]) : 4);
  imprimeExemplos(numeroDeCasasDecimais);

  const int repeticoes = 5000;
  cronometraEImprimeResultados(repeticoes, microsegundos);

  return EXIT_SUCCESS;
}
