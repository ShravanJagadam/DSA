/*
Express as Power Sum 
Given an integer N, find the number of ways it can be expressed as the sum of the Kth powers of unique natural numbers.



Input Format

The first line of input contains T - the number of test cases. It's followed by T lines, each line containing 2 space-separated integers - N and K.



Output Format

Print the number of ways for each test case, separated by a new line.



Constraints

1 <= T <= 100

1 <= N <= 1000

2 <= K <= 10



Examples

Input

3

10 2

100 2

100 3



Output

1

3

1



Explanation



Test-Case 1

There is only 1 way to express 10 as the sum of squares of unique natural numbers: 12 + 32 = 10



Test-Case 2

There are 3 ways to express 100 as the sum of squares of unique natural numbers: 102 = 62 + 82 = 12 + 32 + 42 + 52 + 72 = 100



Test-Case 3

There is only 1 way to express 100 as the sum of 3rd power of unique natural numbers: 13 + 23 + 33 + 43 = 100*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


lli solve(lli N, lli K, lli i, lli sum){


    sum += pow(i,K);
    if(sum > N)
        return 0;
    if(sum == N){
        return 1;
    }

    lli ans  = 0;
    //1^2
    for(int j = i+1; j<=N; j++){
            
            if(sum + pow(j,K) >N)// if curr sum + pow(j,K) becomes greateer than N, then all future values of j sum+pow(j,K) becomes greater than N, which are invalid
                break;            //this is a slight optimisation,which reduces all invalid calls
            ans += solve(N,K,j,sum);
            
            
    }
    sum -= pow(i,K);
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N,K; cin >> N >>K;
        
        //N = a^K + b^K +.....(a,b,c belongs to Natural Numbers)
        
        lli res  = 0;
        for(lli i = 1; i<= N; i++)
        {
            lli sum = 0;
            
            res += solve(N,K,i,sum);
        }
        cout<<res<<endl;
    }

    return 0;
}