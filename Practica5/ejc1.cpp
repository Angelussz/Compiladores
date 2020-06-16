#include <bits/stdc++.h>
using namespace std;
#define MAS '+'
#define MENOS '-'
#define MUL '*'
#define DIV '/'
#define NUM 256
#define PARI '('
#define PARD ')'
#define FIN -1
#define PTCOMA ';'
char lexema[80];
int tok;
FILE *f;
stack<char> pila;
vector<string> posf; 
vector<string> resultado;

void error();
int scaner();
void mostrar();
int precedencia(char a, char b);
void eval(int tok);
void operar();
int main(int n,char *pal[]){
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
        tok =scaner();
        if(tok==EOF)break;
        eval(tok);
    }
    if(f != stdin)
       fclose(f);
}

void eval(int tok){
    if (tok == NUM)
    {
        posf.push_back(lexema);
        
    }
    else if(tok == PTCOMA){
        string tras;
        while (!pila.empty())
                    {
                        string con;
                        con.push_back(pila.top());
                        posf.push_back(con);
                        pila.pop();
                    }
        mostrar();
        operar();
        posf.clear();
        resultado.clear();              
    }
    else{
        if (pila.empty() && tok == PARD)
        {
            pila.push(tok);
            pila.pop();
        }
        else
        {
            if (pila.empty())
        {   
            
            pila.push(tok);
        }
        else
        {
            if (tok == MAS || tok == MENOS )
            {
                int aux = pila.top();
                if (aux == PARI)
                {
                    pila.push(tok);
                }
                if (aux != PARI && precedencia(tok,aux) == 0)
                {
                    string con;
                    con.push_back(pila.top());
                    posf.push_back(con);
                    pila.pop();
                    pila.push(tok);
                }
                else if(aux != PARI && precedencia(tok,aux) < 0){
                    while (!pila.empty())
                    {
                        string con;
                        con.push_back(pila.top());
                        posf.push_back(con);
                        pila.pop();
                    }
                    pila.push(tok);
                    
                }
                /*else
                {
                    cout<<"erroruma"<<endl;
                }*/
                
                
            }
            else if(tok == PARI){
                pila.push(PARI);
            }
            else if(tok == MUL || tok == DIV){
                int aux = pila.top();
                if (aux == PARI)
                {
                    pila.push(tok);
                }
                if (aux != PARI && precedencia(tok,aux) == 0)
                {
                    string con;
                    con.push_back(pila.top());
                    posf.push_back(con);
                    pila.pop();
                    pila.push(tok);
                }
                else if(aux != PARI && precedencia(tok,aux) > 0){
                    pila.push(tok);
                }
                /*else
                {
                    cout<<"erormult";
                }*/
            }
            else if(tok == PARD){
                while (!pila.empty())
                    {
                        if (pila.top() == PARI)
                        {
                            pila.pop();
                        }
                        else
                        {
                            string con;
                        con.push_back(pila.top());
                        posf.push_back(con);
                        pila.pop();
                        }
                    }
            }
        }   
        }
        
        
    }
}
int precedencia(char a, char b){
    int prec1,prec2;
    switch (a)
    {
    case MAS:
        prec1 = 1;
        break;
    case MENOS:
        prec1 = 1;
        break;
    case MUL:
        prec1 = 2;
        break;
    case DIV:
        prec1 = 2;
        break;
    default:
        break;
    }
    switch (b)
    {
    case MAS:
        prec2 = 1;
        break;
    case MENOS:
        prec2 = 1;
        break;
    case MUL:
        prec2 = 2;
        break;
    case DIV:
        prec2 = 2;
        break;
    default:
        break;
    }
    cout<<"p1:"<<prec1<<endl;
    cout<<"p2:"<<prec2<<endl;
    return prec1-prec2;
}
int scaner(){
    int c,i;
    do
    {
        c=fgetc(f);
    } while (isspace(c));
    if(c==EOF) return EOF;
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
    if (c == MAS || c == MENOS || c == PARD || c == PARI || c == MUL || c== DIV || c ==PTCOMA)
    {
        return c;
    }

}

void error(){
    cout<<"sintaxis erronea"<<endl;
}

void mostrar(){
    int i;
    for (i = 0; i < posf.size(); i++)
    {
        cout<<posf[i];
    }
    
}
 // OPERACIONES
 void operar(){
     for (auto &&i : posf)
    {
        if(i == "+")
        {
            int a = stoi(resultado.back());
            resultado.pop_back();
            int b = stoi(resultado.back());
            resultado.pop_back();
            resultado.push_back(to_string(a+b));
        }
        else if(i == "-")
        {
            int a = stoi(resultado.back());
            resultado.pop_back();
            int b = stoi(resultado.back());
            resultado.pop_back();
            resultado.push_back(to_string(b-a));
        }
        else if(i == "*")
        {
            int a = stoi(resultado.back());
            resultado.pop_back();
            int b = stoi(resultado.back());
            resultado.pop_back();
            resultado.push_back(to_string(a*b));
        }
        else if(i == "/")
        {
            int a = stoi(resultado.back());
            resultado.pop_back();
            int b = stoi(resultado.back());
            resultado.pop_back();
            resultado.push_back(to_string(b/a));
        }
        else
            resultado.push_back(i);
    }
    cout<<"resultado: "<<resultado[0]<<endl;
 }