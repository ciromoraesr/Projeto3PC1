#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leitura.h"
#include "shar.h"
#include "quebra.h"
#include "saida.h"
int main() {
    //criando as variáveis x e y que são respectivamente, o número de usuários e o número de senhas
    int x = countusers("usuarios.txt"), y = passwdcount("senhas.txt");
    //alocando memória para os registros de usuário e de usuários com senhas quebradas
    usuario *user = malloc(sizeof(usuario) * x);
    broken *brk = malloc(sizeof(broken) * x);
    //chamando função que lê os dados de cada usuario e coloca seus dados no registro user
    readUsers("usuarios.txt", user);
    //alocando espaço na memória para o número de senhas e o número de senhas criptografadas
    senha *pass = malloc(sizeof(senha) * y);
    senhascrip *crip = malloc(sizeof(senhascrip) * y);
    //printando erro caso alguma dessas alocações não dê certo
    if (pass == NULL || crip == NULL || user  == NULL || brk == NULL) {
        perror("erro de alocacao de memoria");
        exit(1);
    }
    //função que lê as senhas no arquivo de senhas fracas em txt 
    readpasswd("senhas.txt", pass);
    //função que converte cada senha em um hash SHA256 e arquiva elas no registro crip
    sha256(pass,crip, y);
    //inteiro limite que vai ser usado para saber quantos usuarios tiveram as senhas quebrada
    int lim;
    /*funçao que compara as senhas em crip com as senhas de cada usuário e descobre quais usuários
     tiveram suas senhas quebradas, colocando seus dados no registro brk*/
    comparer(crip,pass, user, brk,x, y, &lim);
    //função saída que escreve o arquivo de relatório no formato específicado com cada usuário que teve a senha quebrada
    saida(brk, lim);
    
    free(brk);
    free(user);
    free(pass);
    free(crip);

    return 0;
}
