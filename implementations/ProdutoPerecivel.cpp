#include "../headers/ProdutoPerecivel.h"

#include <ctime>
#include <iomanip>
using std::setw;
using std::setfill;

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
	
	set_data_validade(aux);										
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

void ProdutoPerecivel::imprimeProdutoPerecivel(void) const
{
	imprimeProduto();
	
	cout << "Data de Vencimento do Produto: ";
	cout << setw(2);
	cout << setfill('0') << get_data_validade().dia << "/";
	cout << setfill('0') << get_data_validade().mes << "/";
	cout << setfill('0') << get_data_validade().ano << endl;
}