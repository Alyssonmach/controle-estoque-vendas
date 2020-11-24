#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// atributos associados a um produto basico
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

class Produto 
{
	private:
		// define uma estrutura com todos os atributos associados a um produto
		Produto_prototipo objeto_produto;
    public:
    	Produto(float = 0.0, float = 0.0, string = " ", string = " ", string = " ", int = 0, long int = 0);
        // metodo que verifica se um objeto a ser cadastrado e inconsistente
    	bool valida_objeto_produto(Produto_prototipo);
    	// metodo que configura uma estrutra no objeto da classe produto
		void set_objeto_produto(Produto_prototipo);
		// metodo que configura o atributo associado ao preco de aquisicao do produto
		void set_preco_loja(float);
		// metodo que configura o atributo associado ao preco repassado ao consumidor
		void set_preco_consumidor(float);
		// metodo que configura o atributo associado ao nome do produto
		void set_nome(string);
		// metodo que configura o atributo associado a categoria do produto
		void set_categoria(string);
		// metodo que configura o atributo associado ao fabricante do produto
		void set_fabricante(string);
		// metodo que configura o atributo associado a sua quantidade em estoque
		void set_quantidade(int);
		// metodo que configura o atributo associado ao seu codigo de barras
		void set_codigo(long int);
		// metodo que retorna uma estrutura com os atributos do objeto
		Produto_prototipo get_objeto_produto(void) const;
		// metodo que imprime os atributos do produto para o usuario
		void imprimeProduto(void) const;
};

#endif