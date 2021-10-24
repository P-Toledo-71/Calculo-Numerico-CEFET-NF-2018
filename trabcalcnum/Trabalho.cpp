#include "minhabiblioteca.h"
#include "minhasfuncoes.h"
#include "matriz.h"
#include "Trabalho.h"
#include <cstdlib>
#include <cstdio>
using namespace std;

void TrocaLinhas(Matriz &A, int LinhaA, int LinhaB,int k)
{
	
		/*

		Troca o conteudo da LinhaA com a LinhaB da matriz A a partir da coluna k. por default k = 0

		*/
		int n = A.dim('c'), linhasMatriz = A.dim('l');
#ifdef DEBUG

		if (!(LinhaA >= 0 && linhasMatriz && LinhaB >= 0 && LinhaB < linhasMatriz))
	
		{
			cout << endl << " Referencia a linhas fora dos limites da Matriz - Funcao Troca Linhas" << endl;
			system("pause");
			exit(1);
		}
#endif // DEBUG

		if (LinhaA != LinhaB)
		{
			double aux;

			// Troca LinhaA por LinhaB
			for (int coluna = k; coluna < n; ++coluna)
			{

				aux = A.saida(LinhaA, coluna);
				A.entrada(LinhaA, coluna, A.saida(LinhaB, coluna));
				A.entrada(LinhaB, coluna, aux);

			}
		}
		
	}


void Resolve(Matriz & A, Matriz &b, Matriz &x, bool DBG_VIEW) 
/* Substituicao Regressiva -  adaptado de Metodos Numericos para Engenharia 5a ed, Ed.Bookman,   p.218, figura 9.6;
CHAPRA, Steven;  CANALE,Raymond.
*/
{


	
	int n = (A.dim('c') == A.dim('l') && A.dim('l') == b.dim('l') && b.dim('l') == x.dim('l')) ? A.dim('l') : 0;
#ifdef DEBUG



	if (!n)
	
	{
		cout << endl << " !!!! Dimensoes das Matrizes incompatíveis  - Programa terminado -> funcao Resolve!!!! " << endl;
		system("pause");
		abort();
	}

#endif // DEBUG	
		int  i, j;
		double soma;
		
		for (i = n - 1; i >= 0; i--)// iteracao regresiva que controla a linha na qual esta sendo feita a substituicao
		{
			soma = 0.0;// zera a soma dos coeficentes x variaveis para a linha corrente

			for (j = i + 1; j < n; j++)// iteracao sobre os elementos da linha abaixo da linha corrente 
			{
				soma += A.saida(i, j)*x.saida(j, 0); // acha o valor de coeficiente(j) x variavel(j) e adiciona ao somatorio de                                       coeficentes
			}

			x.entrada(i, 0, (b.saida(i, 0) - soma) / A.saida(i, i));// encontra o valor da variavel cujo coeficente e o                                                                 elemento corrente da diagonal principal e salva no vetor  solucao
#ifdef DEBUG

			if (DBG_VIEW)
			{
				cout << endl << "Substituicao Regressiva passo " << n - i << endl;
				cout << endl << " Vetor x " << endl;
				x.imprime();
			}// if(DBG_VIEW)

#endif // DEBUG

		}
}
	


void Pivoteia(Matriz & A, Matriz &b, int n, int k,  bool DBG_VIEW) 
{


	
	
	/*
	// Iniciaiza PivotCorrente com o elemento da diagonal principal na coluna sendo processada
	*/
	int    LinhaPivoCorrente = k;
	for (int i = k; i < n; i++) // iteracao sobre as linhas comecando a partir da coluna corrente
	{
		double PivotCorrente = abs(A.saida(k, k));// Iniciaiza PivotCorrente com o elemento da diagonal principal na coluna													sendo processada
		double Aik = abs(A.saida(i, k));
		if  ( Aik > PivotCorrente) // verifica se o elemento corrente e maior do que o pivot atual
		{
			PivotCorrente = Aik; // salva o elemento corrente  como pivot corrente
			LinhaPivoCorrente = i;
		}
	}

	if (LinhaPivoCorrente != k)
	{
		TrocaLinhas(A, k, LinhaPivoCorrente); // troca a linha corrente da Matriz de coeficientes pela linha do Pivot Corrente a                                                     partir da coluna 'k'

		TrocaLinhas(b, k, LinhaPivoCorrente); // troca a linha corrente da Matriz de resultados pela linha do Pivot Corrente a

#ifdef DEBUG

		if (DBG_VIEW)
		{
			cout << endl << " Pivoteamento" << endl;
			cout << "Trocando a linha " << k + 1 << " pela linha " << LinhaPivoCorrente + 1 << endl;
			cout << endl << " Matriz A " << endl;
			A.imprime();
			cout << endl << " Matriz B " << endl;
			b.imprime();
		}

#endif // DEBUG
	}
	
				
	}

void Escalona(Matriz &A, Matriz &b, int k, int n, bool DBG_VIEW)
{

	// Escalona a Matriz expandida A|b  na linha k, coluna k

	for (int i = k + 1; i < n; i++)// Iteracao sobre as linhas da Matriz A
	{

		double m = A.saida(i, k) / A.saida(k, k); // Calcula o fator de ajuste dividindo o elemento na linha corrente na posicao 
										   // k pelo elemento da diagonal principal na posicao (k,k)
#ifdef DEBUG	

		if (DBG_VIEW)  A.entrada(i, k, 0.0); // Essa linha é desnecessaria, apenas atribui zeros para facilitar a visualizacao caso a opcao de debug esteja ativada
#endif
		for (int j = k + 1; j < n; j++)

			/*
			iteracao sobre os elementos da linha corrente (i) (caso a DBG_VIEW = true coloca os zeros abaixo da diagonal
			principal para facilitar a visualização, caso contrario ignora os elementos da coluna corrente abaixo da diagonal
			principal para economizar esforco computacional.
			Essa iteracao  subtrai da linha  A(i) a linha A(k) vezes o fator de ajuste
			*/
		{

			A.entrada(i, j, A.saida(i, j) - A.saida(k, j)*m);

		}//j
		b.entrada(i, 0, b.saida(i, 0) - b.saida(k, 0)*m);// Mesma operacao acima sobre o vetor B(i)
	}//i

#ifdef DEBUG

	if (DBG_VIEW)
	{
		cout << endl << "Eliminacao de Gauss passo " << k + 1 << endl;
		cout << endl << " Matriz A " << endl;
		A.imprime();
		cout << endl << " Matriz B " << endl;
		b.imprime();
	}// if(DBG_VIEW)

#endif
}

 void SolucionadorLinear(Matriz &&A_, Matriz &b_, Matriz & x, bool DBG_VIEW)
{
	SolucionadorLinear(A_, b_, x, DBG_VIEW);
}

 void SolucionadorLinear(Matriz &&A_, Matriz &&b_, Matriz & x, bool DBG_VIEW)
 {
	 SolucionadorLinear(A_, b_, x, DBG_VIEW);
 }

 void SolucionadorLinear(Matriz &A_, Matriz &&b_, Matriz & x, bool DBG_VIEW)
 {
	 SolucionadorLinear(A_, b_, x, DBG_VIEW);
 }


void SolucionadorLinear (Matriz &A_, Matriz &b_, Matriz & x, bool DBG_VIEW, bool destrutiva)
{

	/*
	Implementa a Eliminacao de Gauss com pivoteamento parcial e substituição regressiva para solução de sistemas de 
	equacoes lineares de ordem n
	*/
	

	int n = (A_.dim('c') == A_.dim('l') && A_.dim('l') == b_.dim('l') && b_.dim('l') == x.dim('l')) ? A_.dim('l') : 0; // Armazena a ordem do sistema linear caso as dimensoes da matrizes sejam incompativeis atribui 0 a n.

#ifdef DEBUG

	if (n==0)// executa as iteracoes caso as matrizes seja compativeis
	
	{
		cout << endl << " !!!! Dimensoes das Matrizes incompatíveis  - Programa terminado -> funcao SolucionadorLinear!!!! " << endl;
		system("pause");
		abort();
	}

#endif // DEBUG
	
		int  k; // Variaveis de controle de iteracao> k controla o loop externo sobre a matriz inteira
		
	  Matriz &A =  (destrutiva) ? A_ : *&Matriz(A_), b = (destrutiva)?  b_ : *&Matriz(b_);// Matrizes onde as operacoes serao feitas
		
#ifdef DEBUG

		if (DBG_VIEW) // Imprime o estado inicial das matrizes durante depuracao
		{
			A_.imprime();
			cout << endl;
			b_.imprime();
			cout << endl;
		}

#endif

		for (k = 0; k < n - 1; k++)// iteracao principal do algoritmo 
		{

			Pivoteia(A, b, n, k, DBG_VIEW);// executa a operacao de pivoteamento na coluna corrente

			Escalona(A, b, k, n, DBG_VIEW);// executa o escalonamento na linha k, coluna k
							
		}//k


		Resolve(A, b, x, DBG_VIEW); // Executa a substituicao regressiva para obter a solucao do sistema

	}
	



void SOR(Matriz &A, Matriz &b, Matriz &x0, Matriz &x, double omega, int kmax, double ERRO, char criterio, bool DBG_VIEW)
{
	
#ifdef DEBUG

	if (omega < 0 || omega > 2)
	{
		cout << "Valor de Omega deve estar entre 0.0 e 2.0 !! - Funcao SOR - Abortando a funcao" << endl;
		system("pause");
		return;
	}
#endif // DEBUG


	int La = A.dim('l');
	int n = (La == A.dim('c') && La == b.dim('l') && La == x0.dim('l') && La == x.dim('l')) ? La : 0;

#ifdef DEBUG
	if (n == 0)
	{
		cout << endl << " Dimensoes das matrizes incompativeis - funcao SOR - Abortanto a funcao !!!" << endl;
		system("pause");
		abort();
	}
#endif // DEBUG
	
	
			int i, j, k, indice;
			double temp_i, somat, Max;
			n = A.dim('l');
			Matriz Xk(n, 1), Xk1(n, 1); // xk de aproximacao corrente e xk1 vetor de aproximacao atualizado
			Copia(x0, Xk);
			for (k = 0; k < kmax; k++) // controla o numero de interacoes ate obter a convergencia
			{
				for (i = 0; i < n; i++) // controla a linha onde esta sendo calculada a estimativa
				{

					somat = 0.0;

					for (j = 0; j <= i - 1; j++) // Multiplica todos os elementos da linha i  pelo vetor de aproximacao atualizado
					{

						somat += A.saida(i, j)*Xk1.saida(j, 0);
					}

					for (j = i + 1; j < n; j++) // Multiplica todos os elementos da linha i  pelo vetor de aproximacao corrente
					{

						somat += A.saida(i, j)*Xk.saida(j, 0);
					}//j



					temp_i = ((1.0 - omega)  * Xk.saida(i, 0)) + (omega *(b.saida(i, 0) - somat) / A.saida(i, i));
					Xk1.entrada(i, 0, temp_i);// Atualiza o vetor de aproximacao com a nova estimativa para a linha i


				}//i
				if (criterio == 'm')
				{
					// teste de parada modulo do vetor (metodo do quadrado das diferencas)
					somat = 0.0;
					for (indice = 0; indice < n; indice++)
					{
						somat += pow(Xk1.saida(indice, 0) - Xk.saida(indice, 0), 2);
					}
					somat = pow(somat, 0.5);
					if (somat < ERRO)
					{
#ifdef DEBUG



						if (DBG_VIEW)
						{
							cout << endl << " Teste de Parada Modulo do Vetor Excutado ERRO > que  " << somat << endl;
						}


#endif // DEBUG

						break;
					}
				} // criterio == m

				if (criterio == 'M') // criterio do maximo
					// metodo do erro absoluto
				{
					Max = abs(Xk1.saida(0, 0) - Xk.saida(0, 0));
					for (j = 1; j < n; j++)
					{
						if (abs(Xk1.saida(j, 0) - Xk.saida(j, 0)) > Max)
						{
							Max = abs(Xk1.saida(j, 0) - Xk.saida(j, 0));
						}
					}
					if (Max < ERRO)
					{
#ifdef DEBUG
						if (DBG_VIEW)
						{
							cout << endl << " Teste de Parada do Maximo Excutado ERRO > que  " << Max << endl;
						}
#endif
						break;
					}

				}// criterio == M

				Copia(Xk1, Xk); // atualiza estimativas
#ifdef DEBUG

				if (DBG_VIEW)
				{
					Xk1.imprime(10);
					cout << '\n';
				}
#endif

			}//k

			if (k == kmax)
			{
				cout << endl << " Procedimento nao converge !!" << endl;
			}
			Copia(Xk1, x);
	
	
	
}

void ZeraMatriz(Matriz & M)
{
	int i = M.dim('l'), j = M.dim('c');

	for (int ii = 0; ii < i; ii++)
	{
		for (int jj = 0; jj < j; jj++)
		{

			M.entrada(ii, jj, 0.0);
		}
	}
}



