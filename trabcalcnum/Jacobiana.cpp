
#include "Jacobiana.h"

static double h = 1e-8;

double pegaVariacaoJacobiana()
{
	return h;
}

double setaVariacaoJacobiana(double H)
{
	double aux = h;
	h = H;
	return aux;
}



Matriz Jacobiana(Matriz &X,FP Fp,...)
{
	va_list ap;
	int n = X.dim('l');
	FP * vFp = new FP[n];
	if (vFp != NULL)
	{
		va_start(ap, Fp);
		vFp[0] = Fp;
		for (int i = 1; i < n; ++i)
		{
			vFp[i] = va_arg(ap, FP);
		}
		va_end(ap);
		Matriz a(Jacobiana(X, vFp));
		delete[] vFp;
		return a;
	}
	else
	{
		cout << endl << "Erro de alocacao de memoria - funcao Jacobiana(Matrix &x, Fp Fp,...)" << endl;
		system("pause");
		abort();

	}


}//


Matriz Jacobiana(Matriz &X, FP *Fp)
{

	int n = X.dim('l');
	Matriz  Xh(n, 1), Jac(n, n);

	for (int j = 0; j < n; j++)
	{

		if (Fp[j] != NULL)
		{
			DerivadaParcial(X, Xh, Fp[j], h);

			for (int i = 0; i < n; i++)
			{

				Jac(j, i) = Xh(i); // preenche a Matriz Jacobiana

			}

		}
		else
		{
			cout << endl << " Variavel Fp nao pode ser um ponteiro nulo!! " << endl;

			abort();
		}


	}

	return Jac;

}//

void Jacobiana(Matriz &X, Matriz & Jac, FP *Fp)
{

	int n = X.dim('l');
	Matriz  Xh(n, 1);
	if( Jac.Quadrada())
	for (int j = 0; j < n; j++)
	{

		if (Fp[j] != NULL)
		{
			DerivadaParcial(X, Xh, Fp[j], h);

			for (int i = 0; i < n; i++)
			{

				Jac(j, i) = Xh(i); // preenche a Matriz Jacobiana

			}

		}
		else
		{
			cout << endl << " Variavel Fp nao pode ser um ponteiro nulo!! " << endl;

			abort();
		}


	}

	
}//

double  jF1(Matriz & X)
{
	return  2*X[0] * X[0] - X[1] * X[1] - 1;
}

double  jF2(Matriz & X)
{
	return  X[0]*X[0]  + X[1]*X[1]-2;
}
