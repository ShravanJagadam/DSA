/*Sum of OR of Subarrays 
You are given an array of size N. Find the sum of the results of bitwise OR of all the subarrays.



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

21

201



Explanation



Example 1:

The sum of bitwise OR of all subarrays is 3 + 2 + 0 + 1 + 3|2 + 2|0 + 0|1 + 3|2|0 + 2|0|1 + 3|2|0|1 = 21
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

//Usinng inclusion and exclusion principle
//for a bith bit , we check the validity for each elemment 
//Validity : if the bth bit of the current element is 0 or 1 
//If it is 1 it contributes to the XOR sum else no
//At each bit we consider all the subarrays as they contribute to the XOR sum
//Then we find the no of subarrays w.rt.bth bit that do not contribute to the XOR sum
//we subtract them from the total subarray and add the product of (TS - no of subarrays that do not contribute at the bth bit) and their contributioon (1<<b)


lli exclusionAndInclusion(vector<lli> &ar, lli N){

    //inclusion and exclsuion principle
        // ar[0] ar[1] ar[2] ar[3] ar[4]
        //  N     N      y     N     N   validity for bth bit
        lli ans  = 0;
        lli TS = N * (N + 1)/2;//total subarrays count
        for(lli b = 0; b <= 30; b++ ){
                                            //rc - runnign count of invalid elements and rsc - running count of invald subarrays 
            lli rc  = 0;
            lli rsc = 0;  
                                            //runnign count of elements that do not contribute at bth bit
            for(lli i =0; i<N; i++){         //count of subarrays from the non valid elements

                if( ( (ar[i] >> b) & 1 ) == 0 ){
                    rc++;
                }
                else{
 
                    rsc = rsc +    (rc * (rc+1)) /2  ;
                    rc  = 0;
                }
                
            }
            rsc += (rc * (rc+1))/2;             //There may be chance thhat rc != 0 and we havent gone to else at the end of the array


            ans +=( (TS - rsc) * (1<<b) );
        }
        return ans;


}

/* Approach 2 -Counting the subarrays that include the current element  based on the 
start and end points of the subrrays
*/
lli solve(vector<lli> &ar, lli N){

    //inclusion and exclsuion principle
        // ar[0] ar[1] ar[2] ar[3] ar[4]
        //  N     N      y     N     N   validity for bth bit
        lli ans  = 0;
        
        for(lli b = 0; b <= 30; b++ ){
                                        
            lli p = -1, c  = 0;      
            for(lli i =0; i<N; i++){         

                if( ((ar[i] >>b ) & 1 ) == 1 ){
                    c +=  (i - p) * (N - i);
                    p = i;
                }

            }
            ans += (c * (1<<b));
            
        }
        return ans;


}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<lli> ar(N);
        for(lli i =0;i<N; i++) cin >> ar[i];

        
        
        cout<<solve(ar,N)<<endl;
    }

    return 0;
}