#include "../cabecalhos/Estoque.h"
#include "../cabecalhos/Produto.h"
#include "../cabecalhos/ProdutoPerecivel.h"
#include "../cabecalhos/Remedio.h"
#include "../cabecalhos/Sobrecarga1.h"

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
	ifstream arquivo1; 
	arquivo1.open("../arquivos/lista_de_produtos.txt"); 
	
	if(arquivo1.is_open()) 
	{
		while(!arquivo1.eof()) 
		{
			arquivo1 >> p; 
			produtos.push_back(p);
		}
	}
	arquivo1.close(); 
	
	return;
}

void Estoque::lerProdutoPerecivel(void)
{	
	ProdutoPerecivel pp;
	ifstream arquivo2; 
	arquivo2.open("../arquivos/lista_de_produtos_pereciveis.txt"); 
	
	if(arquivo2.is_open()) 
	{
		while(!arquivo2.eof()) 
		{
			arquivo2 >> pp; 
			pereciveis.push_back(pp);
		}
	}
	arquivo2.close(); 
	
	return;
}

void Estoque::lerRemedio(void)
{	
	Remedio r;
	ifstream arquivo3; 
	arquivo3.open("../arquivos/lista_de_remedios.txt"); 
	
	if(arquivo3.is_open()) 
	{
		while(!arquivo3.eof()) 
		{
			arquivo3 >> r; 
			remedios.push_back(r);
		}
	}
	arquivo3.close();
	
	return;
}

void Estoque::salvarProduto(void)
{
	ofstream arquivo1; 
	
	arquivo1.open("../arquivos/lista_de_produtos.txt", std::ios::trunc);
	
	if(arquivo1.is_open())
	{
		for(unsigned i(0); i < produtos.size(); i++)
		{
			arquivo1 << produtos[i]; 
		}	
	}	
	arquivo1.close();
	
	return;
}

void Estoque::salvarProdutoPerecivel(void)
{
	ofstream arquivo2; 
	
	arquivo2.open("../arquivos/lista_de_produtos_pereciveis.txt", std::ios::trunc);
	
	if(arquivo2.is_open())
	{
		for(unsigned i(0); i < pereciveis.size(); i++)
		{
			arquivo2 << pereciveis[i]; 
		}	
	}	
	arquivo2.close();
	
	return;
}

void Estoque::salvarRemedio(void)
{
	ofstream arquivo3; 
	
	arquivo3.open("../arquivos/lista_de_remedios.txt", std::ios::trunc);
	
	if(arquivo3.is_open())
	{
		for(unsigned i(0); i < remedios.size(); i++)
		{
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
		if(produtos[i].get_objeto_produto().codigo == p.get_objeto_produto().codigo)
		{
			return false;
		}
	}
	
	produtos.push_back(p);
	
	return true;
}

bool Estoque::inserirProdutoPerecivel(ProdutoPerecivel pp)
{
	for(unsigned i(0); i < pereciveis.size(); i++)
	{
		if(pereciveis[i].get_objeto_produto().codigo == pp.get_objeto_produto().codigo)
		{
			return false;
		}
	}
	
	pereciveis.push_back(pp);
	
	return true;
}

bool Estoque::inserirRemedio(Remedio r)
{
	for(unsigned i(0); i < remedios.size(); i++)
	{
		if(remedios[i].get_objeto_produto().codigo == r.get_objeto_produto().codigo)
		{
			return false;
		}
	}
	
	remedios.push_back(r);
	
	return true;
}

void Estoque::imprimirProduto() const
{
	for(unsigned i(0); i < produtos.size(); i++)
	{
		cout << "===== "<< i+1 << "° Produto =====" << endl;
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
			remedios[i].imprimeRemedio();
			return true;
		}
		else
			contador++;
	}
	if(contador == remedios.size())
		return false;
	
	return false;
}

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

bool Estoque::pesquisarRemedio(long int codigo) const
{
	unsigned contador(0);
	for(unsigned i(0); i < remedios.size(); i++)
	{
		if(remedios[i].get_objeto_produto().codigo == codigo)
		{
			remedios[i].imprimeRemedio();
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
		
		if(pereciveis[indice].get_data_validade().mes < pereciveis[indice].get_data_atual().mes)
		{
			return true;
		}
		else if(pereciveis[indice].get_data_validade().mes == pereciveis[indice].get_data_atual().mes)
		{
			if(pereciveis[indice].get_data_validade().dia <= pereciveis[indice].get_data_atual().dia)
			{
				return true;	
			}
		}
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
	else if(remedios[indice].get_data_validade().ano - atual.ano > 1)
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
		if(remedios[indice].get_data_validade().mes < remedios[indice].get_data_atual().mes)
		{
			return true;
		}
		else if(remedios[indice].get_data_validade().mes == remedios[indice].get_data_atual().mes)
		{
			if(remedios[indice].get_data_validade().dia <= remedios[indice].get_data_atual().dia)
			{
				return true;
			}
		}
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
	int smallest; 

    for(unsigned i = 0; i < produtos.size() - 1; i++)
    {
        smallest = i;

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
    }
    
    return;
}

void Estoque::ordenaProdutoNome(void)
{
	int smallest; 

    for(unsigned i = 0; i < produtos.size() - 1; i++)
    {
        smallest = i; 

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
    } 
    
    return;			
}

void Estoque::ordenaProdutoFabricante(void)
{
	int smallest; 

    for(unsigned i = 0; i < produtos.size() - 1; i++)
    {
        smallest = i; 

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
    } 
    
    return;			
}

void Estoque::ordenaProdutoEstoque(void)
{
	int smallest; 

    for(unsigned i = 0; i < produtos.size() - 1; i++)
    {
        smallest = i;

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
    } 
    
    return;
}

void Estoque::ordenaPerecivelPrecoVenda(void)
{
	int smallest; 

    for(unsigned i = 0; i < pereciveis.size() - 1; i++)
    {
        smallest = i; 

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
    } 
    
    return;
}
void Estoque::ordenaPerecivelNome(void)
{
	int smallest; 

    for(unsigned i = 0; i < pereciveis.size() - 1; i++)
    {
        smallest = i; 

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
    } 
    
    return;
}
void Estoque::ordenaPerecivelFabricante(void)
{
	int smallest; 

    for(unsigned i = 0; i < pereciveis.size() - 1; i++)
    {
        smallest = i; 

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
    } 
    
    return;
}

void Estoque::ordenaPerecivelEstoque(void)
{
	int smallest; 

    for(unsigned i = 0; i < pereciveis.size() - 1; i++)
    {
        smallest = i; 

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
    } 
    
    return;
}

void Estoque::ordenaRemedioPrecoVenda(void)
{
	int smallest; 

    for(unsigned i = 0; i < remedios.size() - 1; i++)
    {
        smallest = i; 

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
    } 
    
    return;
}


void Estoque::ordenaRemedioNome(void)
{
	int smallest; 

    for(unsigned i = 0; i < remedios.size() - 1; i++)
    {
        smallest = i; 

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
    } 
    
    return;
}
void Estoque::ordenaRemedioFabricante(void)
{
	int smallest; 

    for(unsigned i = 0; i < remedios.size() - 1; i++)
    {
        smallest = i; 

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
    } 
    
    return;
}

void Estoque::ordenaRemedioTarja(void)
{
	int smallest; 

    
    for(unsigned i = 0; i < remedios.size() - 1; i++)
    {
        smallest = i; 

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
    } 
    
    return;
}

void Estoque::ordenaRemedioEstoque(void)
{
	int smallest; 
    
    for(unsigned i = 0; i < remedios.size() - 1; i++)
    {
        smallest = i; 

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
    } 
    
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

Produto Estoque::getProduto(int indice) const
{
	Produto produto_vazio;
	
	try 
	{
		produtos.at(indice);
	}
	catch(out_of_range const& excecao) 
	{
		cout << excecao.what() << endl;
		cout << "Retornando objeto vazio." << endl;
		return produto_vazio;
	}
	return produtos.at(indice);
}

ProdutoPerecivel Estoque::getProdutoPerecivel(int indice) const
{
	ProdutoPerecivel perecivel_vazio;
	
	try 
	{
		pereciveis.at(indice);
	}
	catch(out_of_range const& excecao) 
	{
		cout << excecao.what() << endl;
		cout << "Retornando objeto vazio." << endl;
		return perecivel_vazio;
	}
	return pereciveis.at(indice);
}

Remedio Estoque::getRemedio(int indice) const
{
	Remedio remedio_vazio;
	
	try 
	{
		remedios.at(indice);
	}
	catch(out_of_range const& excecao) 
	{
		cout << excecao.what() << endl;
		cout << "Retornando objeto vazio." << endl;
		return remedio_vazio;
	}
	return remedios.at(indice);
}

vector <Produto> Estoque::getListaProdutos(void) const
{
	return produtos;
}

vector <ProdutoPerecivel> Estoque::getListaProdutosPereciveis(void) const
{
	return pereciveis;
}

vector <Remedio> Estoque::getListaRemedios(void) const
{
	return remedios;
}