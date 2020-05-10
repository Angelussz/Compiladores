#include<iostream>
using namespace std;
bool Letra(char& letra){
    return ((letra>= 'a' && letra<= 'z') || (letra>= 'A' && letra <= 'Z'));
}
bool Numero(char& num){
    return (num>= '0' && num<= '9');
}

int main(){
    string palabra;
    cout<<"Palabra: ";
    cin>>palabra;
    int estado=1;
    char leer = palabra[0];
    int cont=0;
    while (leer)
    {
        switch (estado)
        {
        case 1:
            if (Letra(leer))
            {
                estado = 3;
            }
            else if(Numero(leer)){
                estado = 2;
            }
            else
            {
                cout<<"1SALIR A RUTINA DE ERROR"<<endl;
                return 1;
            }
            break;
        case 2:
            cout<<"2SALIR A RUTINA DE ERROR"<<endl;
            return 1;
            break;
        case 3:
            if(Numero(leer)){
                estado = 3;
            } 
            else if(Letra(leer)){
                estado = 3;
            }
            else{
                cout<<"3SALIR A RUTINA DE ERROR"<<endl;
                return 1;
            }
            break;
        }
        cont++;
        leer = palabra[cont];
    }
    if (estado != 3){
        cout<<"SALIR A RUTINA DE ERROR"<<endl;
    }
    else{
        cout<<"identificador aceptado"<<endl;
    }

    
    return 0;
}