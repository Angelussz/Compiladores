#include <bits/stdc++.h>
using namespace std;
int preanalisis;
void parea(int);
void Resto();
void Term();
void error();

void Exp(){
    if (preanalisis >= '0' && preanalisis <= '9'){
        Term();
        Resto();
    }
    else
    {
        error();
    }
    
}
void Term(){
    if (preanalisis == '0'){
        parea('0');

    }
    else if (preanalisis == '1'){
        parea('1');
    }
    else if (preanalisis == '2'){
        parea('2');
    }
    else if (preanalisis == '3'){
        parea('3');
    }
    else if (preanalisis == '4'){
        parea('4');
    }
    else if (preanalisis == '5'){
        parea('5');
    }
    else if (preanalisis == '6'){
        parea('6');
    }
    else if (preanalisis == '7'){
        parea('7');
    }
    else if (preanalisis == '8'){
        parea('8');
    }
    else if (preanalisis == '9'){
        parea('9');
    }
    else{
        error();
    }
}

void Resto(){
    if (preanalisis=='+')
    {
        parea('+'); 
        Term();
        Resto();
    }
    else if (preanalisis == '-'){
        parea('-');
        Term();
        Resto();
    }
    else if (preanalisis == '.'){
        cout<<endl;
        cout<<"Sintaxis correcta"<<endl;
    }
    else
    {
        error();
    }
    
}

void error()
{
    printf("Error de sintaxis");
}
void parea(int t){
    if (preanalisis==t){
        putchar(preanalisis);
        preanalisis=getchar();
    }
    else
    {
        error();
    }    
}

int main(){
    preanalisis=getchar();
    Exp();
    return 0;
}