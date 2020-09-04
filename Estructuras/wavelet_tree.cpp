#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
// Complexity O(n log(max_element))
// Also use coordinates compression if the elements are to big because the complexity is nlog(max_element)

typedef vector<int>::iterator it;
struct wavelet{
    vector<vector<int>> mapLeft;
    int mx;
    wavelet(vector<int> &A,int mx):mapLeft(mx*2),mx(mx){
        build(A.begin(),A.end(),0,mx-1,1);
    }
    void build(it s,it e,int l,int r,int v){
        if(l== r)return;
        int m = (l+r)>>1;
        mapLeft[v].reserve(e-s+1);
        mapLeft[v].push_back(0);
        auto f = [m](int x){
            return x<=m;
        };
        for(it iter = s; iter!= e;iter++)
            mapLeft[v].push_back(mapLeft[v].back() + (*iter<=m));
        it p = stable_partition(s,e,f);
        build(s,p,l,m,v<<1);
        build(p,e,m+1,r,v<<1|1);
    }

    //counts the number of elements equal to c in range [1,i]
    //IF you want in the range [i,j] only calls rank(j)- rank(i-1)
    int rank(int c,int i){
        i++;
        int l = 0,r = mx-1,u = 1,m,left;
        while(l!= r){
            m = (l+r)>>1;
            left = mapLeft[u][i];
            u<<=1;
            if(c<=m)
                i = left,r = m;
            else 
                i-=left,l = m+1,u|=1;
        }
        return i;
    }

    // return the kth smallest element in a range [i,j]
    // k=1 is the smallest
    // 0 indexed this is indexes are in [0,n-1]
    // [Tested in RPC 2020/08 problem B and SPOJ MKTHNUM]
    int kth(int i,int j,int k){
        j++;
        int l = 0,r = mx-1,u = 1,li,lj;
        while(l!=r){
            int m = (l+r)>>1;
            li = mapLeft[u][i],lj = mapLeft[u][j];
            u<<=1;
            if(k<= lj-li)
                i = li,j = lj, r = m;
            else 
                i-=li,j-=lj,l = m+1,u|=1,k-=(lj-li);
        }
        return r;
    }
    int l,r;
    // count the ocurrences of numbers in the range [a,b]
    // and only in the secuende [i,j]
    // can be seen as how many points are in a specified rectangle with corns i,a and j,b
    int range(int i ,int j ,int a,int b){
        if( b<a || j<i)return 0;
        l = a,r = b;
        return range(i,j+1,0,mx-1,1);
    }

    int range(int i, int j,int a,int b,int v){
        if(b<l || a>r)return 0;
        if(a>=l && b<=r)return j-i;
        int m = (a+b)>>1;
        int li = mapLeft[v][i],lj = mapLeft[v][j];
        return range(li,lj,a,m,v<<1)+range(i-li,j-lj,m+1,b,v<<1|1);
    }


    // Return the minimun number that their frecuence in the range [i,j] is at least k
    // tested in [cdeforces 840D ]
    // complexity depends of k, if k is small and j-i is large maybe go up to o(n)
    // the problem tested has a k up to ((j-i)/5) and the complexity has  o(5log(n))
    int minimun_of_ocurrences(int i,int j,int k){
        return minimun_of_ocurrences(i,j+1,k,1,0,mx-1);
    }  
    int minimun_of_ocurrences(int i,int j,int k,int v ,int l,int r ){
        if(l == r)return j-i>= k?l:mx+2;
        if(j-i<k)return mx+2;
        int m = (l+r)>>1;
        int li = mapLeft[v][i],lj = mapLeft[v][j];
        int c = lj-li;
        int ans= mx+2;
        if(c >=k)
            ans = min(ans,minimun_of_ocurrences(li,lj,k,v<<1,l,m));
        if((j-i)-c>=k)
            ans = min(ans,minimun_of_ocurrences(i-li,j-lj,k,v<<1|1,m+1,r));
        if(c <k && (j-i)-c<k)return mx+2;
        return ans;
    }

    // swap element arr[i] and arr[i+1]
    // No tested    
    void swapadjacent(int i){
        swapadjacent(i,0,mx-1,1);
    }
    void swapadjacent(int i,int l,int r,int v){
        if(l == r)
            return ;
        mapLeft[v][i]= mapLeft[v][i-1] + mapLeft[v][i+1] - mapLeft[v][i];
        // c[i] = c[i-1] + c[i+1] - c[i];
        if(mapLeft[v][i+1]-mapLeft[v][i] == mapLeft[v][i] - mapLeft[v][i-1]){
            if(mapLeft[v][i]-mapLeft[v][i-1])
                return swapadjacent(mapleft[v][i],l,mid,v<<1);
            else
                return swapadjacent(i-mapLeft[v][i],mid+1,r,v<<1|1);
        }
        else
            return ;
    }
};


int main(){
    int t,n,q,l,r,k,c,a,b;
    while(cin>>n>>q){
        vector<int> nums(n);
        vector<int> copy(n);
        vector<int> real(n);
        for(int i = 0;i<n;i++){
            cin>>nums[i];
            copy[i] = nums[i];
        }
        sort(copy.begin(),copy.end());
        vector<int> uniques;
        int last = copy[0];
        uniques.push_back(copy[0]);
        for(int i = 0;i<n;i++){
            if(copy[i]!= last){
                last = copy[i];
                uniques.push_back(copy[i]);
            }
        }
        for(int i = 0;i<n;i++)
            nums[i] = lower_bound(uniques.begin(),uniques.end(),nums[i])-uniques.begin();
        wavelet wt(nums,uniques.size());
        for(int i = 0;i<q;i++){
            // ****** Test  KTH *******
            // cin>>l>>r>>k;
            // l--,r--;
            // cout<<uniques[wt.kth(l,r,k)]<<endl;

            // ****** Test rank *******
            // cin>>c>>l>>r;
            // l--,r--;
            // int number_in_wt = lower_bound(uniques.begin(),uniques.end(),c)-uniques.begin();
            // cout<<wt.rank(number_in_wt,r)-wt.rank(number_in_wt,l-1);

            // ****** Test range *******
            // cin>>a>>b>>l>>r;
            // l--,r--;
            // int a_in_wt = lower_bound(uniques.begin(),uniques.end(),a)-uniques.begin();
            // int b_in_wt = lower_bound(uniques.begin(),uniques.end(),b)-uniques.begin();
            // cout<<wt.range(l,r,a_in_wt,b_in_wt)<<endl;
        }
    }
    return 0;
}