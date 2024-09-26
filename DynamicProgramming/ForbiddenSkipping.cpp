/*
Forbidden Skipping 
Given an array, find the maximum possible sum of elements by choosing a subsequence in which you cannot skip consecutive elements of the array. It means, in your chosen subsequence, if you skip ith element, you cannot skip (i-1)th and (i+1)th elements of the array.



Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, the first line contains N - the size of the array and the second line contains the elements of the array.



Output Format

For each test case, print the maximum possible sum, separated by newline.



Constraints

1 <= T <= 103

1 <= N <= 104

-103 <= arr[i] <= 103



Example

Input

3

5

1 2 3 4 5

5

1 2 -3 4 5

5

1 2 -3 -4 5



Output

15

12

5



Explanation



Test Case 1:

The subsequence which gives maximum sum without skipping consecutive elements is [1,2,3,4,5] .



Test Case 2:

The subsequence which gives maximum sum without skipping consecutive elements is [1,2,4,5] .



Test Case 3:

The subsequence which gives maximum sum without skipping consecutive elements is [1,2,-3,5] .
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<int> ar(N);
        for(int i =0;i<N; i++) cin >> ar[i]; 

        int dp0[N]; //dp0[i] --> max sum till i when ith element is skipped
        int dp1[N]; //dp1[i] -->max sum till i when ith element is considered

        dp0[0] = 0;
        dp1[0] = ar[0];

        for(int i = 1; i<N; i++){
            dp0[i] = dp1[i-1];
            dp1[i] = ar[i] + max(dp0[i-1],dp1[i-1]);
        }
        cout<<max(dp0[N-1],dp1[N-1])<<endl;     

    }

    return 0;
}