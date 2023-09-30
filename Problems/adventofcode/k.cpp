#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
int n,m;
bool valid(int x,int y){
    if(x>=n || y>=m)return false;
    if(x<0 || y <0 )return false;
    return true;
}
int main(){
    string s;
    vector<string> nums;
    string x;
    while(cin>>x){
        nums.push_back(x);
    }
    map<vector<string>,bool> mp;
    int cont = 0;

    vector<string> current = nums;
    m = current[0].size();
    n = current.size();
    while(mp.count(current)== 0){
        mp[current] = true;
        vector<string> copy = current;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(current[i][j]== '.')continue;
                int ocuped = 0;
                for(int k = 0;k<8;k++){
                    int nx = i;
                    int ny = j;
                    while(1){
                        nx+=fx[k];
                        ny+=fy[k];
                        if(!valid(nx,ny))break;
                        if(current[nx][ny]== 'L'|| current[nx][ny]== '#')break;
                    }
                    if(valid(nx,ny) && current[nx][ny]== '#'){
                        ocuped++;
                    }
                }
                if(current[i][j]== 'L'){
                    if(ocuped == 0)
                        copy[i][j] = '#';
                }
                else{
                    if(ocuped>=5)
                        copy[i][j] = 'L';
                }
            }
        }
        current = copy;
        cont++;
    }
    int z = 0;
    for(auto c:current){
        for(auto d:c){
            if(d == '#')z++;
        }
    }
    cout<<z<<endl;
    return 0;
}