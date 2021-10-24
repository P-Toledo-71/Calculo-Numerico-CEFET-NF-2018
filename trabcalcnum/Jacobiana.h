#pragma once
#include <cstdarg>
#include <cmath>
#include "matriz.h"
#include "Derivadas.h"



double pegaVariacaoJacobiana();
double setaVariacaoJacobiana(double H);

Matriz Jacobiana(Matriz & X, FP, ...);

Matriz Jacobiana(Matriz & X, FP * vfp);

void Jacobiana(Matriz & X, Matriz & Jac, FP * Fp);// vers�o para ser chamada dentro de loops para evitar a cria��o/destru��o repetida de matrizes

double jF1(Matriz & X);

double jF2(Matriz & X);
