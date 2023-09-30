#include <bits/stdc++.h>
using namespace std;
#define print(a)for(auto c:a)cout<<c<<" ";cout<<endl;
int main(){
    int n,cont = 1;
    string type;
    cin>>n>>type;
    vector<int> original(n);
    vector<int> copy(n);
    for(int i = 0;i<n;i++)original[i] = i+1;
    if(type =="out"){
        int l = 0,r = 0;
        for(int i = 0;i<n;i++)!(i&1)? copy[i] = (l++)+1: copy[i] = (r++)+(n-(n/2))+1;
        vector<int> aux = copy;
        while(copy != original){
            l = r = 0;
            for(int i = 0;i<n;i++)!(i&1)? copy[i] = aux[(l++)]: copy[i] = aux[(r++)+(n-(n/2))];
            aux = copy;
            cont++;
        }
    }
    else{
        int l = 0,r = 0;
        for(int i = 0;i<n;i++)i&1? copy[i] = (l++)+1: copy[i] = (r++)+(n/2)+1;
        vector<int> aux = copy;
        while(copy != original){
            l = r = 0;
            for(int i = 0;i<n;i++)i&1? copy[i] = aux[(l++)]: copy[i] = aux[(r++)+(n/2)];
            aux = copy;
            cont++;
        }
    }
    cout<<cont<<endl;
    return 0;
}