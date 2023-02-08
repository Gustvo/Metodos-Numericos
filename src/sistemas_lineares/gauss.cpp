#include "sistemas_lineares.hpp"
#include "utilitario.hpp"

#include <cstring>
#include <iostream>
#include <stdexcept>

void gauss(double *c_matrizExtendida, int tamanho, double *out_resultado) {

  std::vector<double> matrizExtendida(
      c_matrizExtendida, c_matrizExtendida + tamanho * (tamanho + 1));

  std::vector<double> novaMatriz;

  // Primeiro passe zera todos os coeficientes a esquerda do pivô
  for (int i = 0; i < tamanho; ++i) {
    auto linha = extraiLinha<double>(matrizExtendida, tamanho, i);
    int indice = checaPivo(linha, i);
    while (indice != -1) {
      double fator = linha[indice];
      for (int j = 0; j < tamanho + 1; ++j)
        linha[j] -= fator * novaMatriz[(tamanho + 1) * indice + j];

      indice = checaPivo(linha, i);
    }
    linha = divideLinha(linha).first;
    for (auto entrada : linha)
      novaMatriz.push_back(entrada);
  }
  // Segundo passe zera os coeficientes a direita do pivô
  for (int i = tamanho - 1; i >= 0; --i) {
    for (int j = i + 1; j < tamanho; ++j) {
      double fator = novaMatriz[i * (tamanho + 1) + j];
      for (int k = 0; k < tamanho + 1; ++k) {
        novaMatriz[i * (tamanho + 1) + k] -=
            fator * novaMatriz[j * (tamanho + 1) + k];
      }
    }
  }

  std::vector<double> matrizResultado;
  for (int i = 0; i < tamanho; ++i)
    matrizResultado.push_back(
        !proximoDeZero(novaMatriz[tamanho + (tamanho + 1) * i])
            ? novaMatriz[tamanho + (tamanho + 1) * i]
            : 0);

  std::memcpy(static_cast<void *>(out_resultado), matrizResultado.data(),
              matrizResultado.size() * sizeof(double));
}
