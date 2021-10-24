#ifndef MATRIZ
#define MATRIZ

# include <cassert>
# include <cstdlib>
# include <iostream>
#include <fstream>
#include <locale>
using namespace std;

# include <cmath>
# include <iomanip>
# include <stdio.h>
# include <string>


class iterador
{
public:

	iterador (class Matriz  & F, bool reverso = false, bool Cm = false, int ii = 0, int jj = 0);
	~iterador();
	bool				  operator==(iterador const &);
	bool				  operator!=(iterador const &);
	double				& operator *();
	iterador			  operator++() {passo(1); return *this;};
	iterador			  operator++(int);
	iterador			  operator--(){passo(-1); return *this;};;
	iterador			  operator--(int);
	void				  setaPos(int, int);
	void				  pegaPos(int &, int &);
	void				  setaColunaMaior(bool = false);
	bool				  pegaColunaMaior();


private:
	class Matriz const & M;
	int i, j, inicio, fim, pos;
	bool CMaior;
	int p;
	void atualizaPosicao();
	void passo(int = 1);
};


// Classe de Matrizes
class Matriz
{
    public:
        // CONSTRUTORES DO OBJETO MATRIZ

        // Construtor Default
        Matriz();
        // Cria vetor
        Matriz (int);
        // Cria Matriz
        Matriz (int, int);
        // Cria Matriz a partir de uma lista estática
        Matriz (double *, int, int);
        // Cria um vetor a partir de uma lista estática
        Matriz (double *, int);
		Matriz ( Matriz const &); //construtor de copia
		Matriz( Matriz  &&); //construtor de transferência

        // FUNÇÕES DE IMPRESSÃO, ACESSO E ALTERAÇÃO DE MATRIZES

        // Imprime uma matriz
        void imprime(int=4 , int=4);
		void salva(const char *, int = 4, int = 4);
        // acessa um elemento da matriz
        double saida(int, int);
        // Acessa um elemento do vetor
        double saida(int);
        // verifica a dimensão da matriz
        int dim(char) const;
        // altera um elemento específico da matriz
        void entrada(int, int, double);

        // Acessa um elemento específico do vetor
        void entrada(int, double);
		double & operator()(int,int=0) const;
		double & operator[](int) const;

        // Destruidor do objeto Matriz
        ~Matriz();
		Matriz transposta();
		bool Quadrada();
		//Metodos para operadores
		Matriz & operator=(Matriz const &); // operador de atribuicao copia
		Matriz & operator=(Matriz &&); // operador de atribuicao transferencia
		const Matriz  operator -() const;
		Matriz  & operator -();
		friend Matriz operator+(Matriz  &, Matriz &);
		friend Matriz operator-(Matriz  &, Matriz &);
		friend Matriz operator*(Matriz  &, Matriz &);
		friend Matriz operator*(Matriz &, double);
		friend Matriz operator*(double, Matriz &);
		friend Matriz operator/(Matriz &, double);
		friend Matriz operator/(double, Matriz &);

		// Metodos para os iteradores
		friend class iterador;
		iterador inicio();// iterador para o inicio da Matriz. Aponta para Matriz(0,0)
		iterador fim();//    iterador para o fim da Matriz. Aponta para Matriz(linha-1,coluna-1)

		iterador rinicio();// iterador reverso para a matriz. Aponta para Matriz(linha-1,coluna-1)
		iterador rfim();// iterador reverso para o fim da Matriz. . Aponta para Matriz(0,0)


    private:
        double **elemento= NULL;
        int linha=0;
        int coluna=0;
        bool quadrada = (linha==coluna);
};


#endif // MATRIZ
