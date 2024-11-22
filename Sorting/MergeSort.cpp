/*Smaller Elements 
You are given an array of integers. For each element in the array, find the number of smaller elements on the right side and print the total count.



Input Format

The first line of input contains T - the number of test cases. It's followed by 2T lines, the first line contains N - the size of the array. The second line contains the elements of the array.



Output Format

For each test case, print the sum of count of smaller elements on right side of each element in the array, separated by new line.



Constraints

30 points

1 <= N <= 103



70 points

1 <= N <= 105



General Constraints

1 <= T <= 100

-104 <= A[i] <= 104﻿



Example

Input

2

5

4 10 54 11 8

6

15 35 25 10 15 12



Output

4

10



Explanation



Test Case 1

Smaller Elements on right side of 4 : 0

Smaller Elements on right side of 10 : 1

Smaller Elements on right side of 54 : 2

Smaller Elements on right side of 11 : 1

Smaller Elements on right side of 8 : 0

Total Count = 0 + 1 + 2 + 1 + 0 = 4



Test Case 2

Smaller Elements on right side of 15 : 2

Smaller Elements on right side of 35 : 4

Smaller Elements on right side of 25 : 3

Smaller Elements on right side of 10 : 0

Smaller Elements on right side of 15 : 1

Smaller Elements on right side of 12 : 0

Total Count = 2 + 4 + 3 + 0 + 1 + 0 = 10
    */

    #include <bits/stdc++.h>
using namespace std;

int c = 0;

void merge(int ar[], int low, int high){

    int temp[high-low+1];

    int mid = (low+high)/2;
    int p1 = low, p2 = mid+1, idx = 0;//2 pointers for two arrays

    while(p1 <= mid && p2 <= high){
        if(ar[p1] <= ar[p2]){
            temp[idx++] = ar[p1++];
        }
        else
        {
            c += (mid-p1+1);
            //cout<<"element inseted is "<<ar[p2]<<endl;
            temp[idx++] = ar[p2++];
        }
    }
    while(p1<=mid){
        temp[idx++] = ar[p1++];
    }
        
    while(p2<=high)
        temp[idx++] = ar[p2++];

        //copy the elements into the original array (low,high)
    for(int i = 0; i<high-low+1; i++){
        ar[low+i] = temp[i]; 
    }

}
void MS(int  ar[], int low, int high){
    if(low == high)//when there is only one element in partiton
        return;

    int mid = (low+high)/2;
    MS(ar,low, mid);
    MS(ar,mid+1,high);

    merge(ar,low,high);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t ; cin >> t;

    while(t--){
        c = 0;
        int N; cin >> N;
        int ar[N];
        for(int i =0; i<N; i++)
            cin >> ar[i];

        int l = 0, h = N-1;
        MS(ar,l,h);



        cout<<c<<endl;
    }

    return 0;
}