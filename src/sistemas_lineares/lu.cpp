#include "sistemas_lineares.hpp"
#include "utilitario.hpp"

void lu(double *c_matrizExtendida, int tamanho, double *out_resultado) {
  std::vector<double> matrizExtendida(
      c_matrizExtendida, c_matrizExtendida + tamanho * (tamanho + 1));

  // Os nomes de matrizes utilizados referem-se aos exemplos do pdf
  // disponibilizado
  std::vector<double> matrizL, matrizU, matrizY;

  // Extrai a matriz Y da matriz extendida
  for (auto i = 0; i < tamanho; ++i)
    matrizY.push_back(matrizExtendida[tamanho + (tamanho + 1) * i]);

  matrizL = criaMatrizIdentidade<double>(tamanho);

  // Primeiro passe zera todos os coeficientes a esquerda do pivô
  for (int i = 0; i < tamanho; ++i) {
    auto linha = extraiLinha<double>(matrizExtendida, tamanho, i);
    int indice = checaPivo(linha, i);
    while (indice != -1) {
      double fator = linha[indice] / matrizU[indice * (tamanho) + indice];

      // Salva o fator utilizado para zerar índice na matriz L
      matrizL[i * tamanho + indice] = fator;
      for (int j = 0; j < tamanho + 1; ++j) {
        linha[j] -= fator * matrizU[(tamanho)*indice + j];
      }
      indice = checaPivo(linha, i);
    }

    // Guarda a linha com os pivôs na posição correta na matriz U
    for (auto entrada = linha.begin(); entrada != linha.end() - 1; ++entrada) {
      matrizU.push_back(*entrada);
    }
  }

  // Remonta a matriz extendida utilizando a matriz L e a matriz Y
  std::vector<double> sistemaLY;
  for (auto i = 0; i < tamanho; ++i) {
    for (auto j = 0; j < tamanho + 1; ++j) {
      if (j < tamanho)
        sistemaLY.push_back(matrizL[i * tamanho + j]);
      else
        sistemaLY.push_back(matrizY[i]);
    }
  }

  std::vector<double> resultadoLY;
  resultadoLY.reserve(tamanho);
  gauss(sistemaLY.data(), tamanho, resultadoLY.data());

  // Remonta a matriz extendida utilizando a matriz U e os resultados do sistema
  // anterior
  std::vector<double> sistemaUX;
  for (auto i = 0; i < tamanho; ++i) {
    for (auto j = 0; j < tamanho + 1; ++j) {
      if (j < tamanho)
        sistemaUX.push_back(matrizU[i * tamanho + j]);
      else
        sistemaUX.push_back(resultadoLY[i]);
    }
  }
  gauss(sistemaUX.data(), tamanho, out_resultado);
}
