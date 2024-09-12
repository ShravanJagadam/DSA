/*
Vertical Order Traversal 
Given an array of unique elements, construct a Binary Search Tree and print the tree in a Vertical Order, starting from the left-most node. Print the nodes in each vertical in sorted order.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - value of the nodes.



Output Format

For each test case, print the Vertical Levels of the Binary Search Tree, separate each level by newline. Separate the output of different test cases with an extra newline.



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

3 1 2 5 4

7

4 5 15 0 1 7 17



Output

1

2

3

4

5



1

2 3 4

5



0

1 4

5 7

15

17



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
void verticalOrder(Node* root, map<int,vector<int> > &mp, int v){
    if(root == NULL) return;

    mp[v].push_back(root->data);

    verticalOrder(root->left,mp,v-1);
    verticalOrder(root->right,mp,v+1);
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
        int v  = 0;//vertical level
        verticalOrder(root,mp,v);
        for(auto x : mp) //x is {k,v}
        {
            vector<int> ls = x.second;
            sort(ls.begin(), ls.end());
            for(auto y : ls)//y is v
                cout<<y<<" ";
            cout<<endl;
        }
        cout<<endl;
        
    }
    return 0;
}
/*
Approach : 
Maintain a map {level, element of that level}
traverse on the tree and fill the map 
traverse on the map and print
*/