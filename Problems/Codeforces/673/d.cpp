#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
struct ans{
    int i,j,x;
};
vector<int> nums;
vector<ans> A;
void add(int i,int j,int x){
    nums[i] -= i*x;
    nums[j] += i*x;
    A.push_back({i+1,j+1,x});
}
int main(){__
    int t = 1,n;
    cin>>t;
    while(t--){
        cin>>n;
        nums.resize(n);
        A.clear();
        int s = 0;
        for(auto &c:nums)cin>>c,s+=c;
        if(s%n){cout<<-1<<endl;continue;};
        for(int i = 1;i<n;i++){
            if(nums[i]%(i+1))
                add(0,i,(i+1)-(nums[i]%(i+1)));
            add(i,0,nums[i]/(i+1));
        }
        for(int i = 1;i<n;i++)
            add(1,i,s/n);

        cout<<A.size()<<endl;
        for(auto c:A){
            cout<<c.i<<" "<<c.j<<" "<<c.x<<endl;
        }
    }
    return 0;
}

