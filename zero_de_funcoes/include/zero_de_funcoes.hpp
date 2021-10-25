#include "intervalo.hpp"
#include <functional>

using Funcao = std::function<double(double)>;

std::pair<double, int> bisseccao(Intervalo i, const double eps, Funcao f);

std::pair<double, int> newton_raphson(const double eps1, const double eps2, double x, Funcao f, Funcao derivada);

std::pair<double, int> posicao_falsa(Intervalo i, const double eps1, const double eps2, Funcao f);

std::pair<double, int> secante(const double eps1, const double eps2, double x0, double x1, Funcao f);
