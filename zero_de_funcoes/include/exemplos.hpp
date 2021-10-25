#pragma once

#include "intervalo.hpp"
#include <chrono>

enum FormatoDuracao { microsegundos, milisegundos, nanosegundos };

// Utiliza as funções definidas em "zero_de_funcoes.hpp", em
// conjunto com os valores utilizados nos exemploes dados nos PDFs para
// calcular os valores de x para que f(x) = 0; f(x) também é definida nos
// PDFs.
// É impresso na tela a definição de f(x) usada, e a lista de resultados no
// formato:
// nome_do_metodo: x = n
void imprimeExemplos(int numeroDeCasasDecimais);

void cronometraEImprimeResultados(const int repeticoes, FormatoDuracao f);