#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leitura.h"
#include "quebra.h"
#include "saida.h"

void saida(broken *brk, int x){
    //abrindo o arquivo "saida.txt" como escrita, portanto o arquivo será criado caso não exista
    char *filename = "saida.txt";
    FILE *out = fopen(filename, "w");
    if(out == NULL){
        perror("unable to open");
        exit(1);
    }
    //iterando entre os registradores de brk e imprimindo seus respectivos valores com base no modelo especificado 
    for(int i = 1; i <= x; i++){
        fprintf(out, "%s\n%s\n%s\n%s\n---", brk[i].brokenlogin, brk[i].brokenpasswd, brk[i].brokename, brk[i].brokenbirth);
        if(i != (x)){
            fprintf(out, "\n");
        }
    }
    fclose(out);
}