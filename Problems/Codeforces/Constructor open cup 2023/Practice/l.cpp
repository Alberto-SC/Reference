#include <bits/stdc++.h>
#define int long long 
#define __ ios_base::sync_with_stdio(false),cin.tie(NULL);
#define endl '\n'

using namespace std;

signed main(){__
    int T = 1,n,k,m;
    while(T--){
        cin>>k>>m;
        vector<string> v(k);
        for(auto &c:v)cin>>c;
        string s = "";
        for(int i = m-1;i>=0;i--){
            for(int j = 0;j<k;j++){
                s+=v[j][i];
            }
            s+=" ";
        }
        string t;
        cin>>t;
        vector<int> pos[26];
        for(int i = 0;i<t.size();i++){
            pos[t[i]-'a'].push_back(i);
        }

        vector<vector<vector <int>>> ROW(207,vector<vector<int>>(k+1,vector<int>(k+1,-1)));


        for(int i = 0;i<k;i++){
            for(int j = 0;j<m;j++){
                for(int r = 1;r<=k;r++){
                    for(auto c:pos[v[i][j]-'a']){
                        if(c>=r)break;
                        cout<<i<<" "<<j<<" "<<c<<" "<<r<<endl;
                        cout << t.size() << endl;
                        bool flag = true;
    
                        

                        for(int l = c,z = 0;l<t.size();l+=r,z++){
                            cout<<t[l]<<" "<<v[i][j-z]<<endl;
                            if(j-z<0 || t[l]!= v[i][j-z]){
                                flag = false;
                                break;
                            }
                        }
                        cout<<flag<<endl;
                        cout<<endl;
                        if(flag){
                            ROW[c][j][r] = i;
                        }
                    }
                }
            }
        }
        
        for(int i = 0;i<t.size();i++){
            for(int j = 0;j<m;j++){
                for(int l = 1;l<=k;l++){
                    cout<<ROW[i][j][l]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }

        for(int row = k;row<=k;row++){
            for(int idxRow = 0;idxRow<row;idxRow++){
                for(int col = 0;col<m;col++){

                    vector<int> ans;
                    int lastIdx = 0;
                    int lastCol = col;
                    int lastRow = idxRow;
                    cout<<row<<" "<<idxRow<<" "<<col<<endl; 
                    for(int r = 0;r<row;r++){
                        cout<<lastIdx<<" "<<lastCol<<" "<<" "<<lastRow<<" "<<row<<endl;
                        if(ROW[lastIdx][lastCol][row] == -1)break;
                        ans.push_back(ROW[lastIdx][lastCol][row]);
                        lastIdx++;
                        lastRow++;
                        if(lastRow == row)lastCol--,lastRow = 0;
                    }
                    cout<<endl;
                    if(ans.size()==row){
                        cout<<row<<endl;
                        rotate(ans.begin(),ans.begin()+(row-idxRow),ans.end());
                        for(auto c:ans)cout<<c+1<<" ";
                        cout<<endl;
                        return 0;
                    }
                }
            }
        }
        cout<<-1<<endl;
    }
    return 0;
}
