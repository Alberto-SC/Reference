#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct str{
    int tile,x,y;
};
vector<string> rotar(vector<string> A){
    vector<string> nw;
    int n = A.size();
    int m = A[0].size();
    for(int i = 0;i<n;i++){
        string aux = "";
        for(int j = m-1;j>=0;j--)
            aux+= A[j][i];
        nw.push_back(aux);
    }
    return nw;
}
vector<string> flipL(vector<string> A){
    vector<string> nw;
    int n = A.size();
    int m = A[0].size();
    for(int i = 0;i<n;i++){
        string aux = "";
        for(int j = m-1;j>=0;j--)
            aux+=A[i][j];
        nw.push_back(aux);
    }
    return nw;
}
vector<string> flipD(vector<string>A){
    vector<string> nw = A;
    reverse(nw.begin(),nw.end());
    return nw;
}
int match(vector<string> grid){
    int mt = 0;
    // for(auto c:grid)cout<<c<<endl;
    // cout<<endl;
    int n = grid.size();
    int m = grid[0].size();
    // for(int i = 2;i<n;i++){

    // }
    return mt;
}
int main(){
    string tile,blank,s;
    int number;
    char dos;
    vector<string> grids[10000];
    vector<vector<int>> nb[10000];
    vector<int> numbers;
    while(cin>>tile>>number>>dos){
        for(int i = 0;i<10;i++){
            cin>>s;
            grids[number].push_back(s);
        }
        nb[number].resize(4,vector<int>());
        numbers.push_back(number);
    }
    int n = numbers.size();
    vector<int> D= {0,9,9,0};
    vector<int> D2= {0,9,9,0};
    for(auto n1:numbers){
        for(auto n2:numbers){
            if(n1 == n2)continue;
            for(int i = 0;i<4;i++){
                for(int j = 0;j<4;j++){
                    for(int z = 0;z<2;z++){
                        int cont = 0;
                        for(int k = 0;k<10;k++){
                            if(i&1){
                                if(j&1){
                                    if(grids[n1][k][D[i]]== grids[n2][z==0?k:9-k][D2[j]])cont++;
                                }
                                else{
                                    if(grids[n1][k][D[i]]== grids[n2][D2[j]][z==0?k:9-k])cont++;
                                }
                            }
                            else {
                                if(j&1){
                                    if(grids[n1][D[i]][k]== grids[n2][z==0?k:9-k][D2[j]])cont++;
                                }
                                else{
                                    if(grids[n1][D[i]][k]== grids[n2][D2[j]][z==0?k:9-k])cont++;
                                }
                            }
                        }
                        if(cont == 10)
                            nb[n1][i].push_back(n2);
                    }
                }
            }
        }
    }
    int leftup ;
    lli ans = 1;
    for(auto c:numbers){
        int d = 0;
        d+=nb[c][0].size();
        d+=nb[c][1].size();
        d+=nb[c][2].size();
        d+=nb[c][3].size();
        if(d==2){
            ans*=c;
            if(nb[c][1].size() && nb[c][2].size())leftup = c;
        }
    }
    // cout<<ans<<endl;
    // PART 2
    cout<<leftup<<endl;
    cout<<numbers.size()<<endl;
    char mega[1000][1000];
    queue<str> q;
    q.push({leftup,0,0});
    int lastx,lasty;
    map<int,bool> vis;
    while(!q.empty()){
        auto pos = q.front();
        q.pop();
        // cout<<pos.tile<<" "<<pos.x<<" "<<pos.y<<" "<<vis[pos.tile]<<endl;
        if(vis[pos.tile])continue;
        lastx = pos.x,lasty = pos.y;
        vis[pos.tile] = true;
        if(pos.x ==0 &&pos.y == 0){
            for(int i = 0;i<10;i++)
                for(int j = 0;j<10;j++)
                    mega[pos.x+i][pos.y+j] = grids[pos.tile][i][j];
        }
        else{
            for(int i = 0;i<4;i++){
                // cout<<"I: "<<i<<endl;
                int cont = 0;
                if(pos.x>0){
                    for(int k = 0;k<10;k++){
                        if(grids[pos.tile][0][k]== mega[pos.x-1][pos.y+k])cont++;
                    }
                }
                if(pos.y>0){
                    for(int k = 0;k<10;k++){
                        if(grids[pos.tile][k][0]== mega[pos.x+k][pos.y-1])cont++;
                    }
                }
                if(pos.x==0||pos.y==0){
                    if(pos.x ==0 && nb[pos.tile][0].size()== 0 &&cont ==10)break;
                    if(pos.y ==0 && nb[pos.tile][3].size()== 0 &&cont ==10)break;
                }
                else if(pos.x && pos.y){
                    if(cont == 20)break;
                }


                grids[pos.tile] = flipD(grids[pos.tile]);
                swap(nb[pos.tile][0],nb[pos.tile][2]);
                cont = 0;
                if(pos.x>0){
                    for(int k = 0;k<10;k++){
                        if(grids[pos.tile][0][k]== mega[pos.x-1][pos.y+k])cont++;
                    }
                }
                if(pos.y>0){
                    for(int k = 0;k<10;k++){
                        if(grids[pos.tile][k][0]== mega[pos.x+k][pos.y-1])cont++;
                    }
                }
                if(pos.x==0||pos.y==0){
                    if(pos.x ==0 && nb[pos.tile][0].size()== 0 &&cont ==10)break;
                    if(pos.y ==0 && nb[pos.tile][3].size()== 0 &&cont ==10)break;
                }
                else if(pos.x && pos.y){
                    if(cont == 20)break;
                }


                grids[pos.tile] = flipL(grids[pos.tile]);
                swap(nb[pos.tile][1],nb[pos.tile][3]);
                cont = 0;
                if(pos.x>0){
                    for(int k = 0;k<10;k++){
                        if(grids[pos.tile][0][k]== mega[pos.x-1][pos.y+k])cont++;
                    }
                }
                if(pos.y>0){
                    for(int k = 0;k<10;k++){
                        if(grids[pos.tile][k][0]== mega[pos.x+k][pos.y-1])cont++;
                    }
                }
                if(pos.x==0||pos.y==0){
                    if(pos.x ==0 && nb[pos.tile][0].size()== 0 &&cont ==10)break;
                    if(pos.y ==0 && nb[pos.tile][3].size()== 0 &&cont ==10)break;
                }
                else if(pos.x && pos.y){
                    if(cont == 20)break;
                }

                grids[pos.tile] = flipD(grids[pos.tile]);
                swap(nb[pos.tile][0],nb[pos.tile][2]);
                cont = 0;
                if(pos.x>0){
                    for(int k = 0;k<10;k++){
                        if(grids[pos.tile][0][k]== mega[pos.x-1][pos.y+k])cont++;
                    }
                }
                if(pos.y>0){
                    for(int k = 0;k<10;k++){
                        if(grids[pos.tile][k][0]== mega[pos.x+k][pos.y-1])cont++;
                    }
                }
                if(pos.x==0||pos.y==0){
                    if(pos.x ==0 && nb[pos.tile][0].size()== 0 &&cont ==10)break;
                    if(pos.y ==0 && nb[pos.tile][3].size()== 0 &&cont ==10)break;
                }
                else if(pos.x && pos.y){
                    if(cont == 20)break;
                }
                grids[pos.tile] = flipL(grids[pos.tile]);
                swap(nb[pos.tile][1],nb[pos.tile][3]);
                grids[pos.tile] = rotar(grids[pos.tile]);
                rotate(nb[pos.tile].begin(), nb[pos.tile].begin()+3, nb[pos.tile].end()); 
                
            }
            for(int i = 0;i<10;i++)
                for(int j = 0;j<10;j++)
                    mega[pos.x+i][pos.y+j] = grids[pos.tile][i][j];
        }   
        if(nb[pos.tile][1].size()){
            int nx = pos.x;
            int ny = pos.y+10;
            if(!vis[nb[pos.tile][1][0]]){
                // cout<<"1: GO FROM: "<<pos.tile<<" "<<pos.x<<" "<<pos.y<<"   TO: "<<nb[pos.tile][1][0]<<" "<<nx<<" "<<ny<<endl;
                q.push({nb[pos.tile][1][0],nx,ny});
            }
        }
        if(nb[pos.tile][2].size()){
            int nx = pos.x+10;
            int ny = pos.y;
            if(!vis[nb[pos.tile][2][0]]){
                // cout<<"2: GO FROM: "<<pos.tile<<" "<<pos.x<<" "<<pos.y<<"   TO: "<<nb[pos.tile][2][0]<<" "<<nx<<" "<<ny<<endl;
                q.push({nb[pos.tile][2][0],nx,ny});
            }
        }
    }
    vector<string>final;
    for(int i = 0;i<lastx+10;i++){
        string aux ="";
        for(int j = 0;j<lasty+10;j++){
            if(j%10 && j%10 != 9)
                aux+=mega[i][j];
            cout<<mega[i][j];
        }
        if(i%10 && i%10 != 9)
            final.push_back(aux);
        cout<<endl;
    }

    cout<<lastx<<" "<<lasty<<endl;
    // for(auto c:final)cout<<c<<endl;
    // for(int i= 0;i<4;i++){
    //     // cout<<match(final)<<endl;
    //     final = flipL(final);
    //     // cout<<match(final)<<endl;
    //     final = flipD(final);
    //     // cout<<match(final)<<endl;
    //     final = flipL(final);
    //     // cout<<match(final)<<endl;
    //     final = rotar(final);
    // }
    cout<<leftup<<endl;
    return 0;
}
