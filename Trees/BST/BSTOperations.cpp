/*
BST Operations 
You are given Q queries. Each query can be one of four types:



1 X: Insert an integer X into the binary search tree.
2 X: Delete X from the tree and replace it with the smallest value from its right sub-tree.
3 X: Print "Yes" if the value exists in the binary search tree, print "No" otherwise.
4: Print the Preorder traversal of the binary search tree.
Input Format

The first line of input contains T - the number of test cases.

The second line contains Q - the number of queries. The Q subsequent lines each contain 2 integers A - the type of query and X - the value to be processed in the query (except for query of type 4).



Output Format

For each test case, print the result, separated by a newline. For any query, if no result exists, print "null".



Constraints

1 <= T <= 100

1 <= Q <= 100

1 <= A <= 4

-105 <= X <= 105



Example

Input

2

8

1 4

1 2

1 6

1 8

2 2

3 3

4

3 1

7

1 5

1 7

1 3

4

3 3

2 3

3 3



Output

Case #1:

No

4 6 8

No

Case #2:

5 3 7

Yes

No



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


Node* insert(Node* root, int x){
    if(root == NULL)
        return new Node(x);

    if(x < root->data)
        root->left = insert(root->left,x);
    else if  (x > root->data)
        root->right = insert(root->right,x);
    return root;
    
}

int getSmall(Node* root){

    while(root->left != NULL){
        root = root->left;
    }
    return root->data;

}
Node* deleteN(Node* root, int x){//find the node wiht the value x and replace it with 

    //1.leaf nodes 2.node with single child 3.node with 2 children
    if(x < root->data)
        root->left = deleteN(root->left,x);
    else if( x > root->data)
        root->right = deleteN(root->right,x);
    else{// x = root->data, this node can be of any 3 types of below. 
    //1.leaf nodes 2.node with single child 3.node with 2 children
        if(root->left == NULL && root ->right == NULL)//leaf
            return NULL;
        else if(root->left == NULL && root->right != NULL){//node with single child 
            return root->right;
        }
        else if(root->left != NULL && root->right == NULL){
            return root->left;
        }
        else{
            //node with 2 child nodes
            //get the smallest element from the right subtree and replace the current nodes value wiht that 
            //and delte the that node.
            int val = getSmall(root->right);
            root->data = val;
            root->right = deleteN(root->right,root->data);
        }
    }
    return root;
}

bool search(Node* root,int x){
    if(root == NULL)
        return false;
    if(root->data < x)
        return search(root->right,x);
    if(root->data > x)
        return search(root->left, x);
    return true;
}

void preOrder(Node* root){
    //DLR
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;
    int tc = 1;
    while(t--){
        cout<<"Case #"<<tc++<<":"<<endl;
        int q; cin >> q; 
        Node* root = NULL;
        while(q--){

            int t,x ; cin >> t; 
            if(t == 1){
                cin >> x;
                root = insert(root,x);

            }
            else if (t == 2){
                cin >> x;
                root = deleteN(root,x);//replace the node to be deleted with smallest value from its right subtree

            }
            else if (t == 3){
                cin >> x;
                cout<<(search(root,x)?"Yes":"No")<<endl;

            }
            else{
                
                preOrder(root);
                cout<<endl;
            }
        }

    }

    return 0;
}