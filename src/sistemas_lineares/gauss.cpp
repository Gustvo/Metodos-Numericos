#include "gauss.hpp"

#include <math.h>
#include <exception>
#include <stdexcept>
#include <iostream>

std::vector<float> divideLinha(std::vector<float> linha) {
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

static int checaAncora(std::vector<float> linha, int indice) {
    for (int i = 0; i < indice; ++i) {
        if(linha[i])
            return i;
    }
    return -1;
}

static void imprimeMatriz(std::vector<float> matriz, int tamanho) {
    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; i < tamanho; ++j)
            std::cout << matriz[i*tamanho + j] << ' ';
        std::cout << '\n';
    }
}



std::vector<float> gauss(std::vector<float> matrizCoeficientes, std::vector<float> matrizRes) {
	const int tamanhoMatriz = matrizRes.size();
    if (tamanhoMatriz != sqrt(matrizCoeficientes.size()))
        throw(std::invalid_argument("Tamanho de matriz incorreto"));

    std::vector<float> novaMatriz;

    // Primeiro passe zera todos os coeficientes a esquerda do pivô
	for (int i = 0; i < tamanhoMatriz; ++i) {
        std::vector<float> linha(matrizCoeficientes.begin() + tamanhoMatriz * i, matrizCoeficientes.begin()+tamanhoMatriz*(1+i));
        linha.push_back(matrizRes[i]);
        int indice = checaAncora(linha, i);
        while (indice != -1) {
            float fator = linha[indice];
            std::cerr << "[Indice, fator]: [" << indice << ", " << linha[indice] << ']' << std::endl;
            for (auto entrada : linha)
                std::cerr << entrada << ' ';
            std::cerr << "\n -----subtraindo----\n";
            for (int j = 0; j < tamanhoMatriz + 1; ++j) {
                std::cerr << novaMatriz[(tamanhoMatriz+1)*indice +j] << ' ';
                linha[j] -= fator*novaMatriz[(tamanhoMatriz+1)*indice+j];
            }
            std::cerr << std::endl;
            for (auto entrada : linha)
                std::cerr << entrada << ' ';
            std::cerr << std::endl;
            indice = checaAncora(linha, i);
        }
        linha = divideLinha(linha);
        std::cerr << "----Inserindo linha na Matriz----\n";
        for (auto entrada : linha) {
            std::cerr << entrada << ' ';
            novaMatriz.push_back(entrada);
        }
        std::cerr << std::endl;
        
	}
    // Segundo passe zera os coeficientes a direita do pivô
    for (int i = tamanhoMatriz - 1; i >= 0; --i) {
        for (int j = i+1; j < tamanhoMatriz; ++j) {
            float fator = novaMatriz[i*(tamanhoMatriz+1)+j];
            for (int k = 0; k < tamanhoMatriz+1; ++k) {
                novaMatriz[i*(tamanhoMatriz+1)+k] -= fator*novaMatriz[j*(tamanhoMatriz+1)+k];
            }
        }
    }
    return novaMatriz;
}
