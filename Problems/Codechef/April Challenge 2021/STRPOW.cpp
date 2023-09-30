#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int ans = 0;
int n;
const int maxn = 1000;
vector<vector<int>> occ(maxn);
vector<int> p(maxn);
void generate_all(int idx,int k,int power = 0,int p = 0){
    if(k == 0|| idx ==n){ 

    }
}


signed main(){__
	int t= 1,k;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0;i<n;i++){
        cin>>a[i]>>p[i]>>b[i]; 
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=15;j++){
            if(j){
                if(j&1 && b[i])
                    occ[i].push_back(j);
                if(j%2==0 &&!b[i])
                    occ[i].push_back(j);
            }
            else 
                occ[i].push_back(0);
        }
    }
    for(int i = 0;i<n;i++){
        for(auto c:occ[i])cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}  
