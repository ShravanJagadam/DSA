/*
Matrix Zig-Zag Traversal 
Given a matrix of size N x M, print the matrix in zig-zag order. Refer example for more details.



Input Format

The first line of input contains N, M - the size of the matrix. It is followed by N lines each containing M integers - elements of the matrix.



Output Format

Print the matrix elements in zig-zag order.



Constraints

1 <= N, M <= 100

-106 <= mat[i][j] <= 106



Example

Input

3 3

5 9 -2

-3 4 1

2 6 1



Output

5 9 -2 1 4 -3 2 6 1



Explanation



Self Explanatory*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
      
        lli N,M; cin >> N >> M ;
        
        
        vector<vector<lli>> ar(N,vector<lli>(M,0));
        
        for(lli i =0;i<N; i++){
            for(lli j =0; j<M ; j++)
                cin >> ar[i][j];
        }
        
   
        int x  = 1;
        for(int r = 0; r<N; r++){

            if(x == 1){
                for(lli i = 0; i<M; i++)
                    cout<<ar[r][i]<<" ";
            }
            else{
                for(lli i = M-1; i>=0; i--)
                    cout<<ar[r][i]<<" ";

            }
            x = x^1;
        }

    

    return 0;
}