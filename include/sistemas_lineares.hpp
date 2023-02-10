#pragma once

extern "C" {
void lu(double *matrizExtendida, int tamanhoMatriz, double *out_resultado);

void gauss(double *matrizExtendida, int tamanho, double *out_resultado);
}
