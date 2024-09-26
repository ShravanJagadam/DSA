/*
Maximum Non-adjacent Subsequence Sum 
Given an array of integers, find the maximum subsequence sum, such that no 2 elements of the subsequence are adjacent to each other. Note that you cannot select an empty subsequence.



Input Format

The first line of input contains T - number of test cases. It is followed by 2T lines. First line of each test case contains N - size of the array and the second line contains N integers - elements of the array.



Output Format

For each test case, print the maximum subsequence sum, separated by new line.



Constraints

1 <= T <= 1000

1 <= N <= 10000

-1000 <= ar[i] <= 1000



Example

Input

4

8

-24 28 28 55 -31 -27 -45 -24

11

40 5 39 45 31 -99 -44 73 -16 -31 27

7

57 18 -14 17 31 16 -16

2

26 61



Output

83

210

90

61



Explanation



Self Explanatory
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<int> ar(N);
        for(int i =0;i<N; i++) cin >> ar[i];
        int dp[N+1];
        //dp[i] --> maximum non-adjacent subsequence sum ending at index i and including ar[i]

        dp[0] = ar[0];
        dp[1] = ar[1];

        int run_max = max(dp[0],0);
        int prev = dp[1];


        for(int i = 2; i<N; i++){
            //get the max from index 0 to index i-2 
           
            dp[i] = ar[i] + run_max;
            run_max = max(run_max,prev);
            prev = dp[i];

        }
        cout<<*max_element(dp,dp+N)<<endl;
    }

    return 0;
}



