
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main(){__
  	int T= 1,n;
    int id = 1;
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

    cin>>T;
    while(T--){
        cin>>n;

        map<int,int> mp;
        for(int p: primes){
            while(n%p==0){
                mp[p]++;
                n/=p;
            }
        }

        if(n !=1){
            cout<<"Case #"<<id<<": "<<-1<<endl;
        }
        else{
            int sum = 0;
            vector<int> ans;
            for(auto c:mp){
                sum+=c.first*c.second;
                for(int i = 0;i<c.second;i++)
                    ans.push_back(c.first);
            }

            if(sum>41)
                cout<<"Case #"<<id<<": "<<-1<<endl;
            else{
                while(ans.size()>=2){
                    bool flag = false;
                    int a = -1,b = -1;
                    for(int i = ans.size()-1;i>=0;i--){
                        for(int j = i-1;j>=0;j--){
                            int nw = ans[i]*ans[j];
                            int old = ans[i]+ans[j];
                            if((sum-old)+nw<=41){
                                flag = true;
                                a = i;
                                b = j;
                                sum-=old; 
                                sum+=nw;
                                break;
                            }
                        }
                        if(flag)break;
                    }
                    if(!flag)break;

                    vector<int> nwAns;
                    for(int i = 0;i<ans.size();i++){
                        if(i!=a && i!= b)nwAns.push_back(ans[i]);
                    }
                    nwAns.push_back(ans[a]*ans[b]);
                    sort(nwAns.begin(),nwAns.end());
                    ans = nwAns;
                }
                if(ans.size()+(41-sum)>100)
                    cout<<"Case #"<<id<<": "<<-1<<endl;
                else{
                    cout<<"Case #"<<id<<": "<<ans.size()+(41-sum)<<" ";
                    for(auto c: ans)cout<<c<<" ";
                    for(int i = 0;i<41-sum;i++)cout<<1<<" ";
                    cout<<endl;
                }
            }
        }
        id++;
    }
    return 0;
}  

