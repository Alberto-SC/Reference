#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#define _FORTIFY_SOURCE 2
#include <bits/stdc++.h>
using namespace std;
#define x first 
#define y second
const int maxn = 1007;
vector<int> p(maxn);
vector<int> sz(maxn,1);

int raiz(int u){
    return u == p[u]?u:p[u] = raiz(p[u]);
}
int components;
void union_by_size(int u,int v){
    u =raiz(u);
    v =raiz(v);
    if(u ==v)return ;
    if(sz[u]>sz[v])swap(u,v);
    sz[v]+=sz[u];
    p[u] = v;
    components--;

}
int main(){
    int n;
    cin>>n;
    components = n;
    iota(p.begin(),p.end(),0);
    vector<pair<int,int>> points(n);
    for(int i = 0;i<n;i++){
        cin>>points[i].x>>points[i].y;
    }
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(points[i].x == points[j].x || points[i].y== points[j].y)
                union_by_size(i,j);
        }
    }
    for(int i = 0;i<n;i++)cout<<p[i]<<" ";
    cout<<endl;
    cout<<components<<endl;
    if(components >2)return cout<<-1<<endl,0;
    else{
        map<int,vector<int>>x1;
        map<int,vector<int>>x2;
        map<int,vector<int>>y1;
        map<int,vector<int>>y2;
        int cm1 = p[0];
        for(int i = 0;i<n;i++){
            if(p[i]== cm1)x1[points[i].x].push_back(points[i].y),y1[points[i].y].push_back(points[i].x);
            else x2[points[i].x].push_back(points[i].y),y2[points[i].y].push_back(points[i].x);
        }
        int mxdist = 0;
        for(auto c:x1){
            sort(c.second.begin(),c.second.end());
            for(int i =1;i<c.second.size();i++)
                mxdist = max(mxdist,c.second[i]-c.second[i-1]);
        }
        for(auto c:x2){
            sort(c.second.begin(),c.second.end());
            for(int i =1;i<c.second.size();i++)
                mxdist = max(mxdist,c.second[i]-c.second[i-1]);
        }
        for(auto c:y1){
            sort(c.second.begin(),c.second.end());
            for(int i =1;i<c.second.size();i++)
                mxdist = max(mxdist,c.second[i]-c.second[i-1]);
        }
        for(auto c:y2){
            sort(c.second.begin(),c.second.end());
            for(int i =1;i<c.second.size();i++)
                mxdist = max(mxdist,c.second[i]-c.second[i-1]);
        }

        if(components ==1){
            cout<<mxdist/2<<endl;
        }
        else{
            cout<<"HI "<<mxdist<<endl;
            for(auto c:x1){
                for(auto yy:y2){
                    int xm = c.first,ym = yy.first;
                    cout<<"Extra Point "<<xm<<" "<<ym<<endl;
                    auto dist_midle1 = lower_bound(yy.second.begin(),yy.second.end(),xm);
                    auto dist_midle2 = lower_bound(c.second.begin(),c.second.end(),ym);
                    if(dist_midle1 == yy.second.end())dist_midle1--;
                    else mxdist = max(mxdist,*dist_midle1-xm);

                    if(dist_midle1 != yy.second.begin()){  
                        dist_midle1--;
                        mxdist = max(mxdist,abs(*dist_midle1-xm));
                    }

                    if(dist_midle2 == c.second.end())dist_midle2--;
                    else mxdist = max(mxdist,*dist_midle2-ym);

                    if(dist_midle2 != c.second.begin()){
                        dist_midle2--;
                        mxdist = max(mxdist,abs(*dist_midle2-ym));
                    }

                }
            }

            for(auto c:y1){
                for(auto yy:x2){
                    int xm = c.first,ym = yy.first;
                    auto dist_midle1 = lower_bound(yy.second.begin(),yy.second.end(),xm);
                    auto dist_midle2 = lower_bound(c.second.begin(),c.second.end(),ym);
                    if(dist_midle1 == yy.second.end())dist_midle1--;
                    else mxdist = max(mxdist,*dist_midle1-xm);

                    if(dist_midle1 != yy.second.begin()){
                        dist_midle1--;
                        mxdist = max(mxdist,abs(*dist_midle1-xm));
                    }

                    if(dist_midle2 == c.second.end())dist_midle2--;
                    else mxdist = max(mxdist,*dist_midle2-ym);

                    if(dist_midle2 != c.second.begin()){
                        dist_midle2--;
                        mxdist = max(mxdist,abs(*dist_midle2-ym));
                    }

                }
            }
            cout<<mxdist<<endl;
        }
    }          
    return 0;
}