/*
Top View of Tree 
Given an array of unique elements, construct a Binary Search Tree and print the top-view of the tree. The top view of a tree is the set of nodes visible when the tree is viewed from the top.



Input Format

Given an array of unique elements, construct a Binary Search Tree and print the top-view of the tree. The top view of a Tree is the set of nodes visible when the tree is viewed from the top.



The first line of input contains T - the number of test cases. It is followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - the value of the nodes.



Output Format

For each test case, print the top view of the Binary Search Tree, separated by a new line. Print the set of visible nodes from left to right.



Constraints

1 <= T <= 1000

1 <= N <= 1000

0 <= ar[i] <= 10000



Example

Input

3

6

10 20 13 3 17 18 

6

10 3 20 15 14 12 

7

10 3 8 20 7 6 4 



Output

3 10 20 18 

12 3 10 20 

4 6 3 10 20 



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


void TV1(Node* root,int v,int d,map<int,pair<int,int> > &mp){
    if(root == NULL)    return;

    if(mp.find(v) != mp.end()){     //entry for a vertical level is already present
        if(mp[v].second > d)          //if the current node has less depth
            mp[v] = {root->data,d};
    }
    else{
        mp[v] = {root->data, d};
    }

    TV1(root->left,v-1,d+1,mp);
    TV1(root->right,v+1,d+1,mp);
}

void TV2(Node* root, map<int,int> &mp){

    queue<pair<Node*,int>>q;    //{Node,its vertical level}
    q.push({root,0});

    while(q.size() != 0){
        pair<Node*,int> k = q.front(); 
        q.pop(); 

        if(mp.find(k.second) == mp.end())
            mp[k.second] = k.first->data;
        if(k.first->left != NULL)
            q.push({k.first->left,k.second-1});
        if(k.first->right != NULL)
            q.push({k.first->right,k.second+1});
    }
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
        /*Approach 1 : vertical Order traversal + depth + map(level ,{element,depth})
        map<int,pair<int,int> > mp;//(vertical level :{element , depth})
        //just do the level order traversal
        TV1(root,0,0,mp);

        for(auto x : mp){

            cout<<x.second.first<<" ";
        }
        cout<<endl;   */

        //Approach2 : level Order traversal + depth 
        //In the queue in push the pair {element , vertical level} 
        map<int,int> mp;    
        TV2(root,mp);
        for(auto x : mp)//{level,ele}
        {
            cout<<x.second<<" ";
        }
        cout<<endl;

    }
    return 0;
}

/*
Approach 1 : 

1.Vertical Order Traversal + depth + map storing {vertical level, {element,depth of the element}}

->For a particular level "v" we keep only the element that has less depth 

->At each node at a particular level,
    if(entry is not present for that level , just insert into the map)

    if(entry is present and the current  node's depth is less than the depth of the element at the level present already in the map)
        we replace the entry with {curr_element,its depth}
    

Approach 2 : while we do level order traversal for each vertical level we

    visit the top nodes first .Based on this fact , we just do the level order 

    traversal 

    ->For each node we push {Node,vertical level } in the queue.

*/