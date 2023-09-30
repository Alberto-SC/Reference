#include <bits/stdc++.h>
using namespace std;
typedef long long ld;
bool cmp(ld a,ld b){
    return a>b;
}
int main(){
    ld n,in;
    vector<ld> nadie;
    vector<ld> A;
    vector<ld> B;
    vector<ld> ambos;
    string a;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a>>in;
        if(a == "00")nadie.push_back(in);
        if(a == "10")A.push_back(in);
        if(a == "01")B.push_back(in);
        if(a == "11")ambos.push_back(in);
    }
    if(A.size()>0)
        sort(A.begin(),A.end(),cmp);
    if(B.size()>0)
        sort(B.begin(),B.end(),cmp);
    ld maxi = 0;
    ld nn = ambos.size(),size;
    size = min(A.size(),B.size());
    for(int i = 0;i<ambos.size();i++)
        maxi += ambos[i];

    for(int i = 0;i<size;i++)
        maxi += A[i]+B[i];
    if(A.size()<=B.size()){
        for(int i = size;i<B.size();i++)
            nadie.push_back(B[i]);
    }
    else{
        for(int i = size;i<A.size();i++)
            nadie.push_back(A[i]);
    } 
    if(nadie.size()>0)
        sort(nadie.begin(),nadie.end(),cmp);
    for(int i = 0;i<nadie.size()&& nn;i++){
        maxi+= nadie[i];
        nn--;
    }
    cout<<maxi<<endl;
    return 0;
}