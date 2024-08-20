/*
Rabin Karp String Matching Algorithm 
Given 2 strings A and B, find the number of occurrences of A in B as a substring.



Note:

Solve using the Rabin-Karp string matching algorithm. Do not use an inbuilt library.



Input Format
The first line of input contains T - the number of test cases. It's followed by T lines. Each line contains 2 strings - A and B, separated by space.



Output Format

For each test case, print the number of occurrences of A in B, separated by a new line.



Constraints

30 points

1 <= len(A), len(B) <= 1000



70 points

1 <= len(A), len(B) <= 10000



General Constraints

1 <= T <= 2000

'a' <= A[i], B[i] <= 'z'



Example

Input

4

smart yekicmsmartplrplsmartrplplmrpsmartrpsmartwmrmsmartsmart

interviews interviewseiwcombvinterviewskrenlzp

ds dsdsajdsrjjdsjjj

algo yalgoalgoalgopalgoaxalgoasaxalgolalgoalgoalgo



Output

6

2

4

9



Explanation



Self Explanatory
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli k = 1e9+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        string A,B; 
        cin >> A >> B;
        lli N = A.size(); //smaller
        lli M = B.size();

        lli p = 53;
        lli p1 = p; //a 2 digit prime number 

        //for the first substring of A  and the string B
        //compute the hashvalue

        lli hA = 0;
        lli hB = 0;
        lli ans = 0;

        for(lli i = 0;i < N; i++){
            hA  =  (hA + A[i]*p1)%k;
            hB  =  (hB + B[i] * p1)%k;
            
            p1 = (p1 * p)%k; 
        }
        //cout<<"ha & hb are "<<hA<<"**"<<hB<<endl;

        if(hA == hB)
            ans++;
        lli p2 = p;
        for(lli i = N; i<M; i++){

            //handle the outgoing char along with the prime multiple
            //handle the incoming char 
            hA = (p * hA)%k;
            hB = (hB - (B[i-N] * p2)%k + (B[i] * p1)%k + k   )%k;
            //cout<<"ha & hb are "<<hA<<"**"<<hB<<endl;

            if(hA == hB) 
                ans++;
        
            p1 = (p1 * p)%k;
            p2 = (p2 * p)%k;

        }
        cout<<ans<<endl;
    }

    return 0;
}