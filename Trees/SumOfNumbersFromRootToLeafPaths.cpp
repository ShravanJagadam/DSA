/*
Given an array of unique elements, construct a Binary Search Tree and print the sum of all the numbers formed along the path from the root node to the leaf nodes.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines. The first line of each test case contains N - the number of nodes in the BST. The next line contains N unique integers - value of the nodes.



Output Format

For each test case, print the sum separated by a newline. Since the output can be very large, print output % 1000000007.



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

4 5 15 2 1 7 17



Output

12345

666

497095



Explanation



Example 1:

Total Sum = 12345



Example 2:

Total Sum = 321 + 345 = 666



Example 3:

Total Sum = 421 + 45157 + 451517 = 497095*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli k = 1e9+7;

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

lli digit(lli x){
    lli c = 0;
    if(x == 0)
        return 1;
    while(x){  
        c++;
        x = x/10;
    }
    return c;
}

lli getSum(Node* root, lli val){
    if(root == NULL)                            //edge case : when the node value itself is "0".
        return 0;
    lli d = digit(root->data);//5
    lli b =  pow(10LL,d)  ;//100000
    val = ( (val * b%k )%k   + root->data  )%k;

    if(root->left == NULL && root->right == NULL)
        return val;
    return ( (getSum(root->left,val)  )%k + (getSum(root->right,val))%k )%k   ;

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
        cout<<getSum(root,0)<<endl;

    }
    return 0;
}