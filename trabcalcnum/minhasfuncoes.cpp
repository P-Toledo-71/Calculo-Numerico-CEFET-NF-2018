# include "minhasfuncoes.h"

// .
// .
// .
// .
// .
// A SUA PROGRAMAÇÃO DEVE FICAR DEPOIS DESSA MENSAGEM. DEIXE 5 LINHAS ACIMA SEM PROGRAMAÇÃO
// ========================================================================================

// R1 em R1
double funcaopadrao(double x)
{
    return x*x;
}


// função Rn em R1
double funcaopadrao(Matriz &X)
{
   return X.saida(0,0)*X.saida(0,0)+3*X.saida(0,1)*X.saida(0,1);
}


// funcao de Rn em Rn

	void funcaopadrao(Matriz &X, Matriz &F)
	{
		int n = 2;

		if ((X.dim('l') != n) || (X.dim('l') != F.dim('l')) || (X.dim('c') != 1) || (F.dim('c') != 1))
		{
			cout << "Incompatibilidade de dimensoes. Abortando...";
			abort();
		}

		double f1, f2, x1, x2;
		x1 = X.saida(0, 0);
		x2 = X.saida(1, 0);

		f1 = x1 * x1 + x2 * x2 - 1;
		f2 = x1 - x2;

		F.entrada(0, 0, f1);
		F.entrada(1, 0, f2);
	}



// Função de elevar a 2
double xquadrado (double x)
{
    return x*x;
}

double xcubo (double x)
{
    return x*x*x;
}


double parabol(Matriz X)
{
    return pow( X.saida(0,0) , 2) + pow(X.saida(0,1),2);
}







// ========================================================================================
// A TUA PROGRAMAÇÃO DEVE FICAR ANTES DESSA MENSAGEM. DEIXE 5 LINHAS ABAIXO SEM PROGRAMAÇÃO
// .
// .
// .
// .
// .
