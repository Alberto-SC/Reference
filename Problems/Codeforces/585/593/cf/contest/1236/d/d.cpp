#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int n,m;
vector<pair<int,int>> fm= {{+0,+1},{+1,+0},{+0,-1},{-1,+0}};
signed main(){__
    int k,x,y;
    cin>>n>>m>>k;
    pair<int,int> mn = {n,m};
    set<pair<int,int>>st;
    for(int i = 0;i<k;i++){
        cin>>x>>y;
        mn = min(mn,{x,y});
        st.insert({x,y});
    } 
    int dir = 0;
    int firstx = mn.first,firsty = mn.second;
    bool turn = true;
    cout<<endl;
    k--;
    while(k){
        cout<<mn.first<<" "<<mn.second<<" -> "; 
        pair<int,int> nxt = {mn.first+fm[dir].first,mn.second+fm[dir].second};
        cout<<nxt.first<<" "<<nxt.second<<endl; 
        if(st.count(nxt)==0){
            cout<<"need turn"<<endl;
            if(turn)break;
            if((dir == 0 || dir == 1) && (mn.second<(m-firsty)|| mn.first<(n-firstx))){
                break;
            }
            if((dir == 2 || dir == 3) && (m-firsty != mn.second || n-firstx != mn.first+1)){
                break;
            }
            dir++; 
            dir%=4;  
            turn = true;
            firstx = mn.first;
            firsty = mn.second;
        }
        
        else{
            turn = false;
            mn = nxt;
            k--;
        }

    }
    if(k)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}  
