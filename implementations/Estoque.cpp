#include "../headers/Estoque.h"
#include "../headers/Produto.h"
#include "../headers/ProdutoPerecivel.h"
#include "../headers/Remedio.h"
#include "../headers/Sobrecarga.h"

// implementacao do construtor da classe (le os arquivos)
Estoque::Estoque()
{
	lerProduto();
	lerProdutoPerecivel();
	lerRemedio();
}

// implementacao do destrutor da classe (salva os arquivos)
Estoque::~Estoque()
{
	salvarProduto();
	salvarProdutoPerecivel();
	salvarRemedio();
}

// método que le os arquivos da classe produto
void Estoque::lerProduto(void)
{
	Produto p;
	// criacao de arquivo para leitura
	ifstream arquivo1; 
	// abrindo o arquivo de leitura
	arquivo1.open("../arquivos/lista_de_produtos.txt"); 
	
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

// método que le os arquivos da classe de produtos pereciveis
void Estoque::lerProdutoPerecivel(void)
{	
	ProdutoPerecivel pp;
	// criacao de arquivo para leitura
	ifstream arquivo2; 
	// abrindo o arquivo de leitura
	arquivo2.open("../arquivos/lista_de_produtos_pereciveis.txt"); 
	
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

// método que le os arquivos da classe remedio
void Estoque::lerRemedio(void)
{	
	Remedio r;
	// criacao de arquivo para leitura
	ifstream arquivo3; 
	// abrindo o arquivo de leitura
	arquivo3.open("../arquivos/lista_de_remedios.txt"); 
	
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

// metodo que salva em um arquivo os produtos cadastrados
void Estoque::salvarProduto(void)
{
	// criando um arquivo para salvar a lista de objetos
	ofstream arquivo1; 
	
	// modo de abertura trunc (abre, apaga e sobreescreve os dados)
	arquivo1.open("../arquivos/lista_de_produtos.txt", std::ios::trunc);
	
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

// metodo que salva em um arquivo os produtos pereciveis cadastrados
void Estoque::salvarProdutoPerecivel(void)
{
	// criando um arquivo para salvar a lista de objetos
	ofstream arquivo2; 
	
	// modo de abertura trunc (abre, apaga e sobreescreve os dados)
	arquivo2.open("../arquivos/lista_de_produtos_pereciveis.txt", std::ios::trunc);
	
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

// metodo que salva em um arquivo os remedios cadastrados
void Estoque::salvarRemedio(void)
{
	// criando um arquivo para salvar a lista de objetos
	ofstream arquivo3; 
	
	// modo de abertura trunc (abre, apaga e sobreescreve os dados)
	arquivo3.open("../arquivos/lista_de_remedios.txt", std::ios::trunc);
	
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

// metodo que insere um produto a lista de produtos
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

// metodo que insere um produto perecivel a lista de produtos pereciveis
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

// metodo que insere um remedio a lista de remedios
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

// metodo que imprime todos os produtos vinculados a lista
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

// metodo que imprime todos os produtos pereciveis vinculados a lista
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

// metodo que imprime todos os remedios vinculados a lista
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

// metodo que remove produtos da lista
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

// metodo que remove produtos pereciveis da lista
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

// metodo que remove remedios da lista
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

// metodo que pesquisa produtos pelo nome
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

// metodo que pesquisa produtos pereciveis pelo nome
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

// metodo que pesquisa remedios pelo nome
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

// metodo que pesquisa produtos pelo codigo de barras
bool Estoque::pesquisarProduto(long int codigo) const
{
	unsigned contador(0);
	for(unsigned i(0); i < produtos.size(); i++)
	{
		if(produtos[i].get_objeto_produto().codigo == codigo)
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

// metodo que pesquisa produtos pereciveis pelo codigo de barras
bool Estoque::pesquisarProdutoPerecivel(long int codigo) const
{
	unsigned contador(0);
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		if(pereciveis[i].get_objeto_produto().codigo == codigo)
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

// metodo que pesquisa remedios pelo codigo de barras
bool Estoque::pesquisarRemedio(long int codigo) const
{
	unsigned contador(0);
	for(unsigned i(0); i < remedios.size(); i++)
	{
		if(remedios[i].get_objeto_produto().codigo == codigo)
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

// metodo que checa os produtos pereciveis que estao pertos de se vencer ate um dado limite de dias
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
		return true;
	}
	
	return false;
}

// metodo que checa os remedios que estao pertos de se vencer ate um dado limite de dias
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
		return true;
	}
	
	return false;
}

// metodo que imprime todos os produtos pereciveis vencidos da lista ate um dado limite de dias
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

// metodo que imprime todos os remedios vencidos da lista ate um dado limite de dias
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

// metodo que remove todos os produtos vencidos da lista
void Estoque::removerProdutosPereciveisVencidos(void)
{
	unsigned contador(0);
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		if(checaVencimentoPerecivel(i, 0))
		{
			removerProdutoPerecivel(pereciveis[i].get_objeto_produto().codigo);
			contador++;
		}
	}
	
	cout << contador << " Produtos Perecíveis vencidos removidos." << endl;
	
	return;
}

// metodo que remove todos os remedios vencidos da lista
void Estoque::removerRemediosVencidos(void)
{
	unsigned contador(0);
	for(unsigned i(0); i < remedios.size(); i++)
	{
		if(checaVencimentoRemedio(i, 0))
		{
			removerRemedio(remedios[i].get_objeto_produto().codigo);
			contador++;
		}
	}
	
	cout << contador << " Remédios vencidos removidos." << endl;
	
	return;
}

void Estoque::ordenaProdutoPrecoVenda(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < produtos.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < produtos.size(); index++)
        {
            if(produtos[index].get_objeto_produto().preco_consumidor < produtos[smallest].get_objeto_produto().preco_consumidor)
            {
                smallest = index;
            }
        }
		Produto produto_auxiliar;
		produto_auxiliar = produtos[i];
    	produtos[i] = produtos[smallest];
    	produtos[smallest] = produto_auxiliar;
    } // fim do for
    
    return;
}

void Estoque::ordenaProdutoNome(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < produtos.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < produtos.size(); index++)
        {
            if(produtos[index].get_objeto_produto().nome.compare(produtos[smallest].get_objeto_produto().nome) < 0)
            {
                smallest = index;
            }
        }
		Produto produto_auxiliar;
		produto_auxiliar = produtos[i];
    	produtos[i] = produtos[smallest];
    	produtos[smallest] = produto_auxiliar;
    } // fim do for
    
    return;			
}

void Estoque::ordenaProdutoFabricante(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < produtos.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < produtos.size(); index++)
        {
            if(produtos[index].get_objeto_produto().fabricante.compare(produtos[smallest].get_objeto_produto().fabricante) < 0)
            {
                smallest = index;
            }
        }
		Produto produto_auxiliar;
		produto_auxiliar = produtos[i];
    	produtos[i] = produtos[smallest];
    	produtos[smallest] = produto_auxiliar;
    } // fim do for
    
    return;			
}

void Estoque::ordenaProdutoEstoque(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < produtos.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < produtos.size(); index++)
        {
            if(produtos[index].get_objeto_produto().quantidade < produtos[smallest].get_objeto_produto().quantidade)
            {
                smallest = index;
            }
        }
		Produto produto_auxiliar;
		produto_auxiliar = produtos[i];
    	produtos[i] = produtos[smallest];
    	produtos[smallest] = produto_auxiliar;
    } // fim do for
    
    return;
}

void Estoque::ordenaPerecivelPrecoVenda(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < pereciveis.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < pereciveis.size(); index++)
        {
            if(pereciveis[index].get_objeto_produto().preco_consumidor < pereciveis[smallest].get_objeto_produto().preco_consumidor)
            {
                smallest = index;
            }
        }
		ProdutoPerecivel produto_auxiliar;
		produto_auxiliar = pereciveis[i];
    	pereciveis[i] = pereciveis[smallest];
    	pereciveis[smallest] = produto_auxiliar;
    } // fim do for
    
    return;
}
void Estoque::ordenaPerecivelNome(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < pereciveis.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < pereciveis.size(); index++)
        {
            if(pereciveis[index].get_objeto_produto().nome.compare(pereciveis[smallest].get_objeto_produto().nome) < 0)
            {
                smallest = index;
            }
        }
		ProdutoPerecivel produto_auxiliar;
		produto_auxiliar = pereciveis[i];
    	pereciveis[i] = pereciveis[smallest];
    	pereciveis[smallest] = produto_auxiliar;
    } // fim do for
    
    return;
}
void Estoque::ordenaPerecivelFabricante(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < pereciveis.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < pereciveis.size(); index++)
        {
            if(pereciveis[index].get_objeto_produto().fabricante.compare(pereciveis[smallest].get_objeto_produto().fabricante) < 0)
            {
                smallest = index;
            }
        }
		ProdutoPerecivel produto_auxiliar;
		produto_auxiliar = pereciveis[i];
    	pereciveis[i] = pereciveis[smallest];
    	pereciveis[smallest] = produto_auxiliar;
    } // fim do for
    
    return;
}

void Estoque::ordenaPerecivelEstoque(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < pereciveis.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < pereciveis.size(); index++)
        {
            if(pereciveis[index].get_objeto_produto().quantidade < pereciveis[smallest].get_objeto_produto().quantidade)
            {
                smallest = index;
            }
        }
		ProdutoPerecivel produto_auxiliar;
		produto_auxiliar = pereciveis[i];
    	pereciveis[i] = pereciveis[smallest];
    	pereciveis[smallest] = produto_auxiliar;
    } // fim do for
    
    return;
}

void Estoque::ordenaRemedioPrecoVenda(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < remedios.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < remedios.size(); index++)
        {
            if(remedios[index].get_objeto_produto().preco_consumidor < remedios[smallest].get_objeto_produto().preco_consumidor)
            {
                smallest = index;
            }
        }
		Remedio produto_auxiliar;
		produto_auxiliar = remedios[i];
    	remedios[i] = remedios[smallest];
    	remedios[smallest] = produto_auxiliar;
    } // fim do for
    
    return;
}


void Estoque::ordenaRemedioNome(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < remedios.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < remedios.size(); index++)
        {
            if(remedios[index].get_objeto_produto().nome.compare(remedios[smallest].get_objeto_produto().nome) < 0)
            {
                smallest = index;
            }
        }
		Remedio produto_auxiliar;
		produto_auxiliar = remedios[i];
    	remedios[i] = remedios[smallest];
    	remedios[smallest] = produto_auxiliar;
    } // fim do for
    
    return;
}
void Estoque::ordenaRemedioFabricante(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < remedios.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < remedios.size(); index++)
        {
            if(remedios[index].get_objeto_produto().fabricante.compare(remedios[smallest].get_objeto_produto().fabricante) < 0)
            {
                smallest = index;
            }
        }
		Remedio produto_auxiliar;
		produto_auxiliar = remedios[i];
    	remedios[i] = remedios[smallest];
    	remedios[smallest] = produto_auxiliar;
    } // fim do for
    
    return;
}

void Estoque::ordenaRemedioTarja(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < remedios.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < remedios.size(); index++)
        {
            if(remedios[index].get_objeto_produto().categoria.compare(remedios[smallest].get_objeto_produto().categoria) < 0)
            {
                smallest = index;
            }
        }
		Remedio produto_auxiliar;
		produto_auxiliar = remedios[i];
    	remedios[i] = remedios[smallest];
    	remedios[smallest] = produto_auxiliar;
    } // fim do for
    
    return;
}

void Estoque::ordenaRemedioEstoque(void)
{
	int smallest; // indice do menor elemento

    // itera sobre size - 1 elementos
    for(unsigned i = 0; i < remedios.size() - 1; i++)
    {
        smallest = i; // primeiro indice do array

        // faz um loop para localizar o indice do menor elemento
        for(unsigned index = i + 1; index < remedios.size(); index++)
        {
            if(remedios[index].get_objeto_produto().quantidade < remedios[smallest].get_objeto_produto().quantidade)
            {
                smallest = index;
            }
        }
		Remedio produto_auxiliar;
		produto_auxiliar = remedios[i];
    	remedios[i] = remedios[smallest];
    	remedios[smallest] = produto_auxiliar;
    } // fim do for
    
    return;
}

bool Estoque::set_entrada_estoque_produto(long int codigo, int quantidade)
{
	if(pesquisarProduto(codigo))
	{
		int indice = getIndiceProduto(codigo); 
		produtos[indice].set_quantidade(produtos[indice].get_objeto_produto().quantidade + quantidade);
		return true;	
	}
	
	return false;
}

bool Estoque::set_entrada_estoque_perecivel(long int codigo, int quantidade)
{
	if(pesquisarProdutoPerecivel(codigo))
	{
		int indice = getIndiceProdutoPerecivel(codigo);
		pereciveis[indice].set_quantidade(pereciveis[indice].get_objeto_produto().quantidade + quantidade);
		return true;
	}
	
	return false;
}

bool Estoque::set_entrada_estoque_remedio(long int codigo, int quantidade)
{
	if(pesquisarRemedio(codigo))
	{
		int indice = getIndiceRemedio(codigo);
		remedios[indice].set_quantidade(remedios[indice].get_objeto_produto().quantidade + quantidade);
		return true;	
	}
	
	return false;
}

bool Estoque::set_saida_estoque_produto(long int codigo, int quantidade)
{
	if(pesquisarProduto(codigo))
	{
		int indice = getIndiceProduto(codigo);
		produtos[indice].set_quantidade(produtos[indice].get_objeto_produto().quantidade - quantidade);
		return true;
	}
	
	return false;
}

bool Estoque::set_saida_estoque_perecivel(long int codigo, int quantidade)
{
	if(pesquisarProdutoPerecivel(codigo))
	{
		int indice = getIndiceProdutoPerecivel(codigo);
		pereciveis[indice].set_quantidade(pereciveis[indice].get_objeto_produto().quantidade - quantidade);	
		return true;
	}
	
	return false;
}

bool Estoque::set_saida_estoque_remedio(long int codigo, int quantidade)
{
	if(pesquisarRemedio(codigo))
	{
		int indice = getIndiceRemedio(codigo);
		remedios[indice].set_quantidade(remedios[indice].get_objeto_produto().quantidade - quantidade);
		return true;
	}
	
	return false;
}

float Estoque::get_despezas(void) const
{
	float despezas = 0;
	for(unsigned i(0); i < produtos.size(); i++)
	{
		despezas += produtos[i].get_objeto_produto().preco_loja * float(produtos[i].get_objeto_produto().quantidade);
	}
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		despezas += pereciveis[i].get_objeto_produto().preco_loja * float(pereciveis[i].get_objeto_produto().quantidade);
	}
	for(unsigned i(0); i < remedios.size(); i++)
	{
		despezas += remedios[i].get_objeto_produto().preco_loja * float(remedios[i].get_objeto_produto().quantidade);
	}
	
	return despezas;
}

int Estoque::getIndiceProduto(long int codigo) const
{
	for(unsigned i(0); i < produtos.size(); i++)
	{
		if(produtos[i].get_objeto_produto().codigo == codigo)
		{
			return i;
		}
	}
	
	return -1;
}

int Estoque::getIndiceProduto(string nome) const
{
	for(unsigned i(0); i < produtos.size(); i++)
	{
		if(produtos[i].get_objeto_produto().nome == nome)
		{
			return i;
		}
	}
	
	return -1;
}

int Estoque::getIndiceProdutoPerecivel(long int codigo) const
{
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		if(pereciveis[i].get_objeto_produto().codigo == codigo)
		{
			return i;
		}
	}
	
	return -1;
}

int Estoque::getIndiceProdutoPerecivel(string nome) const
{
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		if(pereciveis[i].get_objeto_produto().nome == nome)
		{
			return i;
		}
	}
	
	return -1;
}

int Estoque::getIndiceRemedio(long int codigo) const
{
	for(unsigned i(0); i < remedios.size(); i++)
	{
		if(remedios[i].get_objeto_produto().codigo == codigo)
		{
			return i;
		}
	}
	
	return -1;
}

int Estoque::getIndiceRemedio(string nome) const
{
	for(unsigned i(0); i < remedios.size(); i++)
	{
		if(remedios[i].get_objeto_produto().nome == nome)
		{
			return i;
		}
	}
	
	return -1;
}

// metodo que retorna um elemento particular da lista de produtos
Produto Estoque::getProduto(int indice) const
{
	return produtos[indice];
}

// metodo que retorna um elemento particular da lista de produtos pereciveis
ProdutoPerecivel Estoque::getProdutoPerecivel(int indice) const
{
	return pereciveis[indice];
}

// metodo que retorna um elemento particular da lista de remedios
Remedio Estoque::getRemedio(int indice) const
{
	return remedios[indice];
}

// metodo que retorna a lista de produtos
vector <Produto> Estoque::getListaProdutos(void) const
{
	return produtos;
}

// metodo que retorna a lista de produtos pereciveis
vector <ProdutoPerecivel> Estoque::getListaProdutosPereciveis(void) const
{
	return pereciveis;
}

// metodo que retorna a lista de remedios
vector <Remedio> Estoque::getListaRemedios(void) const
{
	return remedios;
}