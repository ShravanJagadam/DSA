/*
Least Common Ancestor 
Given an array of unique elements, construct a Binary Search Tree. Now, given two nodes u and v of the BST, find their Lowest Common Ancestor (LCA). LCA is defined as the furthest node from the root that is an ancestor for both u and v.



Input Format

The first line of input contains T - the number of test cases. The first line of each test case contains N, Q - the number of nodes in the BST and the number of queries. The next line contains N unique integers - value of the nodes. It is followed by Q lines, each containing 2 nodes of the tree, u and v.



Output Format

For each test case, for each query print the LCA of the given nodes u and v, separated by space. Separate the output of different test cases with a newline.



Constraints

1 <= T <= 1000

1 <= N,Q <= 1000

0 <= ar[i] <= 10000



Example

Input

2

5 2

3 2 4 1 5

2 5

1 2

7 3

4 5 15 0 1 7 17

0 15

7 17

17 4



Output

3 2

4 15 4



Explanation



Self Explanatory*/


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

int LCA(Node* root,int u,int v){

    if(root->data < u && root->data < v)
        return LCA(root->right,u,v);
    else if (root->data > u && root->data > v )
        return LCA(root->left,u,v);
    
    return root->data;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t; cin >> t;

    while(t--){
        int N,Q; cin >> N >> Q; 

        Node* root = NULL;

        while(N--){

            int k; cin >> k; 
            root = insert(root,k);
        }

        int u,v;
        while(Q--){
            cin >> u >> v;
            int mu = min(u,v);
            int mv = max(u,v);
            cout<<LCA(root,mu,mv)<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}

/*
Approach : 

->As it is a BST 

There can be 3 cases 
    given nodes can be on the right side of current node
    or given nodes can be on the left side of the current node
    or smaller node can be on the left and larger node can be on the 
    right side of the current node      ->current node is LCA 
*/