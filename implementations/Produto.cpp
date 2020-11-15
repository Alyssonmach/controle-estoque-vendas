#include "../headers/Produto.h"

// implementa��o do construtor da classe Produto
Produto::Produto(float preco_loja, float preco_consumidor, string nome, 
 	 	 	 	 string categoria, string fabricante, int quantidade, 
 	 	 	 	 long int codigo)
{
	set_preco_loja(preco_loja);
	set_preco_consumidor(preco_consumidor);
	set_nome(nome);
	set_categoria(categoria);
	set_fabricante(fabricante);
	set_quantidade(quantidade);
	set_codigo(codigo);	 	
}

//m�todo respons�vel por verificar a qualidade de um objeto
bool Produto::valida_objeto_produto(Produto_prototipo aux)
{
	int contador = 0;
	
	if(aux.preco_loja >= 0)
	{
		contador++;
	}
	
	if(aux.preco_consumidor >= 0)
	{
		contador++;
	}
	
	if(aux.quantidade >= 0)
	{
		contador++;
	}
	
	 if(aux.codigo >= 0)
	{
		contador++;
	}
	
	if(contador == 4)
	{
		return true;
	}
	
	return false;
}

//m�todo que configura um objeto externo no objeto interno da classe
void Produto::set_objeto_produto(Produto_prototipo aux)
{
	if(valida_objeto_produto(aux))
	{
		objeto_produto.preco_loja = aux.preco_loja;
		objeto_produto.preco_consumidor = aux.preco_consumidor;
		objeto_produto.nome = aux.nome;
		objeto_produto.categoria = aux.categoria;
		objeto_produto.fabricante = aux.fabricante;
		objeto_produto.quantidade = aux.quantidade;
		objeto_produto.codigo = aux.codigo;
		
		cout << "Produto cadastrado com sucesso." << endl;
	}
	else
	{
		cout << "Produto n�o cadastrado. Tente novamente." << endl;
	}
}

// m�todo que configura o pre�o da loja
void Produto::set_preco_loja(float preco_loja)
{
	this -> objeto_produto.preco_loja = (preco_loja > 0) ? preco_loja : 0;
}

//m�todo que configura o pre�o de venda para o consumidor
void Produto::set_preco_consumidor(float preco_consumidor)
{
	this -> objeto_produto.preco_consumidor = (preco_consumidor > 0) ? preco_consumidor : 0;
}

// m�todo que configura o nome do produto
void Produto::set_nome(string nome)
{
	this -> objeto_produto.nome = nome;
}

// m�todo que configura a categoria na qual o produto se encaixa
void Produto::set_categoria(string categoria)
{
	this -> objeto_produto.categoria = categoria;
}
	
//m�todo que configura o fabricante do produto	
void Produto::set_fabricante(string fabricante)
{
	this -> objeto_produto.fabricante = fabricante;
}

//m�todo que configura a quantidade em estoque dispon�vel do produto
void Produto::set_quantidade(int quantidade)
{
	this -> objeto_produto.quantidade = (quantidade > 0) ? quantidade : 0;
}

// m�todo que configura o c�digo de barras de identifica��o do produto
void Produto::set_codigo(long int codigo)
{
	this -> objeto_produto.codigo = (codigo > 0) ? codigo : 0;
}

// m�todo que retorna o objeto que a classe produto deve armazenar
Produto_prototipo Produto::get_objeto_produto(void) const
{
	return objeto_produto;
}

// m�todo que imprime os dados da classe
void Produto::imprimeProduto(void) const
{
	cout << "Pre�o de aquisi��o: " << objeto_produto.preco_loja << " R$" << endl;
	cout << "Pre�o de venda: " << objeto_produto.preco_consumidor << " R$" << endl;
	cout << "Nome do produto: " << objeto_produto.nome << endl;
	cout << "Categoria do Produto: " << objeto_produto.categoria << endl;
	cout << "Fabricante: " << objeto_produto.fabricante << endl;
	cout << "Quantidade em Estoque: " << objeto_produto.quantidade << " Produtos" << endl;
	cout << "C�digo de Barras do Produto: " << objeto_produto.codigo << endl;
	
	return;
}
