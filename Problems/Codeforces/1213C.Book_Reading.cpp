#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
    int t;
    cin>>t;
    while(t--){
        lli n,m;
        cin>>n>>m;
        vector<bool> used(10);
        int sum = 0;
        int size = 0;
        bool flag = false;
        for(int i = 1;i<12;i++){
            lli aux = m*i;
            if(used[aux%10])break;  
            used[aux%10] = true;
            sum+=aux%10;
            size++;
        }

        if(m>n)cout<<0<<endl;
        else if(m ==n)cout<<m%10<<endl;
        else{
            lli x = n/m;
            if(size>x){
                int ans = 0;
                for(int i = 1;i<=x;i++){
                    ans += (m*i)%10;
                }
                cout<<ans<<endl;
            }
            else{
                lli ans = (x/size)*sum;
                lli diff = x%size;
                // cout<<sum<<" "<<ans<<" "<<x<<" "<<size<<" "<<diff<<endl;
                for(int i = 1;i<=diff;i++){
                    ans+= (m*i)%10;
                }
                cout<<ans<<endl;
            }

        }
    }
    return 0;
}