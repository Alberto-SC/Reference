#include <bits/stdc++.h>
using namespace std;
typedef struct Treap Treap;
#define MAX 987654321

struct Treap {
    int val, heap, sort;
    Treap * left, * right, * parent;
};

Treap * findCeiling(Treap * root, int sort) {
    if (root == NULL) return NULL;
    Treap * ret = NULL;
    if (root->sort >= sort) {
        ret = findCeiling(root->left, sort);
        if (ret == NULL)
            ret = root;
    } else {
        ret = findCeiling(root->right, sort);
    }
    return ret;
}

void rotateLeft(Treap * node) {
    Treap * child = node->right;
    Treap * par = node->parent;
    Treap * gc = child->left;
    if (gc != NULL)
        gc->parent = node; // 1
    node->right = gc; // 2

    node->parent = child; // 3
    child->left = node; // 4

    child->parent = par; // 5
    if (par != NULL) {
        if (par->left == node)
            par->left = child; // 6
        else
            par->right = child; // 6
    }
}

void rotateRight(Treap * node) {
    Treap * child = node->left;
    Treap * par = node->parent;
    Treap * gc = child->right;
    if (gc != NULL)
        gc->parent = node; // 1
    node->left = gc; // 2

    node->parent = child; // 3
    child->right = node; // 4

    child->parent = par; // 5
    if (par != NULL) {
        if (par->left == node)
            par->left = child; // 6
        else
            par->right = child; // 6
    }
}

void percDown(Treap * node) {
    if (node->left != NULL && node->left->heap < node->heap) {
        if (node->right != NULL && node->right->heap < node->left->heap) {
            rotateLeft(node);
            percDown(node);
        } else {
            rotateRight(node);
            percDown(node);
        }
    } else if (node->right != NULL && node->right->heap < node->heap) {
        rotateLeft(node);
        percDown(node);
    }
}

Treap * newNode(int sort, int ans) {
    Treap * ret =(Treap*) calloc(1, sizeof(Treap));
    ret->sort = sort;
    ret->val = ans;
    ret->heap = rand() % MAX;
    ret->right = NULL;
    ret->left = NULL;
    ret->parent = NULL;
    return ret;
}

Treap * findLower(Treap * root, int sort) {
    if (root == NULL) return NULL;
    if (root->sort < sort) {
        Treap * tans = findLower(root->right, sort);
        if (tans == NULL) return root;
        return tans;
    }
    return findLower(root->left, sort);
}

Treap * getRoot(Treap * root) {
    while (root->parent != NULL) 
        root = root->parent;
    return root;
}

void removeTreap(Treap * root) {
    root->heap = MAX;
    percDown(root);
    Treap * par = root->parent;
    if (par != NULL) {
        if (par->right == root) {
            par->right = NULL;
        } else {
            par->left = NULL;
        }
    }
    free(root);
}

Treap * removeCeiling(Treap * root, int sort) {
    Treap * ceiling = findCeiling(root, sort);
    if (ceiling == NULL) {
        return root;
    }
    Treap * tmp = ceiling->left;
    if (tmp == NULL)
        tmp = ceiling->right;
    if (tmp == NULL)
        tmp = ceiling->parent;
    removeTreap(ceiling);
    return getRoot(tmp);
}

void recAdd(Treap * root, Treap * newNode) {
    if (root->sort < newNode->sort) {
        if (root->right == NULL) {
            newNode->parent = root;
            root->right = newNode;
            return;
        }
        recAdd(root->right, newNode);
    } else {
        if (root->left == NULL) {
            newNode->parent = root;
            root->left = newNode;
            return;
        }
        recAdd(root->left, newNode);
    }
}

void percUp(Treap * node) {
    while (node->parent != NULL && node->parent->heap > node->heap) {
        if (node->parent->right == node)
            rotateLeft(node->parent);
        else
            rotateRight(node->parent);
    }
}

Treap * addTreap(Treap * root, Treap * newNode) {
    recAdd(root, newNode);
    percUp(newNode);
    return getRoot(root);
}

void printTree(Treap * root) {
    if (!root) return;
    printTree(root->left);
    printf("%d %d %d\n", root->heap, root->sort, root->val);
    printTree(root->right);
}

int lis(int * arr, int n) {
    srand(time(0));
    Treap * root = newNode(-1, 0);
    int max = 0;

    for (int i = 0; i < n; i++) {
        if (!i || arr[i] != arr[i - 1]) {
            root = removeCeiling(root, arr[i]);
            int val = findLower(root, arr[i])->val;
            root = addTreap(root, newNode(arr[i], val + 1));
        }
    }
    return findLower(root, n)->val;
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> copy(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
        copy[i] = arr[i];
    }
    sort(copy.begin(),copy.end());
    vector<int> uniques;
    int last = copy[0];
    uniques.push_back(last);
    for(int i = 0;i<n;i++){
        if(copy[i]!= last){
            last = copy[i];
            uniques.push_back(last);
        }
    }
    for(int i =0;i<n;i++)
        arr[i] = lower_bound(uniques.begin(),uniques.end(),arr[i])-uniques.begin();
    vector<int> minLoc(n);
    for (int i = n - 1; i >= 0; i--)
        minLoc[arr[i]] = i;
    for(auto c:arr)cout<<c<<" ";
    cout<<endl;
    for(auto c:minLoc)cout<<c<<" ";
    cout<<endl;

    vector<int> stk(n+3);
    for(int i= 0;i<n;i++){
        stk[++stk[0]] = i;
        while(stk[stk[0]]>minLoc[arr[i]])
            stk[0]--;
    }
    stk[++stk[0]] = n;
    for(auto c:stk)cout<<c<<" ";
    cout<<endl;
    // int * stk = calloc(n + 3, sizeof(int));
    // for (int i = 0; i < n; i++) { njm 
    //     stk[++stk[0]] = i;
    //     while (stk[stk[0]] > minLoc[arr[i]])
    //         stk[0]--;
    // }
    // stk[++stk[0]] = n;
    // int groups = 0;
    // for (int i = 0; i < n; i++)
    //     if (groups < arr[i] + 1)
    //         groups = arr[i] + 1;
    // for (int i = 0; i < n; i++)
    //     arr[i] = n - arr[i];
    // for (int i = 1; i < stk[0]; i++) 
    //     sort(arr + stk[i], stk[i + 1] - stk[i]);
    // for (int i = 0; i < n; i++)
    //     arr[i] = n - arr[i];

    // int ans = lis(arr, n);
    // out32(groups - ans);

    // free(stk);
    // free(arr);
    // free(minLoc);
    return 0;
}
