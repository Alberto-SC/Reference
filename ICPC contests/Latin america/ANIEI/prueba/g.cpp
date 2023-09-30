 #include <iostream>
using namespace std;
int main(void){
int C,A;
cin >> C >> A; // lee la entrada
int quociente = A/(C-1);
int resto = A%(C-1);
int resposta = quociente;
if ( resto > 0 ) resposta++;
cout << resposta << endl; // imprime la respuesta
return 0;
} 
