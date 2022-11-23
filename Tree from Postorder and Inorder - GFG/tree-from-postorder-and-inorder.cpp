//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

Node* func(int postorder[], int posSt, int posEd, int inorder[], int inSt, int inEd, map<int,int>& mp){
        if(posSt>posEd || inSt>inEd) return NULL;
        
        Node* root = new Node(postorder[posEd]);
        int ele = mp[root->data];
        int nEle = ele-inSt;
        
        root->left = func(postorder,posSt,posSt+nEle-1,inorder,inSt,ele-1,mp);
        root->right = func(postorder,posSt+nEle,posEd-1,inorder,ele+1,inEd,mp);
        
        return root;
    }
    
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int inorder[], int postorder[], int n) {
    // Your code here
    map<int,int> mp;
    for(int i=0;i<n;i++) mp[inorder[i]] = i;
    return func(postorder,0,n-1,inorder,0,n-1,mp);
}
