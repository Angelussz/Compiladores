#include <iostream>
using namespace std;
int main(){
    char ins[50];
    int i=0;
    cout<<"Introducir instruccion"<<endl;

    cin.getline(ins,50);
    for(int i=0;ins[i]!='\0';i++){
        cout<<ins[i]<<endl;
    }
}