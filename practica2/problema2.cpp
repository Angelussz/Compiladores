#include <iostream>
using namespace std;

bool Letra(char& letra){
    return ((letra>= 'a' && letra<= 'z') || (letra>= 'A' && letra <= 'Z'));
}
bool Numero(char& num){
    return (num>= '0' && num<= '9');
}

int PorTabla(string palabra)
{
    int tabla[3][3] = {{2,3,-1},{-1,-1,-1},{3,3,0}};
    int estado = 1;
    int entrada;
    char leer;
    int cont = -1;
    do
    {
        cont++;
        leer = palabra[cont];
        if(Numero(leer)){
            entrada = 1;
        }
        else if(Letra(leer)){
            entrada = 2;
            
        }
        else if(!leer){
            entrada = 3;
        }
        else
        {
            cout << "1SALIR A RUTINA DE ERROR"<<endl;
            return 1;
        }
        estado = tabla[estado-1][entrada-1];
        if (estado == -1)
        {
            cout<<"2SALIR A RUTINA DE ERROR"<<endl;
            return 1;
        }
    } while (estado !=0);
    cout<<"ACEPTAR"<<endl;
    return 1;
        
}


int main ()
{
    string palabra;
    cout<<"Palabra: ";
    cin>>palabra;
    PorTabla(palabra);
    return 0;
}
