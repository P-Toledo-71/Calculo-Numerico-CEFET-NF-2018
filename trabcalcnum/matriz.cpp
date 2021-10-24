#include "matriz.h"

static double ** AlocaMatriz(int linha, int coluna = 1);

// CLASSE DE MATRIZES
// ==================

// Construidor padrão
Matriz::Matriz()
{
    linha = 0;
    coluna = 0;
    elemento = NULL;
}

// Cria uma matriz quadrada de ordem definida pelo parâmetro tamanho
Matriz::Matriz(int tamanho)
{

    linha  =  (tamanho <1)  ? 1 : tamanho;
    coluna =  (tamanho < 1) ? 1 : tamanho;
	quadrada = (linha == coluna);
	elemento = AlocaMatriz(tamanho, tamanho);
}

// Construtor de transferência - Usado para transferir Matrizes temporarias entre procedimentos sem ter que copiar todos os dados
Matriz::Matriz(Matriz && Fonte)
{
	linha = Fonte.linha;
	coluna = Fonte.coluna;
	quadrada = (linha == coluna);
	elemento = Fonte.elemento; // Salva referencia para a matriz no objeto novo
	Fonte.elemento = nullptr;// Destroi a referencia para a matriz no objeto antigo
}


// Construtor de Copia - Cria uma copia da Matriz original

Matriz::Matriz(Matriz const & Fonte)
{
	linha = Fonte.linha;
	coluna = Fonte.coluna;
	quadrada = (linha == coluna);
	elemento = AlocaMatriz(linha, coluna);

	for(int i=0;i<linha;i++)
	{

		for (int j = 0; j<coluna; j++)
		{
			elemento[i][j] = Fonte.elemento[i][j];

		}

	}
}


Matriz::Matriz(int L, int C)
{
    linha  = (L>0 ? L : 1);
    coluna = (C>0 ? C : 1);
	quadrada = (linha == coluna);
	elemento = AlocaMatriz(linha, coluna);

}


// Cria matriz a partir de uma lista 2d de valores
Matriz::Matriz(double *LISTA, int L, int C)
{
    linha  = (L>0 ? L : 1);
    coluna = (C>0 ? C : 1);
	quadrada = (linha == coluna);
	elemento = AlocaMatriz(linha, coluna);



    for (int i = 0; i < linha; i++)
    {

        for (int j = 0; j < coluna; j++)
        {
            elemento[i][j] = static_cast <double> (LISTA[i*coluna+j]);

        }

    }
}

// Cria matriz a partir de uma lista 2d de valores          ***********************************************
Matriz::Matriz(double *LISTA,int C)
{
    linha  = 1;
    coluna = (C>0 ? C : 1);
	quadrada = (linha == coluna);
    elemento = AlocaMatriz(linha,coluna);


	for (int j = 0; j < coluna; j++)
	{
		elemento[0][j] = static_cast <double> (LISTA[j]);

	}

}



// Destruidor da Matriz
Matriz::~Matriz()
{
	if (elemento)
	{
		for (int i = 0; i < linha; i++)
		{
			delete[]elemento[i];
		}
		delete[]elemento;
	}
}


Matriz Matriz::transposta()
{

		Matriz AT(coluna, linha);

		for (int i = 0; i<linha; i++)
		{
			for (int j = 0; j<coluna; j++)
			{
				AT.elemento[j][i]  = elemento[i][j];

			}
		}

		return AT;
}

bool Matriz::Quadrada()
{
	return quadrada;
}



void Matriz::imprime(int decimais, int space)
{
    int MaxMod = 0;
    int i = 0, j = 0, k=0, M=0;
	locale atual(std::cout.getloc());
	std::cout.imbue(std::locale(""));

    // Descobre a maior magnitude das componentes da matriz
    i = 0;
    while (i<linha)
    {
        j = 0;
        while (j<coluna)
        {

            M = int(  floor(log10( fabs(elemento[i][j]) ) )  );
            if ( M > MaxMod )
            {
                MaxMod = M;
            }

            j++;
        }
        i++;
    }


    // Imprime cada entrada do vetor
    i=0;
    while (i<linha)
    {
        j = 0;
        while (j < coluna)
        {
            // Magnitude do número atual
            M = int(  floor(log10( fabs(elemento[i][j]) ))   );

            // Imprime sinal de positivo, negativo ou espaço em branco
            if (elemento[i][j]>0.)
            {
                cout << "+";
            }
            else if (elemento[i][j]<0)
            {
                cout << "-";
            }
            else
            {
                cout << " ";
            }

            // Impressão dos números cujo módulo é maior do que 1
            if ( floor (fabs( elemento[i][j] )) > 1.)
            {
                k=0;
                while(k<(MaxMod-M))
                {
                    cout << "0";
                    k++;
                }
            }
            // impressão dos número menores que 1 (da forma 0.xxxx)
            else
            {
                k=0;
                while(k<MaxMod)
                {
                    cout << "0";
                    k++;
                }
            }

            // Imprime a quantidade de casas decimais pedidas, com precisão fixa
            if (elemento[i][j]>0)
            {
                cout << setprecision(decimais) << std::fixed << elemento[i][j];
            }
            else if (elemento[i][j]<0)
            {
                cout << setprecision(decimais) << std::fixed << -1.0*elemento[i][j];
            }
            else
            {
                cout << setprecision(decimais) << std::fixed << elemento[i][j];
            }


            k=0;
            while (k<space)
            {
                printf(" ");
                k++;
            }
            // Incremento de Coluna
            j++;
        }
        // Salta uma linha
        cout << endl;
        // Incremento de linnha
        i++;
    }
	std::cout.imbue(atual);
}

void Matriz::salva(const char * arq, int decimais, int space)
{
	int MaxMod = 0;
	int i = 0, j = 0, k = 0, M = 0;
	std::fstream cout(arq,std::fstream::out);
	cout.imbue(std::locale(""));
	// Descobre a maior magnitude das componentes da matriz
	i = 0;
	while (i<linha)
	{
		j = 0;
		while (j<coluna)
		{

			M = int(floor(log10(fabs(elemento[i][j]))));
			if (M > MaxMod)
			{
				MaxMod = M;
			}

			j++;
		}
		i++;
	}


	// Imprime cada entrada do vetor
	i = 0;
	while (i<linha)
	{
		j = 0;
		while (j < coluna)
		{
			// Magnitude do número atual
			M = int(floor(log10(fabs(elemento[i][j]))));

			// Imprime sinal de positivo, negativo ou espaço em branco
			if (elemento[i][j]>0.)
			{
				cout << "+";
			}
			else if (elemento[i][j]<0)
			{
				cout << "-";
			}
			else
			{
				cout << " ";
			}

			// Impressão dos números cujo módulo é maior do que 1
			if (floor(fabs(elemento[i][j])) > 1.)
			{
				k = 0;
				while (k<(MaxMod - M))
				{
					cout << "0";
					k++;
				}
			}
			// impressão dos número menores que 1 (da forma 0.xxxx)
			else
			{
				k = 0;
				while (k<MaxMod)
				{
					cout << "0";
					k++;
				}
			}

			// Imprime a quantidade de casas decimais pedidas, com precisão fixa
			if (elemento[i][j]>0)
			{
				cout << setprecision(decimais) << std::fixed << elemento[i][j];
			}
			else if (elemento[i][j]<0)
			{
				cout << setprecision(decimais) << std::fixed << -1.0*elemento[i][j];
			}
			else
			{
				cout << setprecision(decimais) << std::fixed << elemento[i][j];
			}


			k = 0;
			while (k<space)
			{
				printf(" ");
				k++;
			}
			// Incremento de Coluna
			j++;
		}
		// Salta uma linha
		cout << endl;
		// Incremento de linnha
		i++;
	}
	cout.close();
}

// Acessa dado interno à matriz
double Matriz::saida(int L, int C)
{
	return operator()(L, C);
}

double & Matriz::operator()(int L, int C) const
{

	if ((L<linha) && (C < coluna))
	{
		return  elemento[L][C];
	}
	else
	{
		throw 1;
		cout << "Erro de indice da matriz. Abortando...\n\n";
		abort();
	}
}

// Acessa dado interno à matriz - caso especial de quando a matriz é um vetor
double & Matriz::operator[](int POSITION) const
{
	if (POSITION<linha)
	{
		return elemento[POSITION][0];
	}
	else
	{
		cout << "Erro de indice da matriz. Abortando...\n\n";
		abort();
	}
}

// Acessa dado interno à matriz - caso especial de quando a matriz é um vetor
double Matriz::saida(int POSITION)
{
	return operator [](POSITION);
}

// Altera dado interno à matriz
void Matriz::entrada(int L, int C, double IN)
{
	operator()(L, C) = IN;

}

// Altera dado interno ao vetor
void Matriz::entrada(int POSITION , double IN)
{
	operator [](POSITION) = IN;
}


// Imprime a dimensão da Matriz
 int Matriz::dim( char LC) const
 {
     if (LC=='l') { return linha;}
     else if (LC=='c') { return coluna; }
     else
     {
         cout << "Funcao dim deve receber 'l' (linha) ou 'c' (coluna) como parametro de entrada. Abortando...\n\n";
         abort();
     }
 }


 Matriz & Matriz::operator=(Matriz const & Fonte)
 {
	 if (linha == Fonte.linha && coluna == Fonte.coluna)
	 {
		 for (auto i = 0; i < linha; i++)
			 for (auto j = 0; j < coluna; j++)
				 elemento[i][j] = Fonte.elemento[i][j];
		 return *this;
	 }
	 else
	 {
		 cout << endl
			 << "As matrizes possuem dimensoes diferentes.  Funcao operador de atribuicao por copia para Matrizes -  Abortando..." <<
			     endl;
		 abort();
	 }


 }

 Matriz & Matriz::operator=(Matriz && Fonte)
 {
	 if (linha == Fonte.linha && coluna == Fonte.coluna)
	 {
		 elemento = Fonte.elemento;
		 Fonte.elemento = nullptr;
		 return *this;
	 }
	 else
	 {
		 cout << endl
			 << "As matrizes possuem dimensoes diferentes.  Funcao operador de atribuicao por tranferencia para Matrizes -  Abortando..." <<
			 endl;
		 abort();
	 }


 }
 const Matriz Matriz::operator-() const
 {
	 Matriz A(*this);

	 for (auto i = A.inicio(); i != A.fim(); i++)
	 {
		 *i *= -1.0;
	 }

	 return A;
 }

  Matriz & Matriz::operator-()
 {
	 Matriz &A =*this;

	 for (auto i = A.inicio(); i != A.fim(); i++)
	 {
		 *i *= -1.0;
	 }

	 return A;
 }
 //

 double ** AlocaMatriz(int linha, int coluna)
 {
	 double **elemento = new double *[linha];
	 int i = 0;
	 if (elemento != nullptr)
	 {


		 for (i = 0; i < linha; i++)
		 {
			 elemento[i] = new double[coluna];
			 if (elemento[i] != nullptr)
				 for (int j = 0; j < coluna; j++)
				 {
					 elemento[i][j] = 0.0;

				 }
			 else break;
		 }
	 }

	 if (i < linha)
	 {
		 cout << endl << "Problemas na alocacao de memoria - funcao AlocaMatriz - Abortando" << endl;
		 exit(1);
	 }

	 return elemento;
 }

 Matriz operator+(Matriz  & A, Matriz  &B)
 {
	 // Checar se as dimensões de A e B são Iguais
	 // Criar uma nova Matriz onde cada elemento resulta da soma de cada elemento correspondente nas matrizes
	 // deve retornar uma matriz





	 // Confere se A e B tem a mesma dimensão
	 if  (A.linha != B.linha || A.coluna != B.coluna)
	 {
		 cout << "As matrizes nao tem dimensoes iguais. Abortando...";
		 abort();
	 }
	 Matriz C(A);
	 for (int i = 0; i<A.linha; i++)
	 {
		 for (int j = 0; j<A.coluna; j++)
		 {

			 C(i, j) = A(i, j) + B(i, j);
		 }
	 }



	 return C;
 }

 Matriz operator-(Matriz  & A, Matriz  &B)
 {
	 // Checar se as dimensões de A e B são Iguais
	 // Criar uma nova Matriz onde cada elemento resulta da subtracao de cada elemento correspondente nas matrizes
	 // deve retornar uma matriz
	 // Confere se A e B tem a mesma dimensão
	 if (A.linha != B.linha || A.coluna != B.coluna)
	 {
		 cout << "As matrizes nao tem dimensoes iguais. Abortando...";
		 abort();
	 }

	 Matriz C(A.linha,A.coluna);

	 for (int i = 0; i < A.linha; i++)
	 {
		 for (int j = 0; j < A.coluna; j++)
		 {
			 C(i, j) = A(i, j) - B(i, j);
		 }
	 }

	 return C;
 }

 Matriz operator*(Matriz  & L, Matriz  &R)
 {
	 // Checar se as dimensões de A e B são Iguais
	 // Criar uma nova Matriz onde cada elemento resulta da soma da multiplicacao das linhas de L de cada elemento correspondente nas matrizes
	 // deve retornar uma matriz
	 // Confere se A e B tem a mesma dimensão
	 if (L.coluna == R.linha)
	 {


		 Matriz A(L.linha, R.coluna);
		 for (int i = 0; i < A.linha; i++)
			 for (int j = 0; j < A.coluna; j++)
				 for (int ii = 0; ii < L.coluna; ii++) A.elemento[i][j] += L.elemento[i][ii] * R.elemento[ii][j];
		 return A;
	 }

	 else
	 {
		 cout << "As matrizes nao tem dimensoes compativeis. Abortando...";
		 abort();
	 }
 }

 Matriz operator*(Matriz & M, double F)
 {

	 if (F != 1.0)
	 {
		 Matriz A(M);
		 for (auto i = A.inicio(); i != A.fim(); i++)
		 {
			 *i *= F;
		 }
		 return A;
	 }
	 else return Matriz(M);
 }

 Matriz operator*( double F, Matriz & M)
 {

	 return operator*(M,F);

 }

 Matriz operator/(Matriz & M, double F)
 {
	 return operator*(M, 1.0 / F);
 }

 Matriz operator/(double F, Matriz & M)
 {

	 return operator*(M, 1.0/F);

 }

  iterador Matriz::inicio()
 {

	 return iterador(*this,false,false,0,0);

 }

  iterador Matriz::fim()
  {
	  return iterador(*this, false, false, linha, coluna);
  }

  iterador Matriz::rinicio()
  {
	  return  iterador(*this, true, false, linha-1, coluna-1);
  }

  iterador Matriz::rfim()
  {

	  return iterador(*this, true, false, -1 ,-1);

  }
