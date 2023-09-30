#include <bits/stdc++.h>

using namespace std;

vector< vector < int > > adys(100005);
int alcance[100005];
int orden[100002];
int oren = 0;
priority_queue<int> cola;
int N, K;


void defesea(int nodo, int puedo){
    if(puedo > alcance[nodo]){ //Mi alcance supera al del vato
        if(alcance[nodo] == 0){ //el vato no habia sido visitado
            cola.push(-nodo); //entonces lo meto a la pqueue
        }
        alcance[nodo] = puedo; //le doy mi poder al vato
		
        int tama = adys[nodo].size();
        int i, nuevo;
        for(i=0; i<tama; i++){
            nuevo = adys[nodo][i];
            defesea(nuevo, puedo-1); //ahora le toca a 
        }
    }
}


void busca(){ // la pqueue
    int actual;
    defesea(1,K+1); //tiro dfs en el primer nodo
    while(!cola.empty()){
        actual = cola.top();
        actual = -actual;
        cola.pop();
        orden[oren] = actual;
        oren++;
        defesea(actual, K+1);
    }
	
	//Impresion de la respuesta
    int i;
    for(i=0; i<N-1; i++){
        cout << orden[i] << " ";
    }
    cout << orden[i] << '\n';
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    int i;
    int u,v;
    for(i=1; i<N; i++){
        cin >> u >> v;
        adys[u].push_back(v);
        adys[v].push_back(u);
    }
    busca();


    return 0;
}