// Arquivo de cabeçalho minhabiblioteca.h. Contém os protótipos das funções
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
// A TUA DECLARAÇÃO DE PROTÓTIPOS DEVE FICAR DEPOIS DESSA MENSAGEM. DEIXE 5 LINHAS ACIMA SEM PROGRAMAÇÃO


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








// TUA DECLARAÇÃO DE PROTÓTIPOS AQUI......................

// TUA DECLARAÇÃO DE PROTÓTIPOS AQUI......................

// A TUA DECLARAÇÃO DE PROTÓTIPOS DEVE FICAR ANTES DESSA MENSAGEM. DEIXE 5 LINHAS ABAIXO SEM PROGRAMAÇÃO
// .
// .
// .
// .
// .

// Função de teste. mantenha essa função no fim do arquivo. Não a apague.
void TesteDeFuncaoComCabecalho (void);

#endif // MINHABIBLIOTECA
