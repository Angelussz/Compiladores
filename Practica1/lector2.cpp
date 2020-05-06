#include <iostream>
#include <fstream>
using namespace std;

int main() {
   char cadena[128];

   ifstream fe("codigo.txt");

   while(!fe.eof()) {
      fe >> cadena;
      for(int i =0;cadena[i]!='\0';i++){
          cout<<cadena[i]<<endl;
      }
   }
fe.close();
   return 0;
}