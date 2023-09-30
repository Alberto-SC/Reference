#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);


int main(){__
	int n;
    cin>>n;
    list<lli> nums;
    vector<lli> a(n);
    for(int i = 0;i<n;i++){
        lli x;cin>>x;
        nums.push_back(x);
        a[i] = x;
    }
    if(n == 1)return cout<<a[0]<<endl,0;
    list<lli> sum;
    sum.push_back(a[1]+a[n-1]);
    for(int i = 1;i<n;i++){
            sum.push_back(a[(i+1)%n]+a[i-1]);
    }
    int x = -1,idx = 0;
    int cont = 0;
    for(auto c:sum){
        if(c>x){
            x = c;
            idx = cont;
        }
        cont++;
    }
    cout<<endl;
    auto it = sum.begin();
    auto itn = nums.begin();
    for(int i = 0;i<idx;i++)it++,itn++;
    while(sum.size()>3){
        // cout<<"MAX "<<*it<<endl;
        auto it1 = it;
        auto it1n = itn;
        auto it2 = it;
        auto it2n = itn;
        it1++;
        it1n++;
        it2--;
        it2n--;
        if(it1 == sum.end())it1++;
        if(it1n == nums.end())it1n++;
        if(it2 == sum.end())it2--;
        if(it2n == nums.end())it2n--;
        it1 = sum.erase(it1);
        it2 = sum.erase(it2);
        it2--;
        if(it2 == sum.end())it2--;
        if(it1 == sum.end())it1++;
        
        // it1++;
        // it2--;
        // if(it1 == sum.end())it1++;
        // if(it2 == sum.end())it2--;
        // if(it1 == it2)break;
        // cout<<*it2n<<" "<<*it1n<<endl;
        // cout<<*it2<<" "<<*it1<<endl;
        *it2 = *it2-*it2n + *it;
        *it1 = *it1-*it1n + *it;
        // cout<<*it2<<" "<<*it1<<endl;
        it1n = nums.erase(it1n);
        it2n = nums.erase(it2n);
        it2n--;
        if(it2n == nums.end())it2n--;
        if(it1n == nums.end())it1n++;
        *itn = *it;
        *it = *it+ *it1n+ *it2n;
        if(*it1>*it2)it = it1,itn = it1n;
        else it = it2,itn = it2n;
        // break;
        // cout<<"LIST"<<endl;
        // for(auto c:sum)cout<<c<<" ";
        // cout<<endl;
        // cout<<"NUMS"<<endl;
        // for(auto c:nums)cout<<c<<" ";
        // cout<<endl;
    }
    lli mx = -1;
    for(auto c:sum){
        mx = max(mx,c);
    }
    cout<<mx<<endl;
    return 0;
}  