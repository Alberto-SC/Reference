#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0L);
using lli = int64_t;
using comp = complex<long double>;
#define print(A)for(auto c:A)cout<<c<<" ";cout<<endl;
#define printc(A)for(auto c:A)cout<<c.real()<<" ";cout<<endl;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

 
int main(){
    lli n,m;
    std::clock_t start;
	double duration;
    // start = std::clock();
    string s,t;
    while(cin>>s>>t){ 
        n = s.size();
        m = t.size();
        int mx = -1;  
        int idx = 0;
        int cont = 0;
        for(int i = 0;i<(n+m)-1;i++){
            cont = 0;
            for(int j = m-1;j>=0;j--){
                // cout<<i-((m-1)-j)<<" "<<j<<endl;
                if(i-((m-1)-j)<0)break;
                else if(i-((m-1)-j)>=n)continue;
                else if(t[j] == s[i-((m-1)-j)])cont++;
            }
            // cout<<cont<<" ";
            if(cont>=mx)mx = cont,idx = i;
        }
        // cout<<endl;
        cout<<idx<<endl;
        if(mx ==0){cout<<0<<endl<<"No matches"<<endl<<endl;continue;}
        string match = string(m,'$');
        for(int j = m-1;j>=0;j--){
            if(idx-((m-1)-j)<0)break;
            else if(idx-((m-1)-j)>=n)continue;
            else if(t[j] == s[idx-((m-1)-j)])match[j] = t[j];
            else if(t[j] != s[idx-((m-1)-j)])match[j] = 'X';
        }
        if(match[0]== '$'){
            int i = 0;
            while(match[i] == '$'){match[i] = t[i];i++;}
            for(int j = m-i;j<n;j++)
                match+= s[i];
        }
        else if(match[m-1] == '$'){
            int i = m-1;
            while(match[i] == '$'){match[i] = t[i];i--;}
            for(int j = n-(i+1)-1;j>=0;j--)
                match=s[j]+match;
        }
        cout<<mx<<endl;
        cout<<match<<endl<<endl;
    }
    return 0;
}