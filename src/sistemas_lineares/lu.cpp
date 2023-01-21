#include "lu.hpp"
#include "utilitario.hpp"
#include "gauss.hpp"

#include <stdexcept>
#include <utility>
#include <iostream>



// Os nomes de matrizes utilizados referem-se aos exemplos do pdf disponibilizado
std::vector<double> lu(std::vector<double> matrizExtendida, int tamanho) {
    if (!validaMatrizExtendida(matrizExtendida, tamanho))
        throw(std::invalid_argument("Tamanho de matriz incorreto"));

    std::vector<double> matrizL, matrizU, matrizY;

    for (auto i = 0; i < tamanho; ++i)
        matrizY.push_back(matrizExtendida[tamanho+(tamanho+1)*i]);

    /* Aloca uma matriz tamanhoXtamanho e preenche com zeros e
       preenche a diagonal principal com 1s
    */
    matrizL.insert(matrizL.begin(), tamanho*tamanho, 0);
    for (auto i = 0; i < tamanho; ++i)
        matrizL[i*tamanho+i] = 1;


    // Primeiro passe zera todos os coeficientes a esquerda do pivô
    for (int i = 0; i < tamanho; ++i) {
        auto linha = extraiLinha<double>(matrizExtendida, tamanho, i);
        int indice = checaPivo(linha, i);
        while (indice != -1) {
            double fator = linha[indice]/matrizU[indice*(tamanho)+indice];

            // Salva o fator utilizado para zerar índice na matriz L
            matrizL[i*tamanho + indice] = fator;
            for (int j = 0; j < tamanho + 1; ++j) {
                linha[j] -= fator*matrizU[(tamanho)*indice+j];
            }
            indice = checaPivo(linha, i);            
        }

        //Guarda a linha com os pivôs na posição correta na matriz U
        for (auto entrada = linha.begin(); entrada != linha.end()-1; ++entrada) {
            matrizU.push_back(*entrada);
        }
	}


    std::vector<double> sistemaLY;
    
    for (auto i = 0; i < tamanho; ++i) {
        for (auto j = 0; j < tamanho+1; ++j) {
            if (j < tamanho)
                sistemaLY.push_back(matrizL[i*tamanho + j]);
            else 
                sistemaLY.push_back(matrizY[i]);
        }
    }

    auto resultadoLY = gauss(sistemaLY, tamanho);
    
    std::vector<double> sistemaUX;
    
    for (auto i = 0; i < tamanho; ++i) {
        for (auto j = 0; j < tamanho+1; ++j) {
            if (j < tamanho)
                sistemaUX.push_back(matrizU[i*tamanho + j]);
            else 
                sistemaUX.push_back(resultadoLY[i]);
        }
    }
    auto resultadoUX = gauss(sistemaUX, tamanho);

    return resultadoUX;
    
}
