/*Preorder Inorder to Postorder 
Given the preorder and inorder traversals of a binary tree with unique elements, print the PostOrder Traversals of the tree.



Input Format

The first line of input contains T - the number of test cases. It's followed by 3T lines. The first line of each test case contains N - the number of nodes in the BST. The second line contains N unique integers denoting the preorder traversal of the tree. The third line contains N unique integers denoting the inorder traversal of the tree.



Output Format

For each test case, print the PostOrder Traversal of the Binary Tree, separated by a newline.



Constraints

1 <= T <= 1000

1 <= N <= 1000

0 <= ar[i] <= 10000



Example

Input

3

7

1 2 4 5 3 6 7

4 2 5 1 6 3 7

10

8 5 9 7 1 12 2 4 11 3

9 5 1 7 2 12 8 4 3 11

9

2 7 3 6 8 11 5 9 4

3 7 8 6 11 2 5 4 9



Output

4 5 2 6 7 3 1

9 1 2 12 7 5 3 11 4 8

3 8 11 6 7 4 9 5 2



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

int idx = 0;//global variable
Node* BST(int pre[],int In[],int l,int h,unordered_map<int,int> &mp){
    if(l > h)
        return NULL;

    int pos = mp[pre[idx]]; 

    Node* x = new Node(pre[idx]);
    idx++;

    x->left = BST(pre,In,l,pos-1,mp);
    x->right = BST(pre,In,pos+1,h,mp); 
    return x;
}

void postOrder(Node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


//BST2 : Approach 2 : print the postOrder without constructing the binary tree

void BST2(int pre[], int In[], int l,int h, unordered_map<int,int> &mp){

    if(l > h)
        return;
    
    int pos = mp[pre[idx]];

    idx++;

    BST2(pre,In,l,pos-1,mp);
    BST2(pre,In,pos+1,h,mp);
    cout<<In[pos]<<" ";//we cannot use here pre[idx] because idx has incremmented to a undesired value
}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        idx  = 0;

        lli N; cin >> N;
        int pre[N], In[N];
        unordered_map<int,int>mp;

        for(int i =0;i<N; i++) cin >>  pre[i];

        for(int j =0;j<N; j++){
            cin >> In[j];
            mp[In[j]] = j;
        }
        int l = 0, h = N-1;
        /*Approach 1 :
        Node* root = NULL;
        root  = BST(pre,In,l,h,mp);
        //PostOrder printing 
        postOrder(root);
        cout<<endl;*/

        //Approach 2 : directly print the postOrder without constructing the tree
        BST2(pre,In,l,h,mp);
        cout<<endl;



    }

    return 0;
}

/*
Approach 1 : Construct a BST and then print PostOrder



1.First element of the preOrder is the root node
2.for each element in the pre, find the position of the valu in In and 
the elements on the left of pos will lie on the left of pre[i] and the elements on the right of 
pos will lie on the right of pre[i] in the BST

To get the position we can use 
1.Linear search on the In OR  -->O(N)
2.store the indices of the elements of Inorder in hashmap{element,idx}
get the index of the element from the map -->O(1)


Approach 2 : Directly print the PostOrder


In both the approaches we used the "idx " as a global variable.
*/