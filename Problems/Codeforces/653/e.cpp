#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    lli t,n,k,a,b;
    cin>>n>>k;
    multiset<lli> two,alice,bob;
    for(lli i = 0;i<n;i++){
        cin>>t>>a>>b;
        if(a == b && a == 1)two.insert(t);
        else if(a == 1)alice.insert(t);
        else if(b == 1)bob.insert(t);
    }
    lli ans = 0;
    int t1 = k,t2 = k;
    while(t1>0 && t2>0){
        if(two.size() && bob.size() && alice.size()){
            lli x = *two.begin(),y = *bob.begin(),z = *alice.begin();
            if(x< y+z){
                two.erase(two.begin());
                ans+=x;
            }
            else {
                ans+=y+z;
                bob.erase(bob.begin());
                alice.erase(alice.begin());
            }
            t1--;
            t2--;
        }
        else if (two.size() && (!bob.size() && !alice.size())){
            ans+= *two.begin();
            t1--;
            t2--;
            two.erase(two.begin());
        }
        else if (!two.size() && bob.size() && !alice.size()){
            lli y = *bob.begin();
            ans += y;
            bob.erase(bob.begin());
            t1--;
        }
        else if (!two.size() && !bob.size() && alice.size()){
            lli y = *alice.begin();
            ans += y;
            alice.erase(alice.begin());
            t2--;
        }
        else if(!two.size() && bob.size() && alice.size()){
            lli y = *bob.begin(),z = *alice.begin();
            ans+=y+z;
            bob.erase(bob.begin());
            alice.erase(alice.begin());
            t1--;
            t2--;
        }
        else if (two.size() && bob.size() && !alice.size()){
            lli y = *bob.begin();
            lli x = *two.begin();
            if(t2== 0){
                if(x<=y){
                    t1--;
                    t2--;
                    ans+=x;
                    two.erase(two.begin());
                }
                else{
                    ans += y;
                    bob.erase(bob.begin());
                    t1--;
                }
            }
            else {
                ans+=x;
                t1--;
                t2--;
                two.erase(two.begin());
            }
        }
        else if (two.size() && !bob.size() && alice.size()){
            lli y = *alice.begin();
            lli x = *two.begin();
            if(t1== 0){

                if(x<y){
                    t1--;
                    t2--;
                    ans+=x;
                    two.erase(two.begin());
                }
                else{
                    ans += y;
                    alice.erase(alice.begin());
                    t2--;
                }
            }
            else{
                t1--;
                t2--;
                ans+=x;
                two.erase(two.begin());
            }
        }
        if(!two.size() && !alice.size() && !bob.size()){break;}
        // cout<<t1<<" "<<t2<<" "<<ans<<" "<<two.size()<<" "<<alice.size()<<" "<<bob.size()<<endl;
    }
    if(t1>0 || t2>0)return cout<<-1<<endl,0;
    cout<<ans<<endl;
    return 0;
}