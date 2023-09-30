#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
	int t= 1,n,x12,x13,x23,a13,a23,a12;
    cin>>n;
    vector<int> nums;
    cout<<"XOR "<<1<<" "<<2<<endl;
    fflush(stdout);   
    cin>>x12;
    cout<<"XOR "<<1<<" "<<3<<endl;
    fflush(stdout);
    cin>>x13;
    cout<<"AND "<<1<<" "<<2<<endl;
    fflush(stdout);
    cin>>a12;
    cout<<"AND "<<1<<" "<<3<<endl;
    fflush(stdout);
    cin>>a13;
    cout<<"AND "<<2<<" "<<3<<endl;
    fflush(stdout);
    cin>>a23;
    x23 =x12^x13;
    int real1 = 0;
    map<vector<int>,int> mp;
    mp[{1,0,1,0}] = 0;
    mp[{0,1,0,1}] = 1;
    mp[{0,1,0,0}] = 0;
    mp[{0,0,1,0}] = 1;
    {
        for(int i = 0;i<30;i++){
            if((a12>>i)&1)real1|=(1<<i);
            else {
                if((x12>>i)&1){
                    cout<<"Hi "<<i<<endl;
                    vector<int> z;
                    z.push_back((a13>>i)&1);
                    z.push_back((x13>>i)&1);
                    z.push_back((x23>>i)&1);
                    z.push_back((a23>>i)&1);
                    for(auto c:z)cout<<c<<" ";
                        cout<<endl;
                    if(mp[z])
                        real1|=(1<<i);
                }
            }
        }
    }
    cout<<real1<<" "<<x13<<" "<<x23<<endl;
    nums.push_back(real1);
    nums.push_back(x12^real1);
    nums.push_back(x13^real1);
    for(int i = 4;i<=n;i++){
        int x;
        cout<<"XOR " <<1<<" "<<i<<endl;
        fflush(stdout);
        cin>>x;
        nums.push_back(x^real1);
    }
    cout<<"! ";
    for(auto c:nums)cout<<c<<" ";
    cout<<endl;
    return 0;
}  

