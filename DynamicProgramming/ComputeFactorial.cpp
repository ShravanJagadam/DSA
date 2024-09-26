/*Compute Factorial 
Given a number N, print N!.



Input Format

The first line of input contains T - number of test cases. It's followed by T lines, each containing a single number N.



Output Format

For each test case, print N!. Since the result can be very large, print N! % 1000000007 [1e9+7].



Constraints

1 <= T <= 106

0 <= N <= 106



Example

Input

3

5

20

50



Output

120

146326063

318608048



Explanation
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int k = 1e9+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli fact[1000000+1];
    fact[0] = 1;
 
    for(int i = 1; i<= 1000000; i++){
       
        fact[i] = (fact[i-1]%k * i ) % k;
        
    }
    
    lli t ; cin >> t;

    while(t--){
        int N ; cin >> N;
        cout<<fact[N]<<endl;
    }

    return 0;
}

//Value of N is t * N is so larege that we get TLE, hence we precompute all the factorials in hand 
//and then print each fact[N] in O(1) time.