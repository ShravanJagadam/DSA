#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

class Node{
public:
    int data; 
    Node* left; 
    Node* right; 

    Node(int d){
        data = d; 
        left = NULL; 
        right = NULL;
    }
};


Node* insert(Node* root, int k){
    if(root == NULL)
        return new Node(k); 
    
    if(root->data < k){
        root->right = insert(root->right,k);
    }
    else if (root->data > k){
        root->left = insert(root->left,k);
    }
    return root;

}

void PreOrder(Node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(Node* root){
    if(root == NULL)
        return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void PostOrder(Node* root){
    if(root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t; cin >> t;

    while(t--){
        int N; cin >> N; 

        Node* root = NULL;

        while(N--){

            int k; cin >> k; 
            root = insert(root,k);
        }
        PreOrder(root);cout<<endl;
        InOrder(root);cout<<endl;
        PostOrder(root);cout<<endl;
        cout<<endl;
    }
    return 0;
}

/*Form a BST and then print the Pre,In,Post Order Traversals*/