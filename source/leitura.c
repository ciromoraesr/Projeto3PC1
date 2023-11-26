#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leitura.h"
//função que conta o número de usuários baseado na quantidade de vezes que a string "---" aparece
int countusers(char *filename){
    FILE *arq = fopen(filename, "r");
    if(arq == NULL){
        perror("unable to open");
        exit(1);    
    }
    int count  = 0;
    char temp[65];
    while(fgets(temp, sizeof(temp), arq) != NULL){
        if(strncmp(temp, "---", 3) == 0){
            count++;
        }
    }
    fclose(arq);
    return count;
}
/*função que lê os dados de cada usuários usando a função fscanf e definindo parâmetros para 
ler os caracteres específicos e retirar os valores \n e \r, armazenando somente os valores necessários no registro de usuários */
void readUsers(char *filename, usuario *user) {
    FILE *arq = fopen(filename, "r");
    if (arq == NULL) {
        perror("Unable to open");
        exit(1);
    }

    int count = 0;
    while (fscanf(arq, "%50[^\n\r]\n%10[^\n]\n%20[^\n]\n%64[^\n]\n%10[^\n]\n---\n",
                  user[count].nome, user[count].birth, user[count].login,
                  user[count].passwd, user[count].lastchange) == 5) {
        count++;
    }

    fclose(arq);
}
// função que lê o número de senhas baseado no número de linhas no arquivo de senhas fracas
int passwdcount(char *filename){
    FILE *passwd = fopen(filename, "r");
    if(passwd == NULL){
        perror("unable to open");
        exit(1);   
    }
    int count  = 0;
    char temp[33];
    while(fgets(temp, sizeof(temp), passwd) != NULL){
        temp[strcspn(temp, "\n")] = '\0';

        if (strcmp(temp, "") != 0) {
            count++;
        }
    }
    fclose(passwd);
    return count;
}
//função para ler as senhas e armazená-las no registro pass
void readpasswd(char *filename, senha *pass) {
    FILE *passwd = fopen(filename, "r");
    if (passwd == NULL) {
        perror("Unable to open");
        exit(1);
    }
    int count = 0;
    char temp[33];
    while (fgets(temp, sizeof(temp), passwd) != NULL) {
        
        temp[strcspn(temp, "\r\n")] = '\0';

        
        strcpy(pass[count].c, temp);

        count++;
    }
    fclose(passwd);
}
