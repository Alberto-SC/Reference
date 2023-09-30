#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);

signed main(){
    int n;
    cin>>n;
    string WO,WD,BO,BD,s;
    int woid = -4, wdid =-2,boid = -3,bdid = -1;
    queue<string> q;
    cin>>WO>>BO>>WD>>BD;
    for(int i = 0;i<n-4;i++){
        cin>>s;
        q.push(s);
    }
    string game; 
    cin>>game;
    int N = game.size();
    int cont = 1,mx = 0;
    for(int i = 1;i<N;i++){
        if(game[i]!=game[i-1])cont = 1;
        else cont++;
        mx = max(mx,cont);
    }
    
    for(int i = 0;i<N;i++){
        
        if(game[i]!=game[i-1])cont = 1;
        else cont++;
        mx = max(mx,cont);
        if(game[i]=='W'){
            swap(WO,WD);
            swap(woid,wdid);
            q.push(BD);
            BD = BO;
            bdid = boid;
            boid = i;
            BO = q.front();
            q.pop();
        }
        else{
            swap(BO,BD);
            swap(boid,bdid);
            q.push(WD);
            WD = WO;
            wdid = woid;
            woid = i;
            WO = q.front();
            q.pop();
        }
        if(cont ==mx){
            if(game[i]== 'W'){
                if(woid<wdid)
                    cout<<WO<<" "<<WD<<endl;
                else
                    cout<<WD<<" "<<WO<<endl;
            }
            else{
                if(boid<bdid)
                    cout<<BO<<" "<<BD<<endl;
                else 
                    cout<<BD<<" "<<BO<<endl;
            }
        }
    }
    return 0;
}