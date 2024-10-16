/*
Rectangular Area Under Histogram 
Given the height of adjacent buildings, find the largest rectangular area possible, where the largest rectangle can be made of a number of contiguous buildings. For simplicity, assume that all buildings have the same width and the width is 1 unit.

Note that the sides of the rectangle have to be parallel to the axes.



Input Format

The first line of input contains T - the number of test cases. It is followed by 2T lines - the first line contains N - the number of buildings. The second line contains the height of the buildings.



Output Format

For each test case, print the area of the largest possible rectangle, separated by a newline.



Constraints

50 points

1 <= T <= 100

1 <= N <= 103

1 <= A[i] <= 1000



100 points

1 <= T <= 100

1 <= N <= 105

1 <= A[i] <= 104



Example

Input

2

7

6 2 5 4 5 1 6

4

5 10 12 4



Output

12

20



Explanation



Example 1:

You can form the following rectangles:

6x1 = 6, 2x5 = 10, 5x1 = 5, 4x3 = 12, 5x1 = 5, 1x7 = 7, 6x1 = 6 : max = 12 [axb means rectangle with height a and width b]



Example 2:

You can form the following rectangles:

5x3 = 15, 10x2 = 20, 12x1 = 12, 4x4 = 16 : max = 20 [axb means rectangle with height a and width b]*/


#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<int> ar(N);
        for(lli i =0;  i<N; i++) cin >> ar[i];

        //for each index , find the index of the element on left which is smaller than the current element.
        //for each index , find the index of the element on right which is smaller than the current element.

        vector<lli> L(N,-1);
        vector<lli>R(N,N);

        //finding L --> are there any potential answers on the left(ie in the stack ) for current element
        stack<lli> st1;

        for(lli i = 0; i<N; i++){

            while( !st1.empty()  && ar[st1.top()] >= ar[i]){
                st1.pop();
            }

            if(!st1.empty())
                L[i] = st1.top() ;

            st1.push(i);
        }

        

        //finding R -->can the current element be the potential answer to the any of the elements on the left(elements in the stack)
        //finding the first smaller elemet on the right for each index
        //if the curr element is smaller than the element in the stack

        stack<lli> st2;

        for(lli i =0; i<N; i++){
            
            while( !st2.empty() && ar[st2.top()] > ar[i]){

                R[st2.top()] = i;
                st2.pop();

            }
            st2.push(i);


        }
        
        lli mx = -1;
        for(lli i = 0; i < N; i++){
            mx = max(mx, (R[i] - L[i] - 1)* ar[i]);
        }
        cout<<mx<<endl;


    }
e
    return 0;
}

/*Each index find the index of the first smallest element on the left p1
For each index find the index of the first smallest element on the right p2
 (p1,...,p2)
 area of the histogram wiht the current height ar[i] and width (p2-p1-1)
 =  (p2-p1)*ar[i]




/*Each index find the index of the first smallest element on the left p1

for the element at current index , check if there are any smallest element on 
the left (i,e in the stack)


For each index find the index of the first smallest element on the right

for each element at current index, check if the current element can be the answer to any of the previous element 
(i.e elements of the stack) 






*/









