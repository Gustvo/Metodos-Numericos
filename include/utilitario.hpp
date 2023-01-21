#pragma once

#include <vector>
#include <cmath>
#include <limits>

template<typename T>
std::pair<std::vector<T>, T> divideLinha(std::vector<T> linha) {
	T primeiroNaoNulo;
	bool primeiroEncontrado = false;
	for (auto i = 0; i < linha.size(); ++i) {
		if (std::fabs(linha[i]) > std::numeric_limits<T>::epsilon() && !primeiroEncontrado) {
			primeiroNaoNulo = linha[i];
			primeiroEncontrado = true;
		}
		if (primeiroEncontrado)
			linha[i] /= primeiroNaoNulo;
	}

	return {linha, primeiroNaoNulo};
}

template<typename T>
int checaPivo(std::vector<T> linha, int indice) {
    for (int i = 0; i < indice; ++i) {
        if(std::fabs(linha[i]) > std::numeric_limits<T>::epsilon())
            return i;
    }
    return -1;
}

template<typename T>
bool validaMatrizExtendida(std::vector<T>& matriz, int tamanho) {
    if (sqrt(matriz.size() - tamanho) != tamanho)
        return false;
    return true;
}

template <typename T>
std::vector<T> extraiLinha(std::vector<T> matrizExtendida, int tamanho, int indice) {
    std::vector<T> linha(matrizExtendida.begin() + (tamanho+1)*indice, matrizExtendida.begin()+(tamanho+1)*(indice+1));
    return linha;
}