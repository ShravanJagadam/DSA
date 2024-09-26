/*
Painting Houses 
There is a line of houses, where each house can be painted with one of the three colors: red, blue and green. The cost of painting each house with a certain color is different. Find the minimum cost to paint all the houses such that no two adjacent house have the same color.



Input Format

The first line of input contains T - number of test cases. It's followed by 4T lines, the first line contains N - number of houses and the second, third and fourth line contains the costs of each house for red, green and blue respectively.



Output Format

For each test case, print the minimum cost, separated by new line.



Constraints

1 <= T <= 100

1 <= N <= 103

1 <= R[i], G[i], B[i] <= 103



Example

Input

1

6

7 3 8 6 1 2

5 6 7 2 4 3

10 1 4 9 7 6



Output

18



Explanation



7 3 8 6 1 2 

5 6 7 2 4 3 

10 1 4 9 7 6



Min cost: 

H-> House

H1 with Green, H2 with Red, H3 with Blue, H4 with Green, H5 with Red, H6 with Green

Overall cost: 5+3+4+2+1+3 = 18
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<int> R(N);
        vector<int> G(N);
        vector<int> B(N);

        for(int i =0;i<N; i++) cin >> R[i];
        for(int i =0;i<N; i++) cin >> G[i];
        for(int i =0;i<N; i++) cin >> B[i];

        int dpR[N]; // dpA[i] ->cost of painting till the ith house, ith house been painted with Red
        int dpG[N]; //dpG[i] ->cost of painting till the ith house, ith house been painted with Green
        int dpB[N]; 

        //Base cases
        dpR[0] = R[0]; dpG[0] =G[0]; dpB[0] = B[0];

        for(int i =1;i<N; i++){
        
            dpR[i] = min(dpG[i-1],dpB[i-1])+R[i];
            dpG[i] = min(dpR[i-1],dpB[i-1])+G[i];
            dpB[i] = min(dpG[i-1],dpR[i-1])+B[i];
        }

        cout<<min(dpR[N-1], min(dpG[N-1],dpB[N-1]))<<endl;

    }

    return 0;
}
/*
we explore all the possibilities 

each house been painted wiht colour Red,Green and Blue*/