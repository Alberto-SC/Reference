#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


bool check(int n){
    vector<int> divs;
    for(int i = 2;i*i<=n;i++){
        if(n%i == 0){
            if(i&1)
            divs.push_back(i);
            if(n/i != i && (n/i)&1)divs.push_back(n/i);
        }
    }
    if(divs.size())return true;
    return false;
}


int main(){__
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        if(n==1)cout<<"FastestFinger"<<endl;
        else if(n&1|| n== 2)cout<<"Ashishgup"<<endl;
        else {
            vector<int> divs;
            for(int i = 2;i*i<=n;i++){
                if(n%i == 0){
                    if(i&1)
                        divs.push_back(i);
                    if(n/i != i && (n/i)&1)divs.push_back(n/i);
                }
            }
            if(divs.size()== 0)cout<<"FastestFinger"<<endl;
            else{
                bool flag = false;
                for(auto c:divs){
                    if(!check(n/c) && n/c!= 2) flag = true;               
                }
                if(flag)cout<<"Ashishgup"<<endl;
                else cout<<"FastestFinger"<<endl;
            }
        }
    }
    return 0;
}

