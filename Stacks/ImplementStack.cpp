/*
Implement Stack 
Implement the Stack data structure and perform push / pop operations.



Note:

Do not use any inbuilt functions / libraries for the Stack.



Input Format
The first line of input contains T - number of operations. It is followed by T lines, each line contains either "push x" or "pop".



Output Format

For each "pop" operation, print the popped element, separated by a newline. If the stack is empty, print "Empty".



Constraints

1 <= T <= 10000

-100 <= x <= 100



Example

Input

8

push 5

pop

pop

push 10

push -15

pop

push -10

pop



Output

5

Empty

-15

-10



Explanation

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int p = -1;
    int ar[1000]; 


    lli t ; cin >> t;
    while(t--){
        string s; cin >> s; 
        int k ;

        if(s == "push"){
            cin >> k; 
            ar[++p] = k;

        }
        else{

            if(p == -1)
                cout<<"Empty"<<endl;
            else    
                cout<<ar[p--]<<endl;
        }  
    } 
    return 0;
}

/*
Create an array of size N and a variable t intialzed to -1
int t = -1;
Each time you want to push an element 
push --> t++, ar[t] = x; 
pop -->t--;
size = t+1;


*/