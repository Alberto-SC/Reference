#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q,a,b;
    cin>>n>>q;
    vector<set<double>> buck((2*n));
    vector<bool> used((2*n));
    int blocks= 0;
    for(int i = 0;i<q;i++){
        cin>>a>>b;
        a--;
        b--;
        int x = (a*n)+b,z;
        a?z= n*-1:z = n;  
        used[x] = !used[x];
        if(used[x]){
            if(used[x+z] == true)
                buck[x].insert(b),buck[x+z].insert(b),blocks++;
            if((x+z)+1<2*n && used[(x+z)+1] == true)
                buck[x].insert(b+0.5),buck[(x+z)+1].insert(b+0.5),blocks++;
            if((x+z)-1>=0  && used[(x+z)-1] == true)
                buck[x].insert(b-0.5),buck[(x+z)-1].insert(b-0.5),blocks++;
        }
        else {
            if(buck[x].find(b)!= buck[x].end())
                buck[x].erase(b),buck[x+z].erase(b),blocks--;
            if(buck[x].find(b+0.5)!= buck[x].end())
                buck[x].erase(b+0.5),buck[(x+z)+1].erase(b+0.5),blocks--;
            if(buck[x].find(b-0.5)!= buck[x].end())
                buck[x].erase(b-0.5),buck[(x+z)-1].erase(b-0.5),blocks--;
        }
        blocks>0?cout<<"No"<<endl:cout<<"Yes"<<endl;        
    }
    return 0;
}