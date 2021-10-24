#pragma once
#include "matriz.h"
#include <cmath>

typedef  double(*FP)(Matriz &);

void DerivadaParcial(Matriz  & X0, Matriz  & X, FP Fxyz = NULL, double h = 1e-3);
Matriz Gradiente(Matriz  & X0, FP Fpotencial, double h = 1e-3);
double DerivaX(double Ponto, double(*Fx)(double), double h = 1e-3);
double F1(Matriz &);
double F2(Matriz &);
double F3(Matriz &);
