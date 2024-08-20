/*
Stock Span 
You are given a series of daily price quotes for a stock and you need to calculate the span of the stock’s price for each day. The span Si of the stock’s price on the current day i is defined as the maximum number of consecutive days just before the current day[including the current day], on which the price of the stock is less than or equal to its price on the current day.



Input Format

The first line of input contains T - the number of test cases. It is followed by 2T lines, the first line contains N - the size of the array. The second line contains N integers - the elements of the array, ith element denotes the stock price on ith day.



Output Format

For each test case, print a space-separated Stock Span Array, separated by a new line.



Constraints

30 points

1 <= T <= 100

1 <= N <= 103



70 points

1 <= T <= 200

1 <= N <= 104



General Constraints

0 <= A[i] <= 104



Example

Input

2

7

100 80 60 70 60 75 85

10

0 7 3 6 6 9 18 0 16 0



Output

1 1 1 2 1 4 6

1 2 1 2 3 6 7 1 2 1



Explanation



Self Explanatory*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<int> ar(N);
        for(lli i =0;i<N; i++) cin >> ar[i];

        vector<lli> dist(N);
        stack<lli> st;

        for(lli i = 0; i < N; i++){

            if(st.empty()){
                dist[i] = 1;
            }
            else{

                while( !st.empty() && ar[st.top()] <= ar[i]){
                    st.pop();
                }
                dist[i] = ( ( st.empty() ) ? i+1 :(i-st.top()) );
            }
            st.push(i);

        }
        

        for(lli i =0;i<N; i++)
            cout<<dist[i]<<" ";
        cout<<endl;
   

    }

    return 0;
}

/* 
Approach : 
Essentially we are finding the distance of the first  largest element on the 
right of the current index
*/





