/*
Sum of AND of Subarrays 
You are given an array of size N. Find the sum of the results of bitwise AND of all the subarrays.



Input Format

The first line of input contains T - the number of test cases. It is followed by 2T lines, the first line contains N - the size of the array. The second line contains the elements of the array.



Output Format

For each test case, print the result separated by a newline.



Constraints

10 points

1 <= T <= 100

1 <= N <= 100

0 <= A[i] <= 105



20 points

1 <= T <= 100

1 <= N <= 1000

0 <= A[i] <= 105



70 points

1 <= T <= 1000

1 <= N <= 104

0 <= A[i] <= 105



Example

Input

2

4

3 2 0 1

6

1 9 8 1 12 0



Output

8

40



Explanation



Example 1:

The sum of bitwise AND of all subarrays is 3 + 2 + 0 + 1 + 3&2 + 2&0 + 0&1 + 3&2&0 + 2&0&1 + 3&2&0&1 = 8*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<int> ar(N);
        for(lli i =0;i<N; i++) cin >> ar[i];
        lli ans  = 0;
        
        for(lli b = 0; b <= 30; b++ ){
                                            //rc - runnign count of valid elements and rsc - running count of valid subarrays 
            lli rc  = 0;
            lli rsc = 0;  
                                            //runnign count of elements that  contribute at bth bit
            for(lli i =0; i<N; i++){         //count of subarrays from the  valid elements
                
                if( ( (ar[i] >> b) & 1 ) == 1){
                    rc++;
                    
                }
                else{
                    
                    rsc = rsc +    ((rc * (rc+1)) /2)  ;
                    rc  = 0;
                }
                
            }
            rsc += (rc * (rc+1))/2;    
                //There may be chance thhat rc != 0 and we havent gone to else at the end of the array


            ans +=  ( rsc * (1<<b) );
        }
        cout<< ans<<endl;

    }

    return 0;
}