// Arquivo .cpp: é o arquivo onde iremos programar as funções que desejamos.
// Sempre, antes de rodar o programa, precisamos declarar o protótipo
// de cada função no arquivo .h (header ou cabeçalho), que funciona como
// um sumário das funções disponíveis na biblioteca


// inclusão do cabeçalho que aponta para esse arquivo
#include <iostream>
using namespace std;

# include "minhabiblioteca.h"
# include "matriz.h"
# include "minhasfuncoes.h"
#include "Trabalho.h"
# include <math.h>
// .
// .
// .
// .
// .
// A TUA PROGRAMAÇÃO DEVE FICAR DEPOIS DESSA MENSAGEM. DEIXE 5 LINHAS ACIMA SEM PROGRAMAÇÃO
// ========================================================================================


// LISTA DE FUNÇÕES A SEREM CRIADAS:

// Valores máximo e mínimo de um vetor
// Valores máximo e mínimo de uma matriz

// média dos valores de um vetor
// média dos valores de uma matriz


// Soma de matrizes     Matriz SOMA(Matriz A, Matriz B);
// Soma de vetores      a função de cima deve já servir;


// Multiplicação de matrizes
// produto interno entre vetores
// produto vetorial entre vetores
// mutiplicação de matriz por vetor
// transposição de vetores e matrizes
// Copiar uma linha de uma matriz para um vetor
// copiar uma coluna de uma matriz para um vetor


// Cria uma matriz identidade
void Identidade (Matriz &ID)
{
    int L,C,i;

    L = ID.dim('l');
    C = ID.dim('c');

    // Conferindo se a matriz é quadrada
    if (L!=C)
    {
        cout << "A matriz nao e quadrada. Abortando...";
        abort();
    }

    for(i=0;i<L;i++)
    {
        ID.entrada(i,i, 1);
    }
}

// Copia a Matriz A para a matriz B.
void Copia (Matriz &A , Matriz &B)
{
    // precisa checar se linhas e colunas são iguais
    // Não retorna nenhuma matriz

    int LA, LB, CA, CB, i,j;

    double temp;

    // Descobre o numero de linahs e colunas das matrizes
    LA = A.dim('l');
    LB = B.dim('l');
    CA = A.dim('c');
    CB = B.dim('c');

    if ( LA!=LB || CA!=CB)
    {
        cout << "As matrizes nao tem dimensoes iguais. Abortando...";
        abort();
    }

    for(i=0; i<LA; i++)
    {
        for (j=0; j<CA; j++)
        {
            temp = A.saida(i,j);
            B.entrada(i,j, temp );
        }
    }

}


void SOMA(Matriz &A , Matriz &B, Matriz &C)
{
    // Checar se as dimensões de A e B são Iguais
    // Criar uma nova Matriz onde cada elemento resulta da soma de cada elemento correspondente nas matrizes
    // deve retornar uma matriz
    int LA, LB, LC, CA, CB, CC, i,j;

    double temp;

    // Descobre o numero de linahs e colunas das matrizes
    LA = A.dim('l');
    LB = B.dim('l');
    LC = C.dim('l');
    CA = A.dim('c');
    CB = B.dim('c');
    CC = C.dim('c');

    // Confere se A e B tem a mesma dimensão
    if ( LA!=LB || CA!=CB)
    {
        cout << "As matrizes nao tem dimensoes iguais. Abortando...";
        abort();
    }

    // Confere se A e C tem a mesma dimensão
    if ( LA!=LC || CA!=CC)
    {
        cout << "As matrizes nao tem dimensoes iguais. Abortando...";
        abort();
    }

    for (i=0; i<LA; i++)
    {
        for (j=0; j<CA; j++)
        {
            temp = A.saida(i,j) + B.saida(i,j);
            C.entrada(i,j, temp );
        }
    }
}

void SUBTRAI(Matriz &A , Matriz &B, Matriz &C)
{
    // Checar se as dimensões de A e B são Iguais
    // Criar uma nova Matriz onde cada elemento resulta da subtraçao de cada elemento correspondente nas matrizes
    // deve retornar uma matriz
    int LA, LB, LC, CA, CB, CC, i,j;

    double temp;

    // Descobre o numero de linhas e colunas das matrizes
    LA = A.dim('l');
    LB = B.dim('l');
    LC = C.dim('l');
    CA = A.dim('c');
    CB = B.dim('c');
    CC = C.dim('c');

    // Confere se A e B tem a mesma dimensão
    if ( LA!=LB || CA!=CB)
    {
        cout << "As matrizes nao tem dimensoes iguais. Abortando...";
        abort();
    }

    // Confere se A e C tem a mesma dimensão
    if ( LA!=LC || CA!=CC)
    {
        cout << "As matrizes nao tem dimensoes iguais. Abortando...";
        abort();
    }

    for (i=0; i<LA; i++)
    {
        for (j=0; j<CA; j++)
        {
            temp = A.saida(i,j) - B.saida(i,j);
            C.entrada(i,j, temp );
        }
    }
}

void MULTIPLICA(Matriz &A , Matriz &B, Matriz &C)
{
    // Checar se as dimensões SÃO COMPATÍVEIS
    // deve retornar uma matriz

    int LA, LB, LC, CA, CB, CC;

    LA = A.dim('l');
    CA = A.dim('c');
    LB = B.dim('l');
    CB = B.dim('c');
    LC = C.dim('l');
    CC = C.dim('c');
    //verifica se o numero de colunas de A e igual ao numero de linhas de B
    if (CA != LB)
    {
        cout << "As matrizes nao podem ser multiplicadas. Dimensoes erradas para A e B. Abortando...";
        abort();
    }
    //verifica se a matriz C tem a quantidade de linhas de A e colunas de B
    if ((LA != LC) || (CB != CC))
    {
        cout << "A matriz C nao tem as dimensoes corretas. Abortando...";
        abort();
    }

    int i, j, k;
    double SOMAT, aik, bkj;

    for (i=0; i<LA; i++)  // percorre as linhas da matriz resposta
    {
        for (j=0; j<CB; j++) // percorre as colunas da matriz resposta
        {
            SOMAT = 0;

            for(k=0; k<CA; k++) //faz o somatorio dos elementos da linha i de A multiplicados pelos elementos da coluna j de B
            {
                aik = A.saida(i,k);
                bkj = B.saida(k,j);
                SOMAT = SOMAT + aik*bkj;
            }
            C.entrada(i, j, SOMAT);
        }
    }
}

void TRANSPOSTA(Matriz &A, Matriz &AT)
{
    int LA, CA, LAT, CAT;

    LA = A.dim('l');
    CA = A.dim('c');
    LAT = AT.dim('l');
    CAT = AT.dim('c');

    if ((LAT != CA) || (CAT != LA))
    {
        cout << "Erro de dimensao na funcao TRANSPOSTA. Abortando...";
        abort();
    }

    int i, j;
    double temp;

    for (i=0; i<LA; i++)
    {
        for (j=0; j<CA; j++)
        {
            temp = A.saida(i,j);
            AT.entrada(j,i, temp);
        }
    }

}

double DerivParc (Matriz &X, int i, double h)
{
    int n = X.dim('c');
    if (i>=n)
    {
        cout << "A derivada parcial nao pode ser calculada para o i informado. Abortando...";
        abort();
    }
   if (h<=0)
    {
        cout << "H não pode ser 0, pois é denominador no calculo de derivada parcial. Abortando...";
        abort();
    }
    Matriz H(1,n), XH(1,n);
    H.entrada(0, i, h);
    SOMA(X, H, XH);
    return (funcaopadrao(XH)-funcaopadrao(X))/h;
}

double e2xTAYLOR (double x , int n)
{
    //SÉRIE DE tAYLOR DA FUNÇÃO e^{2x}
	return 0;
}

int fatorial (int n)
{
    //Fatorial de um número inteiro positivo
	return 0;
}

double DerivProg (double x, double h)
{
    //Calcula a derivada progressiva de funcao padrao
    return(funcaopadrao(x+h)-funcaopadrao(x))/h;
}

double DerivReg (double x, double h)
{
    //Calcula a derivada regressiva de funcao padrao
    return(funcaopadrao(x)-funcaopadrao(x-h))/h;
}

double DerivCen (double x, double h)
{
    //Calcula a derivada central de funcao padrao
    return(funcaopadrao(x+h)-funcaopadrao(x-h))/(2*h);
}

double DerivSeg (double x, double h)
{
    //Calcula a derivada segunda de funcao padrao
    return(funcaopadrao(x+h)-2*funcaopadrao(x)+funcaopadrao(x-h))/(h*h);
}

void TriangSup (Matriz &A, Matriz &b, Matriz &x, bool DBG_VIEW)
{
    int l=A.dim('l'), c=A.dim('c');
    int i, j;
    double somat, temp_xi;
    temp_xi = b.saida(l-1, 0)/A.saida(l-1, l-1);
    x.entrada(l-1, 0, temp_xi);
    if (DBG_VIEW)
    {
        cout << "\nXn = " << x.saida(l-1, 0) << "\n";
    }
    i=l-2;
    while(i>=0)
    {
        somat=0.0;
        for(j=i+1; j<l; j++)
        {
            somat=somat+A.saida(i, j)*x.saida(j, 0);
        }
        if(DBG_VIEW)
        {
            cout << "\n somat = " << somat << "\n";
        }
        temp_xi=(b.saida(i, 0)-somat)/A.saida(i, i);
        x.entrada(i, 0, temp_xi);
        i=i-1;
    }
}

void EliminGauss (Matriz &A, Matriz &b, bool DBG_VIEW)
{
    int n, k=0, i=0, j=0;
    // A deve ser quadrada (A, A_)
    // numero de linhas de b = ordem de A
    n=A.dim('c');
    double m, tempA, tempb;
 
    for (k=0; k<n-1; k++)
    {
		Pivoteia(A, b,  n, k, DBG_VIEW);

        for(i=k+1; i<n; i++)
        {
            m = A.saida(i, k)/A.saida(k, k);
            A.entrada(i, k, 0.0);

            for(j=k+1; j<n; j++)
            {
                tempA = A.saida(i, j) - m*A.saida(k, j);
                A.entrada(i, j, tempA);
            }
            tempb = b.saida(i,0)-m*b.saida(k,0);
            b.entrada(i, 0, tempb);
        }
    }
}


void Jacobi(Matriz &A, Matriz &b, Matriz &x0, Matriz &x, int kmax, double ERRO, bool DBG_VIEW)
{
    int n,i,j,k,indice;
    double temp_i,somat;
    n = A.dim('l');
    Matriz Xk(n,1), Xk1(n,1); // xk resposta atual xk1 nova resosta
    Copia(x0,Xk);
    for(k=0;k<kmax;k++)
    {
        for(i=0;i < n;i++)
        {

            somat = 0.0;
            for(j=0;j < n;j++)
            {
                if(j!=i)
                   {
					 somat+=A.saida(i,j)*Xk.saida(j,0);
                   }

            }//j
          temp_i = (b.saida(i,0)-somat)/A.saida(i,i);
          Xk1.entrada(i,0,temp_i);


        }//i

        // teste de parada
        somat=0.0;
        for(indice=0;indice<n;indice++)
        {
            somat+= pow(Xk1.saida(indice,0)- Xk.saida(indice,0),2);
        }
        somat=pow(somat,0.5);
        if(somat < ERRO)
        {
			if (DBG_VIEW)
			{
				cout << endl << " Teste de Parada Excutado ERRO > que  " << somat;
			}
            break;
        }

        Copia(Xk1,Xk); // atualiza estimativas
        if(DBG_VIEW)
         {
             Xk1.imprime(10);
             cout << '\n';
         }
    }//k

    Copia(Xk1,x);

}

void GaussSeidel(Matriz &A, Matriz &b, Matriz &x0, Matriz &x, int kmax, double ERRO, bool DBG_VIEW)
{
    int n,i,j,k,indice;
    double temp_i,somat;
    n = A.dim('l');
    Matriz Xk(n,1), Xk1(n,1); // xk resposta atual xk1 nova resposta
    Copia(x0,Xk);
    for(k=0;k<kmax;k++)
    {
        for(i=0;i < n;i++)
        {

            somat = 0.0;
            for(j=0;j < n;j++)
            {
                if(j < i)
                   {
                     somat+=A.saida(i,j)*Xk1.saida(j,0);// pega a estimativa atualizada
                   }
                   if(j>i)
                   {
                     somat+=A.saida(i,j)*Xk.saida(j,0);// pega a estimativa corrente
                   }


            }//j
          temp_i = (b.saida(i,0)-somat)/A.saida(i,i);
          Xk1.entrada(i,0,temp_i);


        }//i
        // teste de parada
        somat=0.0;
        for(indice=0;indice<n;indice++)
        {
            somat+= pow(Xk1.saida(indice,0)- Xk.saida(indice,0),2);
        }
        somat=pow(somat,0.5);
        if(somat < ERRO)
        {
			if (DBG_VIEW)
			{
				cout << endl << " Teste de Parada Excutado ERRO > que  " << somat << endl;
			}
            break;
        }

        Copia(Xk1,Xk); // atualiza estimativas
        if(DBG_VIEW)
         {
             Xk1.imprime(10);
             cout << '\n';
         }
    }//k

    Copia(Xk1,x);

}




void GaussSeidel2(Matriz &A, Matriz &b, Matriz &x0, Matriz &x, int kmax, double ERRO, char criterio, bool DBG_VIEW)
{
	int n, i, j, k, indice;
	double temp_i, somat, Max;
	n = A.dim('l');
	Matriz Xk(n, 1), Xk1(n, 1); // xk resposta atual xk1 nova resosta
	Copia(x0, Xk);
	for (k = 0; k<kmax; k++)
	{
		for (i = 0; i < n; i++)
		{

			somat = 0.0;

			for (j = 0; j <= i - 1; j++)
			{

				somat += A.saida(i, j)*Xk1.saida(j, 0);// pega a estimativa atualizada
			}

			for (j = i + 1; j < n; j++)
			{

				somat += A.saida(i, j)*Xk.saida(j, 0);// pega a estimativa corrente
			}//j



			temp_i = (b.saida(i, 0) - somat) / A.saida(i, i);
			Xk1.entrada(i, 0, temp_i);


		}//i
		if (criterio == 'm')
		{
			// teste de parada modulo do vetor
			somat = 0.0;
			for (indice = 0; indice<n; indice++)
			{
				somat += pow(Xk1.saida(indice, 0) - Xk.saida(indice, 0), 2);
			}
			somat = pow(somat, 0.5);
			if (somat < ERRO)
			{
				if (DBG_VIEW)
				{
					cout << endl << " Teste de Parada Modulo do Vetor Excutado ERRO > que  " << somat << endl;
				}
				break;
			}
		}
		if (criterio == 'M') // criterio do maximo
		{
			Max = abs(Xk1.saida(0, 0) - Xk.saida(0, 0));
			for (j = 1; j<n; j++)
			{
				if (abs(Xk1.saida(j, 0) - Xk.saida(j, 0))>Max)
				{
					Max = abs(Xk1.saida(j, 0) - Xk.saida(j, 0));
				}
			}
			if (Max < ERRO)
			{
				if (DBG_VIEW)
				{
					cout << endl << " Teste de Parada Critério do Máximo Executado : Erro >  que  " << Max << endl;
				}
				break;
			}
		}

		Copia(Xk1, Xk); // atualiza estimativas
		if (DBG_VIEW)
		{
			Xk1.imprime(10);
			cout << '\n';
		}
	}//k

	Copia(Xk1, x);

}


void Jacobiana(Matriz &X, Matriz &JAC, double h)
{
	//JAC tem que ser quadrada(nxn), X tem que ser Nx1
	int n = X.dim('l'), i, j;
	Matriz H(n, 1), Xh(n, 1), F(n, 1), Fh(n, 1);
	funcaopadrao(X, F);

	for (j = 0; j<n; j++)
	{
		if (j >= 1)
		{
			H.entrada(j - 1, 0, 0);
		}

		H.entrada(j, 0, h);
		SOMA(X, H, Xh);
		funcaopadrao(Xh, Fh);

		for (i = 0; i<n; i++)
		{

			JAC.entrada(i, j, (1 / h)*(Fh.saida(i, 0) - F.saida(i, 0)));

		}//for do i


	}//for do j


}// 




// ========================================================================================
// A TUA PROGRAMAÇÃO DEVE FICAR ANTES DESSA MENSAGEM. DEIXE 5 LINHAS ABAIXO SEM PROGRAMAÇÃO
// .
// .
// .
// .
// .

// Função de teste. mantenha essa função no fim do arquivo. Não a apague.
// apenas programa acima dela.
void TesteDeFuncaoComCabecalho (void)
{
    // o protótipo da função foi declarada no arquivo .h (header)
    // nesse arquivo (.cpp) é onde iremos realizar a programação do que
    // queremos que a função faça. Nessa função de teste, ela irá apenas
    // imprimir um pequeno texto na tela.

    cout << "Esta e uma funcao de teste." << endl;
}

