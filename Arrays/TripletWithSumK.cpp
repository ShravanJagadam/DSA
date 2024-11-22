/*Triplet with Sum K 
You are given an integer array and a positive integer K. You have to tell if there exists i,j,k in the given array such that ar[i]+ar[j]+ar[k]=K, i≠j≠k.



Input Format

The first line of input contains T - the number of test cases. Its followed by 2T lines, the first line contains N and K - the size of the array and the number K. The second line contains the elements of the array.



Output Format

For each test case, print "true" if the arrays contains such elements, false otherwise, separated by new line.



Constraints

30 points

1 <= T <= 100

3 <= N <= 100



70 points

1 <= T <= 100

3 <= N <= 1000



General Constraints

-100000 <= A[i] <= 100000

0 <= K <= 100000



Example

Input

3

5 60

1 20 40 100 80

12 54

12 45 52 65 21 645 234 -100 14 575 -80 112

3 15

5 5 5



Output

false

true

true



Explanation



Self Explanatory
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t ; cin >> t;

    while(t--){

        int N,K; cin >> N>>K;
        int ar[N];

        for(int i =0;i<N; i++) cin >> ar[i];


        sort(ar, ar+N);
        int res  = 0;

        for(int i =0;i<N-2; i++){

            int p1 = i+1, p2 = N-1;

            int sum = K -ar[i];
            
            while(p1<p2){

                if(ar[p1] + ar[p2] == sum )
                {
                    res = 1; break;
                }
                else if (ar[p1] + ar[p2] > sum ){
                    p2--;
                }
                else 
                    p1++;

            }
            if(res == 1) 
                break;

    }
    if(res == 1)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    
    }
    return 0;
}