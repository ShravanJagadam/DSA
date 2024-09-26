/*Binary Strings without Adjacent 1s 
Find the number of binary strings of length N, such that there are no adjacent 1s in that string.



Input Format

The first line of input contains T - number of test cases. It is followed by T lines, each line contains N - length of the binary string.



Output Format

For each test case, print the number of binary strings of length N, separated by new line. Since the answer can be very large, print answer % 1000000007 [1e9+7].



Constraints

1 <= T <= 105

1 <= N <= 105



Example

Input

5

3

11

7

5

500



Output

5

233

34

13

73724597



Explanation



Example 1:

You can construct the following binary strings of length 3 with no adjacent 1s:

000, 001, 010, 100, 101
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int k = 1e9+7;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli dp0[100000+1];//string that ends with 0
    lli dp1[100000+1]; //string that ends with 1

    dp0[0] = 0;//dp0[i] -->No of valid binarystrings that ends with 0 at ith index.
    dp1[0] = 0;//dp1[i] --> No of valid binarystrings that ends with 1 at ith index.

    dp0[1] = 1;
    dp1[1] = 1; 

    dp0[2] = 2;
    dp1[2] = 1;

    for(int i = 3;i<=100000; i++){
        dp0[i] = (dp0[i-1] + dp1[i-1])%k;
        dp1[i] = dp0[i-1];
    }
    
    
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        
        cout<<(dp0[N] + dp1[N])%k<<endl;

        
        






    }

    return 0;
}


/*
Another way to approach this question 

-->we can append '0' safely to any valid binary string
-->But we can append '1' only to the strings of len "i-1" that have "0 at its previous position
i.e is we can append "01" to strings of len i-2 

*/