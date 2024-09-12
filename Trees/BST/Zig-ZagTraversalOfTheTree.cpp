/*
Zig-Zag Level Order of Tree 
Given an array of unique elements, construct a Binary Search Tree and print the Level Order of the tree in a zig-zag fashion. Assume the root is at level-1, zig-zag means that nodes at even levels will be printed left to right and the nodes at odd levels will be printed from right to left.



Input Format

The first line of input contains T - the number of test cases. It is followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - value of the nodes.



Output Format

For each test case, print the Level Order Traversal of the Binary Search Tree in a zig-zag fashion, separated by a newline.



Constraints

1 <= T <= 1000

1 <= N <= 1000

0 <= ar[i] <= 10000



Example

Input

3

5

1 2 3 4 5

5

3 2 4 1 5

7

4 5 15 0 1 7 17



Output

1 2 3 4 5

3 2 4 5 1

4 0 5 15 1 7 17



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

void LevelOrderTraversal2(Node* root){//Using queue size as separator for each level
    if(root == NULL)
        return; 
    queue<Node*> q;
    q.push(root);
   
    int xr = 1; 
    while(q.size() != 0){

        int sz = q.size();
        if(xr == 1){
             stack<int> st;
            while(sz--){
                Node* c = q.front(); q.pop();        
                st.push(c->data);
                if(c->left != NULL)
                    q.push(c->left);
                if(c->right != NULL)
                    q.push(c->right);
            }
            while(st.size() != 0){
                cout<<st.top()<<" ";
                st.pop();
            }
            xr = xr^1;
            
        }
        else{
            while(sz--){
                Node* c = q.front(); q.pop();        
                cout<<c->data<<" ";
                if(c->left != NULL)
                    q.push(c->left);
                if(c->right != NULL)
                    q.push(c->right);
            }
            xr = xr^1;
        }
        
        
    }
    cout<<endl;
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
        LevelOrderTraversal2(root);
    }
    return 0;
}