#include <bits/stdc++.h>
 
using namespace std;

struct Node {
	int key;
	int sum; // La suma de las llaves que hay en el subarbol del nodo
	int priority;
	Node *l; // Hijo izquierdo
	Node *r; // Hijo derecho

	Node (int key, int priority) : key(key), sum(key), priority(priority), l(NULL), r(NULL) {}
};

void update (Node *T) {
	if (T != NULL) {
		T->sum = T->key;
		if (T->l != NULL) T->sum += T->l->sum;
		if (T->r != NULL) T->sum += T->r->sum;
	}
}

// Recibe el apuntor a las raices de T1 y T2, y devuelve un apuntador a la raiz del nuevo Treap
Node * merge (Node * T1, Node * T2) {
	if (T1 == NULL) return T2;
	if (T2 == NULL) return T1;

	if (T1->priority > T2->priority) {
		T1->r = merge(T1->r, T2);

		update(T1);
		return T1;
	} else {
		T2->l = merge(T1, T2->l);

		update(T2);
		return T2;
	}
}

// Recibe el apuntador a la raiz de T, y devuelve un apuntador a la raiz de T1 y un apuntador a la raiz de T2 en forma de pair
pair<Node*, Node*> split (Node *T, int x) {
	if (T == NULL) return {NULL, NULL};

	if (T->key < x) {
		Node *T1, *T2;
		tie(T1, T2) = split(T->r, x);
		T->r = T1;

		update(T);
		return {T, T2};
	} else {
		Node *T1, *T2;
		tie(T1, T2) = split(T->l, x);
		T->l = T2;

		update(T);
		return {T1, T};
	}
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> dis(numeric_limits<int>::min(), numeric_limits<int>::max());

// Recibe el apuntador a la raiz de T y la nueva llave x, y devuelve un apuntador a la raiz del nuevo treap.
Node * insert (Node *T, int x) {
	Node * TN = new Node(x, dis(rng)); // Prioridad va estar en el rango de [-2^31, 2^31)
	Node * T1, * T2;

	tie(T1, T2) = split(T, x);
	TN = merge(T1, TN);
	TN = merge(TN, T2);

	return TN;
}

// Recibe el apuntador a la raiz de T y la llave x que se quiere eliminar, y devuelve un apuntador a la raiz del nuevo treap
Node * erase (Node *T, int x) {
	Node * T1, * T2, * T3, * T4;

	tie(T1, T2) = split(T, x);
	tie(T3, T4) = split(T2, x + 1);

	return merge(T1, T4);
}

int main() {
	ios_base::sync_with_stdio(); cin.tie(0);
	
	
	return 0;
}
