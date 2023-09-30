#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

int B = 1e12+1;
int A = 1e12;
signed main(){__
    int T = 1,n,q;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        vector<int> zeros;
        n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]== '0')zeros.push_back(i);
        }
        reverse(zeros.begin(),zeros.end());
        int ans= 2e18;
        ans = min({ans,(int)zeros.size()*B,(n-(int)zeros.size())*B});
        
        int ac = 0;
        for(int i = 0;i<n;i++){
            if(s[i]=='1'){
                int x = 0;
                if(zeros.size()>0){
                    x = zeros.back()-i;
                
                    int res1 = ac+ (x*A) + ((zeros.size()-1)*B);
                    int res2 = ac +(B) + ((zeros.size())*B);
            
                    if(res1<res2){
                        swap(s[i],s[zeros.back()]);
                        zeros.pop_back();
                        ac+=x*A;
                    }
                    else ac+=B;
                    ans = min({ans,res1,res2});
                    
                    
                }
                else {

                    break;
                };
            }
            else{
                zeros.pop_back();
                /* cout<<ac<<" "<<zeros.size()<<" "<<B<<" "<<ac+((int)zeros.size()*B)<<endl; */
                ans = min(ans,ac+((int)zeros.size()*B));
            }
            /* cout<<s<<endl; */
        }
        cout<<ans<<endl;
    }
    return 0;
}
 
