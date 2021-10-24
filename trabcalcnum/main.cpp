// Arquivo de programação contendo o main
// Neste arquivo você deverá implementar a EXECUÇÃO das funções
// de cada atividade proposta. Este arquivo não deverá conter
// implementação de funções e sim as chamadas das funções, a fim
// de se utilizá-las e obter resultados. Esse é basicamente um
// arquivo de parâmetros a serem rodados e obtidos resultados.

// ATALHOS INTERESSANTES:
// Comentar linhas: Ctrl + SHIFT + c
// Descomentar linhas: Ctrl + SHIFT + x


// Inclusão de bibliotecas usadas em cada programa
#include <iostream>
using namespace std;

// Biblitoeca desenvolvida durante o curso

#define DEBUGVIEW

# include "matriz.h"
# include "minhabiblioteca.h"
# include "minhasfuncoes.h"
#include  "Trabalho.h"
#include "Jacobiana.h"
#include "Newton.h"
#include "Raizes.h"
#include "Regressao.h"

#include <cmath> 
#include <cstdlib>
#include <cstdio>


// Início da função main. Apenas esta função poderá estar nesse arquivo.
// Nenhuma outra função poderá estar aqui.
using namespace std;

double F(double p)
{
	return log(p + cos(p / 5)) * exp(p + sin(5 * p));
}

/*
int main()
{
	FILE * arq = fopen("QuadGauss.dat","w");
	
		for (int a = 2; a < 7; a++) fprintf(arq, "%d\t%d\t%.30f\n",3,a,intQuadGauss_(FxQuadGauss, 3, 0, a));
		for (int a = 2; a < 7; a++) fprintf(arq, "%d\t%d\t%.30f\n", 5, a, intQuadGauss_(FxQuadGauss, 5, 0, a));
		for (int a = 2; a < 7; a++) fprintf(arq, "%d\t%d\t%.30f\n", 10, a, intQuadGauss_(FxQuadGauss, 10, 0, a));
		for (int a = 2; a < 7; a++) fprintf(arq, "%d\t%d\t%.30f\n", 50, a, intQuadGauss_(FxQuadGauss, 50, 0, a));
		fclose(arq);
		
		double i = 0;
		
		for (int b = 5, a = 0; a < 4995; a = b, b += 5) i += intQuadGauss(FxQuadGauss, a, b, 6);
		cout << i << endl;
	system("pause");
	return 1;
}

int main00()
{
	double Vpy[22] = { .3448,.4695,.5880,.7052,.9772,1.1515,1.4713,1.8725,	2.3958,	2.9634,	3.7575,	4.7305,	5.9609,	7.5037,	9.4735,	                    11.8506,  14.9609,	18.8430, 23.679,29.8684,37.5907,47.2409 };
	double Vpx[22] = { 0.20 ,0.4,0.6,0.8,1,1.2,1.4,1.6,1.8,2,2.2,2.4,2.6,2.8,3,3.2,3.4,3.6,3.8,4,4.2,4.4 };

	Matriz T(Vpx, 22, 1), Y_(Vpy, 22, 1), V(2, 1), Y(Y_.dim('l'), Y_.dim('c'));
	logPonto(Y_, Y); // Aplica o ln aos pontos experimentais
	gRegressao(T, Y, V); // Executa a regressão linear
	V.imprime(30);
	cout << endl;
	auto c = Y.fim();
	for (auto a = Y.inicio(), b = T.inicio(); a != c; a++)//= Y.dim('l')-1; a >= 0;a--)
	{
		*a = exp(V[0])*exp(V[1] * *b++);//Y[a]= exp(V[0])*exp(V[1] * T[a]);
	}
	Y.imprime(30);
	V.salva("coeficientes.dat", 30);
	Y.salva("dadosregressao.dat", 30);
	cout << endl;
	system("pause");
	return 1;
}

int main33()

{
		
	double Vpx[11] = { 1872, 1890, 1900 ,1920 ,1940, 1950 ,1960, 1970, 1980, 1991 ,1996 };

	double Vpy[11] = { 9.9, 14.3, 17.4, 30.6, 41.2, 51.9, 70.2, 93.1, 119.0, 146.2, 157.1 };


	Matriz Px(Vpx, 11, 1), Py(Vpy, 11, 1), P3(2,1), P4(11,1);

	//regressaoMinQuadLinear (Px, Py, P3);
	gRegressao(Px, Py, P4);
	//cout << endl << " Regressao:" << endl;
	//P3.imprime(5);

	cout << endl << " gRegressao:" << endl;
	P4.imprime(5);
	FILE * Arq = fopen("Regressao.txt", "w");
	for (int i = 0; i < P3.dim('l'); i++)
	{
		fprintf(Arq, "%f\n", P3[i]);
	}
	fclose(Arq);
	system("pause");
	
	return 1;

}

int main2()

{

	double Vp1[2] = { -2,1 }, Vp2[2] = { 2,2 }, Vp3[2] = { -2,-2 }, Vp4[2] = { 1,-2 };
	Matriz P1(Vp1, 2, 1), P2(Vp2, 2, 1), P3(Vp3, 2, 1), P4(Vp4, 2, 1);
	setaEpsilon(1e-3);
	//ligaSalva("Newton.txt");
	Matriz S1(Newton(P1, jF1, jF2)), S2(Newton(P2, jF1, jF2)), S3(Newton(P3, jF1, jF2)), S4(Newton(P4, jF1, jF2));
	//desligaSalva();
	cout << endl << "Solucao para o sistema para P1:" << endl;
	S1.imprime(30);
	cout << endl << "Solucao para o sistema para P2:" << endl;
	S2.imprime(30);
	cout << endl << "Solucao para o sistema para P3:" << endl;
	S3.imprime(30);
	cout << endl << "Solucao para o sistema para P4:" << endl;
	S4.imprime(30);
	system("pause");
	int erro = 0; //
	double a = 0.5;
	double b = 1.99;
	double mb = Biseccao(a, b, Ftrab, 1000, 1e-8);
	double ms = Secante(a, b, Ftrab, erro, 1000, 1e-8);
	double os = SecTrab(a, b, Ftrab, 1000, 1e-8, 1e-4);
	double passo = 0.3;
	double d = b;
	double r1 = SecTrab(a, b, Ftrab, 1000, 1e-8, 1e-8);
	double r11 = Secante(a, b, Ftrab, erro, 1000, 1e-8);
	double r2 = SecTrab(r1 + passo, b, Ftrab, 1000, 1e-8, 1e-8);
	double r22 = Secante(r1 + passo, d, Ftrab, erro, 1000, 1e-8);
	double r3 = SecTrab(r2 + passo, b, Ftrab, 1000, 1e-8, 1e-8);
	double r33 = Secante(r2 + passo, d, Ftrab, erro, 1000, 1e-8);
	system("pause");


	return 0;

}
*/



int main()
{
    // =============================================
    // INICIE  SUA PROGRAMAÇÃO ABAIXO DESTA MENSAGEM
    // =============================================


 double Va[25]= {
				 02.0, 03.0, -01.0, 05.0, 05.0,
				 05.0,-10.0,  11.0, 13.0,-01.0,
				 08.0, 01.0,  01.0, 01.0, 02.0,
				 11.0, 05.0, -03.0,-03.0, 01.0,
				 02.0, 02.0,  01.0, 07.0,-14.0
             };

// Trabalho de Eliminacao de Gauus

double Vb[5]={-4.0, 25.0,-4.0,7.0,150.0};
double Vx[5] = {0,0,0,0,0 };
double Vx0[5] = { 2,-2,5,4,3 };
Matriz A(Va,5,5),b(Vb,5,1),x(Vx,5,1), x0(Vx0, 5, 1);

//SolucionadorLinear(A,b,x,DEBUGON);
A.imprime(2);
b.imprime(2);
EliminGauss(A, b, true);
TriangSup(A, b, x, true);

cout <<endl << "Solucao do Sistema" <<endl;

x.imprime(30);

/*

//Trbalho SOR






double  VaSor[25] = { 8,-2,3,-3,-5,      2,5,1,1,3,        4,-4,7,1,-1,    1,1,1,-4,2,    -1,-2,2,2,4 };
double    VbSor[5] = { -12,  56,   -48,   6,   -15 };     //vetor declarado
double    Vx0Sor[5] = { 1,  5,  -1,  8,  5 };
Matriz ASor(VaSor, 5, 5), bSor(VbSor, 5, 1), xSor(5, 1), x0Sor(Vx0Sor, 5, 1);


for (auto a = ASor.inicio(); a != ASor.fim(); a++)
{
	cout << *a << endl;
}

//double omega = .61;
//int kmax = 50;
//
//cout << endl << " SOR  - Criterio de Parada Maximo " << endl;
//SOR(ASor, bSor, x0Sor, xSor, omega, kmax, 0.000001, 'M', DEBUGON);
//
//
//xSor.imprime(30);
//
//cout << endl << " SOR  - Criterio de Parada Modulo " << endl;
//
//SOR(ASor, bSor, x0Sor, xSor, omega, kmax, 0.000001, 'm', DEBUGON);
//
//
//xSor.imprime(30);


system("pause");


	std::locale mylocale("");
	std::cout.imbue(mylocale);

/*	const double pi = acos(-1);
	double Vf1[] = { 2,-3 };
	double Vf2[] = { pi/2,pi };
	double Vf3[] = { 0,2,pi / 2 };
	Matriz mF1(Vf1, 2, 1), mF2(Vf2, 2, 1), mF3(Vf3, 3, 1);
	//Matriz Xf1(2, 1), Xf2(2, 0), Xf3(3, 0);

	double h = 1e-3;

	//Gradiente(mF1, Xf1, F1,h);

	//Gradiente(mF2, Xf2, F2, h);

	//Gradiente(mF3, Xf3, F3,h);

	cout  << std::setprecision(2);

	cout << std::setprecision(2)<< endl <<  '\t' << "O Gradiente da Funcao 1 em ( " << Vf1[0] << " , " << Vf1[1] << " ) e : " << endl;
	Gradiente(mF1, F1, h).imprime(3);

	cout << std::setprecision(2) << endl << '\t' << "O Gradiente da Funcao 2 em ( " << Vf2[0] << " , " << Vf2[1] << " ) e : " << endl;
	Gradiente(mF2, F2, h).imprime(3);

	cout << std::setprecision(2) << endl << '\t' << "O Gradiente da Funcao 3 em ( " << Vf3[0] << " , " << Vf3[1] << " , " << Vf3[2] << " ) e : " << endl;
	Gradiente(mF3, F3, h).imprime(3);
	*/

/*	int erro=0;
	cout << endl << " a Raiz da parababola pela minha secante e: " << Secante(16, 6, Parabola, erro,100, 1e-03) << endl;
	cout << endl << " a Raiz da parababola pela minha Bisecao e: " << Biseccao(1,17, Parabola, 100, 1e-03) << endl;


	/*
	auto Arquivo = fopen("Gradiente.txt","w");
	h = 1e-3;
	for (auto i = 0; i < 16; i ++)
	{


		Gradiente(mF1, Xf1, F1, h);

		Gradiente(mF2, Xf2, F2, h);

		Gradiente(mF3, Xf3, F3, h);

		fprintf(Arquivo, " %5.30e\t%5.30e\t%5.30e\t%5.30e\t%5.30e\t%5.30e\t%5.30e\t%5.30e\t\n", h, Xf1.saida(0,0), Xf1.saida(1,0), Xf2.saida(0, 0), Xf2.saida(1, 0), Xf3.saida(0, 0), Xf3.saida(1, 0), Xf3.saida(2, 0));
		h /= 10;
	}
	fclose(Arquivo);
	*/
	system("pause");


    // ============================================
    // TERMINE SUA PROGRAMAÇÃO ACIMA DESSA MENSAGEM
    // ============================================
	return 0;
}


