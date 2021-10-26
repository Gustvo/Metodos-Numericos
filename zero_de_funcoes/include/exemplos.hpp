#pragma once

#include "cronometragem.hpp"

struct Configuracao {
  FormatoDuracao unidadeDeTempo = microsegundos;
  int numeroDeCasasDecimais = 4;
  int numeroDeRepeticoesParaCronometragem = 5000;
};

// Utiliza as funções definidas em "zero_de_funcoes.hpp", em
// conjunto com os valores utilizados nos exemploes dados nos PDFs para
// calcular os valores de x para que f(x) = 0; f(x) é definida nos PDFs.
// A duração da execução da função é armazenada para comparação de métodos.  É
// impresso na tela a definição de f(x) usada, e uma tabela de resultados no com
// colunas:
// Nome | x -> f(x)=0 | Iteracoes | Tempo
void calculaEImprimeExemplos(Configuracao);