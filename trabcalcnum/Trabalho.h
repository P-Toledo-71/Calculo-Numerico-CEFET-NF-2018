#pragma once
#include "matriz.h"
#include <cmath>
#include <iostream>
#include "Regressao.h"
#include "Integracao.h"
#include "Derivadas.h"

#ifndef DEBUGVIEW

#ifndef DEBUGON

#define DEBUGON false

#endif

#else

#ifndef DEBUGON

#define DEBUGON true

#endif

#endif

void TrocaLinhas(Matriz &, int, int, int = 0);
void SolucionadorLinear(Matriz &A_, Matriz &b_, Matriz &X,  bool = DEBUGON, bool = true);
void SolucionadorLinear(Matriz &&, Matriz &, Matriz &, bool = DEBUGON);
void SolucionadorLinear(Matriz && A_, Matriz && b_, Matriz & x, bool DBG_VIEW=DEBUGON);
void SolucionadorLinear(Matriz & A_, Matriz && b_, Matriz & x, bool DBG_VIEW=DEBUGON);
void Resolve(Matriz & A, Matriz &b, Matriz &x, bool = DEBUGON);
void Pivoteia(Matriz &, Matriz &, int, int, bool = DEBUGON);
void Escalona(Matriz &A, Matriz &b, int k, int n, bool DBG_VIEW = DEBUGON);
void GaussSeidel2(Matriz &A, Matriz &b, Matriz &x0, Matriz &x, int kmax = 500, double ERRO = 0.00001, char criterio = 'm', bool DBG_VIEW = DEBUGON);
void SOR(Matriz &A, Matriz &b, Matriz &x0, Matriz &x, double omega = 0.50, int Iteracoes = 500, double ERRO = 0.00001, char criterio = 'm', bool DBG_VIEW = DEBUGON);




