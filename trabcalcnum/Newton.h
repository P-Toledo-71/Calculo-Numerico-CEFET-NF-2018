#pragma once

#include "Jacobiana.h"
#include "Trabalho.h"
#include <cstdarg>

int pegaIteracoesNewton();

int setaIteracoesNewton(int i);

double pegaEpsilon();

double setaEpsilon(double e);

bool ligaSalva(string const & nome);

void desligaSalva();

double CriterioParada(Matriz  & Mk, Matriz  & Mk1);

Matriz Newton(Matriz & X, FP Fp, ...);

Matriz Newton(Matriz & X, FP * vFp);
