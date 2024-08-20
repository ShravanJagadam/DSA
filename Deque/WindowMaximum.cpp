/*
Window Maximum 
Given an array of integers of size N and a window size K. For each continuous window of size K, find the highest element in the window. Output the sum of the highest element of all the windows.



Input Format

The First line of input contains T - number of test cases. It is followed by 2T lines, the first line contains N and K - the size of the array and the window size K. The second line contains N integers - the elements of the array.



Output Format

For each test case, print the sum of the highest element of all the windows of size K, separated by a newline.



Constraints

30 points

1 <= T <= 1000

1 <= N <= 1000

1 <= K <= N

-104 <= A[i] <= 104



70 points

1 <= T <= 1000

1 <= N <= 10000

1 <= K <= N

-104 <= A[i] <= 104



Example

Input

2

7 3

4 10 54 11 8 7 9

4 2

11 15 12 9



Output

182

42



Explanation



Example 1:

Window [4 10 54] : maximum element = 54

Window [10 54 11] : maximum element = 54

Window [54 11 8] : maximum element = 54

Window [11 8 7] : maximum element = 11

Window [8 7 9] : maximum element = 9

Total Sum = 54 + 54 + 54 + 11 + 9 = 182



Example 2:

Window [11 15] : maximum element = 15

Window [15 12] : maximum element = 15

Window [12 9] : maximum element = 12

Total Sum = 15 + 15 + 12 = 42
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N,K; cin >> N >>K;
        vector<int> ar(N);
        for(lli i =0;i<N; i++) cin >> ar[i];


        deque<lli> dq;

        lli s  = 0;
        for(lli i = 0; i < N; i++){
            
            while(!dq.empty() && ar[dq.back()] < ar[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);

            if(i-K == dq.front())
                dq.pop_front();

            if(i >= K-1)//print the max 
            {
                s += ar[dq.front()];
            }

            
        }
        cout<<s<<endl;
    }

    return 0;
}

/*
for each index "i", check if the back element of the deque is smaller 
than the current element ,
if yes--> pop the back element 
continue the above process for each element 

for each window, the element at the front will be the maximum


Intution : the element at any point in the deque is stored in Decreasing order


*/