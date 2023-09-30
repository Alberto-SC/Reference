#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
int main(){
    string m[3][3];
    int t;
    cin>>t;
    int id = 1;
    vector<vector<int>> diferents;
    vector<int> diffs(6);
    for(int n1 = 0;n1<10;n1++){
        for(int n2 = n1+1;n2<10;n2++){
            for(int n3 = n2+1;n3<10;n3++){
                for(int n4 = n3+1;n4<10;n4++){
                    for(int n5 = n4+1;n5<10;n5++){
                        for(int n6 = n5+1;n6<10;n6++){
                            diffs[0]= n1;
                            diffs[1]= n2;
                            diffs[2]= n3;
                            diffs[3]= n4;
                            diffs[4]= n5;
                            diffs[5]= n6;
                            do {
                                diferents.push_back(diffs);
                            }while(next_permutation(diffs.begin(),diffs.end()));
                        }
                    }
                }
            }   
        }
    }
    // cout<<diferents.size()<<endl;
    vector<vector<int>> ans(diferents.size());
    sort(diferents.begin(),diferents.end());
    char tmp[2];
    int last[3];
    while(t--){
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                scanf("%2s", tmp);
                m[i][j]= tmp;
                // scanf("%s",m[i][j]);
            }
        }
        int idx = 0;
        printf("Case #%d:\n",id);
        for(int i = 0;i<diferents.size();i++){
            bool flag = true;
            for(int j = 0;j<3;j++){
                int sum = 0;
                for(int k = 0;k<3;k++){
                    int x = 0;
                    // if(m[j][k].size()== 2 &&diferents[i][m[j][k][0]-'A']== 0 ){
                        // flag = false;
                        // break;
                    // }
                    for(int z = 0;z<m[j][k].size();z++){
                        x*=10;
                        x+=diferents[i][m[j][k][z]-'A'];
                    }
                    if(k ==2){
                        if(sum != x){
                            flag = false;
                            break;
                        }
                        // last[j] = x;
                    }
                    else
                        sum+=x;
                }
                if(!flag)break;
            }
            // if(last[0]-last[1]!= last[2])continue;
            if(!flag)continue;
            for(int j = 0;j<3;j++){
                int sum = 0;
                for(int k = 0;k<3;k++){
                    int x = 0;
                    for(int z = 0;z<m[k][j].size();z++){
                        x*=10;
                        x+=diferents[i][m[k][j][z]-'A'];
                    }
                    if(k ==2){
                        if(sum != x){
                            flag = false;
                            break;
                        }
                    }
                    else{
                        if(k == 0)
                            sum+=x;
                        else 
                            sum-=x;
                    }
                }
                if(!flag)break;
            }
            if(!flag)continue;

            for(int j = 0;j<6;j++){
                printf("%d",diferents[i][j]);
                if(j<5)printf(" ");
            }
            printf("\n");
        }
        printf("\n");
        // if(t)printf("\n");
        id++;
    }
    return 0;
}