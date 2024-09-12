/*
Height of Tree 
Given an array of unique elements, construct a Binary Search Tree and find the height of the tree.

Input Format

The first line of input contains T - the number of test cases. It is followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Output Format

For each test case, print the height of the Binary Search Tree, separated by a newline.

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

4

2

3

Explanation
Self Explanatory
*/

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

int height(Node* root){
    if(root == NULL)
        return -1;
    return 1 + max(height(root->left), height(root->right));
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
        cout<<height(root)<<endl;
    }
    return 0;
}

/*
We form the Binary tree and then find the height*/