/*
Non Decreasing Subsequences 
You are given an array of integers of size N. Find the total number of non-decreasing subsequences present in the array.



Input Format

The first line of input contains T - the number of test cases. It is followed by 2T lines, the first line contains N - the size of the array. The second line contains the elements of the array.



Output Format

Print the total number of non-decreasing subsequences present in the array for each test case on a new line.

Since this number can be very large, print the result % 1000000007.



Constraints

30 points

1 <= T <= 100

1 <= N <= 20

-105 <= A[i] <= 105



70 points

1 <= T <= 100

1 <= N <= 103

-105 <= A[i] <= 105



Example

Input

2

4

1 8 2 5

10

9 7 8 6 5 7 4 3 2 1



Output

9

14



Explanation



Test-Case 1

The are 9 non-decreasing subsequences:

{1}, {8}, {2}, {5}, {1,8}, {1,2}, {1,5} and {2,5} and {1,2,5}.



Test-Case 2

The are 14 non-decreasing subsequences:

{9}, {7}, {8}, {6}, {5}, {7}, {4}, {3}, {2}, {1}, {7,8}, {7,7}, {6,7} and {5,7}.*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int k = 1e9+7;


lli solve(vector<lli> ar, int N, int idx, int prev){
    //base case 
    if(idx == N){
        return 1;
    }
    //we can always skip and element 
    lli x = solve(ar,N,idx+1,prev);
    //we can choose current element only if >= prev
    if(ar[idx] >= prev)
        lli y = solve(ar,N,idx+1,ar[idx]);

    return (x%k + ((ar[idx] >= prev)?solve(ar,N,idx+1,ar[idx]):0)%k)%k;


}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<lli> ar(N);
        
        for(int i=0;i<N; i++) cin >> ar[i];

        lli prev = INT_MIN;

        lli idx = 0;
        cout<<(solve(ar,N,idx,prev))%k-1<<endl;

    }

    return 0;
}

/*
BF --> genereate all the subsequences and check if each subsequnce is valid or not
Slightly optimised - while generating the subsequnce ,maintain a varaible to store the last considered 
element and based on that, decide whether to choose or not the current element
Optimised ?

*/