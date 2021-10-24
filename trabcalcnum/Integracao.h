#pragma once

double FxQuadGauss(double x);

double FxQuadGInf(double x);

double intQuadGauss_(double(*Funcao)(double), double a, double b, int p=8, double passo=5);

double intQuadGauss(double(*Funcao)(double), double a, double b, int p=8);

double intQuadGauss4(double(*Funcao)(double), double a, double b);

double intQuadGauss4_1(double(*Funcao)(double), double a, double b);

double intQuadGauss4_2(double(*Funcao)(double), double a, double b);
