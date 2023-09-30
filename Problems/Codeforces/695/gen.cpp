// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;
#define accuracy chrono::steady_clock::now().time_since_epoch().count()

mt19937 rng(accuracy);

int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}

int main(){
    int t,n;
    t = rand(1, 2);
    cout<<t<<endl;
    while(t--){
        n = rand(1,10);
        cout<<n<<endl;
        for(int i = 0;i<n;i++){
            int u = rand(1,10);
            cout<<u<<" ";
        }
        cout<<endl;
    }
}
    
