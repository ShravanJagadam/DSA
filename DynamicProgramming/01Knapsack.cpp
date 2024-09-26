/*
The Knapsack Problem 
The famous knapsack problem. You are packing for a vacation on the sea side and you are going to carry only one bag with capacity S. You also have N items that you might want to take with you to the sea side. Unfortunately you can not fit all of them in the knapsack so you will have to choose. For each item you are given its size and its value. You want to maximize the total value of all the items you are going to bring. What is this maximum total value?.



Input Format

The first line of input contains T - number of test cases. First line of each test case contains - S and N. N lines follow with two integers on each line describing one of your items. The first number is the size of the item and the next is the value of the item.



Output Format

For each test case, print the total maximum value from the best choice of items for your trip, separated by new line.



Constraints

30 points

1 <= T <= 100

1 <= N <= 20



120 points

1 <= T <= 1000

1 <= N <= 500



General Constraints

1 <= S <= 500

1 <= W[i] <= 50

0 <= V[i] <= 1000



Example

Input

2

4 5

1 8

2 4

3 0

2 5

2 3

106 5

52 298

89 123

6 882

53 566

17 337



Output

13

1785



Explanation



Self Explanatory*/

  #include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli C, N; cin >>C >> N; //S ->Knapsack capacity

        vector<int> V(N);
        vector<int> W(N);
        for(int i =0;i<N; i++){
            cin >> W[i];
            cin >> V[i];
        }

        int dp[N+1][C+1];
        //dp[i][j] --> max value obtained from filling a knapsack
        // of capacity "j" using the first "i" items
        for(int j =0;j<C+1; j++)
            dp[0][j] = 0;//value obtained when you have no items 
        for(int i=1; i<=N; i++){
            for(int j =0;j<=C; j++){
                dp[i][j] = max(dp[i-1][j] , (j>=W[i-1]) ? (dp[i-1][j-W[i-1]] + V[i-1]) : 0);
            }
        }

     
        cout<<dp[N][C]<<endl;
    }

    return 0;
}
//Make sure to hadle the indeices properly.







