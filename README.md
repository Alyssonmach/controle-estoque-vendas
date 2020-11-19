# controle-estoque-e-vendas
#### Projeto de controle de estoque e vendas em Farmácia.

### Membros do projeto

- **Alysson Machado** (Pessoa responsável por modelar o formato dos objetos das classes e implementação do estoque da farmácia);
- **Nathan Ferreira** (Pessoa responsável por implementar o funcionamento da classe de Vendas, essa que tem comunicação direta com o estoque);
- **Iago Miguel** (Pessoa Responsável por cuidar da gestão dos funcionários da farmácia, determinando o modelo de cadastro por objetos);
- **Marcos Pereira** (Pessoa responsável por implementar o funcionamento da classe de Vendas, essa que tem comunicação direta com o estoque);

### Objetivo

Implementar um projeto que faça o controle de estoque e vendas de uma farmácia usando a linguagem de programação C++. 

### Classes Implementadas

- Sobrecarga [**Concluído**]

A classe Sobrecarga é responsável por realizar sobrecarga em operadores específicos, de modo que seja possível fazer toda a parte de manipulação com os arquivos nos construtores e destrutores, garantido que as listas de objetos sejam lidas logo no início da execução e sobrescritas ao final da execução.

- Produto [**Concluído**]

A classe Produto é responsável por armazenar diversos atributos de um objeto não perecível. Envolve informações sobre preço de aquisição, preço de compra, nome do produto, nome do fabricante, categoria, quantidade em estoque e código de barras do produto. Os métodos são referentes a configuração e impressão dos atributos.

- Perecivel [**Concluído**]

A classe Perecível é responsável por armazenar diversos atributos de um objeto perecível. Sendo uma classe que tem herança com a classe Produto, ela vai englobar todos os métodos envolvidos nessa classe, com o adicional de uma data de validade. Além disso, foi implementado um método que computa a data atual do produto, de modo que seja possível verificar se tal produto está vencido ou não.

- Remedio [**Concluído**]

A classe Remedio é responsável por armazenar diversos atributos de um objeto perecível. Sendo uma classe que tem herança com a classe Perecivel, ela vai englobar todos os métodos envolvidos nessa classe, com o adicional de informações de medidas do remédio e informações da finalidade desse remédio.

- Estoque [**Concluído**]

A classe Estoque é responsável por fazer todos os gerenciamentos dos produtos disponíveis a venda na farmácia. Armazenando todos os objetos pertencentes a classe Produto, Perecivel e Remedio em um Vector, foi implementado os seguintes métodos:

- [x] Métodos para checar o vencimento de produtos Perecíveis e Remédios;
- [x] Métodos para ler as listas de Produtos, Produtos Perecíveis e Remédios armazenados em um arquivo; 
- [x] Métodos para salvar as listas de Produtos, Produtos Perecíveis e Remédios armazenados em um .arquivo; 
- [x] Métodos para inserir os Produtos, Produtos Perecíveis e Remédios nas listas de Vector;
- [x] Métodos para imprimir os Produtos, Produtos Perecíveis e Remédios nas listas de Vector;
- [x] Métodos para remover os Produtos, Produtos Perecíveis e Remédios nas listas de Vector;
- [x] Métodos para remover os Produtos, Produtos Perecíveis e Remédios que estão vencidos nas listas .de Vector;
- [x] Métodos para pesquisar os Produtos, Produtos Perecíveis e Remédios nas listas de Vector;
- [x] Métodos para pesquisar os Produtos, Produtos Perecíveis e Remédios que estão vencidos nas listas de Vector;
- [X] Métodos que retornam um objeto armazenado na lista de Vector através do índice;
- [x] Métodos para retornar todas as listas de vector que armazena os objetos Produto, Produto Perecível e Remédio armazenados em arquivos distintos;

- Vendas [**Em construção**]

A classe Vendas é responsável por fazer a comunicação indireta com o Estoque. Através dela, os funcionários de uma farmácia poderiam elaborar notas fiscas dos consumidores e realizar o cálculo da parte financeira da farmácia.

- Cadastro [**Em construção**]

A classe Cadastro é responsável por fazer a gestão de funcionários da farmácia. Em outras farmácias, armazena informações de cadastro dos funcionários, criando senhas de acesso específica para cada um deles. Há três tipos distintos de cadastro:

- [x] Cadastro Universal e único dá poder a uma só pessoa de registrar novos funcionários;
- [x] Cadastro de funcionários de vendas dá poder aos membros de de gerar saída de produtos do estoque por meio de notas fiscais;
- [x] Cadastro de operários de estoque dá livre acesso ao estoque da loja, de modo que seja possível implementar todos os métodos envolvidos da classe Estoque;


### Diretórios

- Arquivos

- [x] Contém todos os arquivos de texto .txt que armazenam em lista os objetos referenciados na lista de Vector;
 
- Headers

- [x] Contém todos os arquivos de cabeçalho .h das classes utilizadas no projeto;

- Implementations

- [x] Contém todos os arquivos de implementação .cpp das classes utilizadas no projeto;

 - Tests

 - [x] Contéum todos os arquivos de teste .cpp que testam cada um dos métodos da classe;
