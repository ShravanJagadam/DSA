/*Width of Tree 
Given an array of unique elements, construct a Binary Search Tree and find the width of the tree. The width of the tree is defined as the maximum distance between the vertical levels of any pair of nodes, where both the nodes belong to the same horizontal level.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - the value of the nodes.



Output Format

For each test case, print the width of the tree, separated by a newline.



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

0

4

2



Explanation



Self Explanatory
    */
    #include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

class Node{
public:
    int data;
    int vlvl;
    Node* left; 
    Node* right; 

    Node(int d){
        data = d; 
        vlvl = 0;
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

void fillVerticalLevel(Node* root, int lvl){
    if(root == NULL)    return; 
    root->vlvl = lvl;
    fillVerticalLevel(root->left,lvl-1);
    fillVerticalLevel(root->right,lvl+1);
}

int widthOfTree(Node* root){
    queue<Node*> q; 
    q.push(root);

    int sz,mn,mx;
    int res  = 0;

    while(q.size() != 0){
        
        sz = q.size();
        mn = INT_MAX;
        mx = INT_MIN;
        for(int i = 0; i<sz; i++){
            Node* k = q.front();
            q.pop();
            mn = min(mn,k->vlvl);
            mx = max(mx, k->vlvl);
            if(k->left != NULL) q.push(k->left);
            if(k->right != NULL) q.push(k->right);
        }
        
        res = max(res,mx - mn);
        
    }
    return res;
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
        fillVerticalLevel(root,0);
        //Do a level order traversal and at each level, get the max and min vertical level
        cout<<widthOfTree(root)<<endl;
    }
    return 0;
}
/*
Approach : Along with the node's  data, maintain the vertical level 
also for each node

->while doing the level order traversal 
At each level maintain the min and max vetical levels for all the nodes at that level


max - min vertical lvelel at all the horizontal levels is the width of the tree. 




*/