#pragma once

#include "zero_de_funcoes.hpp"

#include <string>
#include <functional>

struct Metodo {
  std::string nome;
  std::function<_func_sig()> funcao;
};
