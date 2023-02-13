#pragma once

extern "C" {
typedef double (*Funcao)(double);

double trapezioRepetida(Funcao func, double limiteInferior,
                        double limiteSuperior, int divisoes);

double simpson13Repetida(Funcao func, double limiteInferior,
                         double limiteSuperior, int divisoes);

double simpson38Repetida(Funcao func, double limiteInferior,
                         double limiteSuperior, int divisoes);
}
