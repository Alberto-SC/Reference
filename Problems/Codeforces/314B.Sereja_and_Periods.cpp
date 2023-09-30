#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    int sa = a.size(),sb = b.size();
    vector<int> t(sb+1);
    for(int i = 0;i<sb;i++){
        int k = i;
        for(int j = 0;j<sa;j++){
            if(a[j]== b[k%sb])k++;
        }
        t[i] = k;
    }
    int how = 0,idx = 0;
    while(n--){
        idx = t[idx];
        how+= idx/sb;
        idx%=sb;
    }
    cout<<how/m<<endl;
    return 0;
} 