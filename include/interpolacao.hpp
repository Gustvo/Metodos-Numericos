#pragma once

extern "C" {
void interpolacaoSistemaLinear(const unsigned int numeroDePontos,
                               double *abscissas, double *ordenadas,
                               double *out_resultado);
double interpolacaoLagrange(const unsigned int numeroDePontos,
                            double *abscissas, double *ordenadas,
                            double pontoAInterpolar);
void interpolacaoNewton();
}
