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
			// adiciona o objeto a lista através do vector
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
			// adiciona o objeto a lista através do vector
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
			// adiciona o objeto a lista através do vector
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
		cout << "===== "<< i+1 << "° Produto =====" << endl;
		// imprime todos os atributos vinculados ao produto
		produtos[i].imprimeProduto();
		cout << endl;
	}
	
	return;
}

void Estoque::imprimirProdutoPerecivel(void) const
{
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		cout << "===== "<< i+1 << "° Produto Perecível =====" << endl;
		// imprime todos os atributos vinculados ao produto perecível
		pereciveis[i].imprimeProdutoPerecivel();
		cout << endl;
	}
	
	return;
}

void Estoque::imprimirRemedio(void) const
{
	for(unsigned i(0); i < remedios.size(); i++)
	{
		cout << "===== "<< i+1 << "° Remédio =====" << endl;
		// imprime todos os atributos vinculados ao remédio
		remedios[i].imprimeRemedio();
		cout << endl;
	}
	
	return;
}

bool Estoque::removerProduto(long int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < produtos.size(); i++)
	{
		if(produtos[i].get_objeto_produto().codigo == codigo)
		{
			produtos.erase(produtos.begin() + i);
			return true;
		}
		else
			contador++;
	}
	if(contador == produtos.size())
		return false;
	
	return false;
}

bool Estoque::removerProdutoPerecivel(long int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		if(pereciveis[i].get_objeto_produto().codigo == codigo)
		{
			pereciveis.erase(pereciveis.begin() + i);
			return true;
		}
		else
			contador++;
	}
	if(contador == pereciveis.size())
		return false;
	
	return false;
}

bool Estoque::removerRemedio(long int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < remedios.size(); i++)
	{
		if(remedios[i].get_objeto_produto().codigo == codigo)
		{
			remedios.erase(remedios.begin() + i);
			return true;
		}
		else
			contador++;
	}
	if(contador == remedios.size())
		return false;
	
	return false;
}

bool Estoque::pesquisarProduto(string nome) const
{
	unsigned contador(0);
	for(unsigned i(0); i < produtos.size(); i++)
	{
		if(produtos[i].get_objeto_produto().nome == nome)
		{
			produtos[i].imprimeProduto();
			return true;
		}
		else
			contador++;
	}
	if(contador == produtos.size())
		return false;
	
	return false;
}

bool Estoque::pesquisarProdutoPerecivel(string nome) const
{
	unsigned contador(0);
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		if(pereciveis[i].get_objeto_produto().nome == nome)
		{
			pereciveis[i].imprimeProdutoPerecivel();
			return true;
		}
		else
			contador++;
	}
	if(contador == pereciveis.size())
		return false;
	
	return false;
}

bool Estoque::pesquisarRemedio(string nome) const
{
	unsigned contador(0);
	for(unsigned i(0); i < remedios.size(); i++)
	{
		if(remedios[i].get_objeto_produto().nome == nome)
		{
			remedios[i].imprimeProdutoPerecivel();
			return true;
		}
		else
			contador++;
	}
	if(contador == remedios.size())
		return false;
	
	return false;
}

bool Estoque::checaVencimentoPerecivel(int indice, int limite)
{
	Data atual;
	
	atual = pereciveis[indice].get_data_atual();
	
	int acumula_atual, acumula_vencido, verifica, anual;
	
	acumula_atual = ((12 - atual.mes) * 30) + atual.dia;
	acumula_vencido = ((12 - pereciveis[indice].get_data_validade().mes) * 30);
	acumula_vencido += pereciveis[indice].get_data_validade().dia;
	
	if(pereciveis[indice].get_data_validade().ano - atual.ano == 1)
	{
		verifica = acumula_atual + acumula_vencido;
		if(verifica <= limite)
		{
			return true;
		}
	}
	else if(pereciveis[indice].get_data_validade().ano - atual.ano > 1)
	{
		
		verifica = acumula_atual + acumula_vencido;
		anual = (pereciveis[indice].get_data_validade().ano - atual.ano - 1) * 365;
		verifica += anual;
		if(verifica <= limite)
		{
			return true;
		}
	}
	else if(pereciveis[indice].get_data_validade().ano - atual.ano == 0)
	{
		if(acumula_vencido - acumula_atual <= limite)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
	
	return false;
}

bool Estoque::checaVencimentoRemedio(int indice, int limite)
{
	Data atual;
	
	atual = remedios[indice].get_data_atual();
	
	int acumula_atual, acumula_vencido, verifica, anual;
	
	acumula_atual = ((12 - atual.mes) * 30) + atual.dia;
	acumula_vencido = ((12 - remedios[indice].get_data_validade().mes) * 30);
	acumula_vencido += remedios[indice].get_data_validade().dia;
	
	if(remedios[indice].get_data_validade().ano - atual.ano == 1)
	{
		verifica = acumula_atual + acumula_vencido;
		if(verifica <= limite)
		{
			return true;
		}
	}
	else if(pereciveis[indice].get_data_validade().ano - atual.ano > 1)
	{
		
		verifica = acumula_atual + acumula_vencido;
		anual = (remedios[indice].get_data_validade().ano - atual.ano - 1) * 365;
		verifica += anual;
		if(verifica <= limite)
		{
			return true;
		}
	}
	else if(remedios[indice].get_data_validade().ano - atual.ano == 0)
	{
		if(acumula_vencido - acumula_atual <= limite)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
	
	return false;
}

bool Estoque::pesquisaPerecivelVencido(int limite)
{
	unsigned contador(0);
	cout << "Produtos Perecíveis com " << limite << " dias antes do vencimento: " << endl << endl;
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		if(checaVencimentoPerecivel(i, limite))
		{
			cout << "=== " << i + 1 << "° Produto Perecível === " << endl;
			pereciveis[i].imprimeProdutoPerecivel();
			cout << endl;
		}
		else
			contador++;
	}
	if(contador == pereciveis.size())
		return false;
	
	return true;
}

bool Estoque::pesquisaRemedioVencido(int limite)
{
	unsigned contador(0);
	cout << "Remédios com " << limite << " dias antes do vencimento: " << endl << endl;
	for(unsigned i(0); i < remedios.size(); i++)
	{
		if(checaVencimentoRemedio(i, limite))
		{
			cout << "=== " << i + 1 << "° Remédio === " << endl;
			remedios[i].imprimeProdutoPerecivel();
			cout << endl;
		}
		else
			contador++;
	}
	if(contador == remedios.size())
		return false;
	
	return true;
}