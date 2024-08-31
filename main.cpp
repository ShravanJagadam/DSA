#include <bits/stdc++.h>
using namespace std;
// to set precision use fixed,setprecision(number_of_points_after_decimal)
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define mod 1000000007
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define pb push_back
#define debugvector(h) \
  for (auto &l : h)    \
  cout << l << " "
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef long double ld;
typedef long long int lli;

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int d){
        data = d;
        prev = NULL; 
        next = NULL;
    }
};
int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    //************************
    //start you code here

    #include <bits/stdc++.h>
using namespace std;

class LRUCache{
    public:

        class Node{
            public:
            int key;
            int val;
            Node *prev;
            Node *next;

            Node(int key,int val){
                this->key = key;
                this->val = val;
            }
        };

    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);

    void addNode(Node *newnode){
        Node *temp = head->next;

        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(Node *delnode){
        Node *prevv = delnode->prev;
        Node *nextt = delnode->next;

        nextt->prev = prevv;
        prevv->next = nextt;
    }

    int cap;
    unordered_map<int, Node *> m;

    LRUCache(int capacity){
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }

    int get(int key){
        if(m.find(key) != m.end()){
            Node *resNode = m[key];
            int ans = resNode->val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key,int value){
        if(m.find(key) !=m.end()){
            Node *curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        m[key] = head->next;
    }

    vector<int> getCurrentCache(){
        vector<int> cacheContent;
        Node *temp = head->next;
        while(temp!=tail){
            cacheContent.push_back(temp->key);
            temp = temp->next;
        }
        return cacheContent;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        LRUCache cache(k);

        for(int i=0;i<n;i++){
            int page;
            cin>>page;
            cache.put(page,1);
        }

        vector<int> finalCache = cache.getCurrentCache();
        reverse(finalCache.begin(),finalCache.end());
        for(int i=0;i<finalCache.size();i++){
            cout<< finalCache[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
   

    //************************

static const int __ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

