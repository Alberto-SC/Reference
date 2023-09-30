#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int lli;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);

template<typename T>
struct TreapNode{
	TreapNode<T> *left, *right;
	T value;
	int key, size;
	bool rev;
	T sum, add;

	TreapNode(T value = 0): value(value), key(rand()), size(1), left(NULL), right(NULL), sum(value), add(0), rev(false){}
};

template<typename T>
struct Treap{
	TreapNode<T> *root;
	Treap(): root(NULL) {}
	inline int nodeSize(TreapNode<T>* t){return t ? t->size: 0;}
	inline T nodeSum(TreapNode<T>* t){return t ? t->sum : 0;}
	inline void update(TreapNode<T>* &t){
		if(!t) return;
		t->size = 1 + nodeSize(t->left) + nodeSize(t->right);
		t->sum = t->value;
		push(t->left), push(t->right); 
		t->sum = t->value + nodeSum(t->left) + nodeSum(t->right);
	}

	int size(){return nodeSize(root);}

	void merge(TreapNode<T>* &t, TreapNode<T>* t1, TreapNode<T>* t2){
		if(!t1) t = t2;
		else if(!t2) t = t1;
		else if(t1->key > t2->key)
			merge(t1->right, t1->right, t2), t = t1;
		else
			merge(t2->left, t1, t2->left), t = t2;
		update(t);
	}

	void split(TreapNode<T>* t, T & x, TreapNode<T>* &t1, TreapNode<T>* &t2){
		if(!t)
			return void(t1 = t2 = NULL);
		if(x < t->value)
			split(t->left, x, t1, t->left), t2 = t;
		else
			split(t->right, x, t->right, t2), t1 = t;
		update(t);
	}

	void insert(TreapNode<T>* &t, TreapNode<T>* x){
		if(!t) t = x;
		else if(x->key > t->key)
			split(t, x->value, x->left, x->right), t = x;
		else
			insert(x->value < t->value ? t->left : t->right, x);
		update(t);
	}

	TreapNode<T>* search(T & x){
		TreapNode<T> *t = root;
		while(t){
			if(x == t->value) break;
			t = (x < t->value ? t->left : t->right);
		}
		return t;
	}

	void erase(TreapNode<T>* &t, T & x){
		if(!t) return;
		if(t->value == x)
			merge(t, t->left, t->right);
		else
			erase(x < t->value ? t->left : t->right, x);
		update(t);
	}

	void insert(T & x){insert(root, new TreapNode<T>(x));}

	void erase(T & x){erase(root, x);}

	void updateVal(T & old, T & New){
		if(search(old))
			erase(old), insert(New);
	}

	T kth(int i){
		assert(0 <= i && i < nodeSize(root));
		TreapNode<T> *t = root;
		while(i != nodeSize(t->left)){
			if(i < nodeSize(t->left)){
				t = t->left;
			}else{
				i -= nodeSize(t->left) + 1;
				t = t->right;
			}
		}
		return t->value;
	}

	int lessThan(T & x){
		int ans = 0;
		TreapNode<T> *t = root;
		while(t){
			if(x > t->value){
				ans += nodeSize(t->left) + 1;
				t = t->right;
			}else{
				t = t->left;
			}
		}
		return ans;
	}

	inline void push(TreapNode<T>* t){
		if(!t) return;
		if(t->add){
			t->value += t->add;
			t->sum += t->add * nodeSize(t);
			if(t->left) t->left->add += t->add;
			if(t->right) t->right->add += t->add;
			t->add = 0;
		}
		if(t->rev){
			swap(t->left, t->right);
			if(t->left) t->left->rev ^= true;
			if(t->right) t->right->rev ^= true;
			t->rev = false;
		}
	}

	void split2(TreapNode<T>* t, int i, TreapNode<T>* &t1, TreapNode<T>* &t2){
		if(!t)
			return void(t1 = t2 = NULL);
		push(t);
		int curr = nodeSize(t->left);
		if(i <= curr)
			split2(t->left, i, t1, t->left), t2 = t;
		else
			split2(t->right, i - curr - 1, t->right, t2), t1 = t;
		update(t);
	}

	inline int aleatorio(){
		return (rand() << 15) + rand();
	}

	void merge2(TreapNode<T>* &t, TreapNode<T>* t1, TreapNode<T>* t2){
		push(t1), push(t2);
		if(!t1) t = t2;
		else if(!t2) t = t1;
		else if(aleatorio() % (nodeSize(t1) + nodeSize(t2)) < nodeSize(t1))
			merge2(t1->right, t1->right, t2), t = t1;
		else
			merge2(t2->left, t1, t2->left), t = t2;
		update(t);
	}

	void insert_at(T & x, int i){
		if(i > nodeSize(root)) return;
		TreapNode<T> *t1 = NULL, *t2 = NULL;
		split2(root, i, t1, t2);
		merge2(root, t1, new TreapNode<T>(x));
		merge2(root, root, t2);
	}

	void erase_at(int i){
		if(i >= nodeSize(root)) return;
		TreapNode<T> *t1 = NULL, *t2 = NULL, *t3 = NULL;
		split2(root, i, t1, t2);
		split2(t2, 1, t2, t3);
		merge2(root, t1, t3);
	}

	void update_at(TreapNode<T>* t, T & x, int i){
		push(t);
		assert(0 <= i && i < nodeSize(t));
		int curr = nodeSize(t->left);
		if(i == curr)
			t->value = x;
		else if(i < curr)
			update_at(t->left, x, i);
		else
			update_at(t->right, x, i - curr - 1);
		update(t);
	}

	T nth(TreapNode<T>* t, int i){
		push(t);
		assert(0 <= i && i < nodeSize(t));
		int curr = nodeSize(t->left);
		if(i == curr)
			return t->value;
		else if(i < curr)
			return nth(t->left, i);
		else
			return nth(t->right, i - curr - 1);
	}

	void update_at(T & x, int i){update_at(root, x, i);}

	T nth(int i){return nth(root, i);}

	void add_update(T & val, int l, int r){
		TreapNode<T> *t1 = NULL, *t2 = NULL, *t3 = NULL;
		split2(root, l, t1, t2);
		split2(t2, r - l + 1, t2, t3);
		t2->add += val;
		merge2(root, t1, t2);
		merge2(root, root, t3);
	}

	void reverse_update(int l, int r){
		TreapNode<T> *t1 = NULL, *t2 = NULL, *t3 = NULL;
		split2(root, l, t1, t2);
		split2(t2, r - l + 1, t2, t3);
		t2->rev ^= true;
		merge2(root, t1, t2);
		merge2(root, root, t3);
	}

	void rotate_update(int k, int l, int r){
		TreapNode<T> *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
		split2(root, l, t1, t2);
		split2(t2, r - l + 1, t2, t3);
		k %= nodeSize(t2);
		split2(t2, nodeSize(t2) - k, t2, t4);
		merge2(root, t1, t4);
		merge2(root, root, t2);
		merge2(root, root, t3);
	}

	T sum_query(int l, int r){
		TreapNode<T> *t1 = NULL, *t2 = NULL, *t3 = NULL;
		split2(root, l, t1, t2);
		split2(t2, r - l + 1, t2, t3);
		T ans = nodeSum(t2);
		merge2(root, t1, t2);
		merge2(root, root, t3);
		return ans;
	}

	void inorder(TreapNode<T>* t){
		if(!t) return;
		push(t);
		inorder(t->left);
		cout << t->value << " ";
		inorder(t->right);
	}

	void inorder(){inorder(root);}
};
int main(){__
	srand(time(NULL));
	int t,l,r,n;
    cin>>t;
    while(t--){
        cin>>n;
	    Treap<int> *T = new Treap<int>();
        string s,t;
        cin>>s>>t;
        for(int i = 0;i<n;i++){
            int x = int(s[i]-'0');
            T->insert_at(x,i);
        }
        vector<int> operations;
        for(int i = n-1;i>=0;i--){
            int x,y;
            y = int(t[i]-'0');
            x = T->nth(i);
            x%=2;
            if(x == y)continue;
            int first = T->nth(0);
            first%=2;
            int val = 1;
            if(first == y){
                T->add_update(val,0,0);
                operations.push_back(1);
            }
            T->add_update(val,0,i);
            T->reverse_update(0,i);
            operations.push_back(i+1);
        }
        cout<<operations.size()<<" ";
        for(auto c:operations)cout<<c<<" ";
        cout<<endl;
    }
	return 0;
}