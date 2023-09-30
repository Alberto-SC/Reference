#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

// Paradigma: Divide y vencerás

int sumaMaximaCruzada(int A[], int izquierda, int mitad, int n){ 
  // Elementos: Izquierda -> Mitad 
  int suma=0, izq_suma=0; 
  for(int i=mitad; i>=izquierda; i--){ 
    suma+=A[i]; 
    if(suma>izq_suma){
      izq_suma=suma;
    } 
  } 
  
  // Elementos: Mitad -> Derecha 
  int der_suma=0;
  suma=0;
  for(int i=mitad+1; i<=n; i++){ 
    suma+=A[i]; 
    if(suma>der_suma){
      der_suma=suma;
    } 
  } 

  return max({izq_suma+der_suma, izq_suma, der_suma}); 
}

int sumaMaximaSubarreglo(int A[], int izquierda, int n){ 
  // Caso base: 1 elemento 
  if(izquierda==n){
    return A[izquierda];
  }

  int mitad=(izquierda+n)>>1; 

  return max({
    // Suma máxima de izquierda -> mitad
    sumaMaximaSubarreglo(A, izquierda, mitad), 
    // Suma máxima de mitad -> derecha
    sumaMaximaSubarreglo(A, mitad+1, n), 
    // Suma máxima de cruza por la mitad
    sumaMaximaCruzada(A, izquierda, mitad, n)
  }); 
} 
  
int main(){ 
  int n=0; cin >> n;
  int A[n];
  
  for(int i=0; i<n; i++){
    cin >> A[i]; 
  }

  int maxima_suma=sumaMaximaSubarreglo(A, 0, n-1); 
  cout << maxima_suma;
  
  return 0; 
} 