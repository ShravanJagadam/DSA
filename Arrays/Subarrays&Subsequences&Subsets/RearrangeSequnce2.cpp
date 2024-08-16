/*Rearrange Sequence - 2 
You are given an array of size N containing integers which may not be unique. Find the size of the largest subarray that can be rearranged to form a strictly contiguous sequence.



Input Format

The first line of input contains T - number of test cases. Its followed by 2T lines, the first line contains N - the size of the array. The second line contains the elements of the array.



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

4 3 3 1 1

9

8 8 6 7 3 5 7 1 1



Output

2

3



Explanation



Test-Case 1

The largest subarray which can be rearranged to form a contiguous sequence here, is {4, 3} which can be rearranged to form {3, 4}.



Test-Case 2

The largest subarray which can be rearranged to form a contiguous sequence here, is {8, 6, 7} which can be rearranged to form {6, 7, 8}.*/

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
        //there are duplicates in this given array 
        // while you try to consider an element , check whether you already
        //have the current element considered previously

        lli ans = INT_MIN;
        for(lli i =0;i<N; i++){
            lli a = ar[i],b = ar[i];
            unordered_set<lli> st;
            for(lli j = i; j<N; j++){
                    //check whether this element is already 
                    //present in the considered subarray [i,j]
                    if(st.find(ar[j]) == st.end())//ar[j] is considered yet
                    {
                        a = min(a, ar[j]);
                        b = max(b,ar[j]);
                        st.insert(ar[j]);
                        if(b-a+1 == j-i+1)
                            ans = max(ans,j-i+1);

                    }
                    else 
                        break;//break the j loop since we are looking for a subarray(i.e contiguous elements                
                    
            }
        }
        cout<<ans<<endl;
    }    

    return 0;
}