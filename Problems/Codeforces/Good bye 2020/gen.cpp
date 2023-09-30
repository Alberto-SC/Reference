#include <bits/stdc++.h>
using namespace std;
#define accuracy chrono::steady_clock::now().time_since_epoch().count()
mt19937 rng(accuracy);
int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}
int main(){
    int t = rand(1,10);
    cout<<t<<endl;
    while(t--){
        int n = rand(1,10);
        for(int i = 0;i<n;i++){
            cout<<char(rand(0,25)+'a');
        }
        cout<<endl;
    }
    return 0;
}