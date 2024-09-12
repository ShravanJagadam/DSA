/*
Check BST 
Given a binary tree with unique elements, check if it's a Binary Search Tree.

The input is given in the form of a complete binary tree, represented using an array. Assuming the array index starts from 1, the root will be at index 1. For every index i, its child nodes will be at 2i and 2i+1.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines. The first line of each test case contains N - the number of nodes in the tree. The next line contains N integers - nodes of the binary tree in the form of a Complete Binary Tree.



Output Format

For each test case, print "True" if the given Binary Tree is a Binary Search Tree, "False" otherwise, separated by a newline.



Constraints

1 <= T <= 1000

1 <= N <= 1000

0 <= ar[i] <= 10000



Example

Input

5

11

92 10 963 5 334 928 973 2 9 263 860

9

156 153 6947 149 154 1761 7230 9 152

4

40 49 87 651

5

449 792 594 688 618

15

736 43 882 3 460 741 887 0 42 247 465 739 844 886 888



Output

False

True

False

False

True



Explanation



Self Explanatory
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int prv = INT_MIN;//global variable

class Node{
    public:
    int data; 
    int idx;
    Node* left; 
    Node* right;
    Node(int d,int i){
        data = d;
        idx = i;
        left = NULL;
        right = NULL;
    }
};

bool checkBST(Node* root){
    if(root == NULL)    return true;//InOrder traversal will give the sorted array of the nodes
    if(checkBST(root->left) == false) return false;

    if(root->data > prv)     prv = root->data;    
    else  return false;

    return checkBST(root->right);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){
        prv = INT_MIN;
        lli N; cin >> N;
        vector<int> v; 
        v.push_back(-1);
        for(int i =0;i<N; i++)
        {   int k ; cin >> k;
            v.push_back(k);
        }

        Node* root = new Node(v[1],1);

        queue<Node*> q; 
        q.push(root);

        while(q.size() != 0){
            Node* c = q.front(); 
            q.pop();
            int cur_i = c->idx;

            if(2*cur_i <= N){
                c->left = new Node(v[2*cur_i],2*cur_i);
                q.push(c->left);
            }
            if(2* cur_i + 1 <= N){
                c->right = new Node(v[2*cur_i+1],2*cur_i+1);
                q.push(c->right);
            }
        }
        
        cout<<(checkBST(root)?"True":"False")<<endl;
    }

    return 0;
}