#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leitura.h"
#include "quebra.h"
#include "shar.h"
 //função que compara o valor de user.passwd e crip.senha
void comparer(senhascrip *crip, senha *pass, usuario *user, broken *brk, int x, int y, int *lim) {
    int count  =0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            /* e para cada usuário que a senha consta no banco de dados de senhas fracas,
             são armazenados no registro brk o seu nome, senha, login e data de nascimento*/
            if (strcmp(user[i].passwd, crip[j].senha) == 0) {
                strcpy(brk[i].brokenpasswd, pass[j].c);
                strcpy(brk[i].brokename, user[i].nome);
                strcpy(brk[i].brokenbirth, user[i].birth);
                strcpy(brk[i].brokenlogin, user[i].login);
                count++;
            }
        }
    }
    //alterando o valor do inteiro lim para ser usado na main como o número de usuários que tiveram a senha quebrada
    *lim = count;
}
