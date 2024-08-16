




























/*Rearrange Sequence - 1 
You are given an array of size N containing unique integers. Find the size of the largest subarray that can be rearranged to form a contiguous sequence.

A contiguous sequence means that the difference of adjacent elements should be 1.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines, the first line contains N - the size of the array. The second line contains the elements of the array.



Output Format

For each test case, print the size of the largest subarray that can be rearranged to form a contiguous sequence, on a new line.



Constraints

30 points

1 <= T <= 100

4 <= N <= 100



70 points

1 <= T <= 100

4 <= N <= 1000



General Constraints

0 <= A[i] <= 105



Example

Input

2

5

1 3 2 6 5

9

0 8 6 5 7 10 3 2 1



Output

3

4



Explanation



Test-Case 1

The largest subarray that can be rearranged to form a contiguous sequence is [1, 3, 2] which can be rearranged to form [1, 2, 3].



Test-Case 2

The largest subarray that can be rearranged to form a contiguous sequence is [8, 6, 5, 7] which can be rearranged to form [5, 6, 7, 8].*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<lli> ar(N);
        for(lli i =0; i<N; i++) cin >> ar[i];

        //ITs an N^2 soltuion where we check for each subarray (i,j)
        lli ans = INT_MIN;
        for(lli i =0;i<N; i++){
            lli a = ar[i],b = ar[i];
            for(lli j = i; j<N; j++){
                    a = min(a, ar[j]);
                    b = max(b,ar[j]);
                    if(b-a+1 == j-i+1){
                        ans = max(ans,j-i+1);
                        
                    }
                    //even there is an invalid element we do not break the subarray [i....j]
                    //assuming this element may become valid in the future after some elements
                    //so we explore all the subarrays completely
                        
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}