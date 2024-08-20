/*
Substring Matching 
You are given two strings A and B. You are also given Q queries with 4 indices i, j, k, and l. Check whether the substring of A[i:j] matches the substring of B[k:l].



Input Format

The first line of input contains T - the number of test cases. In each test case, the first line contains the string A and the second line contains the string B.

The next line contains an integer Q - the number of queries. The Q subsequent lines each contain 4 integers i, j, k, and l, separated by a space.



Output Format

For each query, on a new line, print "Yes" if the substring of A matches the substring of B, print "No" otherwise.



Constraints

30 points

1 <= T <= 100

1 <= len(A), len(B) <= 100

0 <= Q <= 1000



120 points

1 <= T <= 100

1 <= len(A), len(B) <= 10000

0 <= Q <= 10000



General Constraints

'a' <= A[i], B[i] <= 'z'

0 <= i <= j < len(A)

0 <= k <= l < len(B)



Example

Input

2

smartinterviews

intermediate

2

5 9 0 4

1 3 2 4

hackerrank

hackerearth

1

0 3 0 3



Output

Yes

No

Yes



Explanation



Test-Case 1

The substring of "smartinterviews" from index 5 to 9 is "inter". The substring of "intermediate" from 0 to 4 is also "inter". Since these both are equal, the output is "Yes".

The substring of "smartinterviews" from index 1 to 3 is "mar". The substring of "intermediate" from 2 to 4 is "ter". Since these both are not equal, the output is "No".*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli k1 = 1e9+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;
    //pre-compute the power array
    lli pow[10000+2];
    pow[0] = 1;
    pow[1] = 43;

    for(lli i =2;i<10000+2; i++) pow[i] = (pow[i-1]* 43)%k1;


    

    while(t--){

        string a,b; 
        cin >> a >> b;

        lli n = a.size(); 
        lli m = b.size();
        //compute the prefix hash value for each string pHA and pHB

        lli p = 43;
        lli p1 = p*p, p2 = p*p;

        lli pHA[n], pHB[m]; //prefix hash arrays

        pHA[0] = (a[0] * p)%k1;
        pHB[0] = (b[0] * p)%k1;

        for(lli i =1;i<n; i++) {
            pHA[i] = (pHA[i-1] + (a[i] *p1)%k1  )%k1;
            p1 = (p1*p)%k1;

        } 
        
        for(lli i =1;i<m; i++){
            pHB[i] = (pHB[i-1] +  (b[i] * p2)%k1  )%k1;
            p2 = (p2*p)%k1;
        }

        

        //for each query check & balance the powers and check if they are equal

        lli q; cin >> q;
        lli i,j,k,l; 

        while(q--){

            cin >> i >> j >> k >> l;

            lli hA = (pHA[j] - ((i!=0)?pHA[i-1] : 0) + k1)%k1;//[i....j]
            lli hB = (pHB[l] - ( (k!= 0 )?pHB[k-1]: 0) + k1 )%k1;//[k...l]

            //balance the power based on "i and k "comparision
            lli d = abs(i-k);
            if(i>k){
                hB = (hB * pow[d])%k1;
            }
            else 
                hA = (hA * pow[d])%k1;

            if(hA == hB ){
                cout<<"Yes"<<endl;
                continue;
            }else{
                cout<<"No"<<endl;
                continue;
            }
        }
    }

    return 0;
}