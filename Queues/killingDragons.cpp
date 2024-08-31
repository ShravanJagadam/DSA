/*
Killing Dragons 
A prince is on a mission to save the princess. On the way, there is a circular track with N dungeons. Each dungeon has a dragon, which can be defeated with an energy Ai. Each dungeon also has an vessel with an energy drink, whose energy level is Bi kept for consumption. In order to save the princess, the prince has to defeat all the dragons. The prince can chose which dungeon to start from.



Please note the following points:



The prince cannot defeat a dragon if his current energy level is less than the energy required to kill a dragon.
The prince uses only minimum amount of energy to defeat the dragon, and carries the rest with him.
The prince is so exhausted in the search for the princess, that when he reaches the circular track his energy level is 0.
Once the prince enters the circular track, he can advance only in forward direction in order to kill the next dragon.


Input Format

The first line of input contains T - number of test cases. Its followed by 3T lines. First line contains N - the number of dungeons.

Second line contains N integers - the amount of energy required to defeat the dragon, starting from the 1st dungeon.

Third line contains N integers - the amount of energy in the vessel, starting from the 1st dungeon.



Output Format

For each test case, print the dungeon number starting at which, the prince can defeat all the dragons. If there are multiple possible answers, print the smallest number. If the prince cannot defeat the dragons, print -1.



Constraints

30 points

1 <= T <= 10

1 <= N <= 1000

1 <= Ai, Bi <= 1000



70 points

1 <= T <= 10

1 <= N <= 100000

1 <= Ai, Bi <= 1000



Example

Input

3

3

1 5 7

2 6 3

4

5 10 12 4

20 2 1 15

3

7 10 6

8 9 7



Output

-1

4

1



Explanation



Test Case 1:

From the 1st dungeon, the prince has 2 units of energy after fighting 2 dragons, not enough for the 3rd.

From the 2nd dungeon, the prince has 1 unit of energy after fighting 1 dragon, not enough for the 3rd.

From the 3rd dungeon, the prince doesn't have enough energy to fight the 3rd dragon.



Test Case 2:

From the 1st dungeon, the prince has 7 units of energy after fighting 2 dragons, not enough for the 3rd.

From the 2nd dungeon, the prince doesn't have enough energy to fight the 2nd dragon.

From the 3rd dungeon, the prince doesn't have enough energy to fight the 3rd dragon.

From the 4th dungeon, the prince has 11 units of energy after fighting the 4th dragon, 26 after the 1st, 18 after the 2nd, and 7 after the 3rd, ensuring victory.*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;

    while(t--){

        lli N; cin >> N;
        vector<lli> drag(N);
        vector<lli> ener(N);

        lli total_ener= 0;
        lli total_drag = 0;


        for(lli i =0;i<N; i++){
            cin >> drag[i]; 
            total_drag += drag[i];
        }

        for(lli i =0;i<N; i++){
            cin >> ener[i]; 
            total_ener += ener[i];
        }

        

        if(total_drag > total_ener )
        {
            cout<<-1<<endl;
            continue;
        }


        
        
        lli r_idx;//running index
        queue<lli> q;
        lli ans  = -1;

        //find the first starting position in the N positions
        for(lli i = 0;i<N; i++){
            if(ener[i] >= drag[i]){
                r_idx = i;
                break;
            }
                
        }
        lli cur_ener;
        cur_ener = ener[r_idx];
        
        
        while(1){
            
            while(cur_ener >= drag[r_idx]){

                q.push(r_idx);
                cur_ener = cur_ener - drag[r_idx];

                if(q.size() == N)
                {
                    ans = q.front()+1;
                    break;
                }
                r_idx = (r_idx+1)%N;
                cur_ener= cur_ener + ener[r_idx];
            }
            if(ans != -1)
             break;

            while(cur_ener < drag[r_idx]){
                if(!q.empty()){
                    int k  = q.front();
                    cur_ener -= ener[k];//remove  the first energy
                    cur_ener += drag[k];//add the first drag(opposite of line 175)
                    q.pop();
                }
                else{
                    while(ener[r_idx] < drag[r_idx]){
                        r_idx = (r_idx + 1)%N; 
                    }
                    cur_ener = ener[r_idx];
                                      
                }
                
                //cout<<"*7*"<<endl;
                
            }
            //cout<<"*8*"<<endl;
        }
        cout<<ans<<endl;   
    }

    return 0;
}