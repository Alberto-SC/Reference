#include "bits/stdc++.h"
using namespace std ;
#define int long long 
#define accuracy chrono::steady_clock::now().time_since_epoch().count()
mt19937 rng(accuracy);

int rand(int l, int r){
  uniform_int_distribution<int> ludo(l, r); return ludo(rng);
}

void sol(){
    int t = rand(1,10);
    cout<<t<<endl;
	while(t--){
        int n = rand(2,10);
        vector<int> perm(n);
		cout<<n<<endl;
        iota(perm.begin(),perm.end(),1);
        random_shuffle(perm.begin(),perm.end());
        bool flag = false;
        int mx =((3*n)/2)+30;
        while(mx--){
            char op;
            cin>>op;
            if(op == '?'){
                int type,i,j,x;
                cin>>type>>i>>j>>x;
                if(type==1){
                    cout<<max(min(x,perm[i-1]),min(x+1,perm[j-1]))<<endl;
                }
                else{
                    cout<<min(max(x,perm[i-1]),max(x+1,perm[j-1]))<<endl;
                }
            }
            else if(op=='!'){
                vector<int> res(n);
                for(int i = 0;i<n;i++){
                    cin>>res[i];
                }
                if(res ==perm)flag = true;
                else cout<<"WA"<<endl;
                break;
            }
        }
        if(flag)cout<<"AC"<<endl;
        else cout<<"TLE"<<endl;

	}
}

signed main(){
	sol();
}