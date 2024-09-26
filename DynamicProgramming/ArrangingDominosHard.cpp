/*Arranging Dominos Hard 
You are given a floor of size 5xN. You have tiles of 2 different sizes: 1x5 and 2x5. Of course, you can rotate the tiles to get 2 more tile sizes: 5x1 and 5x2. You have to do the flooring using these tiles in the following way:

Floor space should be completely covered by tiles.
You cannot break tiles, ie, you have to use a tile entirely or not at all.
Any tile should not extend beyond the floor space.
Tiles should be placed parallel to the floor boundaries.
Your task is to find the number of ways in which you can lay the tiles on the floor.



Input Format

The first line of input contains T - number of test cases. It's followed by T lines, each line contains N - the length of the floor. The width of the floor is fixed to be 5.



Output Format

For each test case, print the number of ways in which you can lay the tiles on the floor, separated by new line. Since the output can be very large, print result % 1000000007 [1e9+7].



Constraints

1 <= T <= 104

1 <= N <= 106



Example

Input

5

2

4

20

120

10



Output

2

5

466098

562804719

457



Explanation



Self Explanatory
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int k = 1e9+7;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli dp[1000000+1]; 
    dp[0] =1; 
    dp[1] = 1; 
    dp[2] = 2; 
    dp[3] = 3; 
    dp[4] = 5; 
    for(int i =5; i<= 1000000; i++){
        dp[i] =  ((dp[i-1] + dp[i-2])%k + (dp[i-5] * 8)%k)%k;
    }
    
    lli t ; cin >> t;

    while(t--){
        int N ; cin >> N; 

        cout<<dp[N]<<endl;
    
    }

    return 0;
}
/*

Consider you are at ith position

1->You can fill the ith position with 1tile of 1h*5v tile ->So dp[i] depends on dp[i-1]
2->You can fill the (i-1)th and ith position with tile 2H*5V->So dp[i] depends on dp[i-2]
3->you can fill the position from i to i-4 using the tiles horizontally in 8 ways 


*/