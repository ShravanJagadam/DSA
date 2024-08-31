#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    lli t ; cin >> t;
    int ar[1000];
    lli p1 = -1, p2 = -1;
    int size  = 0;

    string s; 
    
    while(t--){

        //lets implement a circular queue
        cin >> s; 
        int x ;

        

        if(s == "Enqueue")
        {
            cin >> x ;
            p2 = p2 +1;
            ar[p2%1000] = x;
            size++;
            
        }else{
            if(size  == 0)
                cout<<"Empty"<<endl;
            else{
                p1 = (p1+1)%1000;
                cout<<ar[p1]<<endl;
                size--;
            }
            
                                    
        }
    }

    return 0;
}



/*
Approach : 



intialize 2 pointers front and rear 

f = -1, r = -1; 

-->Each time you want to add an element increment r and add element at index "r";
-->and increment the size as well
-->Each time you want to deque an element, we increment and the front pointer 
-->If the space is a constraint we can implement the circular Queue by taking mod N

*/