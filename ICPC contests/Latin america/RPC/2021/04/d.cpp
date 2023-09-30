#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

const int sz = 160;
struct basisxor{
    bitset<sz> bs[sz];
    bitset<sz> index[sz];
    bitset<sz> zero;
    int bsz = 0;
    basisxor(){
        for(int i=0;i<sz;i++) bs[i]=zero;
    }
    bool chk(bitset<sz> b){
        bitset<sz> ans;
        int i;
        for(i = sz-1;i>=0;i--){
            if(b[i]== 0)continue;
            if(b.count()== 0)break;
            if(bs[i].count()==0)break;
            b^=bs[i];
            ans^=index[i];
        }
        if(b.count()==0) return true;
        return false;
    }

    bool add(bitset<sz> b){
        int i;
        bitset<sz> x;
        for(i = sz-1;i>=0;i--){
            if(b[i]== 0)continue;
            if(b.count()== 0)break;
            if(bs[i].count()==0)break;
            b^=bs[i];
        }

        if(i ==-1)return false;
        bs[i] = b;
        bsz++;
        return true;
    }
    void print(){
        for(int i =sz-1;i>=0;i--){
            cout<<"I: "<<i<<" "<<bs[i]<<" idx: "<<endl;
        }
    }
};

signed main(){
	int n,m,k;
    cin>>n>>m>>k;
    string s;
    vector<basisxor> pref(n);
    for(int i = 0;i<n;i++){
        cin>>s;
        bitset<sz> bs;
        int id = (k*4)-1;
        for(int j = 0;j<k;j++){
            stringstream ss;
            ss<<hex<<s[j];
            int x;
            ss>>x;
            bitset<4> b(x);
            for(int z = 3;z>=0;z--){
                bs[id--] = b[z];
            }
            ss.str("");
        }
        // cout<<bs<<endl;
        for(int j = i;j<n;j++)
            pref[j].add(bs);
    }
    for(int i = 0;i<m;i++){
        cin>>s;
        bitset<sz> bs;
        int id = (k*4)-1;
        for(int j = 0;j<k;j++){
            stringstream ss;
            ss<<hex<<s[j];
            int x;
            while(ss>>x){
                bitset<4> b(x);
                for(int z = 3;z>=0;z--)
                    bs[id--] = b[z];
            }
        }
        int idx = -1;
        for(int j = 0;j<n;j++){
            if(bs.count()==0){
                if((j+1)-pref[j].bsz>0){
                    idx = j+1;
                    break;
                }
            }
            else if(pref[j].chk(bs)){
                idx = j+1;
                break;
            }
        }
        cout<<idx<<endl;
    }
    return 0;
}  
