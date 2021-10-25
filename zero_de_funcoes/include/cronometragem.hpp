#pragma once

#include "zero_de_funcoes.hpp"

#include <functional>
#include <string>

enum FormatoDuracao { microsegundos, milisegundos, nanosegundos };

struct ResultadoCronometragem {
  long duracao;
  std::string unidade;
};

ResultadoCronometragem
cronometraFuncao(const int repeticoes,
                 std::function<_func_sig()> funcao,
                 FormatoDuracao formatoDuracao);
