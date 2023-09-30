#include <bits/stdc++.h>
using namespace std;
const int maxn = 120;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
int main(){
    int n,k1,k2,x,m1i = 0,m2i = 0; 
    list<int> a,b;
    cin>>n;
    cin>>k1;
    map<list<int>,int> m1;
    map<pair<int,int>,int> m2;
    for(int i = 0;i<k1;i++){
        cin>>x;
        a.push_back(x);
    }
    cin>>k2;
    for(int i = 0;i<k2;i++){
        cin>>x;
        b.push_back(x);
    }
    m1[a] = m1i++;
    m1[b] = m1i++;
    pair<int,int> g = {m1[a],m1[b]};
    m2[g] = m2i++;

    int games = 0,last = m2[g],win;
    while(true){
        int topa = a.front(),topb = b.front();
        a.pop_front();
        b.pop_front();
        if(topa> topb){
            a.push_back(topb);
            a.push_back(topa);
        }
        else{
            b.push_back(topa);
            b.push_back(topb);
        }
        if(m1.find(a)==m1.end())m1[a] =m1i++;
        if(m1.find(b)==m1.end())m1[b] =m1i++;
        g = {m1[a],m1[b]};
        if(m2.find(g)== m2.end())m2[g] =m2i++;
        else return cout<<-1<<endl,0;
        games++;
        if(a.size() == 0){win=2;break;}
        if(b.size() == 0){win=1;break;}

    }  
    cout<<games<<" "<<win<<endl;
    return 0;
}