/*
Full Binary Tree 
Given an array of unique elements, construct a Binary Search Tree and check if it is a Full Binary Tree [FBT]. A FBT is one in which each node is either a leaf or possesses exactly 2 child nodes.



Input Format

The first line of input contains T - the number of test cases. It is followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - value of the nodes.



Output Format

For each test case, print "True" if the Binary Search Tree is an FBT, "False" otherwise, separated by a newline.



Constraints

1 <= T <= 1000

1 <= N <= 1000

0 <= ar[i] <= 10000



Example

Input

3

5

1 2 3 4 5

11

8 3 30 15 40 18 12 17 25 1 7

7

4 5 15 0 1 7 17



Output

False

True

False



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
bool checkFBT(Node* root){

    if(root->left == NULL && root->right != NULL)
        return false;
    
    else if(root->left != NULL && root->right == NULL)
        return false;

    else if(root->left != NULL && root->right != NULL){
        return checkFBT(root->left) && checkFBT(root->right);
    }
    return true;    
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
        cout<<( checkFBT(root)?"True":"False" )<<endl;
    }
    return 0;
}
/*
Construct a BT and then check if each node has either 0 or 2 nodes */