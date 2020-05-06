//Cifrado Cesar
#include <iostream>
#include <fstream>
using namespace std;
void cifrar(string nombre,string cifrar,char cadena[]){
    
    ifstream entrada(nombre);
    ofstream salida;
    salida.open(cifrar);
    int palabra;
    int posicion=1;
    while(!entrada.eof()) {
      entrada.getline(cadena,200);
      
      for(int i =0;cadena[i]!='\0';i++){
          
          palabra = (int)cadena[i];
        
          if(palabra>64 && palabra<91){
              palabra = palabra + 3;
              if(palabra>90){
                  palabra = palabra-90;
                  palabra = 64+palabra;
              }
              cadena[i] = static_cast<char>(palabra);

          }
          else if(palabra>96 && palabra<123){
              palabra = palabra + 3;
              if(palabra>122){
                  palabra = palabra-122;
                  palabra = 96+palabra;
              }
              cadena[i] = static_cast<char>(palabra);
          }
      }
      salida<<cadena<<endl;
      

   }
   entrada.close();
   salida.close();
}
void descifrar(string cifrado,string descifrar,char cadena[]){
    ifstream entrada(cifrado);
    ofstream salida;
    salida.open(descifrar);
    int palabra;
    int posicion=1;
    while(!entrada.eof()) {
      entrada.getline(cadena,200);
      
      for(int i =0;cadena[i]!='\0';i++){
          
          palabra = (int)cadena[i];
        
          if(palabra>64 && palabra<91){
              palabra = palabra - 3;
              if(palabra<65){
                  palabra = 65-palabra;
                  palabra = 91-palabra;
              }
              cadena[i] = static_cast<char>(palabra);

          }
          else if(palabra>96 && palabra<123){
              palabra = palabra - 3;
              if(palabra<97){
                  palabra = 97-palabra;
                  palabra = 123-palabra;
              }
              cadena[i] = static_cast<char>(palabra);
          }
      }
      salida<<cadena<<endl;
      

   }
   entrada.close();
   salida.close();

}
int main() {
   char cadena[200];
   
   string nombre = "codigo1.txt";
   string cifrado = "cifrado.txt";
   string descifrado = "descifrado.txt";
   cifrar(nombre,cifrado,cadena);
   descifrar(cifrado,descifrado,cadena);
   return 0;
}