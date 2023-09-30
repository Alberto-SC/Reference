#include <bits/stdc++.h>
using namespace std;
int getpow(int lim){
    int x = 0;
    while(1<<x<=lim){x++;}
    return x;
}
int main(){
    int sum,lim;
    cin>>sum>>lim;
    int pw = getpow(lim);
    pw--;
    int aux = pw,left,rigth;
    set<int> s;
    while(sum>0 && aux>=0){
        left = pw-aux,rigth = pw+1-(pw-aux);
        for(int i = 0;i<pow(2,left);i++)
            if((sum-pow(2,aux))>=0 && (i<<rigth)+pow(2,aux)<=lim)sum-=pow(2,aux),s.insert((i<<rigth)+pow(2,aux));
        aux--;
    }
    if(sum>0)return cout<<-1<<endl,0;
    cout<<s.size()<<endl;
    for(auto c:s)cout<<c<<" ";
    return cout<<endl,0;
}