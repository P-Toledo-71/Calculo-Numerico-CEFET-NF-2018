#include "matriz.h"



iterador::iterador(Matriz  & S, bool reverso, bool cm, int ii, int jj ) : M(S), i(ii),j(jj),inicio(0),
                                       fim( (M.linha - 1)*M.coluna + (M.coluna - 1)),
	                                   pos(0),CMaior(cm),p(reverso?-1:1)
{
	atualizaPosicao();
}
iterador::~iterador()
{
	inicio = 0;
	fim = 0;
	pos = 0;
}

bool iterador::operator==(iterador const & F)
{

	return (&M == &F.M && pos == F.pos && i==F.i && j == F.j && inicio == F.inicio && fim == F.fim) ?  true:false;

}


bool iterador::operator!=(iterador const & F)
{

	return ! operator==(F) ;

}

double & iterador::operator*()
{
	return M(i,j);
}

iterador  iterador::operator++(int)
{
	iterador aux(*this);
	passo(1);
	return aux;
}



iterador  iterador::operator--(int)
{
	iterador aux(*this);
	passo(-1);
	return aux;
}

void iterador::atualizaPosicao()
{
	pos = (i)*M.coluna + (j);
}



void iterador::passo(int passo)
{
	int &ii = (CMaior) ? j : i;
	int &jj = (CMaior) ? i : j; // item que e percorrido a cada passo, se o iterador for do tipo coluna Maior jj sera a linha, caso contrario sera coluna
	int bi = (CMaior) ? M.coluna - 1 : M.linha - 1;
	int bj = (CMaior) ? M.linha - 1 : M.coluna - 1;// parametro de baliza para o item que e percorrido a cada passo, se o iterador for do tipo coluna Maior bj sera a quantidade de linhas, caso contrario sera a de colunas
												   //int binicio = (passo == 1) ? inicio:fim;
												   //int bfim    = (passo == 1) ? fim : inicio;
												   //int binicio = (passo == 1) ? inicio:fim;
												   //int bfim    = (passo == 1) ? fim : inicio;

	if (ii == bi && jj == bj && passo > 0)
	{
		ii = bi + 1;
		jj = bj + 1;
	}
	else
	{
		if (ii == 0 && jj == 0 && passo < 0)
		{
			ii = -1;
			jj = -1;
		}
		else
		{
			jj = (jj < bj) ? jj + passo : 0;
			ii = (jj == 0 && ii < bi) ? ii + passo : ii;
		}
	}
	atualizaPosicao();

}



void iterador::setaPos(int ii, int jj)
{
	if (ii > 0 && ii < M.linha && jj >0 && jj < M.coluna)
	{
		i = ii;
		j = jj;
		atualizaPosicao();
	}

}

void iterador::pegaPos(int &ii, int &jj)
{
	ii = i;
	jj = j;

}

void iterador::setaColunaMaior(bool f)
{
	CMaior = f;
}

bool iterador::pegaColunaMaior()
{
	return CMaior;
}
