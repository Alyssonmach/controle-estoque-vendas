#include "../headers/Remedio.h"

Remedio::Remedio(float preco_loja, float preco_consumidor, string nome, string categoria, 
				 string fabricante, int quantidade, long int codigo, int dia, int mes,
	   	     	 int ano, string medida, string info_adicional) : ProdutoPerecivel(preco_loja, 
                 preco_consumidor, nome, categoria, fabricante, quantidade, codigo, dia, mes,
				 ano)
{
	set_medida(medida);
	set_info_adicional(info_adicional);		 	
}

void Remedio::set_objeto_remedio(Produto_prototipo aux1, Data aux2, Drogaria aux3)
{
	if(verifica_vencimento(aux2))
	{
		set_objeto_produto(aux1);
		set_data_validade(aux2);
		set_medida(aux3.medida);
		set_info_adicional(aux3.info_adicional);
	}
}

void Remedio::set_medida(string medida)
{
	this -> objeto_remedio.medida = medida;
	
	return;
}

void Remedio::set_info_adicional(string info_adicional)
{
	this -> objeto_remedio.info_adicional = info_adicional;
}

Drogaria Remedio::get_objeto_remedio(void) const
{
	return objeto_remedio;
}