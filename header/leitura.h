#ifndef LEITURA_H
#define LEITURA_H

typedef struct senha {
    char c[33];
}senha;

typedef struct usuario {
    char nome[51], birth[11], login[21], passwd[65], lastchange[11];
} usuario;

typedef struct senhascrip {
    char senha[65];

}senhascrip;
typedef struct broken {
    char brokename[51];
    char brokenpasswd[33];
    char brokenlogin[21];
    char brokenbirth[11];
} broken;
int countusers(char *filename);
void readUsers(char *filename, usuario *user);
int passwdcount(char *filename);
void readpasswd(char *filename, senha *pass);

#endif