#pragma once

#include <cmath>
#include <limits>
#include <vector>

template <typename T> bool proximoDeZero(T numero) {
  if (std::fabs(numero) < std::numeric_limits<T>::epsilon())
    return true;
  return false;
}

template <typename T>
std::pair<std::vector<T>, T> divideLinha(std::vector<T> linha) {
  T primeiroNaoNulo;
  bool primeiroEncontrado = false;
  for (auto i = 0; i < linha.size(); ++i) {
    if (!proximoDeZero(linha[i]) && !primeiroEncontrado) {
      primeiroNaoNulo = linha[i];
      primeiroEncontrado = true;
    }
    if (primeiroEncontrado)
      linha[i] /= primeiroNaoNulo;
  }

  return {linha, primeiroNaoNulo};
}

template <typename T> int checaPivo(std::vector<T> linha, int indice) {
  for (int i = 0; i < indice; ++i) {
    if (!proximoDeZero(linha[i]))
      return i;
  }
  return -1;
}

template <typename T>
bool validaMatrizExtendida(std::vector<T> &matriz, int tamanho) {
  if (sqrt(matriz.size() - tamanho) != tamanho)
    return false;
  return true;
}

template <typename T>
std::vector<T> extraiLinha(std::vector<T> matrizExtendida, int tamanho,
                           int indice) {
  std::vector<T> linha(matrizExtendida.begin() + (tamanho + 1) * indice,
                       matrizExtendida.begin() + (tamanho + 1) * (indice + 1));
  return linha;
}

template <typename T> std::vector<T> criaMatrizIdentidade(int tamanho) {
  std::vector<T> matrizIdentidade;
  matrizIdentidade.insert(matrizIdentidade.begin(), tamanho * tamanho, 0);
  for (auto i = 0; i < tamanho; ++i)
    matrizIdentidade[i * tamanho + i] = 1;

  return matrizIdentidade;
}
