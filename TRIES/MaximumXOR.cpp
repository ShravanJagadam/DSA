/*Maximum XOR 
Given an array of positive integers, find 2 elements such that their xor: a ^ b is maximum.



Input Format

The first line of input contains T - number of test cases. It's followed by 2T lines - the first line contains N: the size of the array. The second line contains N integers - the elements of the array.



Output Format

For each test case, print the value of the maximum xor, separated by new line.



Constraints

30 points

2 <= N <= 103



120 points

2 <= N <= 105



General Constraints

1 <= T <= 100

0 <= A[i] <= 106



Example

Input

2

3

12 15 9

5

13 11 35 3 32



Output

6

46



Explanation



Example 1:

You can form the following xor pairs:

12^15 = 3, 12^9 = 5, 15^9 = 6 : max = 6
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int msb_pos = log2(1000000);

class Node{
    public:
    Node* C[2];

    Node(){
        C[0] = NULL;
        C[1] = NULL;
    }
};

bool checkBit(int x , int i){
      
    return 1 & (x>>i);
}

void insert(Node* root, int x){         //forming the TRIE
    for(int i = msb_pos; i>=0; i--){

        int bitv = (checkBit(x,i))?1:0;
        if(root->C[bitv] == NULL)
            root->C[bitv] = new Node();
        root = root->C[bitv];
    }
}

int solve(Node* root,int a){            //

    int ans  = 0;
    for(int b = msb_pos; b>=0; b--){

        int bitv = checkBit(a,b)?1:0;
        
        if(root->C[1-bitv] != NULL){
            ans += (1<<b);
            root = root->C[1-bitv];
        }
        else
            root = root->C[bitv];
    }
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;
    while(t--){

        lli N; cin >> N;
        vector<int> ar(N);
        Node* root = new Node();
        for(int i =0; i<N; i++){
            cin >> ar[i];
            insert(root,ar[i]);
        }
        int res  = 0;
        for(int i =0;i<N; i++){
            res = max(res,solve(root,ar[i]));
        }
        cout<<res<<endl; 
    }

    return 0;
}

/*
Approach : 



BruteForece : try every possible pair and find the max XOR

Optimised 
based on the bit position in the binary representation of the nummber 
Contribution: 
    msb bit contributes the most to the XOR 
    then other bits on the right of msb contributions decreases by "/2" on to the right

1.Insert the binary representation of the numbers (msb bit on the top and the remaining bits on the right of msb towards the child nodes in the trie )

2.Then for everey element in the array "a[i]",

    for every bit in the element "ar[i]", 
    check if there is number with opposite bit at that position 
    checking can be done from the trie 
    thus calculate the the XOR for each element and take the max

*/