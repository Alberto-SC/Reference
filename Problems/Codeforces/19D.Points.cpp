#include <bits/stdc++.h>
using namespace std;
vector<int> st;

int N;
void update(int pos ,int x,int v = 1,int sl = 0,int sr = N-1){
    if(sl == sr)st[v]+=x;
    else{
        int mid = (sl+sr)>>1;  
        if(pos<=mid)
            update(pos,x,v<<1,sl,mid);
        else   
            update(pos,x,v<<1|1,mid+1,sr);
        st[v] = st[v<<1]+st[v<<1|1];
    }
}

int query(int l,int r,int v = 1,int sl = 0,int sr = N-1,int s = 1){
    
}
int main(){
    int n,type,x,y;
    cin>>n;
    string type;
    vector<int> xs;
    for(int i = 0;i<n;i++){
        cin>>type;
        cin>>x>>y;
        if(type[0] == 'a'){
            xs.push_back(x);
            querys.push_back({1,x,y});
        }
        else if(type[0] == 'f'){
            querys.push_back({2,x,y});
        }
        else{
            querys.push_back({3,x,y});
        }
    }
    sort(xs.begin(),xs.end());
    vector<int> C(xs.size());
    vector<set<int>> sets(xs.size());
    st.resize(4*xs.size());
    N = xs.size();
    for(int i = 0;i<n;i++){
        x = querys[i].x;
        y = querys[i].y;
        if(querys[i].type == 1){
            int idx= lower_bound(xs.begin(),xs.end(),x)-xs.begin();
            update(idx,1);
            C[idx]++;
            sets[idx].insert(y);
        }
        else if(querys[i].type == 2){
            int idx= lower_bound(xs.begin(),xs.end(),x)-xs.begin();
            update(idx,-1);
            C[idx]--;
            sets[idx].erase(y);
        }
        else{
            int xfirst = query(x+1,xs.size()-1);
            auto yfirst = upper_bound(sets[xfirst].begin,sets[xfirst].end(),y);
            if(C[xfirst] && yfirst!= sets[xfirst].end())
                cout<<xs[xfirst]<<" "<<*yfirst;
            else    
                cout<<-1<<endl;
        }
    }
    return 0;
}