#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
using namespace __gnu_pbds;
using namespace std;
 
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
 
#define ld long double
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define input(v,n) for(ll i=0; i<n; i++) cin>>v[i]
#define output(v,n) for(ll i=0; i<n; i++) cout<<v[i]<<" "
#define ll long long
#define ff first
#define se second
// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
 typedef tree<ll, null_type, less<ll>, rb_tree_tag,
              tree_order_statistics_node_update>
     new_data_set;

class LRUCache{
    
    // 
    list<int> dq;
    int csize;
    
    unordered_map<int , list<int>:: iterator> ta;
    public:
    LRUCache(int);
    void refer(int x);
    void display();
};

LRUCache::LRUCache(int n){
    csize=n;
}
void LRUCache::refer(int x){
    
    // not present in cache
    if(ta.find(x)==ta.end()){
        //  if cache is full
        if(dq.size()==csize){
            int last=dq.back();
            dq.pop_back();
            ta.erase(last);
        }
    }else{
        dq.erase(ta[x]);
    }
    dq.push_front(x);
    ta[x]=dq.begin();
}

void LRUCache::display(){
    for(auto it=dq.begin(); it!=dq.end(); it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
}

  
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    LRUCache ca(4);
  
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
    
    
    return 0;   
}
