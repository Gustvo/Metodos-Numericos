#include "exemplos.hpp"
#include "cronometragem.hpp"
#include "metodo.hpp"
#include "zero_de_funcoes.hpp"
#include "zero_de_polinomios.hpp"

#include <iomanip>
#include <iostream>
#include <vector>

// f(x) = x³ - 9x + 3
constexpr double func(double x) { return x * x * x - 9 * x + 3; }

// f'(x) = 3x² - 9
constexpr double func_derivada(double x) { return 3 * x * x - 9; }

// p(x) = x³ - 9x + 3
static Polinomio polinomio = {1, 0, -9, 3};

static Intervalo intervalo = {0, 1}; // Intervalo usado em todas as questões
static double ε = 0.001;             // ε usado em todas as questões

const int iteracoesBirgeVieta = 3;

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

  functions.push_back(
      {"Birge-Vieta", [=]() { return birgeVieta(iteracoesBirgeVieta, 1, polinomio); }});

  return functions;
}

static void imprimeCabecalho(int numeroDeIteracoes) {
  std::cout << "f(x) = x³ - 9x + 3\n"
            << "ε = " << ε
            << "\n\n"
               "\tNome\tx->f(x)=0\tIterações\tTempo (x" << numeroDeIteracoes <<
	       ")\n";
}

static void imprimeNota(int repeticoes) {
  std::cout << "\n"
               "*Tempo que a função demora para encontrar o resultado "
            << repeticoes << " vezes\n";
}

struct _resultados {
  std::string nome;
  double x;
  int iteracoes;
  long duracao;
  std::string unidadeDeTempo;
};

static void imprimeLinha(int numeroDeCasasDecimais, _resultados resultado) {
  std::cout << std::setprecision(numeroDeCasasDecimais) << std::fixed
            << resultado.nome << ":\t" << resultado.x << "\t"
            << resultado.iteracoes << "\t\t" << resultado.duracao << ' '
            << resultado.unidadeDeTempo << std::endl;
}

static _resultados calculaECronometraMetodo(Configuracao config,
                                            Metodo metodo) {
  auto [x, iteracoes] = metodo.funcao();
  auto [duracao, unidade] =
      cronometraFuncao(config.numeroDeRepeticoesParaCronometragem,
                       metodo.funcao, config.unidadeDeTempo);

  return {metodo.nome, x, iteracoes, duracao, unidade};
}

static std::vector<_resultados>
calculaECronometraExemplos(Configuracao config) {
  std::vector<_resultados> tabela;
  for (auto metodo : getMethods()) {
    auto resultado = calculaECronometraMetodo(config, metodo);
    tabela.push_back(resultado);
  }
  return tabela;
}

static void imprimeResultados(const std::vector<_resultados> tabela,
                              Configuracao config) {
  imprimeCabecalho(config.numeroDeRepeticoesParaCronometragem);
  for (auto linha : tabela)
    imprimeLinha(config.numeroDeCasasDecimais, linha);
}

void calculaEImprimeExemplos(Configuracao config) {
  auto resultados = calculaECronometraExemplos(config);
  imprimeResultados(resultados, config);
}
