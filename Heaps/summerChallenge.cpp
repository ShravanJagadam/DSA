/*Summer Challenge 
During the summer break for the "Smart Interviews" course, the instructor wants to ensure that students maintain their problem-solving skills. To achieve this, a sequence of N contests has been created. Each contest consists a specific set of problems.



The student has the capability of solving K problems per day. Each day, he has to pick the contest that has the highest number of problems. If there are several contests with the same number of problems, the student picks the one with the earlier occurrence in the sequence. The student cannot pick multiple contests on a single day, he can only choose a single contest on a day.



The student continues to pick contests until all contest problems are solved. Determine the order in which contests will be completed by the student.



Input Format

The first line of input contains T - the number of test cases. The first line of each test case contains two integers N - the number of contests and K - the capability of the student to solve the problems in a single day. The second line of each test case contains N integers, denoting the number of problems in each contest.



Output Format

Print the indices of the array in which the student completes all the N-contests.



Constraints

30 points

1 <= T <= 10

1 <= N <= 100

1 <= A[i], K <= 100



70 points

1 <= T <= 100

1 <= N <= 105

1 <= A[i], K <= 109



Example

Input

3

3 2

1 2 3

2 3

1 1

4 3

2 8 3 5



Output

2 1 3

1 2

3 1 2 4



Explanation



Test Case 1:

On each day the number of problems in the contest change as follows: [1,2,3]→[1,2,1]→[1,0,1]→[0,0,1]→[0,0,0].



Test Case 2:

On each day the number of problems in the contest change as follows: [1,1]→[0,1]→[0,0].



Test Case 3:

On each day the number of problems in the contest change as follows: [2,8,3,5]→[2,5,3,5]→[2,2,3,5]→[2,2,3,2]→[2,2,0,2]→[0,2,0,2]→[0,0,0,2]→[0,0,0,0].
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    auto myCmp = [](pair<int,int> a, pair<int,int> b){
        if(a.first != b.first)
            return a.first < b.first;
        else
            return a.second > b.second;
    };

    while(t--){

        /*

        lli N,K; cin >> N >> K;
        priority_queue< pair<int,int> ,
              vector<pair<int,int> >,
              decltype(myCmp)    >      maxheap(myCmp);
        int x;
        for(int i =0;i<N; i++){
            cin >> x;
            maxheap.push({x,i+1});
        }

        while(maxheap.size() != 0){

            pair<int,int> p = maxheap.top();
            maxheap.pop();

            if(p.first - K <= 0)
                cout<<p.second<<" ";
            else{
                maxheap.push({p.first - K,p.second});
            }
        }
        cout<<endl;*/
        lli N,K; cin >> N >> K;
        int x;
        priority_queue< pair<int,int> ,
              vector<pair<int,int> >,
              decltype(myCmp)    >      maxheap(myCmp);//{element,index}
        for(int i =0;i<N; i++){
            cin >> x;
            if(x%K  == 0 )
                cout<<i+1<<" ";
            else
                maxheap.push({x%K,i+1});
        }
        while(maxheap.size() != 0){

            pair<int,int> p = maxheap.top();
            maxheap.pop();

            cout<<p.second<<" ";
        }
        cout<<endl;
    }

    return 0;
}
/*
Approach 1: 
Intially we are inserting all pairs of {element,index}
directly into the heaps and each time , we are extracting the max element 
and then subtracting it by K, times , then if it is still greater than K 
then we put it back into the heap or else we discard the element and print its index




Approach : 2
Instead of directly inserting the {element,index} paris into the 
heaps , insert {element%K, index}, so as to decrease the number of iterations 
and in each iteration we process single element and discard it 

-->get the max element ,print it and discard it (since now all the elements int
the heap are less than K )




*/