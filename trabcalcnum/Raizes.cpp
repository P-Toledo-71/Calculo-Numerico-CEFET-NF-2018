#include "Raizes.h"

/*

Funcoes para o calculo de raizes


*/




double Secante(double X1, double X2, double(*Fx)(double), int & erro, int iteracoes, double epsilon)
/*

Calcula a raiz de uma equacao pelo metodo da secante
Parametros:
X1 -> ordenada do primeiro ponto da secante
X2 -> ordenada do segundo ponto da secante
Fx -> ponteiro para uma funcao que aceite um argumento double e retorna um double
erro -> referencia para uma variavel  que ira retorna uma condicao de erro segunda a tabela:
0: Termino normal

*/
{
	double X;// Variavel para armazenar a resposta
	erro = 0;
	do // Executa os calculos enquanto iteracoes for maior que zero e que Fx para os pontos seja maior que erro;
	{
		double y1 = Fx(X1); // Variavel para armazenar o valor de Fx no ponto1
		double y2 = Fx(X2); // Variavel para armazenar o valor de Fx no ponto2
		double FX = 0.0;
		X = X2 - (y2 *  (X2 - X1)  / (y2 - y1));
		if (abs((FX = Fx(X))) < epsilon || (abs(y1 - y2) < epsilon)) break;
		X1 = X2;
		X2 = X;

	} while (--iteracoes > 0);

	(iteracoes > 0) ? erro = erro : 1;

	return X;
}


double SecTrab(double x0, double x1, double (*Fx) (double), int kmax,double tol1, double tol2)
{
double xk1 = 0.0; // Xk+1
double xk0 = x0; // xk-1
double  xk = x1;
for (; kmax > 0; kmax--) // 1 Para k = 0 : max faça :
{

	xk1 = (xk0 * Fx(xk) - xk*Fx(xk0)) / (Fx(xk)-Fx(xk0));
	if (abs(xk1 - xk) < tol1 || abs(Fx(xk1)) < tol2) return xk1;
	xk0 = xk;
	xk = xk1;
	

}

cout << endl << "Metodo da secante nao convergiu" << endl;
return NAN;
}

double Ftrab(double x)
{
	if ( x>= 2.0)
	{
		cout << endl << "funcao nao definida para x >= 2, abortando " << endl;
		system("pause");
		exit(1);
	}
	double pi = acos(-1);
	return ( (pow(x, 2) - 1) * cos(pi / x) ) - log(2-x);
}

double Parabola(double x)
{
	return sin(x / 5);//pow(x, 3) - (2 * pow(x, 2)) - 5*x +3;
}

double Biseccao(double X1, double X2, double(*Fx)(double), int iteracoes, double erro)
{
	double X = 0;
	if (Fx(X1)*Fx(X2) < 0.0)
	{
		if (Fx(X1) > erro && Fx(X2) > erro) // testa o caso dos pontos fornecido já serem raizes

		{
			do
			{
				X = (X1 + X2) / 2; // X recebe o ponto médio entre os pontos

				if ((abs(Fx(X)) < erro || abs(X1 - X2) < erro)) return X; // Caso o Fx(X) seja menor do que o erro X e uma raiz de Fx

				if (Fx(X)*Fx(X2) < 0.0) // Caso Fx(X) tenha sinal diferente do de  Fx(X2) a raiz esta direita de X 
				{
					X1 = X;
				}
				else // Caso Fx(X) tenha sinal igual ao de Fx(X2) a raiz esta a esquerda de X 
				{
					X2 = X;
				}

			} while (--iteracoes > 0);// controla o numero de iteracoes para localizar a raiz
		}
		else return (Fx(X1) <= erro) ? Fx(X1) : Fx(X2); // caso um dos pontos originais seja raiz retorna o menor deles
	}


	return NAN;

}


