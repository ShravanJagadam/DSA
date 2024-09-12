/*Complete Binary Tree 
Given an array of unique elements, construct a Binary Search Tree and check if it is a Complete Binary Tree [CBT]. In a Complete Binary Tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible.



Input Format

The first line of input contains T - the number of test cases. It is followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - value of the nodes.



Output Format

For each test case, print "Yes" if it is a Complete Binary Search Tree, "No" otherwise, separated by a newline.



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

4 2 5 3 1

7

4 5 15 0 1 7 17



Output

No

Yes

No



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
bool checkCBT(Node* root){
    
    queue<Node*> q;
    q.push(root); 
    while(q.size() != 0){
        Node* t = q.front();
        q.pop();

        if(t != NULL){
            q.push(t->left);
            q.push(t->right);
        }
        else{//everything in the queue from this point must be NULL,else it is not a CBT
            while(q.size() != 0){
                if(q.front() != NULL)
                    return false;
                q.pop();
            }
        }
    }
    return true;
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
        
        cout<<(checkCBT(root) ? "Yes" : "No")<<endl;
    
    }
    return 0;
}

/*
Approach: Just do a BFS traversal, if the node is not NULL
insert it into the queue, 
Once the popped element is NULL from the queue, then all the elements from that 
point in the queue must be NULL else it is not a CBT*/