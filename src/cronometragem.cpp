#include "cronometragem.hpp"
#include "exemplos.hpp"

#include <chrono>
#include <functional>

template <typename formatoDuracao>
static long _cronometraFuncao(const int repeticoes,
                              std::function<_func_sig()> funcao) {
  using clock = std::chrono::steady_clock;
  using time_point = std::chrono::time_point<clock>;
  using std::chrono::duration_cast;

  time_point start = clock::now();
  for (int i = 0; i < repeticoes; ++i)
    funcao();
  auto duracao = duration_cast<formatoDuracao>(clock::now() - start).count();
  return duracao;
}

ResultadoCronometragem
cronometraFuncao(const int repeticoes,
                 std::function<_func_sig()> func,
                 FormatoDuracao formatoDuracao) {
  long resultado;
  std::string unidade;
  switch (formatoDuracao) {
  case FormatoDuracao::nanosegundos:
    resultado = _cronometraFuncao<std::chrono::nanoseconds>(repeticoes, func);
    unidade = "ns";
    break;

  case FormatoDuracao::microsegundos:
    resultado = _cronometraFuncao<std::chrono::microseconds>(repeticoes, func);
    unidade = "µs";
    break;

  case FormatoDuracao::milisegundos:
    unidade = "ms";
    resultado = _cronometraFuncao<std::chrono::milliseconds>(repeticoes, func);
    break;
  }

  return {resultado, unidade};
}
