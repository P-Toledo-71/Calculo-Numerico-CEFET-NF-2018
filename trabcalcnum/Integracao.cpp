#include "minhabiblioteca.h"
#include "Integracao.h"

#define NPONTOS 5
#define NPESOS  3
static double X[NPONTOS] = { -0.906179845938664,   -0.538469310105683,  0.000000000000000, 0.906179845938664, 0.538469310105683 };
static double W[NPONTOS] = { 0.236926885056189 ,	0.478628670499366,	0.568888888888889, 0.236926885056189, 0.478628670499366 };
static double X0[] = { -0.577350269100, 0.577350269100 };
static double X1[] = { -0.774596669200,	0.0000000000,	0.774596669200 };
static double X2[] = { -0.861136311500, -0.339981043500,	0.339981043500,	 0.861136311500 };
static double X3[] = { -0.906179845900, -0.538469310100,	0.0000000000,	 0.538469310100,	0.906179845900 };
static double X4[] = { -0.932469514200, -0.661209386400, -0.238619186000, 0.238619186000,	0.661209386400,	0.932469514200 };
static double X5[] = { -0.949107912300, -0.741531185500, -0.405845151300, 0.0000000000,	    0.405845151300,	0.741531185500,	0.949107912300 };
static double X6[] = { -0.960289856400, -0.796666477400, -0.525532409900,-0.183434642400,	0.183434642400,	0.525532409900,	0.796666477400, 0.960289856400 };


static double W0[] = { 1.000000000000, 1.000000000000 };
static double W1[] = { 0.555555555500,	0.888888888800,	0.555555555500 };
static double W2[] = { 0.347854845100,	0.652145154800,	0.652145154800,	0.347854845100 };
static double W3[] = { 0.236926885000,	0.478628670400,	0.568888888800,	0.478628670400,	0.236926885000 };
static double W4[] = { 0.171324492300,	0.360761573000,	0.467913934500,	0.467913934500,	0.360761573000,	0.171324492300 };
static double W5[] = { 0.129484966100,	0.279705391400,	0.381830050500,	0.417959183600,	0.381830050500,	0.279705391400,	0.129484966100 };
static double W6[] = { 0.101228536200,	0.222381034400,	0.313706645800,	0.362683783300,	0.362683783300,	0.313706645800,	0.222381034400, 0.101228536200 };

static double *X_[7] = { X0,X1,X2,X3,X4,X5,X6 };
static double *W_[7] = { W0,W1,W2,W3,W4,W5,W6 };

double FxQuadGauss(double x)
{
	return sqrt(1.0 / exp(x*x));    //exp((-(x*x)) * 0.5);
}

double FxQuadGInf(double x)
{
	return ((1.0 / (x*x)) * FxQuadGauss(1.0/x));
}

double intQuadGauss_(double(*Funcao)(double), double a, double b, int p, double passo)
{
	if (abs(abs(a) - abs(b)) > 5)
	{
		double i = 0,c,d;
		int s = 1;
		if (a > b) { i = a; a = b; b = i; i = 0; s = -1; }
		for (d = passo, c = 0; c < b-passo; c = d, d += passo) i += intQuadGauss(FxQuadGauss, c, d, p);
		return (s*i);
	}
	else return intQuadGauss(Funcao, a, b, p);
}

/*
{ -0.577350269100,	0.577350269100},
{ -0.774596669200,	0.0000000000,	0.774596669200},
{ -0.861136311500, -0.339981043500,	0.339981043500,	 0.861136311500},
{ -0.906179845900, -0.538469310100,	0.0000000000,	 0.538469310100,	0.906179845900},
{ -0.932469514200, -0.661209386400, -0.238619186000, 0.238619186000,	0.661209386400,	0.932469514200},
{ -0.949107912300, -0.741531185500, -0.405845151300, 0.0000000000,	    0.405845151300,	0.741531185500,	0.949107912300},
{ -0.960289856400, -0.796666477400, -0.525532409900,-0.183434642400,	0.183434642400,	0.525532409900,	0.796666477400, 0.960289856400}

*/
double intQuadGauss(double(*Funcao)(double), double a, double b, int p)
{
	// Implementacao faz uso de 2 vetores paralelos para os  coeficientes e dos pesos
	if (p > 1 && p < 8)
	{
		int i = p - 2;
		double S = 0.0;
		const double c = (b - a)*0.5 , d = (a + b)*0.5;
		for (int j = 0; j < p; j++)
		{
						
			//S += W[i][j] * Funcao(c * X[i][j] + d);
		}
		return (c*S);
	}
	else
	{
		cout << endl << " A quantidade de Pontos deve estar entre 2 e 7" << endl;
		system("pause");
		exit(1);
	}
}



double intQuadGauss4(double(*Funcao)(double), double a, double b)
{
	// Implementacao faz uso de 2 vetores paralelos para os  coeficientes e dos pesos
	


	double S = 0.0;
	const double c = b - a, d = a + b;
	for (int i = 0; i < NPONTOS; i++)
	{
				S += W[i] * (Funcao(((c)* X[i] + d) / 2));
	}

	return ((c)*S) / 2;

}

double intQuadGauss4_1( double (*Funcao)(double), double a ,double b)
{
// Implementacao faz uso do operador resto da divisao inteira (%) para sincronizar os vetores de coeficientes e dos pesos
// de forma que o vetor do pesos possua apenas 3 elementos e não 5 evitando o armazenamento de valores repetidos

	double S = 0.0;
	const double c = b - a,  d = a + b;
	for (int i = 0; i < NPONTOS; i++)
	{
		S += W[i % NPESOS] * (Funcao(((c) * X[i] + d) / 2));
	}

	return ((c)*S) / 2;

}

double intQuadGauss4_2(double(*Funcao)(double), double a, double b)
{
	// Implementacao faz uso das caracteristicas de simetria dos coeficientes e pesos dos polinomios de Legendre para otimizar 
	// o uso de memoria. São usados apenas 5 valores double para armazenar as tabelas enquanto em uma implementacao ingenua seriam
	// necessarios 10 valores double.

	
	const double c = b - a, d = a + b;
	double S =  W[2] * (Funcao(d/2)); // como o coeficiente do Polinomio de Legendre eh 0 a equacao de transformacao se resume ao valor de d/2, a+b.
	for (int i = 0; i < 2; i++)
	{
		S += W[i] * (Funcao( (c * (-X[i]) + d) / 2) + Funcao((c * X[i] + d) / 2));// o loop faz o calculo para os valores positivos e negativos dos coeficientes ao mesmo tempo
	}

	return ((c)*S) / 2;

}