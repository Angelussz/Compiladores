#include<iostream>
using namespace std;

bool Numero(char& num){
    return (num>= '0' && num<= '9');
}
bool Negativo(char& menos){
    return (menos== '-');
}
bool Signo(char& punto){
    return (punto== '.');
}

int Estados(string numero){
    int estado=1;
    char leer = numero[0];
    int cont=0;
    while (leer)
    {
        switch (estado)
        {
        case 1:
            if (Numero(leer))
            {
                estado = 2;
            }
            else if(Signo(leer)){
                estado = 3;
            }
            else if(Negativo(leer)){
                estado =  4;
            }
            else
            {
                cout<<"1SALIR A RUTINA DE ERROR"<<endl;
                return 1;
            }
            break;
        case 2:
            if (Numero(leer))
            {
                estado = 2;
            }
            else if(Signo(leer)){
                estado = 3;
            }
            else if(Negativo(leer)){
                cout<<"2.1SALIR A RUTINA DE ERROR"<<endl;
                return 1;
            }
            else{
                cout<<"2.2SALIR A RUTINA DE ERROR"<<endl; 
                return 1; 
            }
            break;
        case 3:
            if (Numero(leer))
            {
                estado = 3;
            }
            else if(Signo(leer)){
                cout<<"3.11SALIR A RUTINA DE ERROR"<<endl;
                return 1;
            }
            else if(Negativo(leer)){
                cout<<"3.2SALIR A RUTINA DE ERROR"<<endl;
                return 1;
            }
            else{
                cout<<"3.3SALIR A RUTINA DE ERROR"<<endl; 
                return 1; 
            }
            break;
            case 4:
            if (Numero(leer))
            {
                estado = 4;
            }
            else if(Signo(leer)){
                estado = 3;
            }
            else if(Negativo(leer)){
                cout<<"4.1SALIR A RUTINA DE ERROR"<<endl;
                return 1;
            }
            else{
                cout<<"4.2SALIR A RUTINA DE ERROR"<<endl; 
                return 1; 
            }
            break;
        }
        
        cont++;
        leer = numero[cont];
    }
    if ( estado == 2 || estado == 3 || estado == 4){
            cout<<"ACEPTADO"<<endl;
        }
    return 1;
}

int main(){
    string palabra;
    cout<<"Numero: ";
    cin>>palabra;
    Estados(palabra);
    return 0;
}