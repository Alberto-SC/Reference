#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
int n;
static const int T = (1 << 20);
static const ll INF = 1e15 + 7;
struct Node {
    ll min;
    int minCnt;
    ll secondMin;

    ll max;
    int maxCnt;
    ll secondMax;

    ll sum;
    // int diffGcd; 

    ll pushSum;
    ll pushEq;
} tree[T]; 



void mergeC(int v) {
    tree[v].sum = tree[v<<1].sum + tree[v<<1|1].sum;

    tree[v].max = max(tree[v<<1].max,tree[v<<1|1].max); 

    if(tree[v<<1].max == tree[v<<1|1].max){
        tree[v].maxCnt = tree[v<<1].maxCnt + tree[v<<1|1].maxCnt;
        tree[v].secondMax = max(tree[v<<1].secondMax,tree[v<<1|1].secondMax);
    }
    else if(tree[v<<1].max > tree[v<<1|1].max){
        tree[v].maxCnt = tree[v<<1].maxCnt;
        tree[v].secondMax = max(tree[v<<1|1].max,tree[v<<1].secondMax);
    }
    else{
        tree[v].maxCnt = tree[v<<1|1].maxCnt;
        tree[v].secondMax = max(tree[v<<1].max,tree[v<<1|1].secondMax);
    }


    tree[v].min = min(tree[v<<1].min,tree[v<<1|1].min); 

    if(tree[v<<1].min == tree[v<<1|1].min){
        tree[v].minCnt = tree[v<<1].minCnt + tree[v<<1|1].minCnt;
        tree[v].secondMin = min(tree[v<<1].secondMin,tree[v<<1|1].secondMin);
    }
    else if(tree[v<<1].min < tree[v<<1|1].min){
        tree[v].minCnt = tree[v<<1].minCnt;
        tree[v].secondMin = min(tree[v<<1|1].min,tree[v<<1].secondMin);
    }
    else{
        tree[v].minCnt = tree[v<<1|1].minCnt;
        tree[v].secondMin = min(tree[v<<1].min,tree[v<<1|1].secondMin);
    }
}

// Trivial build , is need to have the correct values of tags pushSum and pushEq.
// [sl,sr) , is the range of the node. 
void build(const vector<int>& A,int v = 1,int sl = 0,int sr = n) {
    tree[v].pushSum = 0;
    tree[v].pushEq = -1;
    if (sl + 1 == sr) {
        tree[v].max = A[sl];
        tree[v].secondMax = -INF;
        tree[v].maxCnt = 1;

        tree[v].min = A[sl];
        tree[v].secondMin = INF;
        tree[v].minCnt = 1;

        tree[v].sum = A[sl];
    } else {
        int m = (sl+sr)>>1;
        build(A,v<<1,sl,m);
        build(A,v<<1|1,m,sr);
        mergeC(v);
    }
}


void pushEq(int l,int r,int v,ll val){
    tree[v].min = tree[v].max = tree[v].pushEq = val;
    tree[v].minCnt = tree[v].maxCnt = r-l;
    tree[v].secondMax = -INF;
    tree[v].secondMin = INF;

    tree[v].sum = (r-l)*val;
    tree[v].pushSum = 0;
}

void pushSum(int l,int r,int v,ll val){
    if(tree[v].min == tree[v].max){
        pushEq(l,r,v,tree[v].min+val);
        return ;
    }

    tree[v].min += val;
    tree[v].max += val;
    tree[v].pushSum += val;
    tree[v].sum += (r-l)*val;

    if(tree[v].secondMax  != -INF)
        tree[v].secondMax += val;
    
    if(tree[v].secondMin != INF)
        tree[v].secondMin += val;

}

// Asign a[i] = min(a[i],val)
// Mantain a max and second max value and in each pushMIn call only updates the maximum value,
// second max will be updated lazy by their childrens.
void pushMin(int l,int r,int v,ll val){
    if(tree[v].min >= val)
        pushEq(l,r,v,val);
    else if(tree[v].max>val){
        if(tree[v].secondMin == tree[v].max){
            tree[v].secondMin = val;
        }
        tree[v].sum -= (tree[v].max-val)*tree[v].maxCnt;
        tree[v].max = val;
    }   
}

// Asign a[i] = max(a[i],val)
void pushMax(int l,int r,int v,ll val){
    if(tree[v].max <= val)
        pushEq(l,r,v,val);
    else if(tree[v].min<val){
        if(tree[v].secondMax== tree[v].min){
            tree[v].secondMax = val;
        }
        tree[v].sum += (val-tree[v].min)*tree[v].minCnt;
        tree[v].min = val;
    }   
}

void propagate(int l, int r,int v) {
    // The node is a leaf
    if (l + 1 == r) {
        return;
    }
    int mid = (l+r)>>1;
    if (tree[v].pushEq != -1) {
        pushEq(l, mid, v<<1,tree[v].pushEq);
        pushEq(mid, r, v<<1|1,tree[v].pushEq);
        tree[v].pushEq = -1;
    } else {
        pushSum(l, mid, v<<1,  tree[v].pushSum);
        pushSum(mid, r, v<<1|1,tree[v].pushSum);
        tree[v].pushSum = 0;

        pushMin(l, mid, v<<1,  tree[v].max);
        pushMin(mid, r, v<<1|1,tree[v].max);

        pushMax(l, mid, v<<1,  tree[v].min);
        pushMax(mid, r, v<<1|1,tree[v].min);
    }
}



// [l,r) Query ranges       
// [sl,sr) Node range
// a[i] = min(a[i],val), l <= i < r
void updateMin(int l,int r,ll val,int v = 1,int sl = 0,int sr = n){
    if(l>=sr || r<=sl || tree[v].max<=val) // Break condition
        return;

    if(sl>=l && sr<=r && tree[v].secondMax <val){
        pushMin(sl,sr,v,val);
        return ;
    } 
    propagate(sl,sr,v);

    int m = (sl+sr)>>1;
    updateMin(l,r,val,v<<1,sl,m);
    updateMin(l,r,val,v<<1|1,m,sr);

    mergeC(v);
}

// [l,r) Query ranges
// [sl,sr) Node range
// a[i] = max(a[i],val), l <= i < r
void updateMax(int l,int r,ll val,int v = 1,int sl = 0,int sr = n){
    if(l>=sr || r<=sl || tree[v].min>=val) // Break condition
        return;

    if(sl>=l && sr<=r && tree[v].secondMin > val){
        pushMax(sl,sr,v,val);
        return ;
    } 
    propagate(sl,sr,v);

    int m = (sl+sr)>>1;
    updateMax(l,r,val,v<<1,sl,m);
    updateMax(l,r,val,v<<1|1,m,sr);

    mergeC(v);
}

// [l,r) Query ranges
// [sl,sr) Node range
// a[i] = val, l <= i < r
void updateEq(int l,int r,ll val,int v = 1,int sl = 0,int sr = n){
    if(l>=sr || r<=sl )
        return;
    if(sl>=l && sr<=r){
        pushEq(sl,sr,v,val);
        return ;
    }

    propagate(sl,sr,v);

    int m = (sl+sr)>>1;
    updateEq(l,r,val,v<<1,sl,m);
    updateEq(l,r,val,v<<1|1,m,sr);
    mergeC(v);
}

// a[i] = a[i]+val, l <=i <r 
void updateSum(int l,int r,ll val,int v = 1,int sl = 0,int sr = n){
    if(l>=sr || r<=sl)
        return ;
    if(sl>=l && sr<=r){
        pushSum(sl,sr,v,val);
        return ;
    }
    propagate(sl,sr,v);

    int m = (sl+sr)>>1;
    updateSum(l,r,val,v<<1,sl,m);
    updateSum(l,r,val,v<<1|1,m,sr);
    mergeC(v);
}


ll querySum(int l,int r,int v = 1,int sl = 0,int sr = n){
    if(r<=sl || sr<=l)
        return 0;

    if(sl>=l && sr<=r){
        return tree[v].sum;
    }

    propagate(sl,sr,v);

    int m = (sl+sr)>>1;
    return querySum(l,r,v<<1,sl,m)+querySum(l,r,v<<1|1,m,sr);
}


ll  queryMax(int l,int r,int v = 1,int sl = 0,int sr = n){
    if(r<=sl || sr<=l)
        return 0;

    if(sl>=l && sr<=r)
        return tree[v].max;

    propagate(sl,sr,v);

    int m = (sl+sr)>>1;
    return max(querySum(l,r,v<<1,sl,m),querySum(l,r,v<<1|1,m,sr));
}


ll queryMin(int l,int r,int v = 1,int sl = 0,int sr = n){
    if(r<=sl || sr<=l)
        return 0;

    if(sl>=l && sr<=r)
        return tree[v].min;

    propagate(sl,sr,v);

    int m = (sl+sr)>>1;
    return min(querySum(l,r,v<<1,sl,m),querySum(l,r,v<<1|1,m,sr));
}

void print(){
    for(int i = 0;i<n;i++){
        cout<<querySum(i,i+1)<<" ";
    }
    cout<<endl;
}

signed main(){__
    int T = 1,x,val,p;
    cin>>n;
    vector<int> nums(n);
    for(auto &c:nums)cin>>c;
    build(nums);
    int q;
    cin>>q;
    while(q--){
        cin>>p;
        if(p ==1){
            cin>>x>>val;
            x--;
            updateEq(x,x+1,val);
        }
        else{
            cin>>val;
            updateMax(0,n,val);
        }
    }
    for(int i = 0;i<n;i++){
        cout<<querySum(i,i+1)<<" ";
    }
    cout<<endl;
    return 0;
}