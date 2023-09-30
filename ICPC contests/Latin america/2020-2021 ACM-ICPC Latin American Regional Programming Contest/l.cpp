#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
	int t= 1,n,x,s,d;
    cin>>n>>x;
    vector<int> activity(300000);
    for(int i = 0;i<n;i++){
        cin>>s>>d;
        activity[s]++;
        activity[s+d+1]--;
    }
    for(int i = 1;i<200007;i++)
        activity[i] = activity[i]+activity[i-1];
    int mn = 300007,best = 0;
    for(int i = 0;i<=8*60;i++){
        int problems = 0;
        for(int j = 0;i+(j*x)<=200007;j++){
            if(activity[i+(j*x)])problems++;
        }
        if(problems<mn)
            mn = min(problems,mn),best = i;
    }
    cout<<best<<" "<<mn<<endl;
    return 0;
}  
