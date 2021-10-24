

#include "Newton.h"
#include <cstdio>

static int iteracoes = 100;// Maximo de iteracoes a serem tentadas ate antes de atingir o criterio de parada
static double h = 1e-8;// valor de epsilon( ZERO ) para a funcao NEWTON
static FILE * Arq = nullptr;

int pegaIteracoesNewton()
{
	return iteracoes;
}

int setaIteracoesNewton(int i)
{
	int a = i;
	iteracoes = i;
	return a;
}

double pegaEpsilon()
{
	return h;

}

double setaEpsilon(double e)
{
	double a = h;
	h = e;
	return a;

}

bool ligaSalva(string const & nome)
{
	if (Arq != nullptr)
	{
		fclose(Arq);
		Arq = nullptr;

	}
	else
	{
		Arq = fopen(nome.c_str(),"w");
	}

	return (Arq) ? true : false;
}

void desligaSalva()
{
	if (Arq != nullptr)
	{
		fclose(Arq);
		Arq = nullptr;
	}

}

double CriterioParada(Matriz  & Mk,Matriz  & Mk1)
{
	// teste de parada modulo do vetor (metodo do quadrado das diferencas)
	double somat = 0.0;
	int n = Mk.dim('l');
	for (int indice = 0; indice < n; indice++)
	{
		somat += pow(abs(Mk[indice] - Mk1[indice]), 2);
	}

	return pow(somat, 0.5);
	
}

Matriz Newton(Matriz & X, FP Fp, ...)
/*

Funcao para calcular raizes para funcoes de varias variaveis pelo metodo de newton.
Essa funcao faz uso de uma lista de rgumentos variaveis onde os argumentos apos o parametro Fp sao ponteiros para funcao
do tipo double F(Matriz &).

uso : Newton( X, Fp1,Fp2,Fp3,Fp4...Fpn);



*/
{
	int n = X.dim('l'),i=iteracoes; // n determina a quantidade variaveis, funcoes e solucoes que o procedimento ira manipular
	va_list ap;
	// Recuperacao das funcoes passadas como argumento
	FP * vFp = new FP[n]; //  vetor em tempo de execucao para armazenar as funcoes
	if (vFp != nullptr)
	{
		va_start(ap, Fp);
		vFp[0] = Fp; // salva a funcao  obrigatoria
		for (int i = 1; i < n; ++i) vFp[i] = va_arg(ap, FP);// salva as funcoes opcionais
		va_end(ap);
		// Fim da recuperacao das funcoes passadas como argumento

		Matriz Xk1(Newton(X, vFp));

		delete[] vFp;// apaga o vetor de funcoes

		return Xk1;
	} 

	return Matriz(0, 0);
}


Matriz Newton(Matriz & X, FP *	vFp)

{
	int n = X.dim('l'), i = iteracoes; // n determina a quantidade variaveis, funcoes e solucoes que o procedimento ira manipular
	Matriz Xk(X), Xk1(X), Fk(n, 1), V(n, 1), Jac(n,n);// Xk : estimativas da iteracao anterior, Xk1 estimativas da iteracao atual, Fk: valor das funcoes na iteracao anterior, V: resultado do sistema

	
		do
		{

			Xk = Xk1;// atualiza as estimativas
			for (int j = 0; j < n; j++)// calcula -Fk
			{
				Fk[j] = -vFp[j](Xk);
			}
			Jacobiana(Xk,Jac, vFp);
			SolucionadorLinear(Jac, Fk, V);// resolve o sistema
			Xk1 = V + Xk; // calcula as estimativas atualizadas

			if (Arq) fprintf(Arq, "%.30f\t%.30f\t%.30f\t%.30f\t%.30f\t%d\n", h, X[0], X[1], Xk1[0], Xk1[1], i);

		} while (CriterioParada(Xk, Xk1) > h && --i > 0);

		
	
	return Xk1;
}

/*
		Faça
			Atualiza as estimativas
			Calcula -Fk;
			Cacula a Jacobiana
			Encontre V pela Solução do Sistema:  Jacobiana | -Fk
			Encontre o valor das novas estimativas calculando V + Xk
			iteracoes = iteracoes -1

		Enquanto Criterio de Parada > Epsilon E Iteracoes > 0




*/