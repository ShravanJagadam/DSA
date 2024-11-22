/*Triple Trouble 
Given an array of size 3X+1, where every element occurs three times, except one element, which occurs only once. Find the element that occurs only once.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines, the first line contains N - the size of the array (of the form 3X + 1) and second line contains the elements of the array.



Output Format

For each test case, print the number which occurs only once, separated by new line.



Constraints

30 points

1 <= T <= 100

1 <= N <= 103



70 points

1 <= T <= 100

1 <= N <= 106



Example

Input

2

10

5 7 8 7 7 9 5 9 5 9

7

10 20 20 30 20 30 30



Output

8

10



Explanation



Self Explanatory*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    //get each bit of the element that is missing 
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ar[n];
        for(int i =0;i<n; i++){
            cin>>ar[i];
        }
        // in the 31 bits calculate the no of elements whose bits are 1 
        // and whose bits are 0
        // if the number of element having ith bit are not a mutliple 
        // of 3, then the non-repeating element also  have the same bit 
        // as its ith bit 
        int ans = 0;
        for(int i=0;i<=30;i++){
            int c1 = 0;//count of 1s at ith bit
            for(int j =0;j<n; j++){
                
                if((ar[j]>>i) & 1 == 1)
                    c1++;
            }
            if(c1%3 != 0)
                ans = ans + (1<<i);

        }
        cout<<ans<<endl;
    }
    
    return 0;
}