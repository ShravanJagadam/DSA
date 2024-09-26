/*
Find Excel Column Name
Given a positive integer N, which represents the column number of a standard excel sheet, find its corresponding column title.



Input Format

First line of input contains T - number of test cases. It is followed by T lines, each line contains a single integer N.



Output Format

For each test case, print the column title, separated by newline.



Constraints

1 <= T <= 105

1 <= N <= 1018



Example

Input

4

1

26

27

28



Output

A

Z

AA

AB



Explanation



Self Explanatory
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  

      int t; cin >> t; 
      while(t--){
          long long int N ; cin >> N; 
          
          string ans = "";
         
          while(N){
              N -= 1;
              ans = char(N%26 + 65) + ans;
              N = N/26;
          }
          cout<<ans<<endl;
      }
    return 0;
}


/*   
Approach : 
0-Z
1-A
2-B
3-C*/