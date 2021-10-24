#pragma once
#include "matriz.h"
#include <cmath>
double Secante(double X1, double X2, double(*Fx)(double), int &erro, int iteracoes, double epsilon);
double Biseccao(double X1, double X2, double(*Fx)(double), int iteracoes, double epsilon);
double SecTrab(double x0, double x1, double(*Fx)(double), int kmax, double tol1, double tol2);
double Ftrab(double x);
double Parabola(double x);
