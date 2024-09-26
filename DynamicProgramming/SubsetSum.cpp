/*
    Subset Sum 
Given a set of non-negative integers, and a value S, determine if there is a subset of the given set with sum equal to S.



Input Format

The first line of the input contains T - the number of test cases. It is followed by 2T lines - the first line of each test case contains N - number of elements in given array and S - the required sum. The second line contains elements of the array.



Output Format

For each test case, print "YES" if there is a subset of the given set with sum equal to given S, otherwise "NO", separated by new line .



Constraints

30 points

1 <= N <= 10

0 <= S <= 100



120 points

1 <= N <= 100

0 <= S <= 1000



General Constraints

1 <= T <= 100

0 <= A[i] <= 103



Example

Input

2

5 15

10 4 5 9 1

5 17

13 11 19 20 21



Output

YES

NO



Explanation



Example 1:

15 = 9 + 5 + 1



Example 2:

No such subset exists.*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N,S; cin >> N>>S;
        vector<int> ar(N);
        for(int i =0;i<N; i++) cin >> ar[i]; 

        //dp[i][j] --> is there a subset whose sum is "j" with the first "i" elements
        bool dp[N][S+1];
        //Base case 
        for(int j=0;j<=S; j++)//is it possible to get "j" sum using the first element
            dp[0][j] = false;
        dp[0][0] = true;//it is possible to get "0" sum using 0 elements//do not pick the element 
        if(ar[0] <= S)
            dp[0][ar[0]] = true;
        for(int i=1; i<N; i++){
            for(int j = 0; j<=S; j++)
            {
                dp[i][j] = dp[i-1][j] || (  (j>=ar[i])?dp[i-1][j-ar[i]] : false);
            }
        }
        cout<<(dp[N-1][S]>0?"YES":"NO" )<<endl;;

    }

    return 0;
}