/*Rearrange Sequence - 3 
You are given an array of size N containing integers. Find the size of the largest subarray that can be rearranged to form a contiguous sequence.

A contiguous sequence means that the difference of adjacent elements should be 0 or 1.



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

6

5 2 3 3 1 1

9

8 8 6 7 3 5 7 4 1



Output

5

8



Explanation



Test-Case 1

The largest subarray which can be rearranged to form a contiguous sequence is [2, 3, 3, 1, 1] which can be rearranged to form [1, 1, 2, 3, 3].



Test-Case 2

The largest subarray which can be rearranged to form a contiguous sequence is [8, 8, 6, 7, 3, 5, 7, 4] which can be rearranged to form [3, 4, 5, 6, 7, 7, 8, 8].*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<lli> ar(N);
        for(lli i =0;i<N; i++) cin >> ar[i];

        lli ans  = 0;
        for(lli i =0;i<N; i++)
        {
            lli mx = INT_MIN, mn = INT_MAX;
            set<lli> st;
            for(lli j =i; j<N; j++){

                mx = max(mx,ar[j]);
                mn = min(mn, ar[j]);//we explore all the subarrays [i....j]
                st.insert(ar[j]);

                if( (mx - mn + 1 == st.size() ) && (j-i+1 > ans) )
                    ans = j -i+1;
            }
        }     
        cout<<ans<<endl;
        
    }

    return 0;
}