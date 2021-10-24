#include "Derivadas.h"
void DerivadaParcial(Matriz  & X0, Matriz  & X, FP Funcao, double h)

/*
Calcula a derivada parcial numérica da funcao designada por Funcao
Parametros:
X0 -> Matriz linha com o valor das variaveis da funcao
X -> Matriz linha onde serao retornados os valores da derivada numerica para cada variavel
Funcao -> Ponteiro para a funcao que se deseja calcular a derivada
h -> Parametro para calculo da variacao da funcao, default = 1e-3;

*/
{
	// Verificacao da consistencia dos parametros

	if (Funcao != NULL && h > 0.0  && X0.dim('l') == X.dim('l') && X0.dim('c') == 1 && X0.dim('c') == X.dim('c'))
	{
		int n = X0.dim('l');

		Matriz Xh(X0); // cria o vetor de controle para determinar em qual variavel sera calculada a derivada parcial

		for (int i = 0; i < n; i++)
		{


			Xh[i] = X0[i] + h;  // Seta a varivavel para a qual esta sendo calculada a derivada parcial

			X[i] = (Funcao(Xh) - Funcao(X0)) / h; // calcula a derivada parcial para a variavel corrente

			Xh[i] = X0[i]; //Limpa a selecao da variavel
		}

	}
	else
	{
		cout << endl << " Parametros incorretos para a funcao DerivadaParcial!!" << endl << " Abortando o programa " << endl;
		system("pause");
		exit(1);
	}
}




Matriz  Gradiente(Matriz  & X0, FP Fpotencial, double h)
{
	Matriz X(X0.dim('l'), X0.dim('c'));

	DerivadaParcial(X0, X, Fpotencial, h);

	return X;

}

double  DerivaX(double Ponto, double(*Fpotencial)(double), double h)


{
	if (h != 0.0)

	{
		return (Fpotencial(Ponto + h) - Fpotencial(Ponto)) / h;
	}
	else
	{
		cout << endl << " O parametro h não pode ser igual a zero!! - Funcao DerivaX" << endl;
		exit(1);

	}
	return NAN;

}


double F1(Matriz & R) // funcao potencial 1
{


	if (R.dim('l') == 2) return pow(R[0], 2) + pow(R[1], 2);

	else return NAN;
}

double F2(Matriz & R) // funcao potencial 2
{
	if (R.dim('l') == 2) return cos(R[0]) + pow(R[0], 2) * sin(R[1]);

	else return NAN;
}

double F3(Matriz & R)// funcao potencial 3
{
	if (R.dim('l') == 3) return exp(R[0]) + pow(R[1], 2) + cos(R[2]);

	else return NAN;
}

