/*
Left View of Tree 
Given an array of unique elements, construct a Binary Search Tree and print the left-view of the tree. The left view of a tree is the set of nodes visible when the tree is viewed from the left side.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - value of the nodes.



Output Format

For each test case, print the left-view of the Binary Search Tree, separated by a newline.



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

3 2 1

4 0 1 7



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

        queue<Node*> q; 
        q.push(root); 
        int sz;
        while(q.size() != 0){
            sz = q.size(); 
            for(int i =0;i<sz; i++){
                Node* k = q.front(); 
                q.pop(); 
                if(k->left != NULL) q.push(k->left);
                if(k->right != NULL) q.push(k->right);
                if(i==0)    
                    cout<<k->data<<" ";
            }

        }
        cout<<endl;
    }
    return 0;
}

/*
Approach : just do the level order traversal 
print only the first element at each level*/