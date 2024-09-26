/*
Longest Increasing Subsequence 
Given an array of size N, find the length of the Longest Increasing Subsequence (LIS).



Input Format

First line of input contains T - number of test cases. Its followed by 2T lines, the first line of each test case contains N - the size of the array and second line contains the elements of the array.



Output Format

For each test case, print the length of the Longest Increasing Subsequence (LIS), separated by newline.



Constraints

100 points

1 <= T <= 100

1 <= N <= 100



100 points

1 <= T <= 103

1 <= N <= 104



General Constraints

-104 <= arr[i] <= 104



Example

Input

3

7

-12 39 -9 72 32 95 -8

4

43 60 15 -5

6

94 19 58 80 14 48



Output

4

2

3



Explanation



Example: Possible LIS of length of 4 is {-12 -9 32 95} or {-12 -9 72 95}*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(t--){
        //O(N) Approach
        lli N; cin >> N;
        vector<int> ar(N);
        for(int i =0;i<N; i++) cin >> ar[i];

        vector<int> br;//br[i] -->represents the smallest ending element for a Increasing Subsequence of length "i"
        for(int i =0;i<N; i++)
        {
            auto it = lower_bound(br.begin(), br.end(),ar[i]);//check if there is any element that is greater than or equal the current element
            if(it == br.end())
                br.push_back(ar[i]);
            else{
                int idx = it - br.begin();//replace the immediately greater than or equal element
                br[idx] = ar[i];
            }
        }
        cout<<br.size()<<endl;
    }

    return 0;
}
/*
In the above approach : 

we check if there is any element greater than the current element 
then current element can replace that element and can be the smallest ending element 
for a Increasing Subsequence of length "i"
*/




/*
N^2  Approach
int dp[N];
    fill(dp,dp+N,1); //dp[i] -->LIS till ith index including ith element
    dp[0] = 1;
    for(int i =1; i<N; i++){
        for(int j =0;j<i;j++){
            if(ar[j]<ar[i])
                dp[i] = max(dp[i],dp[j]+1);
        }
    }
    
    cout<<*max_element(dp,dp+N)<<endl;
*/