    #include <bits/stdc++.h>
    using namespace std;
    #define endl '\n'

    int n,node = 1;
    vector<pair<int,int>>ans;
    void construct(int init,int d ,int deg,int level = 0){
        // cout<<"HI "<<init<<" "<<d<<endl;
        if(node == n|| d == 0)return;
        ans.push_back({init,++node});
        // cout<<init<<" "<<++node<<endl;
        if(node ==n)return;

        for(int i = 0;i<d-1;i++){
            ans.push_back({node++,node});
            // cout<<node++<<" "<<node<<endl;
            if(node== n)return;
        }
        int copy = node;
        if(level ==0){
        for(int i = 1;i<(int)ceil(d/2.0);i++){
            if(node==n)return;
            for(int j = 0;j<deg-2;j++){
                if(node == n)return;
                construct((copy-d)+i,i,deg,level+1);
            }
        }
        if(d%2 == 0){
            for(int j = 0;j<deg-2;j++){
                if(node == n)return;
                construct((copy-d)+(d/2),d/2,deg,level+1);
            }
        }
        for(int i = 0;i<(int)ceil(d/2.0)-1;i++){
            if(node == n)return;
            for(int j = 0;j<deg-2;j++){
                if(node==n)return;l.o
                if(d%2 ==0 )
                    construct((copy-d)+ d/2+(i+1),(d/2)-i-1,deg,level+1);
                else
                    construct((copy-d)+ d/2+(i+1),(d/2)-i,deg,level+1);
            }
        }
        }
        else {
            for(int i = 1;i<d;i++){
                if(node== n)return;
                for(int j = 0;j<deg-2;j++){
                    if(node == n)return;
                    construct(copy-d+i,d-i,deg,level+1);
                }
            }
        }
    }

    int main(){
        int d,deg;
        cin>>n>>d>>deg;
        if(d>=n)return cout<<"NO"<<endl,0;
        if(deg == 1 && d>1)return cout<<"NO"<<endl,0;
        construct(1,d,deg);
        if(node<n)return cout<<"NO"<<endl,0;
        cout<<"YES"<<endl;
        for(auto c:ans)cout<<c.first<<" "<<c.second<<endl;
        return 0;
    }