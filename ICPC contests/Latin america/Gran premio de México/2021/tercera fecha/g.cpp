#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n;
    while(t--){
        cin>>n;    
        int fib1 =  2,fib2 = 3;
        vector<int> _all;
        _all.push_back(2);
        _all.push_back(3);
        for(int i = 0;i<72;i++){
            _all.push_back(fib1+fib2);
            fib1 = fib2;
            fib2 = _all.back();
        }
        vector<int> fibos;
        bool flag = true;
        while(n>1){
            int fibo = -1;
            int idx = lower_bound(_all.begin(),_all.end(),n)-_all.begin();
            if(idx<_all.size() && _all[idx]== n){
                fibos.push_back(n);
                break;
            }
            for(int i =_all.size()-1;i>=0;i--){
                if(_all[i]>n)continue;
                if(n%_all[i]==0){
                    fibo = _all[i];
                    break;
                }
            }
            if(fibo==-1){
                flag = false;
                break;
            }
            fibos.push_back(fibo);
            n/=fibo;
        }
        vector<int> blocks;
        for(auto c:fibos){
            int idx = lower_bound(_all.begin(),_all.end(),c)-_all.begin();
            blocks.push_back(idx+1);
        }
        if(!flag)return cout<<"IMPOSSIBLE"<<endl,0;
        sort(blocks.rbegin(),blocks.rend());
        for(int i = 0;i<blocks.size();i++){
            for(int j = 0;j<blocks[i];j++)
                cout<<'A';
            cout<<'B';
        }
        cout<<endl;
    }
    return 0;
}  
