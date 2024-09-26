/*
Bitonic Sequence 
Given an array of integers, find the length of the longest bitonic sequence. A subsequence is called Bitonic if it is first increasing (non-decreasing, i.e., not strictly increasing), and then decreasing (non-increasing, i.e., not strictly decreasing).

A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.



Input Format

The first line of input contains T - number of test cases. It is followed by 2T lines, the first line contains N - the size of the array. The second line contains the elements of the array.



Output Format

For each test case, print the length of the longest bitonic sequence, separated by new line.



Constraints

1 <= T <= 100

1 <= N <= 1000

-10000 <= A[i] <= 10000



Example

Input

3

5

4 15 -10 11 8

7

15 -5 7 7 6 12 -3

10

1 5 1 3 8 5 1 3 4 3



Output

4

5

7



Explanation



Example 1:

4 15 11 8 : 4



Example 2:

-5 7 7 6 -3 : 5, or

-5 7 7 12 -3 : 5



Example 3:

1 1 3 8 5 3 3 : 7*/
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


        int LIS[N];//LIS[i] --> is the LIS till i including i(left -->right)
        int LDS[N];//LDS[i] --> is the LDS from i including i(right -->left)
        fill(LIS,LIS+N,1);
        fill(LDS,LDS+N,1);


        LIS[0] = 1; 
        LDS[N-1] = 1;

        for(int i =1; i<N; i++){
            for(int j =0;j<i; j++){
                if(ar[j]<=ar[i])
                    LIS[i] = max(LIS[i],LIS[j]+1);
            }
        } 


        for(int i = N-2; i>=0; i--){
            for(int j = N-1; j>i;j--){
                if(ar[j] <= ar[i])
                    LDS[i] = max(LDS[i],LDS[j]+1);
            }
        }

        int ans  = 0;
        for(int i =0;i<N; i++)
            ans = max(ans, LIS[i]+LDS[i]-1);
        cout<<ans<<endl;
    }

    return 0;
}

/*
Approach : 
LIS : We find LIS from left to right
LDS : We find LIS from right to left

we use both of them to find the longest length of the Bitonic sequence.
*/