// Arquivo destinado as sobrecargas utilizadas no projeto.

#include "Produto.h"
#include "ProdutoPerecivel.h"
#include "Remedio.h"
#include <string>

// Sobrecarregando o operador de saída << para que possa gravar um objeto inteiro em um arquivo.
ofstream& operator << (ofstream& arquivo1, Produto& p)
{
	arquivo1 << endl << p.get_objeto_produto().preco_loja << endl;
	arquivo1 << p.get_objeto_produto().preco_consumidor << endl;
	arquivo1 << p.get_objeto_produto().nome << endl;
	arquivo1 << p.get_objeto_produto().categoria << endl;
	arquivo1 << p.get_objeto_produto().fabricante << endl;
	arquivo1 << p.get_objeto_produto().quantidade << endl;
	arquivo1 << p.get_objeto_produto().codigo;
	
	return arquivo1;
}

// Sobrecarregando o operador de saída << para que possa gravar um objeto inteiro em um arquivo.
ofstream& operator << (ofstream& arquivo2, ProdutoPerecivel& pp)
{
	arquivo2 << endl << pp.get_objeto_produto().preco_loja << endl;
	arquivo2 << pp.get_objeto_produto().preco_consumidor << endl;
	arquivo2 << pp.get_objeto_produto().nome << endl;
	arquivo2 << pp.get_objeto_produto().categoria << endl;
	arquivo2 << pp.get_objeto_produto().fabricante << endl;
	arquivo2 << pp.get_objeto_produto().quantidade << endl;
	arquivo2 << pp.get_objeto_produto().codigo << endl;
	arquivo2 << pp.get_data_validade().dia << endl;
	arquivo2 << pp.get_data_validade().mes << endl;
	arquivo2 << pp.get_data_validade().ano;
	
	return arquivo2;
}

// Sobrecarregando o operador de saída << para que possa gravar um objeto inteiro em um arquivo.
ofstream& operator << (ofstream& arquivo3, Remedio& r)
{
	arquivo3 << endl << r.get_objeto_produto().preco_loja << endl;
	arquivo3 << r.get_objeto_produto().preco_consumidor << endl;
	arquivo3 << r.get_objeto_produto().nome << endl;
	arquivo3 << r.get_objeto_produto().categoria << endl;
	arquivo3 << r.get_objeto_produto().fabricante << endl;
	arquivo3 << r.get_objeto_produto().quantidade << endl;
	arquivo3 << r.get_objeto_produto().codigo << endl;
	arquivo3 << r.get_data_validade().dia << endl;
	arquivo3 << r.get_data_validade().mes << endl;
	arquivo3 << r.get_data_validade().ano << endl;
	arquivo3 << r.get_objeto_remedio().medida << endl;
	arquivo3 << r.get_objeto_remedio().info_adicional;
	
	return arquivo3;
}

// Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo1, Produto& p)
{
	
	float preco_loja, preco_consumidor;
	string nome, categoria, fabricante;
	int quantidade;
	long int codigo;
	
	arquivo1 >> preco_loja;
	p.set_preco_loja(preco_loja);
	arquivo1 >> preco_consumidor;
	p.set_preco_consumidor(preco_consumidor);
	getline(arquivo1, nome);
	p.set_nome(nome);
	getline(arquivo1, categoria);
	p.set_categoria(categoria);
	getline(arquivo1, fabricante);
	p.set_fabricante(fabricante);
	arquivo1 >> quantidade;
	p.set_quantidade(quantidade);
	arquivo1 >> codigo;
	p.set_codigo(codigo);
	
	return arquivo1;
}

// Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo2, ProdutoPerecivel& pp)
{
	
	float preco_loja, preco_consumidor;
	string nome, categoria, fabricante;
	int quantidade, dia, mes, ano;
	long int codigo;
	
	arquivo2 >> preco_loja;
	pp.set_preco_loja(preco_loja);
	arquivo2 >> preco_consumidor;
	pp.set_preco_consumidor(preco_consumidor);
	getline(arquivo2, nome);
	pp.set_nome(nome);
	getline(arquivo2, categoria);
	pp.set_categoria(categoria);
	getline(arquivo2, fabricante);
	pp.set_fabricante(fabricante);
	arquivo2 >> quantidade;
	pp.set_quantidade(quantidade);
	arquivo2 >> codigo;
	pp.set_codigo(codigo);
	arquivo2 >> dia;
	arquivo2 >> mes;
	arquivo2 >> ano;
	
	Data aux;
	aux.dia = dia;
	aux.mes = mes;
	aux.ano = ano;
	
	pp.set_data_validade(aux);
	
	return arquivo2;
}

// Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo3, Remedio& r)
{
	
	float preco_loja, preco_consumidor;
	string nome, categoria, fabricante, medida, info_adicional;
	int quantidade, dia, mes, ano;
	long int codigo;
	
	arquivo3 >> preco_loja;
	r.set_preco_loja(preco_loja);
	arquivo3 >> preco_consumidor;
	r.set_preco_consumidor(preco_consumidor);
	getline(arquivo3, nome);
	r.set_nome(nome);
	getline(arquivo3, categoria);
	r.set_categoria(categoria);
	getline(arquivo3, fabricante);
	r.set_fabricante(fabricante);
	arquivo3 >> quantidade;
	r.set_quantidade(quantidade);
	arquivo3 >> codigo;
	r.set_codigo(codigo);
	arquivo3 >> dia;
	arquivo3 >> mes;
	arquivo3 >> ano;
	
	Data aux;
	aux.dia = dia;
	aux.mes = mes;
	aux.ano = ano;
	
	r.set_data_validade(aux);
	
	getline(arquivo3, medida);
	r.set_medida(medida);
	getline(arquivo3, info_adicional);
	r.set_info_adicional(info_adicional);	
	
	return arquivo3;
}