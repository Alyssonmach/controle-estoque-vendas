#include "../headers/Vendas.h"

#include <ctime>

using namespace std;

Vendas::Vendas(void)
{
	float a;
	
    ifstream myfile1;
    myfile1.open("../financas/apurado.txt");
    myfile1 >> a;
    this -> apurado  = a;
    myfile1.close();
    
    ifstream myfile2;
    myfile2.open("../financas/saldo.txt");
    myfile2 >> a;
    this -> saldo  = a;
    myfile2.close();
}

Vendas::~Vendas(void)
{
	ofstream myfile1;
	myfile1.open("../financas/apurado.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile1.is_open())
	{
		myfile1 << (this -> apurado);
		myfile1.close();
	}
	else cout << "Não foi possível abrir o arquivo." << cout;
	
	ofstream myfile2;
	myfile2.open("../financas/saldo.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile2.is_open())
	{
		myfile2 << (this -> saldo);
		myfile2.close();
	}
	else cout << "Não foi possível abrir o arquivo." << cout;
}

void Vendas::adiciona_apurado(float apurado)
{
	this -> apurado += (apurado > 0) ? apurado : 0; 
	
	return;
}

void Vendas::adiciona_saldo(float saldo)
{
	this -> saldo += (saldo > 0) ? saldo : 0; 
	
	return;
}

int Vendas::quantidade_notas_fiscais(void)
{
	DIR *dir;
	struct dirent *lsdir;
	
	int count = 0;
	
	dir = opendir("../NotasFiscais/notas_de_compras/");
	
	while((lsdir = readdir(dir)) != NULL)
	{
		count++;
	}
	
	return (count - 2);
}

string Vendas::diretorio_nota(int arquivo_atual)
{
	string nome = "NotaFiscal";
	char snum[1];
	
	nome = nome + itoa(arquivo_atual, snum, 10);
	nome = "../NotasFiscais/notas_de_compras/" + nome + ".txt";
	
	return nome;
}

void Vendas::inserir_nota_produto(Produto aux)
{
	produto_nota.push_back(aux);
	
	return;
}

void Vendas::inserir_nota_perecivel(ProdutoPerecivel aux)
{
	perecivel_nota.push_back(aux);
	
	return;
}

void Vendas::inserir_nota_remedio(Remedio aux)
{
	remedio_nota.push_back(aux);
	
	return;
}

bool Vendas::pesquisar_nota_produto(long int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < produto_nota.size(); i++)
	{
		if(produto_nota[i].get_objeto_produto().codigo == codigo)
		{
			produto_nota[i].imprimeProduto();
			return true;
		}
		else
			contador++;
	}
	if(contador == produto_nota.size())
		return false;
	
	return false;
}

bool Vendas::pesquisar_nota_perecivel(long int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < perecivel_nota.size(); i++)
	{
		if(perecivel_nota[i].get_objeto_produto().codigo == codigo)
		{
			perecivel_nota[i].imprimeProdutoPerecivel();
			return true;
		}
		else
			contador++;
	}
	if(contador == perecivel_nota.size())
		return false;
	
	return false;
}

bool Vendas::pesquisar_nota_remedio(long int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < remedio_nota.size(); i++)
	{
		if(remedio_nota[i].get_objeto_produto().codigo == codigo)
		{
			remedio_nota[i].imprimeProdutoPerecivel();
			return true;
		}
		else
			contador++;
	}
	if(contador == remedio_nota.size())
		return false;
	
	return false;
}

bool Vendas::apaga_da_nota_produto(long int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < produto_nota.size(); i++)
	{
		if(produto_nota[i].get_objeto_produto().codigo == codigo)
		{
			produto_nota.erase(produto_nota.begin() + i);
			return true;
		}
		else
			contador++;
	}
	if(contador == produto_nota.size())
		return false;
	
	return false;
}

bool Vendas::apaga_da_nota_perecivel(long int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < perecivel_nota.size(); i++)
	{
		if(perecivel_nota[i].get_objeto_produto().codigo == codigo)
		{
			perecivel_nota.erase(perecivel_nota.begin() + i);
			return true;
		}
		else
			contador++;
	}
	if(contador == perecivel_nota.size())
		return false;
	
	return false;
}

bool Vendas::apaga_da_nota_remedio(long int codigo)
{
	unsigned contador(0);
	for(unsigned i(0); i < remedio_nota.size(); i++)
	{
		if(remedio_nota[i].get_objeto_produto().codigo == codigo)
		{
			remedio_nota.erase(remedio_nota.begin() + i);
			return true;
		}
		else
			contador++;
	}
	if(contador == remedio_nota.size())
		return false;
	
	return false;
}

void Vendas::imprime_historico_fiscal(void) const
{
  string linha;
  ifstream myfile ("../NotasFiscais/historico/historico_notas_fiscais.txt");
  if (myfile.is_open())
  {
    while (getline(myfile, linha))
    {
      cout << linha << '\n';
    }
    myfile.close();
  }
  else cout << "Não foi possível abrir o histórico." << endl;
  
  return;
}

void Vendas::limpa_historico_notas(void)
{
	ofstream myfile;
	myfile.open("../NotasFiscais/historico/historico_notas_fiscais.txt", std::ios::trunc);
    myfile.close();
    
	return;
}

void Vendas::restaura_historico_notas(void)
{
	DIR *dir;
	struct dirent *lsdir;
	
	dir = opendir("../NotasFiscais/notas_de_compras/");
	limpa_historico_notas();
	if((lsdir = readdir(dir)) == NULL)
	{
		cout << "Não há notas fiscais registradas." << endl;
		return;
	}
	else
	{
		for(int i(0); i < quantidade_notas_fiscais(); i++)
		{
			string linha;
		    ifstream myfile2 (diretorio_nota(i).c_str());
		    if (myfile2.is_open())
		    {
		      while ( getline (myfile2,linha) )
		      {
		          ofstream myfile;
				  myfile.open ("../NotasFiscais/historico/historico_notas_fiscais.txt", std::ofstream::out | std::ofstream::app);
				  if (myfile.is_open())
				  {
					  	myfile << linha << endl;
				    	myfile.close();
				  }
				  else cout << "Não foi possível abrir o arquivo." << cout;
		      }
		      myfile2.close();
		  }
		  else cout << "Não foi possível abrir o arquivo." << cout;
		  
		  ofstream myfile;
          myfile.open ("../NotasFiscais/historico/historico_notas_fiscais.txt", std::ofstream::out | std::ofstream::app);
		  if (myfile.is_open())
          {
				myfile << endl;
				myfile.close();
          }
          else cout << "Não foi possível abrir o arquivo." << cout;  
		}
	}
	
	return;
}

void Vendas::imprime_ultimas_notas(int limite)
{	
	if(quantidade_notas_fiscais() < limite)
	{
		cout << "Não há notas suficientes para impressão." << endl;
		return;
	}
	else
	{
		for(int i(0); i < limite; i++)
		{
			string linha;
		    ifstream myfile2 (diretorio_nota(quantidade_notas_fiscais() - i - 1).c_str());
		    if (myfile2.is_open())
		    {
		      while ( getline (myfile2,linha) )
		      {
		          cout << linha << '\n';
		      }
		      myfile2.close();
		      cout << endl;
		  }
		  else cout << "Não foi possível abrir o arquivo." << cout;
		}
	}
	
	return;
}

Data Vendas::retornaDataAtual(void) const
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
void Vendas::monta_nota_fiscal(void)
{
	  cout << fixed << setprecision(2);
	  
	  ofstream myfile;
	  myfile.open ("../NotasFiscais/historico/historico_notas_fiscais.txt", std::ofstream::out | std::ofstream::app);
	  if (myfile.is_open())
	  {
	  	
	  		myfile << "=== Nota Fiscal da Farmácia === Data: ";
	  		myfile << setw(2);
	   	   	myfile << setfill('0') << retornaDataAtual().dia << "/";
			myfile << setfill('0') << retornaDataAtual().mes << "/";
			myfile << setfill('0') << retornaDataAtual().ano << endl;
	  		for(unsigned i(0); i < produto_nota.size(); i++)
			{
				myfile << "Nome do Produto: " << produto_nota[i].get_objeto_produto().nome;
				myfile << " / Preço do Produto: " << produto_nota[i].get_objeto_produto().preco_consumidor << " R$";
				myfile << " / Código de Barras: " << produto_nota[i].get_objeto_produto().codigo << endl;
			}
			
			for(unsigned i(0); i < perecivel_nota.size(); i++)
			{
				myfile << "Nome do Produto: " << perecivel_nota[i].get_objeto_produto().nome;
				myfile << " / Preço do Produto: " << perecivel_nota[i].get_objeto_produto().preco_consumidor << " R$";
				myfile << " / Código de Barras: " << perecivel_nota[i].get_objeto_produto().codigo << endl;
			}
			
			for(unsigned i(0); i < remedio_nota.size(); i++)
			{
				myfile << "Nome do Produto: " << remedio_nota[i].get_objeto_produto().nome;
				myfile << " / Preço do Produto: " << remedio_nota[i].get_objeto_produto().preco_consumidor << " R$";
				myfile << " / Código de Barras: " << remedio_nota[i].get_objeto_produto().codigo << endl;
			}
			myfile << endl;
	    	myfile.close();
	  }
	  else cout << "Não foi possível abrir o arquivo." << cout;
	  
	  std::ofstream myfile1;
	  myfile1.open(diretorio_nota(quantidade_notas_fiscais()).c_str(), std::ofstream::out | std::ofstream::app);
	  if (myfile1.is_open())
	  {
			myfile1 << "=== Nota Fiscal da Farmácia === Data: ";
	  		myfile1 << setw(2);
	   	   	myfile1 << setfill('0') << retornaDataAtual().dia << "/";
			myfile1 << setfill('0') << retornaDataAtual().mes << "/";
			myfile1 << setfill('0') << retornaDataAtual().ano << endl;
	  		for(unsigned i(0); i < produto_nota.size(); i++)
			{
				myfile1 << "Nome do Produto: " << produto_nota[i].get_objeto_produto().nome;
				myfile1 << " / Preço do Produto: " << produto_nota[i].get_objeto_produto().preco_consumidor << " R$";
				myfile1 << " / Código de Barras: " << produto_nota[i].get_objeto_produto().codigo << endl;
			}
			
			for(unsigned i(0); i < perecivel_nota.size(); i++)
			{
				myfile1 << "Nome do Produto: " << perecivel_nota[i].get_objeto_produto().nome;
				myfile1 << " / Preço do Produto: " << perecivel_nota[i].get_objeto_produto().preco_consumidor << " R$";
				myfile1 << " / Código de Barras: " << perecivel_nota[i].get_objeto_produto().codigo << endl;
			}
			
			for(unsigned i(0); i < remedio_nota.size(); i++)
			{
				myfile1 << "Nome do Produto: " << remedio_nota[i].get_objeto_produto().nome;
				myfile1 << " / Preço do Produto: " << remedio_nota[i].get_objeto_produto().preco_consumidor << " R$";
				myfile1 << " / Código de Barras: " << remedio_nota[i].get_objeto_produto().codigo << endl;
			}
	    	myfile1.close();
	  }
	  else cout << "Não foi possível abrir o arquivo." << cout;
	  
	  long int codigo;
  	  bool estado;
  
	  for(unsigned i(0); i < produto_nota.size(); i++)
	  {
	  	adiciona_saldo(produto_nota[i].get_objeto_produto().preco_consumidor);
	  	adiciona_apurado(produto_nota[i].get_objeto_produto().preco_consumidor - produto_nota[i].get_objeto_produto().preco_loja);
	  	codigo = produto_nota[i].get_objeto_produto().codigo;
	  }
	  
	  estado = apaga_da_nota_produto(codigo);
	  
	  for(unsigned i(0); i < perecivel_nota.size(); i++)
	  {
	  	adiciona_saldo(perecivel_nota[i].get_objeto_produto().preco_consumidor);
	  	adiciona_apurado(perecivel_nota[i].get_objeto_produto().preco_consumidor - perecivel_nota[i].get_objeto_produto().preco_loja);
	  	codigo = perecivel_nota[i].get_objeto_produto().codigo;
	  }
	  
	  estado = apaga_da_nota_perecivel(codigo);
	  
	  for(unsigned i(0); i < remedio_nota.size(); i++)
	  {
	  	adiciona_saldo(remedio_nota[i].get_objeto_produto().preco_consumidor);
	  	adiciona_apurado(remedio_nota[i].get_objeto_produto().preco_consumidor - remedio_nota[i].get_objeto_produto().preco_loja);
	  	codigo = remedio_nota[i].get_objeto_produto().codigo;
	  }
	  
	  estado = apaga_da_nota_remedio(codigo);
	
	return;
}

void Vendas::fecha_conta_mes(void)
{
	apurado = 0;
	saldo = 0;
	
	ofstream myfile1;
	myfile1.open("../financas/apurado.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile1.is_open())
	{
		myfile1 << apurado;
		myfile1.close();
	}
	else cout << "Não foi possível abrir o arquivo." << cout;
	
	ofstream myfile2;
	myfile2.open("../financas/saldo.txt", std::ofstream::out | std::ofstream::trunc);
	if (myfile2.is_open())
	{
		myfile2 << saldo;
		myfile2.close();
	}
	else cout << "Não foi possível abrir o arquivo." << cout;
	
	return;
}

float Vendas::get_apurado(void) const
{
	return apurado;
}

float Vendas::get_saldo(void) const
{
	return saldo;
}