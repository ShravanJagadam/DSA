/*Largest Concatenated Number 
Given an array of integers, find the largest number that can be constructed by concatenating all the elements of the given array.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines. The first line of each test case contains N - the size of the array and the second line contains N integers - the elements of the array.



Output Format

For each test case, print the largest number that can be constructed by concatenating all the elements of the given array, separated by a new line.



Constraints

1 <= T <= 1000

1 <= N <= 1000

0 <= ar[i] <= 1000



Example

Input

3

8

49 73 58 30 72 44 78 23

4

69 9 57 60

2

40 4



Output

7873725849443023

9696057

440



Explanation



Self Explanatory
*/

#include <bits/stdc++.h>
using namespace std;

bool myCompare (string &a,string &b){
    return a+b > b+a;
}

    

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t ; cin >> t;

    while(t--){

        int N; cin >> N;
        vector<string> s(N);

        for(int i =0;i<N; i++){
            int x; cin >>x;
            s[i] = to_string(x);
        }

        

        
        sort(s.begin(), s.end(), myCompare);

        for(int i =0;i<N; i++) cout<<s[i];
    
        cout<<endl; 

    }

    return 0;
}