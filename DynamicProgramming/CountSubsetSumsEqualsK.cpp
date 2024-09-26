/*
Given an array of size N containing positive integers and a target sum K. Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target K, since the number of ways can be very large, print answer modulo 1e9 + 7.



Input Format

The first line of input contains T - the number of test cases. It is followed by 2T lines. The first line of each test case contains the N - size of the array and the K - target sum. The second line contains N integers - elements of the array.



Output Format

Print the number of ways for each test case separated by a new line.



Constraints

30 points

1 <= N <= 20



70 points

1 <= N <= 100



General Constraints

1 <= T <= 100

1 <= K <= 103

1 <= A[i] <= 103



Example

Input

2

4 5

1 4 4 5

3 4

2 2 1



Output

3

1



Explanation



Self Explanatory*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int k = 1e9+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N,K; cin >> N>>K;
        vector<int> ar(N);
        for(int i =0;i<N; i++) cin >> ar[i]; 

        //dp[i][j] --> #Number of ways selecting the elements from the array such that the sum is "j" with the first "i" elements
        vector<vector<int>> dp(N,vector<int>(K+1,0));
        
        //Base case 
        for(int j=0;j<=K; j++)//#ways of selecting from "0th" element such that the sum is "j"
            dp[0][j] = 0;
        dp[0][0] = 1;//#ways of selecting from "0th" element such that the sum is "0"(do not pick it)
        if(ar[0] <= K)//#ways of selecting from "0th" element such that the sum is "j"
            dp[0][ar[0]] = 1;
        
        for(int i=1; i<N; i++){
            for(int j = 0; j<=K; j++)
            {
                dp[i][j] = (dp[i-1][j]  +  (  (j>=ar[i]) ? dp[i-1][j-ar[i]]  : 0))%k;
            }
        }
        
        cout<<dp[N-1][K]<<endl;;

    }

    return 0;
}