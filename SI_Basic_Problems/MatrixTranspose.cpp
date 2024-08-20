/*
Transpose Matrix 
Given a matrix of size N x M, print the transpose of the matrix.



Input Format

The first line of input contains N, M - the size of the matrix. It is followed by N lines each containing M integers - elements of the matrix.



Output Format

Print the transpose of the given matrix.



Constraints

1 <= N, M <= 100

-109 <= ar[i] <= 109



Example

Input

2 2

5 -1

19 8



Output

5 19

-1 8



Explanation



Self Explanatory
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  
        
    lli N,M; cin >>N >> M;
    vector<vector<int>> ar(N,vector<int>(M));

    for(lli i =0;i<N; i++){
        for(lli j =0;j<M; j++)
            cin >> ar[i][j];
    }

    for(lli i =0;i<M; i++){
        for(lli j =0;j<N; j++)
            cout<<ar[j][i]<<" ";
        cout<<endl;
    }
    return 0;
}