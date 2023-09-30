#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,w,h,n;
    cin>>t;
    while(t--){
        cin>>w>>h>>n;
        char p1[w][h];
        char p2[w][h];
        int cont1 = 0,cont2 = 0;
        for(int i = h-1;i>=0;i--)
            for(int j = 0;j<w;j++){
                cin>>p1[j][i];
                if(p1[j][i] == '#')cont1++;
            }
        for(int i = h-1;i>=0;i--)
            for(int j = 0;j<w;j++){
                cin>>p2[j][i];
                if(p2[j][i] == '#')cont2++;
            }
        vector<pair<int,int>> shots;
        int x,y;
        // for(auto c:shots)cout<<c.first<<" "<<c.second<<endl;
        bool turn = 0;
        bool end = false;
        for(int i = 0;i<n;i++){
            cin>>x>>y;
            if(end)continue;
            if(!turn){
                if(p2[x][y] == '#'){
                    cont2--;
                    p2[x][y] = '-';
                    if(cont2 == 0)
                        turn = !turn;   
                }
                else
                    turn = !turn;
                    
            }
            else{
                if(p1[x][y] == '#'){
                    cont1--;
                    p1[x][y] = '-';
                    if(cont1 == 0){
                        turn = !turn;
                        end = true;
                    }
                }
                else {
                    turn = !turn;
                    if(!turn && cont1*cont2 == 0)end = true;
                }
            }
            // cout<<cont1<<" "<<cont2<<"  "<<turn<<"   "<<shots[i].first<<","<<shots[i].second<<endl;
        }
        if (cont1== 0 && cont2 > 0)
			cout<<"player two wins\n";
		else if (cont1 > 0  && cont2 == 0)
			cout<<"player one wins\n";
		else	cout<<"draw\n";
    }
    return 0;
}
