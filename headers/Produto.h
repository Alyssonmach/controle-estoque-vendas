#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// definindo uma struct com os atributos do produto
struct Produto_prototipo 
{
	float preco_loja;
	float preco_consumidor;
	string nome;
	string categoria;
	string fabricante;
	int quantidade;
	long int codigo;
};

// definindo a classe Produto (configura e retorna os atributos do produto)
class Produto 
{
	// esécificador de acesso private
	private:
		// membro de dados da classe
		Produto_prototipo objeto_produto;
    // especificador de acesso public
    public:
    	// construtor da classe (default)
    	Produto(float = 0.0, float = 0.0, string = " ", string = " ", string = " ", 
				int = 0, long int = 0);
    	// membros de funções da classe
    	bool valida_objeto_produto(Produto_prototipo);
		void set_objeto_produto(Produto_prototipo);
		void set_preco_loja(float);
		void set_preco_consumidor(float);
		void set_nome(string);
		void set_categoria(string);
		void set_fabricante(string);
		void set_quantidade(int);
		void set_codigo(long int);
		Produto_prototipo get_objeto_produto(void) const;
};

#endif