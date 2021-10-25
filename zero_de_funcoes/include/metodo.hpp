#pragma once

#include <string>
#include <functional>

struct Metodo {
  std::string nome;
  std::function<std::pair<double, int>()> funcao;
};
