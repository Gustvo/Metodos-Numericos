#include "exemplos.hpp"
#include "cronometragem.hpp"
#include "metodo.hpp"
#include "zero_de_funcoes.hpp"

#include <iomanip>
#include <iostream>
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

static void imprimeResultadoDeExemplos(Configuracao config, Metodo metodo) {
  auto resultado = metodo.funcao();
  auto cronometragem =
      cronometraFuncao(config.numeroDeRepeticoesParaCronometragem,
                       metodo.funcao, config.unidadeDeTempo);
  std::cout << std::setprecision(config.numeroDeCasasDecimais) << std::fixed
            << metodo.nome << ":\tx = " << resultado.first << "\t"
            << resultado.second << "\t\t" << cronometragem.duracao << ' '
            << cronometragem.unidade << std::endl;
}

static void imprimeCabecalho() {
  std::cout << "f(x) = x³ - 9x + 3\n"
            << "ε = " << std::setprecision(3) << ε << "\nIntervalo = ["
            << intervalo.a << ", " << intervalo.b
            << "]\n\n"
               "\tNome\tx->f(x)=0\tIterações\tTempo*\n";
}

static void imprimeNota(int repeticoes) {
  std::cout << "\n"
               "*Tempo que a função demora para encontrar o resultado "
            << repeticoes << " vezes\n";
}

void imprimeExemplos(Configuracao config) {
  imprimeCabecalho();
  for (auto metodo : getMethods()) {
    imprimeResultadoDeExemplos(config, metodo);
  }
  imprimeNota(config.numeroDeRepeticoesParaCronometragem);
}
