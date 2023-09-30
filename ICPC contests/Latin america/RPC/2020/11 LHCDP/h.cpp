#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

lli _hash(string const& s) {
    lli p = 31; 
    lli m = 1e9 + 9;
    int S = s.size();
    vector<lli> p_pow(S); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    lli h_s = 0; 
    for (int i = 0; i < S; i++){
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 
        if(h_s<0)
            (h_s+=m)%=m;
    }
    return h_s;
}


int main(){__
    int t = 1,n;
    string a,b,c;
    cin>>a>>b>>c;
    n = a.size();
    vector<pair<lli,int>> hashes;
    for(int i = 0;i<n;i++){
        string s = "";
        for(int j = 0;j<n;j++){
            s+=a[(i+j)%n];
        }
        // cout<<s<<endl;
        hashes.push_back({_hash(s),i});
    }
    sort(hashes.begin(),hashes.end());
    int mn = n+1;
    // cout<<endl;
    for(int i = 0;i<n;i++){
        string Need = "";
        for(int j = 0;j<n;j++){
            if(b[j]!= c[(j+i)%n]){
                if('A' != b[j] && 'A' != c[(j+i)%n]){
                    Need+="A";
                }
                else if('B' != b[j] && 'B' != c[(j+i)%n]){
                    Need+="B";
                }
                else if('C' != b[j] && 'C' != c[(j+i)%n]){
                    Need+="C";
                }
                else break;
            }
        }
        if(Need.size()== n){
            // cout<<i<<endl;
            // cout<<Need<<endl;
            lli hashA = _hash(Need);
            // cout<<hashA<<endl;
            auto idx = lower_bound(hashes.begin(),hashes.end(),make_pair(hashA,0));    
            auto idx2 = lower_bound(hashes.begin(),hashes.end(),make_pair(hashA+1,0));    
            if(hashA == idx->first)
                mn = min(mn,int(ceil(min(i,n-i)/2.0))+min(idx->second,n-idx->second));
            idx2--;
            if(hashA == idx2->first)
                mn = min(mn,int(ceil(min(i,n-i)/2.0))+min(idx2->second,n-idx2->second));

        }
    }

    for(int i = 0;i<n;i++){
        string Need = "";
        for(int j = 0;j<n;j++){
            if(c[j]!= b[(j+i)%n]){
                if('A' != c[j] && 'A' != b[(j+i)%n]){
                    Need+="A";
                }
                else if('B' != c[j] && 'B' != b[(j+i)%n]){
                    Need+="B";
                }
                else if('C' != c[j] && 'C' != b[(j+i)%n]){
                    Need+="C";
                }
                else break;
            }
            else break;
        }
        if(Need.size()== n){
            // cout<<i<<endl;
            // cout<<Need<<endl;
            lli hashA = _hash(Need);
            // cout<<hashA<<endl;
            auto idx = lower_bound(hashes.begin(),hashes.end(),make_pair(hashA,0));
            auto idx2 = lower_bound(hashes.begin(),hashes.end(),make_pair(hashA+1,0));
            if(hashA == idx->first)
                mn = min(mn,int(ceil(min(i,n-i)/2.0))+min(idx->second,n-idx->second));
            idx2--;
            if(hashA == idx2->first)
                mn = min(mn,int(ceil(min(i,n-i)/2.0))+min(idx2->second,n-idx2->second));
            // cout<<idx->first<<" "<<idx->second<<endl;
        }
    }

    if(mn ==n+1)cout<<-1<<endl;
    else
        cout<<mn<<endl;
    return 0;
}

