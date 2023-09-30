#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
	int t= 1,n;
    cin>>t;
    string num = "123456789";
    vector<int> pos(51,1e9);
    do {
        int sum = 0;
        for(int i = 0;i<9;i++){
            sum+= num[i]-'0';
            pos[sum] =min(pos[sum],stoi(num.substr(0,i+1)));
        }
    }while(next_permutation(num.begin(),num.end()));
    while(t--){
        cin>>n;
        if(pos[n]==1e9)cout<<-1<<endl;
        else
            cout<<pos[n]<<endl;
    }
    return 0;
}  

