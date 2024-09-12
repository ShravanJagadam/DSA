/*
String Modulo 
You are given 2 numbers N & P. Print N % P.



Input Format

The first line of input contains T - the number of test cases. It's followed by T lines, each line contains 2 numbers N and P, separated by space.



Output Format

For each test case, print the value of N % P, separated by a new line.



Constraints

20 points

1 <= T <= 100

1 <= N <= 1018

1 <= P <= 108



80 points

1 <= T <= 100

1 <= N <= 1010000

1 <= P <= 1015



Example

Input

4

5 2

4 10

1085377843 81765943

8290826691135830692772803 95972011



Output

1

4

22420584

60316167



Explanation



Self Explanatory*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;
    string  N;
    lli P;
    while(t--){

        cin >> N >> P;
        
        lli res = 0;
        for(int i =0;i<N.size(); i++){
           
            res = (res * 10 + (N[i]-'0'))%P;
        }
        cout<< res<<endl;
      
    }

    return 0;
}

/*
Approach : 
Modulo power for large numbers represented as strings
The idea is to process all digits one by one and use the property that 

xy (mod a) ? ((x (mod a) * 10) + (y (mod a))) mod a

where, x : left-most digit

y: rest of the digits except x.


*/