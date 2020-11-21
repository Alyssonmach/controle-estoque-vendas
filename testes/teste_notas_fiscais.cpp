#include <iostream>
#include <fstream>
#include <locale>
#include <cstdio>
#include <cstdlib>
#include <dirent.h>
#include <string>

using namespace std;

int main (void) {
	
  setlocale(LC_ALL, "Portuguese");
  
  DIR *dir;
  struct dirent *lsdir;
  char snum[1];
	
  int count = 0;
  string nome = "NotaFiscal", numero;
	
  dir = opendir("../NotasFiscais/notas_de_compras/");
	
  while((lsdir = readdir(dir)) != NULL)
  {
		cout << lsdir -> d_name << endl;
		count++;
  }
	
  cout << count - 2 << " Arquivos" << endl;
	
  nome = nome + itoa(count - 2, snum, 10);
  cout << nome << endl;
  closedir(dir);
  
  nome = "../NotasFiscais/notas_de_compras/" + nome + ".txt";
  
  ofstream myfile;
  myfile.open ("../NotasFiscais/historico/historico_notas_fiscais.txt", std::ofstream::out | std::ofstream::app);
  if (myfile.is_open())
  {
	  	myfile << "=== Teste === Data: 12/12/1111" << endl;
	  	myfile << "Nome do lojista" << endl;
    	myfile << "Nome do Produto - Preço" << endl;
    	myfile << "info info" << endl << endl;
    	myfile.close();
  }
  else cout << "Não foi possível abrir o arquivo." << cout;
  
  std::ofstream myfile1;
  myfile1.open(nome.c_str(), std::ofstream::out | std::ofstream::app);
  if (myfile1.is_open())
  {
	  	myfile1 << "=== Teste === Data: 12/12/1111" << endl;
	  	myfile1 << "Nome do lojista" << endl;
    	myfile1 << "Nome do Produto - Preço" << endl;
    	myfile1 << "info info" << endl << endl;
    	myfile1.close();
  }
  else cout << "Não foi possível abrir o arquivo." << cout;

  string line;
  ifstream myfile2 ("../NotasFiscais/historico/historico_notas_fiscais.txt");
  if (myfile2.is_open())
  {
    while ( getline (myfile2,line) )
    {
      cout << line << '\n';
    }
    myfile2.close();
  }
  else cout << "Não foi possível abrir o arquivo." << cout;
  
  return 0;
}