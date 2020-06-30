#include <bits/stdc++.h>
using namespace std;
#define EST 256 //Estados
#define NUM 257

int scaner();
void evaluar(int token);
void conversion();
void evaluare(int num);
void evaluara(vector<int> &a);
void evaluarb(vector<int> &b);
void evaluare2(vector<int> &res,vector<int> &salida);
void evaluare1(vector<int> &cont ,int num);
FILE *f;
char lexema[80];
std::vector<int> vestados;
std::vector<int> vestacep;
std::vector<int> ventradas;

std::vector<int> conS;
std::vector<int> conSA;
std::vector<int> conSB;
std::vector<int> conA;
std::vector<int> conB;
ofstream conjunto("out.txt");

int trans[13][3];
int nest;
int token;
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
        token =scaner();
        if(token==EOF)break;
        evaluar(token);
        //mostrar(token);
    }

    if(f != stdin)
       fclose(f);
    
    conversion();
    conjunto.close();
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
        return EST;
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

}


void evaluar(int token){
    if (strcmp(lexema, "Estados") == 0)
    {
        printf("%s \n",lexema);
        token = scaner();
        nest = atoi(lexema);//numero de estados
        printf("%i \n",nest);
        for (int i = 0; i < nest; i++)
        {
            token = scaner();
            vestados.push_back(atoi(lexema));
        }
        for (int i = 0; i < nest; i++)
        {
            cout<<vestados[i]<<" ";
        }
        cout<<endl;
    }
    if (strcmp(lexema, "Estados_de_aceptacion") == 0)
    {
        printf("%s \n",lexema);
        token = scaner();
        nest = atoi(lexema); //numero estados aceptacion 
        printf("%i \n",nest);
        for (int i = 0; i < nest; i++)
        {
            token = scaner();
            vestacep.push_back(atoi(lexema));
        }
        cout<<vestacep.front();
        cout<<endl;
    }
    if (strcmp(lexema, "Entradas") == 0){
        printf("%s \n",lexema);
        token = scaner();
        nest = atoi(lexema); //numero de entradas
        printf("%i \n",nest);
        for (int i = 0; i < nest; i++)
        {
            token = scaner();
            ventradas.push_back(atoi(lexema));
        }
        for (int i = 0; i < nest; i++)
        {
            cout<<ventradas[i]<<" ";
        }
        cout<<endl;
        
    }
    if (strcmp(lexema, "Transiciones") == 0){//Epsilon = 2
        printf("%s \n",lexema);
        token = scaner();
        nest = atoi(lexema); //numero de entradas
        printf("%i \n",nest);
        for (int i = 0; i < nest; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                token = scaner();
                trans[i][j] = atoi(lexema);
            }
            
        }
        for (int i = 0; i < nest; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                
                cout<<trans[i][j]<< " ";
            }
            cout<<endl;
            
        }

    } 
    
}
/*
 for (int i = 0; i < a.size(); i++)
 {
     conS.push_back(a[i]);
 }
 
  for (int i = 0; i < conA.size(); i++)
  {
      evaluare(conA[i]);
  }
  
  
}

void evaluarb(vector<int> b){//evaluara los valores donde la transicion sea 1
    for (int i = 0; i < b.size(); i++)
  {
      for (int j = 0; j < 13; j++)
      {
          if (trans[j][0] == b[i] && trans[j][1] == 0 )
          {
              conB.push_back(trans[j][2]);
          }
          
      }
      
  }
for (int i = 0; i < b.size(); i++)
 {
     conS.push_back(b[i]);
 }
  for (int i = 0; i < conB.size(); i++)
  {
      evaluare(conB[i]);
  }

}
*/

void evaluare(int num){//evaluara los valores donde la transicion sea epsilon =  solo en la entrada = 0
    for (int i = 0; i < 13; i++)
    {
        if (trans[i][0] == num && trans[i][1] == 2)
        {
            conS.push_back(trans[i][2]);
            evaluare(trans[i][2]);
        }
        
    }
}
void evaluare1(vector<int> &cont ,int num){//evaluara los valores donde la transicion sea epsilon = 2
    for (int i = 0; i < 13; i++)
    {
        if (trans[i][0] == num && trans[i][1] == 2)
        {
            cont.push_back(trans[i][2]);
            evaluare1(cont,trans[i][2]);
        }
        
    }
}
void evaluare2(vector<int> &res,vector<int> &salida){
    
    for (int i = 0; i < res.size(); i++)
    {
        
        salida.push_back(res[i]);
        
        evaluare1(salida,res[i]);
        
    }
    
}

void evaluara(vector<int> &a){//evaluara los valores donde la transicion sea 0
  for (int i = 0; i < a.size(); i++)
  {
      for (int j = 0; j < 13; j++)
      {
          if (trans[j][0] == a[i] && trans[j][1] == 0 )
          {
              conA.push_back(trans[j][2]);
          }
          
      }
  }
  evaluare2(conA,conSA);//Problemas por esta parte
}

void evaluarb(vector<int> &b){//evaluara los valores donde la transicion sea 0
  for (int i = 0; i < b.size(); i++)
  {
      for (int j = 0; j < 13; j++)
      {
          if (trans[j][0] == b[i] && trans[j][1] == 1 )
          {
              conB.push_back(trans[j][2]);
          }
          
      }
  }
  evaluare2(conB,conSB);//Problemas por esta parte
}
void conversion(){
    int entrada = vestados.front();
    conS.push_back(entrada);
    evaluare(entrada);
    for (int i = 0; i < conS.size(); i++)
    {
        conjunto<<conS[i]<<" ";
    }
    conjunto<<endl;
    evaluara(conS);
    for (int i = 0; i < conSA.size(); i++)
    {
        conjunto<<conSA[i]<<" ";
    }
    conjunto<<endl;

    evaluarb(conS);
    for (int i = 0; i < conSB.size(); i++)
    {
        conjunto<<conSB[i]<<" ";
    }
    conjunto<<endl;
}