#include <iostream>
using namespace std;
int RM[100001];
int idx=0;

struct Node{
    int cnt;
    int l,r;
    Node (int x , int y , int z){
        cnt = x ;
        l = y ;
        r = z;
    }
    Node (){
        cnt=   0 ;
        l  =  -1 ;
        r  =  -1;
    }
}tree[8600001];


int build(int L,int R){
	++idx;
	int x = idx;
	if(L ==R)
		return x;
	tree[x].l = buil(L,mid(L,R));
	tree[x].r = buil(mid(L,R)+1,R);
	return x;
}

int update(int L , int R , int root , int qidx ){
    if(R<qidx||L>qidx)
        return root;
    ++idx;
    int x = idx;
    if( R==qidx && L==qidx){
        tree[x] = Node(tree[root].cnt+1,-1,-1);
        return x;
    }
    tree[x] = Node(tree[root].cnt+1,update(L,mid(L,R),tree[root].l,qidx),update(mid(L,R)+1,R,tree[root].r,qidx));
    return x;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,q;
	cin>>n>>q;
	vector<int> A(N+1),V;
	vector < int > B(N+1);
    vector < int > root(N+1);
	A[0] = 0;
	for(int i = 1;i<=n;i++){	
		cin>>A[i];
		V.push_back(A[i]);
	}
	sort(V.begin(),V.end());
	for(int i = 0;i<N;i++){
		B[i] = lower_bound(V.begin(),V.end(),A[i]-V.begin())
		RM[B[i]] = A[i];
	}
	root[0] = build(0,N-1);
	for(int i = 0;i<=N;i++){
		root[i] = update(0,N-1,root[i-1],B[i]);
	}
	for(int i= 0;i<M;i++){
		cin>>x>>y>>z;
		cout<<RM[query(0,N-1,root[x-1],root[y],z)]<<'\n';
	}

	return 0;
}