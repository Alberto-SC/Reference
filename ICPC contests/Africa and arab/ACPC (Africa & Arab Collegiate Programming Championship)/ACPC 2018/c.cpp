#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    freopen("coffee.in", "r", stdin);  
	// freopen("output.txt", "w", stdout);
	int t= 1,n,c,p,s,m,l;
    string name;
    cin>>t;
    while(t--){
        cin>>c>>p;
        map<string,vector<int>> coffe; 
        for(int i = 0;i<c;i++){
            cin>>name>>s>>m>>l;
            vector<int> z = {s,m,l};
            coffe[name] = z;
        }
        string coff,sz;
        map<string,int> mp ;
        mp["small"] =0;
        mp["medium"] =1;
        mp["large"] =2;
        for(int i = 0;i<p;i++){
            cin>>name>>sz>>coff;
            int x = coffe[coff][mp[sz]];
            x+= 100/p;
            if(x%5 == 1)x--;
            if(x%5 == 4)x++;
            cout<<name<<" "<<x<<endl;
        }

    }
    return 0;
}  

