/*
Non Divisible Subsets 
You are given an array of integers of size N and another integer K. Find the size of the largest subset of the array in which the sum of any two numbers is not perfectly divisible by K.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines, the first line contains N - the size of the array and K, separated by a space. The second line contains the elements of the array.



Output Format

For each test case, print the size of the largest subset in which the sum of any two numbers is not perfectly divisible by K, separated by a newline.



Constraints

10 points

1 <= T <= 100

1 <= N <= 10

1 <= K <= 50

0 <= arr[i] <= 102



20 points

1 <= T <= 100

1 <= N <= 102

1 <= K <= 102

0 <= arr[i] <= 105



70 points

1 <= T <= 100

1 <= N <= 104

1 <= K <= 105

0 <= arr[i] <= 105



Example

Input

2

4 3

1 7 2 4 

5 2

1 2 3 4 5



Output

3

2



Explanation



Test Case 1:

The subset {1, 7, 4} is the largest subset with the sum of any two numbers { {1,7}=8, {1,4}=5, {7,4}=11 } not perfectly divisible by K=3.



Test Case 2:

The subset {1, 2} or {2, 3} or {3, 4} or {4, 5} can be the largest subset with the sum of any two numbers not perfectly divisible by K=2.*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t ; cin >> t;

    while(t--){

        int N,K; cin >> N>>K;
        vector<int> ar(N);

        for(int i =0;i<N; i++) cin >> ar[i];

        int count[K];
        fill(count,count+K,0);

        for(int i =0;i<N; i++)
            count[(ar[i])%K]++;

        int ans = 0 ;
        
        if(count[0] > 0) ans = 1;

        int i = 1, j = K-1;

        while(i<j){

            ans += max(count[i], count[j]);
            i++;j--;

        }
        if( i == j && count[i] > 0 ) ans++;
        cout<< ans<<endl;   
    }

    return 0;
}

/*
Approach : 
->create an array of size K say count 
count the number of elements in the input array such that count[i] = no of elements
int the input array such that ar[i]%k = i;

using 2 pointer technique.

i =1, j = k-1
we have to select either of the elements (either i or either j ), max of them to get the max length
*/