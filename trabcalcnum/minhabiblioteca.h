// Arquivo de cabe�alho minhabiblioteca.h. Cont�m os prot�tipos das fun��es
#ifndef MINHABIBLIOTECA
#define MINHABIBLIOTECA

# include <cassert>
# include <cstdlib>
# include "matriz.h"
#include"minhasfuncoes.h"
// .
// .
// .
// .
// .
// A TUA DECLARA��O DE PROT�TIPOS DEVE FICAR DEPOIS DESSA MENSAGEM. DEIXE 5 LINHAS ACIMA SEM PROGRAMA��O


void Identidade (Matriz &);
void Copia (Matriz &, Matriz&);
void SOMA(Matriz & , Matriz &, Matriz &);
void SUBTRAI(Matriz & , Matriz &, Matriz &);
int fatorial (int);
double e2xTAYLOR (double, int);
Matriz SOMA(Matriz & , Matriz & );
void MULTIPLICA(Matriz & , Matriz & , Matriz &);
void TRANSPOSTA(Matriz &, Matriz &);
double DerivProg (double , double = 0.01);
double DerivReg (double , double = 0.01);
double DerivCen (double , double = 0.01);
double DerivSeg (double , double = 0.01);
double DerivParc (Matriz & , int , double = 0.01);
void TriangSup (Matriz &, Matriz &, Matriz &, bool = false);
void EliminGauss (Matriz &, Matriz &, bool = false);
void Jacobi(Matriz &, Matriz &, Matriz &, Matriz &, int =500, double  = 0.00001, bool =false);
void GaussSeidel(Matriz &, Matriz &, Matriz &, Matriz &, int =500, double  = 0.00001, bool = false);

#include "Jacobiana.h"
#include "Newton.h"
#include "Raizes.h"
#include "Derivadas.h"








// TUA DECLARA��O DE PROT�TIPOS AQUI......................

// TUA DECLARA��O DE PROT�TIPOS AQUI......................

// A TUA DECLARA��O DE PROT�TIPOS DEVE FICAR ANTES DESSA MENSAGEM. DEIXE 5 LINHAS ABAIXO SEM PROGRAMA��O
// .
// .
// .
// .
// .

// Fun��o de teste. mantenha essa fun��o no fim do arquivo. N�o a apague.
void TesteDeFuncaoComCabecalho (void);

#endif // MINHABIBLIOTECA
