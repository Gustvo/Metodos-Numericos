#include "exemplos.hpp"
#include "metodo.hpp"
#include "zero_de_funcoes.hpp"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

// f(x) = x³ - 9x +3
static double func(double x) { return x * x * x - 9 * x + 3; }

// f'(x) = 3x² - 9
static double func_derivada(double x) { return 3 * x * x - 9; }

static Intervalo intervalo = {0, 1}; // Intervalo usado em todas as questões
static double ε = 0.001;             // ε usado em todas as questões

static std::vector<Metodo> getMethods() {
  std::vector<Metodo> functions;

  functions.push_back(
      {"Bissecção", [=]() { return bisseccao(intervalo, ε, func); }});
  functions.push_back({"Posição Falsa",
                       [=]() { return posicao_falsa(intervalo, ε, ε, func); }});
  functions.push_back({"Newton Raphson", [=]() {
                         return newton_raphson(ε, ε, 0.5, func, func_derivada);
                       }});
  functions.push_back({"Secante", [=]() { return secante(ε, ε, 0, 1, func); }});

  return functions;
}

static void imprimeResultadoDeExemplos(Metodo metodo,
                                       int numeroDeCasasDecimais) {
  auto resultado = metodo.funcao();
  std::cout << std::setprecision(numeroDeCasasDecimais) << std::fixed
            << metodo.nome << ":\tx = " << resultado.first << "\t"
            << resultado.second << " iteracoes"<< '\n';
}

template <typename T, typename... Args>
static std::string format(T str, Args... args) {
  std::string output;
  output.resize(1000);
  sprintf(output.data(), str, args...);
  return output;
}

void imprimeExemplos(int numeroDeCasasDecimais) {
  std::string header = format("f(x) = x³ - 9x + 3\n"
                              "ε = %.3f\n"
                              "Intervalo = [%.1f, %.1f]\n",
                              ε, intervalo.a, intervalo.b);
  std::cout << header << std::endl;
  for (auto metodo : getMethods())
    imprimeResultadoDeExemplos(metodo, numeroDeCasasDecimais);
  std::cout << std::endl;
}

struct _ResultadoCronometragem {
  std::string metodo;
  long duracao;
};

using ResultadoCronometragem = std::vector<_ResultadoCronometragem>;

template <typename formatoDuracao>
static ResultadoCronometragem cronometraExemplos(const int repeticoes) {
  using clock = std::chrono::steady_clock;
  using time_point = std::chrono::time_point<clock>;
  using std::chrono::duration_cast;

  ResultadoCronometragem resultados;

  for (auto metodo : getMethods()) {
    time_point start = clock::now();
    for (int i = 0; i < repeticoes; ++i)
      metodo.funcao();

    auto duracao = duration_cast<formatoDuracao>(clock::now() - start).count();
    resultados.push_back({metodo.nome, duracao});
  }

  return resultados;
}

static void ImprimeResultadosDeCronometragem(int repeticoes,
                                             ResultadoCronometragem resultados,
                                             const std::string unidade) {
  std::cout << "Tempos (x" << repeticoes << "):\n";
  for (auto medicao : resultados) {
    std::cout << medicao.metodo << ":\t" << medicao.duracao << ' ' << unidade
              << '\n';
  }
}

void cronometraEImprimeResultados(const int repeticoes,
                                  const FormatoDuracao formatoDuracao) {
  ResultadoCronometragem resultados;
  std::string unidade;
  switch (formatoDuracao) {
  case FormatoDuracao::nanosegundos:
    resultados = cronometraExemplos<std::chrono::nanoseconds>(repeticoes);
    unidade = "ns";
    break;

  case FormatoDuracao::microsegundos:
    resultados = cronometraExemplos<std::chrono::microseconds>(repeticoes);
    unidade = "µs";
    break;

  case FormatoDuracao::milisegundos:
    resultados = cronometraExemplos<std::chrono::milliseconds>(repeticoes);
    unidade = "ms";
    break;
  }

  ImprimeResultadosDeCronometragem(repeticoes, resultados, unidade);
}
