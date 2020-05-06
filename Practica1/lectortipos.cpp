#include <iostream>
#include <fstream>
using namespace std;

int main() {
   char cadena[200];
   char cadena2[200];
   ifstream entrada("texto.txt");

   while(!entrada.eof()) {
      entrada>>cadena;
      bool palabra=false;
      bool numero=false;
      bool caracter=false;
      if(((int)cadena[0] >64 && (int)cadena[0] <91) || ((int)cadena[0] >96 && (int)cadena[0] <123)){

               palabra = true;
               for(int i=1;cadena[i] = '\0';i++){
                  if(((int)cadena[i] <65 || ((int)cadena[i]>90 && cadena[i]<97)) ||((int)cadena[i] > 122) ){
                     palabra = false;
                     break;
                  }
               }  
         }
      else if((int)cadena[0] >47 && (int)cadena[0] <58){

               numero= true;  
               for(int i=1;cadena[i] = '\0';i++){
                  if((int)cadena[i]<48 || (int)cadena[i]>57){
                     numero = false;
                     break;
                  }
               }   
         }
      else if(((int)cadena[0] >32 && (int)cadena[0] <48) || ((int)cadena[0] >57 && (int)cadena[0] <65) || ((int)cadena[0]>90 && (int)cadena[0]<97) || ((int)cadena[0]>122 && (int)cadena[0]<=126)){
               
               caracter = true;
               if(cadena[1] != '\0'){
                  caracter = false;
               }
      }
      else
      {
          cout<<"fuera de parametros"<<endl;
      }
      


      if(palabra == true){
         cout<<"es una palabra"<<endl;
      }
      else if(numero == true){
         cout<<"es un numero"<<endl;
      }
      else if(caracter == true){
         cout<<"es un caracter"<<endl;
      }
      else{
         cout<< "no es nada o es combinacion de palabras,numeros y/o caracteres"<<endl;
      }
      
   }
   entrada.close();

   return 0;
}