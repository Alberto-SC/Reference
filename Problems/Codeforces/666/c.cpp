#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
int main(){__
    lli n;
    cin>>n;
    vector<lli> nums(n);
    for(auto &c:nums)cin>>c;
    if(n ==1){
        cout<<"1 1"<<endl;
        cout<<0<<endl;
        cout<<"1 1"<<endl;
        cout<<0<<endl;
        cout<<"1 1"<<endl;
        cout<<-nums[0]<<endl;
        return 0;
    }
    cout<<"1 1"<<endl;
    cout<<n-(MOD(nums[0],n))<<endl;
    nums[0]+= n-(MOD(nums[0],n));
    cout<<"2 "<<n<<endl;
    for(lli i = 1;i<n;i++){
        if(nums[i]%n == 0)cout<<0<<" ";
        else {
            lli x = n-(MOD(nums[i],n));
            lli y = (n-1)*(n-x);
            cout<<y<<" ";
            nums[i]+=y;
        }
    }
    cout<<endl;
    cout<<"1 "<<n<<endl;
    for(lli i = 0;i<n;i++)
        cout<<-nums[i]<<" ";
    
    return 0;
}

