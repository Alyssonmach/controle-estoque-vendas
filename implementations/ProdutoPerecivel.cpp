#include "../headers/ProdutoPerecivel.h"

#include <ctime>

ProdutoPerecivel::ProdutoPerecivel(float preco_loja, float preco_consumidor, 
									string nome, string categoria, string fabricante,
									int quantidade, long int codigo, int dia, int mes,
									int ano) : Produto(preco_loja, preco_consumidor, nome,
									categoria, fabricante, quantidade, codigo)
{
	Data aux;
	
	aux.dia = dia;
	aux.mes = mes;
	aux.ano = ano;
	
	if(verifica_vencimento(aux))
	{
		set_data_validade(aux);	
	}
	else
	{
		this -> data_validade.dia = 0;
		this -> data_validade.mes = 0;
		this -> data_validade.ano = 0;
	}
									
} 

bool ProdutoPerecivel::verifica_vencimento(Data vencimento)
{
	Data atual;
	
	atual = get_data_atual();
	
	size_t acumula_atual, acumula_vencido, verifica;
	
	acumula_atual = ((12 - atual.mes) * 30) + atual.dia;
	acumula_vencido = ((12 - vencimento.mes) * 30) + vencimento.dia;
	
	if(vencimento.ano - atual.ano == 1)
	{
		verifica = acumula_atual + acumula_vencido;
		if(verifica)
		{
			return true;
		}
	}
	else if(vencimento.ano - atual.ano > 1)
	{
		return true;
	}
	else if(vencimento.ano - atual.ano == 0)
	{
		if(acumula_vencido - acumula_atual >= 1)
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

void ProdutoPerecivel::set_objeto_perecivel(Produto_prototipo aux1, Data aux2)
{
	if(verifica_vencimento(aux2))
	{
		set_objeto_produto(aux1);
		set_data_validade(aux2);
	}
	
	return;
}

void ProdutoPerecivel::set_data_validade(Data aux)
{
	if(verifica_vencimento(aux))
	{
		this -> data_validade.dia = (aux.dia > 0 && aux.dia <= 31) ? aux.dia : 0;
		this -> data_validade.mes = (aux.mes > 0 && aux.mes <= 12) ? aux.mes : 0;
		this -> data_validade.ano = (aux.ano > 0) ? aux.ano : 0;
	}
	
	return;
}

Data ProdutoPerecivel::get_data_validade(void) const
{
	return data_validade;
}

Data ProdutoPerecivel::get_data_atual(void) const
{
	Data aux;
	
	time_t t;
	struct tm * infoTempo;
	
	time(&t);
	infoTempo = localtime(&t);
	
	aux.dia = infoTempo -> tm_mday;
	aux.mes = ++(infoTempo -> tm_mon);
	aux.ano = 1900 + (infoTempo -> tm_year);
	
	return aux;
}

void ProdutoPerecivel::imprimeProdutoPerecivel(void) const
{
	imprimeProduto();
	
	cout << "Data Vencimento do Produto: ";
	cout << setw(2);
	cout << setfill('0') << get_data_validade().dia << "/";
	cout << setfill('0') << get_data_validade().mes << "/";
	cout << setfill('0') << get_data_validade().ano << endl;
}