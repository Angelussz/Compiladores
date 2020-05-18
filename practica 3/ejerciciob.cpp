#include <bits/stdc++.h>

#define MAYOR '>'
#define MENOR '<'
#define IGUAL '='
#define PUNTOYCOMA ';'
#define COMA ','
#define PARI '('
#define PARD ')'
#define CORI '['
#define CORD ']'
#define LLAI '{'
#define LLAD '}'
#define SUMA '+'
#define RESTA '-'
#define MULTIPLICACION '*'
#define DIVISION '/'
#define ID 256
#define NUM 257
#define MAYORIGUAL 258
#define MENORIGUAL 259
#define IGUALDAD 260
#define DIFERENCIA 261
#define WHILE 262
#define IF 263
#define FOR 264


int scaner();
void mostrar(int);
int espalres();

FILE *f;
char lexema[80];

int main(int n,char *pal[]){
    int token;
    f = stdin;
    if(n==2){
        f = fopen(pal[1],"rt");
        if (f==NULL){
            f = stdin;
        }
    }
    if(f==stdin) {
        printf("Ingrese texto ........ termine con Ctrl z \n");
    }
    while (1)
    {
        token =scaner();
        if(token==EOF)break;
        mostrar(token);
    }
    if(f != stdin)
       fclose(f);
}

int scaner(){
    int c;
    int i;
    do
    {
        c=fgetc(f);
    } while (isspace(c));
    if(c==EOF) return EOF;
    if(isalpha(c)){
        i=0;
        do{
            lexema[i++] = c;
            c=fgetc(f);

        }while(isalnum(c) || c=='_');
        lexema[i] =0;
        ungetc(c,f);
        i = espalres();
        if(i>=0){
            return i;
        }
        return ID;
    }
    if(isdigit(c)){
        i=0;
        do{
            lexema[i++]=c;
            c=fgetc(f);
        }while(isdigit(c));

        lexema[i]=0;
        ungetc(c,f);
        return NUM;
    }

    if ((c==';')||(c=='(') ||(c==',')||(c==')')||(c=='[')||(c==']')||(c=='{')||(c=='}')) 
    {
        return c;
    }
    if ((c=='+')||(c=='-') || (c=='*')) 
    {
        return c;
    }
    if(c=='/')
    {
        c=fgetc(f);
        if (c=='/')
        {
            while (1)
            {
                c=fgetc(f);
                if (c=='\n') break;
                if(c==EOF) break;
            }
        }
        else if(c=='*')
        {
            while (1)
            {
                c=fgetc(f);
                if (c=='*'){
                    c=fgetc(f);
                    if (c=='/') break;
                }
                if(c==EOF) break;
            }
        }
        else
        {
            ungetc(c,f);
            
            return DIVISION;
        }
    }
    if(c=='>'){
        c=fgetc(f);
        if(c=='='){
            lexema[0]='>';lexema[1]='=';lexema[2]=0;
            return MAYORIGUAL;
        }
        ungetc(c,f);
        return MAYOR;
    }
    if(c=='<'){
        c=fgetc(f);
        if(c=='='){
            lexema[0]='<';lexema[1]='=';lexema[2]=0;
            return MENORIGUAL;
        }
        ungetc(c,f);
        return MENOR;
    }
    if(c=='='){
        c=fgetc(f);
        if(c=='='){
            lexema[0]='=';lexema[1]='=';lexema[2]=0;
            return IGUALDAD;
        }
        ungetc(c,f);
        return IGUAL;
    }
    if(c=='!'){
        c=fgetc(f);
        if(c=='='){
            lexema[0]='!';lexema[1]='=';lexema[2]=0;
            return DIFERENCIA;
        }
        ungetc(c,f);
        return DIFERENCIA;
    }
}

int espalres(){
    if(strcmp(lexema,"while") == 0){
        return WHILE;
    }
    if(strcmp(lexema,"if")==0){
        return IF;
    }
    if(strcmp(lexema,"for")==0){
        return FOR;
    }
    return -1;
}

void mostrar(int token){
    switch (token)
    {
    case ID: printf("token = ID [%s] \n",lexema); break;
    case NUM: printf("token = NUM [%s] \n",lexema); break;
    case MAYORIGUAL: printf("token = MAYORIGUAL [%s]\n",lexema); break;
    case MENORIGUAL: printf("token = MENORIGUAL [%s]\n",lexema); break;
    case IGUALDAD: printf("token = IGUALDAD [%s]\n",lexema); break;
    case DIFERENCIA: printf("token = DIFERENCIA [%s]\n",lexema); break;
    case WHILE: printf("token = WHILE [%s] \n",lexema); break;
    case IF: printf("token = IF [%s] \n",lexema); break;
    case FOR: printf("token = FOR [%s] \n",lexema); break;
    case PARI: printf("token = PARI [%c] \n",token); break;
    case PARD: printf("token = PARD [%c] \n",token); break;
    case CORI: printf("token = CORI [%c] \n",token); break;
    case CORD: printf("token = CORD [%c] \n",token); break;
    case LLAI: printf("token = LLAI [%c] \n",token); break;
    case LLAD: printf("token = LLAD [%c] \n",token); break;
    case MAYOR: printf("token = MAYOR [%c] \n",token); break;
    case MENOR: printf("token = MENOR [%c]\n",token); break;
    case IGUAL: printf("token = IGUAL [%c]\n",token); break;
    case COMA: printf("token = COMA [%c]\n",token); break;
    case PUNTOYCOMA: printf("token = PUNTOYCOMA [%c]\n",token); break;
    case SUMA: printf("token = SUMA [%c]\n",token); break;
    case RESTA: printf("token = RESTA [%c]\n",token); break;
    case MULTIPLICACION: printf("token = MULTIPLICACION [%c]\n",token); break;
    case DIVISION: printf("token = DIVISION [%c]\n",token); break;
    }
}


