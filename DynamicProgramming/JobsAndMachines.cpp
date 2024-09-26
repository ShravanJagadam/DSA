/*Jobs and Machines 
You have to complete N jobs using 2 machines. You can only work on 1 job at a time and the jobs should be completed in the order given in the input. The time to complete a particular job is differ g time of K involved between the machines. Find the minimum time required to complete all the jobs.



Input Format

The first line of input contains T - number of test cases. First line of each testcase contains 2 integers N and K, it is followed by 2 lines, each containing N integers where ith number in each line denotes the time taken by the Machine-1 and Machine-2 to complete the ith job respectively.



Output Format

For each test case, print the minimum time to complete all the jobs, separated by a newline.



Constraints

1 <= T <= 103

1 <= N, K <= 103

1 <= A[i], B[i] <= 105



Example

Input

2

5 8

11 34 50 29 17

36 48 27 13 18

5 2

18 23 44 37 36

46 29 42 45 8



Output

111

132



Explanation



Example 1:

Jobs will be executed in the following order: Machine-1, Machine-1, Machine-2, Machine-2, Machine-2.

Total Cost = 11 + 34 + 8 + 27 + 13 + 18 = 111.



Example 2:

Jobs will be executed in the following order: Machine-1, Machine-1, Machine-1, Machine-1, Machine-2.

Total Cost = 18 + 23 + 44 + 37 + 2 + 8 = 132.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        int N,K; cin >> N >> K;
        vector<int> A(N);
        vector<int> B(N);

        for(int i =0;i<N; i++) cin >> A[i]; 
        for(int j =0;j<N; j++) cin >> B[j]; 

        int dpA[N];
        int dpB[N]; 

        dpA[0] = A[0]; 
        dpB[0] = B[0]; 

        for(int i= 1; i<N; i++)
        {
            dpA[i] = min(dpA[i-1], dpB[i-1]+K) + A[i];
            dpB[i] = min(dpA[i-1]+K, dpB[i-1]) + B[i];
        }
        cout<<min(dpA[N-1],dpB[N-1])<<endl;
        
    }

    return 0;
}


/*

We consider all the possibilities , each job been doing on machine A, and machine B

*/