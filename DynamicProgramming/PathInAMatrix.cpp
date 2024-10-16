/*Path in a Matrix 
Given a matrix, find the number of ways to reach from the top-left cell to the right-bottom cell. At any step, from the current cell (i,j) you can either move to (i+1,j) or (i,j+1) or (i+1, j+1). Please note that certain cells are forbidden and cannot be used.



Input Format

The first line of input contains T - number of test cases. First line of each test case contains N, M - size of the matrix and B - number of forbidden cells. It is followed by B lines each containing a pair (i,j) - index of the forbidden cell.



Output Format

For each test case, print the number of ways, separated by new line. Since the output can be very large, print output % 1000000007.



Constraints

30 points

1 <= N, M <= 10



70 points

1 <= N, M <= 100



General Constraints

1 <= T <= 500

0 <= i < N

0 <= j < M



Example

Input

5

5 2 1

2 0

7 3 1

1 0

6 3 1

5 2

2 9 1

0 1

5 6 2

0 1

1 0



Output

4

24

0

2

129



Explanation



Self Explanatory
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int k = 1e9+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N,M,B; cin >> N >> M >> B;
        vector<vector<lli>> ar(N,vector<lli>(M,1));

        int i,j;
        for(int k =0;k<B; k++){
            cin >> i >> j;
            ar[i][j] = 0;
        }
        //Base case 
        int flag = -1;
        for(int j =0;j<M; j++)//0th row, once a block cell is found, all cells to the right of it are not accessible
        {
            if(ar[0][j] == 0)
                flag = 1;
            if(flag != -1)
                ar[0][j] = 0;
        }

        flag = -1;
        for(int i =0;i<N; i++){//0th column, once a block cell is found, all cells below it are not accessible
            if(ar[i][0] == 0)
                flag = 1;     
            if(flag != -1)
                ar[i][0] = 0;          
            
        }
        for(int  i =1;i<N; i++){
            for(int j =1; j<M  ; j++){
                if(ar[i][j] != 0)//computing the answer only for a unblocked cell
                    ar[i][j] = (    (ar[i-1][j]  + ar[i][j-1])%k  + ar[i-1][j-1])%k;
            }
        }
        cout<<ar[N-1][M-1]<<endl;
    }

    return 0;
}