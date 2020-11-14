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
	ifstream arquivo1; // Criando um arquivo apenas para leitura.
	arquivo1.open("lista_de_produtos.txt"); // Abrindo o arquivo de leitura.
	
	if(arquivo1.is_open()) // Verificando se o arquivo foi aberto.
	{
		while(!arquivo1.eof()) // Enquanto for diferente de eof(end of file) continue se repetindo.
		{
			arquivo1.ignore(); // Ignorando o caractere de quebra de linha que está no início de cada objeto.
			arquivo1 >> p; // Utilizando a sobrecarga do operador >> para inicializar o objeto.
			produtos.push_back(p); // Adicionando o objeto a lista.
		}
	}
	arquivo1.close(); // Fechando o arquivo de leitura.
	
	return;
}

void Estoque::lerProdutoPerecivel(void)
{
	ProdutoPerecivel pp;
	ifstream arquivo2; // Criando um arquivo apenas para leitura.
	arquivo2.open("lista_de_produtos_pereciveis.txt"); // Abrindo o arquivo de leitura.
	
	if(arquivo2.is_open()) // Verificando se o arquivo foi aberto.
	{
		while(!arquivo2.eof()) // Enquanto for diferente de eof(end of file) continue se repetindo.
		{
			arquivo2.ignore(); // Ignorando o caractere de quebra de linha que está no início de cada objeto.
			arquivo2 >> pp; // Utilizando a sobrecarga do operador >> para inicializar o objeto.
			pereciveis.push_back(pp); // Adicionando o objeto a lista.
		}
	}
	arquivo2.close(); // Fechando o arquivo de leitura.
	
	return;
}

void Estoque::lerRemedio(void)
{
	Remedio r;
	ifstream arquivo3; // Criando um arquivo apenas para leitura.
	arquivo3.open("lista_de_remedios.txt"); // Abrindo o arquivo de leitura.
	
	if(arquivo3.is_open()) // Verificando se o arquivo foi aberto.
	{
		while(!arquivo3.eof()) // Enquanto for diferente de eof(end of file) continue se repetindo.
		{
			arquivo3.ignore(); // Ignorando o caractere de quebra de linha que está no início de cada objeto.
			arquivo3 >> r; // Utilizando a sobrecarga do operador >> para inicializar o objeto.
			remedios.push_back(r); // Adicionando o objeto a lista.
		}
	}
	arquivo3.close(); // Fechando o arquivo de leitura.
	
	return;
}

void Estoque::salvarProduto(void)
{
	ofstream arquivo1; // Criando um arquivo para salvar a lista de objetos.
	
	/* Utilizando o modo de abertura trunc, que abre e apaga os dados anteriores armazenados nele. Como toda a lista
	foi carregada no vector se utilizassemos o modo de abertura app o arquivo iria ficar com objetos repetidos.*/
	arquivo1.open("lista_de_produtos.txt", std::ios::trunc);
	
	if(arquivo1.is_open())
	{
		for(unsigned i(0); i < produtos.size(); i++)
		{
			// Utilizando a sobrecarga do operador << para gravar o objeto no arquivo.
			arquivo1 << produtos[i]; 
		}	
	}	
	arquivo1.close();
	
	return;
}

void Estoque::salvarProdutoPerecivel(void)
{
	ofstream arquivo2; // Criando um arquivo para salvar a lista de objetos.
	
	/* Utilizando o modo de abertura trunc, que abre e apaga os dados anteriores armazenados nele. Como toda a lista
	foi carregada no vector se utilizassemos o modo de abertura app o arquivo iria ficar com objetos repetidos.*/
	arquivo2.open("lista_de_produtos_pereciveis.txt", std::ios::trunc);
	
	if(arquivo2.is_open())
	{
		for(unsigned i(0); i < pereciveis.size(); i++)
		{
			// Utilizando a sobrecarga do operador << para gravar o objeto no arquivo.
			arquivo2 << pereciveis[i]; 
		}	
	}
	
	arquivo2.close();
	
	return;
}

void Estoque::salvarRemedio(void)
{
	ofstream arquivo3; // Criando um arquivo para salvar a lista de objetos.
	
	/* Utilizando o modo de abertura trunc, que abre e apaga os dados anteriores armazenados nele. Como toda a lista
	foi carregada no vector se utilizassemos o modo de abertura app o arquivo iria ficar com objetos repetidos.*/
	arquivo3.open("lista_de_remedios.txt", std::ios::trunc);
	
	if(arquivo3.is_open())
	{
		for(unsigned i(0); i < remedios.size(); i++)
		{
			// Utilizando a sobrecarga do operador << para gravar o objeto no arquivo.
			arquivo3 << remedios[i]; 
		}	
	}
	
	arquivo3.close();
	
	return;
}

bool Estoque::inserirProduto(Produto p)
{
	for(unsigned i(0); i < produtos.size(); i++)
	{
		// Verificando se já não existe uma pessoa na lista com o mesmo CPF.
		if(produtos[i].get_objeto_produto().codigo == p.get_objeto_produto().codigo)
			return false;
	}
	
	produtos.push_back(p);
	return true;
}

bool Estoque::inserirRemedio(Remedio r)
{
	for(unsigned i(0); i < remedios.size(); i++)
	{
		// Verificando se já não existe uma pessoa na lista com o mesmo CPF.
		if(remedios[i].get_objeto_produto().codigo == r.get_objeto_produto().codigo)
			return false;
	}
	
	remedios.push_back(r);
	return true;
}

bool Estoque::inserirProdutoPerecivel(ProdutoPerecivel pp)
{
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		// Verificando se já não existe uma pessoa na lista com o mesmo CPF.
		if(pereciveis[i].get_objeto_produto().codigo == pp.get_objeto_produto().codigo)
			return false;
	}
	
	pereciveis.push_back(pp);
	return true;
}

void Estoque::imprimirLista() const
{
	for(unsigned i(0); i < produtos.size(); i++)
	{
		cout << i+1 << "ª Pessoa: " << endl;
		//produtos[i].imprimeDados();
		cout << produtos[i].get_objeto_produto().nome;
		cout << endl;
	}
}
