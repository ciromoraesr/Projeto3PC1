# Ataque de Dicionáro
Projeto 3 da disciplina Programação de Computadores 1 realizado de acordo com o arquivo: https://danielsaad.com/programacao-de-computadores-1/assets/trabalhos/ataque-de-dicionario.pdf

# Autor
Nome: Ciro Moraes Rocha
Disciplina: Programação de Computadores 1
Instituição: Instituto Federal de Brasília (IFB)

# Descrição

O projeto se trata de um algoritmo que recebe um arquivo de texto com usuários e um arquivo de texto com possíveis senhas fracas, nos dados do usuário consta a sua senha em SHA256, portanto o código deve ser capaz de converter cada senha no arquivo de senhas fracas em sua versão SHA256 e comparar com as senhas de cada usuário, gerando no final um arquivo de saida de texto que consta com os dados dos usuários que tiveram suas senhas descobertas e suas respectivas senhas.

# Exemplo
Arquivo de usuários:

Daniel Saad<br /> 
01/01/1850<br /> 
danielsaad
981a16abd878e773ba98c10fd55db367a05f807f2eb5b5c3f2b86efbb218e2e3<br /> 
03/11/2023<br /> 
---<br /> 
Marcus Vinicius<br /> 
02/02/1950<br /> 
marquinhos<br /> 
65e84be33532fb784c48129675f9eff3a682b27168c0ea744b2cf58ee02337c5<br /> 
20/10/2023<br /> 
---<br /> 
Cleidison Santos<br /> 
24/12/2000<br /> 
cleidison<br /> 
d58d736c7a967fb5f307951932734f8b0594725faa5011dbb66a8c538e635fb6<br /> 
10/5/2021<br /> 
---<br /> 

Arquivo de senhas fracas:

swordfish<br /> 
flamengo<br /> 
letmein<br /> 
irobot<br /> 
qwerty<br /> 

Arquivo de Saída:

marquinhos<br /> 
qwerty<br /> 
Marcus Vinicius<br /> 
02/02/1950<br /> 
---<br /> 
cleidison<br /> 
flamengo<br /> 
Cleidison Santos<br /> 
24/12/2000<br /> 
---<br /> 

# Instruções de utilização

1 - Instale e extraia o arquivo Projeto3PC1_CiroMoraes do arquivo Projeto3PC1_CiroMoraes.zip;

2- No diretório atualize o arquivo de texto chamado "usuarios.txt" com novas informações de usuários que deseja testar, lembre-se de manter o formato de texto dos usuários que já constam no arquivo, e lembre-se também de manter o nome do arquivo como "usuarios.txt";

3 - Como no item anterior, também consta no arquivo um arquivo chamado "senhas.txt" com as senhas fracas que serão utilizadas, atualize esse arquivo de acordo com os exemplos já inseridos com a quantidade de senhas que deseja testar, mantendo o seu respectivo nome;

4 - Instale a bilbioteca openssl no linux, para checar se ela já foi instalada, utilize o comando "openssl version".

5 - Com os arquivos já criados, navegue até o diretório em que a pasta está localizada e utilize o comando make para compilar o código;

6 - Com o executável "exec" já criado, utilize o comando "./exec" para executar o programa;

7 - Uma pasta chamada "saida.txt" será criada com as informações dos usuários que tiveram suas senhas quebradas, seguindo o padrão fornecido no exemplo;

# Considerações Finais

Este projeto foi fundamental para o desenvolvimento de programas capazes de interagir eficientemente com arquivos de texto. Além disso, proporcionou insights valiosos sobre a alocação dinâmica de memória, levando-me a considerar essa abordagem como uma solução eficaz para otimizar o espaço de memória diante de desafios em constante expansão. A implementação do algoritmo SHA256 desempenhou um papel crucial, destacando a importância da criptografia em senhas contemporâneas. Foi particularmente interessante descobrir esta nova biblioteca no sistema Linux durante o desenvolvimento do projeto.
