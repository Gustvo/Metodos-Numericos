#include "gauss.hpp"

#include <math.h>
#include <exception>
#include <stdexcept>
#include <iostream>

static std::vector<float> divideLinha(std::vector<float> linha) {
	float primeiroNaoNulo;
	bool primeiroEncontrado = false;
	for (auto i = 0; i < linha.size(); ++i) {
		if (linha[i] != 0 && !primeiroEncontrado) {
			primeiroNaoNulo = linha[i];
			primeiroEncontrado = true;
		}
		if (primeiroEncontrado)
			linha[i] /= primeiroNaoNulo;
	}

	return linha;
}

static int checaPivo(std::vector<float> linha, int indice) {
    for (int i = 0; i < indice; ++i) {
        if(linha[i])
            return i;
    }
    return -1;
}


static bool validaMatrizExtendida(std::vector<float>& matriz, int tamanho) {
    if (sqrt(matriz.size() - tamanho) != tamanho)
        return false;
    return true;
}

template <typename T>
static std::vector<T> extraiLinha(std::vector<T> matrizExtendida, int tamanho, int indice) {
    std::vector<T> linha(matrizExtendida.begin() + (tamanho+1)*indice, matrizExtendida.begin()+(tamanho+1)*(indice+1));
    return linha;
}

std::vector<float> gauss(std::vector<float> matrizExtendida, int tamanho) {
    if (!validaMatrizExtendida(matrizExtendida, tamanho))
        throw(std::invalid_argument("Tamanho de matriz incorreto"));

    std::vector<float> novaMatriz;

    // Primeiro passe zera todos os coeficientes a esquerda do pivô
	for (int i = 0; i < tamanho; ++i) {
        auto linha = extraiLinha<float>(matrizExtendida, tamanho, i);
        int indice = checaPivo(linha, i);
        while (indice != -1) {
            float fator = linha[indice];
            for (int j = 0; j < tamanho + 1; ++j)
                linha[j] -= fator*novaMatriz[(tamanho+1)*indice+j];

            indice = checaPivo(linha, i);
        }
        linha = divideLinha(linha);
        for (auto entrada : linha) 
            novaMatriz.push_back(entrada);
        
	}
    // Segundo passe zera os coeficientes a direita do pivô
    for (int i = tamanho - 1; i >= 0; --i) {
        for (int j = i+1; j < tamanho; ++j) {
            float fator = novaMatriz[i*(tamanho+1)+j];
            for (int k = 0; k < tamanho+1; ++k) {
                novaMatriz[i*(tamanho+1)+k] -= fator*novaMatriz[j*(tamanho+1)+k];
            }
        }
    }


    std::vector<float> matrizResultado;
    for (int i = 0; i < tamanho; ++i)
        matrizResultado.push_back(novaMatriz[tamanho+(tamanho+1)*i]);
    return matrizResultado;
}
