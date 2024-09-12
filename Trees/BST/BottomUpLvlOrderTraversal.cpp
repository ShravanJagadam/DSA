/*
Bottom-Up Level Order of Tree 
Given an array of unique elements, construct a Binary Search Tree and print the Level Order of the tree, not top-down, but bottom-up.



Input Format

The first line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.



Output Format

For each test case, print the bottom-up Level Order of the Binary Search Tree, separate each level by newline. Separate the output of different test cases with an extra newline.



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

5

4

3

2

1



1 5

2 4

3



7 17

1 15

0 5

4



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

void BottomUpLvlOrderTraversal(Node* root){

    queue<Node*> q;
    q.push(root);
    stack<int> st;
    while(q.size() != 0){

        int sz = q.size();

        while(sz--){
            Node* c = q.front();
            q.pop();
            st.push(c->data);
            if(c->right != NULL)
                q.push(c->right);
            if(c->left != NULL)
                q.push(c->left);
        
        }
        st.push(INT_MAX);
    }

    st.pop();//At the top of the stack there is an extra INT_MAX, hence we removed that
    while(st.size() != 0){

        if(st.top() != INT_MAX)
            cout<<st.top()<<" ";
        else
            cout<<endl;
        st.pop();
        
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
        BottomUpLvlOrderTraversal(root);
    }
    return 0;
}

/*
Approach : Used stack to store the LVL Order traversal and INTMAX as the level
separator
->Order of insertion of child nodes does matter*/