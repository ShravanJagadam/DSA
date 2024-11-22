/*
Pair with Difference K 
You are given an integer array and an integer K. You have to tell if there exists a pair of integers in the given array such that ar[i]-ar[j]=K and i≠j.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines, the first line contains N and K - the size of the array and the number K. The second line contains the elements of the array.



Output Format

For each test case, print "true" if the arrays contains such elements, "false" otherwise, separated by new line.



Constraints

40 points

2 <= N <= 1000



60 points

2 <= N <= 100000



General Constraints

1 <= T <= 100

-105 <= ar[i], K <= 105



Example

Input

2

5 60

1 20 40 100 80

10 11

12 45 52 65 21 645 234 14 575 112



Output

true

false



Explanation



Self Explanatory*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t ; cin >> t;

    while(t--){

        int N,K; cin >> N>> K;

        K = abs(K);
        int ar[N];
        for(int i = 0;i<N; i++)  cin >> ar[i];

        sort(ar,ar+N);

        //for(int i=0;i<N; i++) cout<<ar[i]<<" "<<endl;

        //Handle the test case when K = 0, if(i == j) it shoudln't return true
        int i = 0,j = 1;
        int res  = 0;
        while(j<N)
        {
            if(  (i!=j)   &&    ((ar[j] - ar[i])   == K  )   ) //(i != j can also handle the case when k =0)
            {
                res = 1; break;
            }
            else if((ar[j] - ar[i]) > K){
                i++;
            }
            else
                j++;
        }
        cout<<((res == 1)?"true":"false")<<endl;
    }

    return 0;
}