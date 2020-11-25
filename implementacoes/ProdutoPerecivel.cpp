#include "../cabecalhos/ProdutoPerecivel.h"

#include <ctime>
#include <iomanip>

using std::setw;
using std::setfill;

ProdutoPerecivel::ProdutoPerecivel(float preco_loja, float preco_consumidor, string nome, string categoria, string fabricante, int quantidade, long int codigo, int dia, int mes, int ano) : Produto(preco_loja, preco_consumidor, nome, categoria, fabricante, quantidade, codigo)
{
	Data aux;
	
	aux.dia = dia;
	aux.mes = mes;
	aux.ano = ano;
	
	set_data_validade(aux);										
} 

bool ProdutoPerecivel::valida_objeto_perecivel(Produto_prototipo aux, Data daux)
{
	int contador(0);
	
	if(valida_objeto_produto(aux))
	{
		if(valida_data_validade())
			return false;
		
		contador += (daux.dia > 0 && daux.dia <= 31) ? 0 : 1;
		contador += (daux.mes > 0 && daux.mes <= 12) ? 0 : 1;
		contador += (daux.ano > 0) ? 0 : 1;
		if(!contador)
			return true;
		
	}
	else
		return false;
	
	return false;
}

bool ProdutoPerecivel::valida_data_validade(void)
{
	Data atual;
	
	atual = get_data_atual();
	
	int acumula_atual, acumula_vencido, verifica, anual;
	
	acumula_atual = ((12 - atual.mes) * 30) + atual.dia;
	acumula_vencido = ((12 - get_data_validade().mes) * 30);
	acumula_vencido += get_data_validade().dia;
	
	if(get_data_validade().ano - atual.ano == 1)
	{
		verifica = acumula_atual + acumula_vencido;
		if(verifica <= 0)
		{
			return true;
		}
	}
	else if(get_data_validade().ano - atual.ano > 1)
	{
		
		verifica = acumula_atual + acumula_vencido;
		anual = (get_data_validade().ano - atual.ano - 1) * 365;
		verifica += anual;
		if(verifica <= 0)
		{
			return true;
		}
	}
	else if(get_data_validade().ano - atual.ano == 0)
	{
		
		if(get_data_validade().mes < get_data_atual().mes)
		{
			return true;
		}
		else if(get_data_validade().mes == get_data_atual().mes)
		{
			if(get_data_validade().dia <= get_data_atual().dia)
			{
				return true;	
			}
		}
	}
	
	return false;
}

void ProdutoPerecivel::set_objeto_perecivel(Produto_prototipo aux1, Data aux2)
{
	set_objeto_produto(aux1);
	set_data_validade(aux2);
	
	return;
}

void ProdutoPerecivel::set_data_validade(Data aux)
{
		this -> data_validade.dia = (aux.dia > 0 && aux.dia <= 31) ? aux.dia : 0;
		this -> data_validade.mes = (aux.mes > 0 && aux.mes <= 12) ? aux.mes : 0;
		this -> data_validade.ano = (aux.ano > 0) ? aux.ano : 0;
	
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

void ProdutoPerecivel::imprimeDataAtual(void) const
{
	cout << "Data de Atual: ";
	cout << setw(2);
	cout << setfill('0') << get_data_atual().dia << "/";
	cout << setfill('0') << get_data_atual().mes << "/";
	cout << setfill('0') << get_data_atual().ano << endl;
	
	return;
}

void ProdutoPerecivel::imprimeDataVencimento(void) const
{
	cout << "Data de Vencimento do Produto: ";
	cout << setw(2);
	cout << setfill('0') << get_data_validade().dia << "/";
	cout << setfill('0') << get_data_validade().mes << "/";
	cout << setfill('0') << get_data_validade().ano << endl;
	
	return;
}

void ProdutoPerecivel::imprimeProdutoPerecivel(void) const
{
	imprimeProduto();
	imprimeDataVencimento();
}