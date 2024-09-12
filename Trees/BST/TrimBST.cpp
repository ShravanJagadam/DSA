/*
    Trim BST 
You are given two integers L, R, and an array of unique elements, construct a Binary Search Tree from the array, and then trim the BST in a manner such that all its elements lie between [L, R].

Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant).



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines. The first line of each test case contains three integers, N - the number of nodes in the BST, L - the lower limit of the range, and R - the upper limit of the range. The next line contains N unique integers - value of the nodes.



Output Format

For each test case, print the preorder traversal of the trimmed tree, separated by a newline.



Constraints

1 <= T <= 1000

1 <= N <= 1000

0 <= ar[i] <= 10000



Example

Input

3

5 2 4

1 2 3 4 5

5 1 4

3 2 4 1 5

7 2 10

4 5 15 0 1 7 17



Output

2 3 4

3 2 1 4

4 5 7



Explanation



Self Explanatory.*/

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

Node* trim(Node* root, int L , int R){
    if(root == NULL)
        return root;
    if(root->data < L)
        return trim(root->right,L,R);
    if(root->data > R)
        return trim(root->left,L,R);
    root->left  = trim(root->left,L,R);//if root is valid, then we trim the left subtree and attach it to left of the root
    root->right = trim(root->right,L,R);//and also trim the right subtree and attach it to the right of the root
    return root;
    
}

void preOrder(Node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t; cin >> t;

    while(t--){
        int N,L,R; cin >> N >>L >>R; 

        Node* root = NULL;

        while(N--){

            int k; cin >> k; 
            root = insert(root,k);
        }
        Node* k = trim(root,L,R);
        preOrder(k);
        cout<<endl;
    }
    return 0;
}