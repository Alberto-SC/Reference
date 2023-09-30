  #include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){__
    int t = 1,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        string s;
        cin>>s;
        bool flag = true;
        vector<bool> pass(n,false);
        for(int i = 0;i<n;i++){
          if(!flag)break;
          if(s[i]== '?' && !pass[i]){
            int found = -1;
            for(int j = i;j<n;j+=k){
              if(s[j] != '?'){
                found = s[j]-'0';
                break;}
            }
            if(found== -1){ 
              for(int j = i;j>=0;j-=k){
                if(s[j]!= '?'){
                  found = s[j]-'0';
                  break;
                }
              }
            }
            if(found!= -1){
              for(int j = i;j<n;j+=k){
                if(s[j] != '?' && s[j]!= char(found+'0')){flag = false;break;}
                else s[j]= char(found+'0');
              }
            } 
            else {
              for(int j = i;j<n;j+=k)pass[j]=true; 
            }
          }
        }
        // cout<<s<<endl;
        if(!flag){cout<<"NO"<<endl;continue;}
        int ones = 0,zeros = 0;
        for(int i = 0;i<k;i++){
          if(s[i]== '0')zeros++;
          else if(s[i]== '1')ones++;
        }

        int ao= (k/2)-ones,az = (k/2)-zeros;
        if(ones+zeros<k){
          for(int i = 0;i<k;i++){
            if(s[i]== '?'){
              if(ao)s[i]= '1',ao--;
              else s[i]= '0',az--;
            }
          }
        }
        if(ao != 0 || az != 0)flag = false;
        for(int i = 0;i<n;i++){
          if(i+k<n &&s[i+k]!= '?'  && s[i] != s[i+k] )flag = false;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

