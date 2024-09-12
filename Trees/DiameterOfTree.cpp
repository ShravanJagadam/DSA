/*
Diameter of a Tree 
Given an array of unique elements, construct a Binary Search Tree and find the diameter of the tree. Diameter is defined as the number of nodes on the longest path between 2 nodes of the tree.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - the value of the nodes.



Output Format

For each test case, print the diameter of the Binary Search Tree, separated by a newline.



Constraints

1 <= T <= 1000

1 <= N <= 5000

0 <= ar[i] <= 10000



Example

Input

3

5

1 2 3 4 5 

5

2 4 3 1 5 

7

4 5 15 0 1 7 17



Output

5

4

6



Explanation



Self Explanatory
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int res;

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


int diameterOfTree(Node* root){
    if(root == NULL)    return 0;

    int l = diameterOfTree(root->left);
    int r = diameterOfTree(root->right);

    int curr_ans = l + r + 1;
    res = max(res,curr_ans);

    return max(l,r) + 1; 
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
        res  = 0;
        
        int x  = diameterOfTree(root);
        cout<<res<<endl;
    }
    return 0;
}
/*
we are considering all the subtrees 
having each node as the root node and updating the "res"

and we are passing only the max length (either from left or from right ) to 

its previous node.
*/