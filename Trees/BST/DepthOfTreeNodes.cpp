/*
Depth of Tree Nodes 
Given an array of unique elements, construct a Binary Search Tree and for every node, print the depth of that node.



Input Format

The first line of input contains T - the number of test cases. It is followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - value of the nodes.



Output Format

For each test case, print the depth of every node of the Binary Search Tree, separated by a newline.



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

0 1 2 3 4

0 1 1 2 2

0 1 2 1 2 3 3



Explanation



Self Explanatory*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
class Node{
    public:
    int data,depth; 
    Node* left; 
    Node* right;
    Node(int d, int dep){
        data  = d;
        depth = dep;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int x){
    if(root == NULL)
        return new Node(x,-1);
    
    if(x > root->data)
        root->right = insert(root->right,x);
    if(x < root->data)
        root->left = insert(root->left, x);
    return root;
}

void fillDepth(Node* root,int dep){
    if(root == NULL)
        return;
    root->depth = dep;
    fillDepth(root->left,dep+1);
    fillDepth(root->right,dep+1);
    
}

void getDepth(Node* root, unordered_map<int,int> & mp){
    if(root == NULL)
        return; 
    mp[root->data] = root->depth;
    getDepth(root->left,mp);
    getDepth(root->right,mp);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        Node* root = NULL;
        vector<int> node;
        int x;
        for(int i =0; i<N; i++)
        {
            cin >> x;
            node.push_back(x);
            root = insert(root,x);
            
        }
        
        fillDepth(root,0);

        unordered_map<int,int> mp;
        getDepth(root,mp);

        for(int x : node)
            cout<<mp[x]<<" ";
        cout<<endl;

    }

    return 0;
}

//Can we do it without using extra space.