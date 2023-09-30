#include <bits/stdc++.h>
using namespace std;

int main(){
  int n=0; cin >> n;
  string cant; cin >> cant;
  int days=0;
  cant = cant.substr(1);
  cant = cant.substr(cant.find('.')+1);
  int saldo = stoi(cant);
  for(int i=1; i<n+1; i++){
    string aux; cin >> aux;
    int dep;
    aux = aux.substr(aux.find('.')+1);
    dep = stoi(aux);
    saldo+=dep;
    if(saldo%100)
        days++;
  }

  cout << days << "\n";
  return 0;
}