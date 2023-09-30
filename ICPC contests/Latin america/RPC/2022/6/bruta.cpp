#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

int n,m;
vector<int> nums;
vector<int> F(1007);
int getNum(int x1,int x2,int x3){
    x1--,x2--,x3--;
    int ans = x1*m*m;
    ans+=x2*m;
    ans+=x3;
    return ans;
}

bool check(int x1,int x2){
    set<int> last;
    set<int> last2;
    last2.insert(x2);
    for(int i = 1;i<=m;i++){
        if(F[getNum(x1,x2,i)]==nums[1]){
            last.insert(i);
        }
    }
    for(int i = 2;i<=n;i++){
        set<int> nw;
        for(int y1:last2){
            for(auto y2:last){
                for(int y3 = 1;y3<=m;y3++){
                    if(F[getNum(y1,y2,y3)]== nums[i%n])
                        nw.insert(y3);
                }
            }
        }
 m        last2 = last;
        last = nw;
    }   
    if(last.count(x2) && last2.count(x1))return true;
    return false;

}

signed main(){
    cin>>n>>m;
    nums.resize(n);
    for(int i = 0;i<m*m*m;i++){
        cin>>F[i];
    }
    for(auto &c:nums)cin>>c;

    for(int i = 1;i<=m;i++){
        for(int j = 1;j<=m;j++){
            if(check(i,j))return cout<<"YES"<<endl,0;
        }
    }
    cout<<"NO"<<endl;
}   