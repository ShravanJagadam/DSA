/*Maximum Path Sum 
Given a binary tree with unique elements, find the maximum path sum of any non-empty path.

The input is given in form of a complete binary tree, represented using an array. Assuming array index start from 1, root will be at index 1. For every index i, its child nodes will be at 2i and 2i+1.



Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the tree. The next line contains N integers - nodes of the binary tree in the form of a Complete Binary Tree.



Output Format

For each test case, print the maximum path sum, separated by newline.



Constraints

30 points

1 <= T <= 100

1 <= N <= 100



70 points

1 <= T <= 103

1 <= N <= 104



General Constraints

-105 <= ar[i] <= 105



Example

Input

3

15

5 1 7 2 3 -1 13 4 8 9 20 14 -3 6 10

3

10 -1 8

7

5 1 3 2 4 0 6



Output

59

18

19



Explanation



Self Explanatory
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli res;

class Node{
    public:
    int data;
    int idx;
    Node* left; 
    Node* right; 

    Node(int d, int i){
        data = d;
        idx = i;
        left = NULL;
        right = NULL;
    }
};
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

lli maxSumPath(Node* root){
    
    if(root == NULL) return 0;

    lli l = maxSumPath(root->left);
    lli r = maxSumPath(root->right);

    lli curr_ans = l + r +  (root->data);
    res = max(res,curr_ans);

    return max (0ll, max(l,r)+root->data);//here we are handling the if the path sum is -ve

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N,x; cin >> N;
        vector<int> nodes; 
        nodes.push_back(-1);
        for(int i = 1; i <= N; i++){
            cin >> x; 
            nodes.push_back(x);
        }

        Node* root = new Node(nodes[1],1);
        queue<Node*> q; 
        q.push(root);

        while(q.size() != 0){       //Constructing the binary tree from the array 

            Node* k = q.front();
            q.pop();
            int idx = k->idx;
            if(2*idx <= N){
                k->left = new Node(nodes[2*idx], 2*idx);
                q.push(k->left);
            }
                
            if(2*idx + 1 <= N ){
                 k->right = new Node(nodes[2*idx+1], 2*idx+1);
                q.push(k->right);
            }
               
        }
        res = INT_MIN;//Making sure that atleast one node is considered incase if there are all -ve nodes
        maxSumPath(root);
        cout<<res<<endl;
        
        
    }

    return 0;
}