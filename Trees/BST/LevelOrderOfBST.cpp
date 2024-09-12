/*
Level Order of Tree 
Given an array of unique elements, construct a Binary Search Tree and print the Level Order of the tree.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - value of the nodes.



Output Format

For each test case, print the Level Order of the Binary Search Tree, separate each level by a newline. Separate the output of different test cases with an extra newline.



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

1

2

3

4

5



3

2 4

1 5



4

0 5

1 15

7 17



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
void LevelOrderTraversal1(Node* root){//Using dummy NULL as separator for each level
    if(root == NULL)
        return; 
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size() != 0){
        Node* c = q.front(); q.pop();

        if(c == NULL) cout<<endl;

        if(c == NULL && q.size() != 0){
            q.push(NULL);
            continue;
        }
        else if(c == NULL && q.size() == 0)
            break;
            
       
        cout<<c->data<<" ";

        if(c->left != NULL)
            q.push(c->left);
        if(c->right != NULL)
            q.push(c->right);
    }
    cout<<endl;
}
void LevelOrderTraversal2(Node* root){//Using queue size as separator for each level
    if(root == NULL)
        return; 
    queue<Node*> q;
    q.push(root);
   

    while(q.size() != 0){

        int sz = q.size();

        while(sz--){
            Node* c = q.front(); q.pop();        
            cout<<c->data<<" ";
            if(c->left != NULL)
                q.push(c->left);
            if(c->right != NULL)
                q.push(c->right);
        }
        cout<<endl;
        
    }
    cout<<endl;
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
        //LevelOrderTraversal1(root);
        LevelOrderTraversal2(root);
        cout<<endl;
    }
    return 0;
}

/*
Approach1 : using the dummy NULL as a separator for each level , At the end this goes 
into infinite loop and insert NULL into the queue only when the size of the queue is not zero and break if the size is 0
Approach2 : Using the "count" as the separator for each level*/