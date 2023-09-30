#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'
const int sz = 500;
struct basisxor{
    bitset<sz> bs[sz];
    bitset<sz> index[sz];
    bitset<sz> zero;
    basisxor(){
        for(int i=0;i<sz;i++) bs[i]=zero;
    }
    bitset<sz> chk(bitset<sz> &b){
        bitset<sz> ans;
        int i;
        for(i = sz-1;i>=0;i--){
            if(b[i]== 0)continue;
            if(b.count()== 0)break;
            if(bs[i].count()==0)break;
            b^=bs[i];
            ans^=index[i];
        }
        if(b.count()==0) return ans;
        return zero;
    }

    bool add(bitset<sz> &b,int idx){
        int i;
        bitset<sz> x;
        x[idx]= 1;
        for(i = sz-1;i>=0;i--){
            if(b[i]== 0)continue;
            if(b.count()== 0)break;
            if(bs[i].count()==0)break;
            b^=bs[i];
            x^=index[i];
        }

        if(i ==-1)return false;
        bs[i] = b;
        index[i] = x;
        return true;
    }
    void print(){
        for(int i =sz-1;i>=0;i--){
            cout<<"I: "<<i<<" "<<bs[i]<<" idx: "<<endl;
        }
    }
};
int main(){__
    int n,x;
    cin>>n;
    basisxor bs;
    for(int i = 0;i<n;i++){
        bitset<sz> b;
        for(int j = 0;j<n;j++){
            cin>>x;
            if(x)
                b[j] = 1;
        }
        bs.add(b,i);
    }
    vector<bitset<sz>> res;
    for(int i = 0;i<n;i++){
        bitset<sz> b;
        b[i] = 1;
        bitset<sz> ans = bs.chk(b);
        if(ans.count())
            res.push_back(ans);
    }
    if(res.size()== n){

        for(auto c:res){
            for(int i = 0;i<n;i++){
                if(c[i]==1)
                    cout<<i+1<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<-1<<endl;
    return 0;
}