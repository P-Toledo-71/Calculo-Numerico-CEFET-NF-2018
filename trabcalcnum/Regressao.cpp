#include "matriz.h"
#include"Trabalho.h"
#include "minhabiblioteca.h"
#include "Regressao.h"




void regressaoMinQuadLinear(Matriz & Px, Matriz &Py, Matriz &X)
{
	
	int n = X.dim('l');
	int P = Px.dim('l');
	if (n < P)
	{

		Matriz A(P, n);
		for (int i = 0; i < P; i++)
		{

			for (int j = 0; j < n; j++)
			{
				A(i, j) = pow(Px[i], j);
			}
		}

		Matriz At(A.transposta());
		SolucionadorLinear(At*A, At*Py, X);
	}
	else {
		cout << endl << "Dimensoes incompativeis" << endl;
		system("pause");
	}
}

void logPonto(Matriz  & Entrada, Matriz & Saida)
{
	if (Entrada.dim('l') != Saida.dim('l') || Entrada.dim('c') != Saida.dim('c'))
	{
		cout << endl << "Matrizes nao sao compatives" << endl;
		system("pause");
		exit(1);
	}

	for (int i = Entrada.dim('l')-1; i >= 0; i--)
		for (int j = Entrada.dim('c')-1; j >= 0; j--)
			Saida.entrada(i, j, log(Entrada.saida(i, j)));
	
}

void expPonto(Matriz  & Entrada, Matriz & Saida)
{
	if (Entrada.dim('l') != Saida.dim('l') || Entrada.dim('c') != Saida.dim('c'))
	{
		cout << endl << "Matrizes nao sao compatives" << endl;
		system("pause");
		exit(1);
	}

	for (int i = Entrada.dim('l')-1; i >= 0; i--)
		for (int j = Entrada.dim('c')-1; j >= 0; j--)
			Saida.entrada(i, j, exp(Entrada.saida(i, j)));

}

void gRegressao(Matriz & Px, Matriz &Py, Matriz &X, bool DBG_VIEW)
{
	int P = Px.dim('l');
	int n = X.dim('l');
	Matriz A(P, n), At(n, P), AtA(n, n), AtPy(n, 1),Py_(Py.dim('l'),Py.dim('c'));
	for (int i = 0; i < P; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A.entrada(i, j, pow(Px.saida(i, 0), j));
		}
	}
		TRANSPOSTA(A, At);
		MULTIPLICA(At, A, AtA);
		MULTIPLICA(At, Py, AtPy);
		if (DBG_VIEW)
		{
			cout << endl << "Matriz A:" << endl;
			A.imprime(10);
			cout << endl << "Matriz Transposta de A:" << endl;
			At.imprime(10);
			cout << endl << "Produto de At por A:" << endl;
			AtA.imprime(10);
			cout << endl << "Produto de At por Y:" << endl;
			AtPy.imprime(10);
		}
		EliminGauss(AtA, AtPy);
		TriangSup(AtA, AtPy, X);
}