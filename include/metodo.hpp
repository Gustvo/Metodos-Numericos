#pragma once

#include "zero_de_funcoes.hpp"

#include <functional>
#include <string>

struct Metodo {
  std::string nome;
  std::function<_func_sig()> funcao;
};
