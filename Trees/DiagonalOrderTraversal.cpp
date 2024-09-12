/*Diagonal Order Traversal 
Given an array of unique elements, construct a Binary Search Tree and print the tree in a Diagonal Order, starting from the root node. Print the nodes in each diagonal in descending order.



Input Format

The First line of input contains T - number of test cases. It is followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.



Output Format

For each test case, print the Diagonal Levels of the Binary Search Tree, separate each level by newline.



Constraints

1 <= T <= 103

1 <= N <= 103

0 <= ar[i] <= 104



Example

Input

2

5

3 2 4 1 5

7

4 5 15 0 1 7 17



Output

3 2 1

4

5



4 0

5 1

15 7

17



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


void DOT(Node* root, int v, map<int,vector<int>> &mp){
    if(root == NULL)    return;

    mp[v].push_back(root->data);
    DOT(root->left,v,mp);
    DOT(root->right,v+1,mp);
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
        map<int,vector<int>> mp;
        DOT(root,0,mp);

        for(auto x : mp){

            vector<int> ls = x.second;
            sort(ls.begin(), ls.end(),greater<int>() );
            for(auto y : ls)
                cout<<y<<" ";
            cout<<endl;
        }
        cout<<endl;
        
    }
    return 0;
}

/*
Approach : 
Same as vertical order but

consider a curr node at vertical level 0
then its left "curr->left " as also at level 0
and its curr->left is also at level 0
so on.....

It's right element is on the next vertical level 
and this node left is also on same lvel

Essentially: 
curr , curr->left, curr->left ->left ......are on all same level.


*/