#include "../headers/Estoque.h"
#include "../headers/Produto.h"
#include "../headers/ProdutoPerecivel.h"
#include "../headers/Remedio.h"
#include "../headers/Sobrecarga.h"

Estoque::Estoque()
{
	lerProduto();
	lerProdutoPerecivel();
	lerRemedio();
}

Estoque::~Estoque()
{
	salvarProduto();
	salvarProdutoPerecivel();
	salvarRemedio();
}

void Estoque::lerProduto(void)
{
	Produto p;
	// criacao de arquivo para leitura
	ifstream arquivo1; 
	// abrindo o arquivo de leitura
	arquivo1.open("lista_de_produtos.txt"); 
	
	// verificando se o arquivo foi efetivamente aberto
	if(arquivo1.is_open()) 
	{
		// Enquanto for diferente de eof(end of file) continue se repetindo.
		while(!arquivo1.eof()) 
		{
			// utilizando a sobrecarga de operador >> para inicializar o arquivo
			arquivo1 >> p; 
			// adiciona o objeto a lista atrav�s do vector
			produtos.push_back(p);
		}
	}
	// fechando o arquivo de leitura
	arquivo1.close(); 
	
	return;
}

void Estoque::lerProdutoPerecivel(void)
{	
	ProdutoPerecivel pp;
	// criacao de arquivo para leitura
	ifstream arquivo2; 
	// abrindo o arquivo de leitura
	arquivo2.open("lista_de_produtos_pereciveis.txt"); 
	
	// verificando se o arquivo foi efetivamente aberto
	if(arquivo2.is_open()) 
	{
		// Enquanto for diferente de eof(end of file) continue se repetindo.
		while(!arquivo2.eof()) 
		{
			// utilizando a sobrecarga de operador >> para inicializar o arquivo
			arquivo2 >> pp; 
			// adiciona o objeto a lista atrav�s do vector
			pereciveis.push_back(pp);
		}
	}
	// fechando o arquivo de leitura
	arquivo2.close(); 
	
	return;
}

void Estoque::lerRemedio(void)
{	
	Remedio r;
	// criacao de arquivo para leitura
	ifstream arquivo3; 
	// abrindo o arquivo de leitura
	arquivo3.open("lista_de_produtos_remedios.txt"); 
	
	// verificando se o arquivo foi efetivamente aberto
	if(arquivo3.is_open()) 
	{
		// Enquanto for diferente de eof(end of file) continue se repetindo.
		while(!arquivo3.eof()) 
		{
			// utilizando a sobrecarga de operador >> para inicializar o arquivo
			arquivo3 >> r; 
			// adiciona o objeto a lista atrav�s do vector
			remedios.push_back(r);
		}
	}
	// fechando o arquivo de leitura
	arquivo3.close();
	
	return;
}

void Estoque::salvarProduto(void)
{
	// criando um arquivo para salvar a lista de objetos
	ofstream arquivo1; 
	
	// modo de abertura trunc (abre, apaga e sobreescreve os dados)
	arquivo1.open("lista_de_produtos.txt", std::ios::trunc);
	
	if(arquivo1.is_open())
	{
		for(unsigned i(0); i < produtos.size(); i++)
		{
			// utilizando a sobrecarga do operador << para gravar o objeto no arquivo.
			arquivo1 << produtos[i]; 
		}	
	}	
	// fechando o arquivo
	arquivo1.close();
	
	return;
}

void Estoque::salvarProdutoPerecivel(void)
{
	// criando um arquivo para salvar a lista de objetos
	ofstream arquivo2; 
	
	// modo de abertura trunc (abre, apaga e sobreescreve os dados)
	arquivo2.open("lista_de_produtos_pereciveis.txt", std::ios::trunc);
	
	if(arquivo2.is_open())
	{
		for(unsigned i(0); i < pereciveis.size(); i++)
		{
			// utilizando a sobrecarga do operador << para gravar o objeto no arquivo.
			arquivo2 << pereciveis[i]; 
		}	
	}	
	// fechando o arquivo
	arquivo2.close();
	
	return;
}

void Estoque::salvarRemedio(void)
{
	// criando um arquivo para salvar a lista de objetos
	ofstream arquivo3; 
	
	// modo de abertura trunc (abre, apaga e sobreescreve os dados)
	arquivo3.open("lista_de_produtos_remedios.txt", std::ios::trunc);
	
	if(arquivo3.is_open())
	{
		for(unsigned i(0); i < remedios.size(); i++)
		{
			// utilizando a sobrecarga do operador << para gravar o objeto no arquivo.
			arquivo3 << remedios[i]; 
		}	
	}	
	// fechando o arquivo
	arquivo3.close();
	
	return;
}

bool Estoque::inserirProduto(Produto p)
{
	for(unsigned i(0); i < produtos.size(); i++)
	{
		// verifica se o produto cadastrado possui um outro codigo
		if(produtos[i].get_objeto_produto().codigo == p.get_objeto_produto().codigo)
		{
			return false;
		}
	}
	
	// caso seja um produto de codigo diferente, insere o produto a lista
	produtos.push_back(p);
	
	return true;
}

bool Estoque::inserirProdutoPerecivel(ProdutoPerecivel pp)
{
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		// verifica se o produto cadastrado possui um outro codigo
		if(pereciveis[i].get_objeto_produto().codigo == pp.get_objeto_produto().codigo)
		{
			return false;
		}
	}
	
	// caso seja um produto de codigo diferente, insere o produto a lista
	pereciveis.push_back(pp);
	
	return true;
}

bool Estoque::inserirRemedio(Remedio r)
{
	for(unsigned i(0); i < remedios.size(); i++)
	{
		// verifica se o produto cadastrado possui um outro codigo
		if(remedios[i].get_objeto_produto().codigo == r.get_objeto_produto().codigo)
		{
			return false;
		}
	}
	
	// caso seja um produto de codigo diferente, insere o produto a lista
	remedios.push_back(r);
	
	return true;
}

void Estoque::imprimirProduto() const
{
	for(unsigned i(0); i < produtos.size(); i++)
	{
		cout << "===== "<< i+1 << "� Produto =====" << endl;
		//produtos[i].imprimeDados();
		cout << produtos[i].get_objeto_produto().preco_loja << endl;
		cout << produtos[i].get_objeto_produto().preco_consumidor << endl;
		cout << produtos[i].get_objeto_produto().nome << endl;
		cout << produtos[i].get_objeto_produto().categoria << endl;
		cout << produtos[i].get_objeto_produto().fabricante << endl;
		cout << produtos[i].get_objeto_produto().quantidade << endl;
		cout << produtos[i].get_objeto_produto().codigo << endl;
		cout << endl;
	}
}

void Estoque::imprimirProdutoPerecivel(void) const
{
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		cout << "===== "<< i+1 << "� Produto Perec�vel =====" << endl;
		//produtos[i].imprimeDados();
		cout << endl;
	}
}
