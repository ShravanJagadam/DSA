/*Compute nCr 
Given n and r, compute nCr.



Note:

Do not use BigInteger class, it defeats the purpose of the problem statement.



Input Format
The first line of input contains T - number of test cases. It is followed by T lines, each line contains 2 integers - N and R.



Output Format

For each test case, print the value of nCr, separated by new line. Since the number can be very large, print result % 1000000007.



Constraints

20 points

1 <= T <= 100

0 <= N, R <= 30



80 points

1 <= T <= 500000

0 <= N, R <= 2000



Example

Input

5

4 2

3 1

25 12

30 14

6 4



Output

6

3

5200300

145422675

15



Explanation



Self Explanatory
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int k = 1e9+7;

    

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli N=2000,R=2000; 
    int dp[2000+1][2000+1];//dp[i][j] -->No of ways of selecting the "j" elements from the first "i" elements 
    //Base case

    for(int j =0;j<=R; j++) //No of ways of selecting j items from 0 items
        dp[0][j] =0;
    
    for(int i =0;i<=N; i++)//No of ways of selecting 0 items from i items
        dp[i][0] = 1;
    
    for(int i =1; i<=N; i++){
        for(int j =1; j<=R; j++)
        {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%k;//(#ways select the ith item + do not select the ith item)
        }
    }
    lli t ; cin >> t;

    while(t--){
        int n,r;
        cin >> n>>r;
        cout<<dp[n][r]<<endl;

    }

    return 0;
}



/*
NcR = N-1 C R-1 + N-1 c R #ways (consider the Nth element + do not consider the Nth element)
*/