// #include <iostream>
// using namespace std;

// cout << __builtin_popcount(7) << endl;
// cout << __builtin_popcount(13) << endl;
// //* built in function to count number of set bits (number of 1's);
#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair <int,int> p;
typedef pair <p,int> t;
const int N = 2e5+23;

int a[N],b[N];
vector <vector<p>> cycles; /// all the cycles are stored here (actually the swaps that are needed to sort them)
vector <p> swaps;
vector <t> sol;

void op(int i,int j,int k){
    sol.push_back(t(p(i,j),k));
}

void solve(){
    cycles.clear();
    swaps.clear();
    sol.clear();
    int n,parity = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    vector <vector<p>> oddcycles; /// we'll put all cycles of odd length here
    for(int i = 1; i <= n; i++){ /// now we single out the cycles
        vector <p> v;
        while(a[i] != i){ /// a[i] is the position where the element currently on position i should go
            v.push_back(p(i,a[i])); /// add this swap
            parity++;
            swap(a[i],a[a[i]]);
        }
        if(v.size()){
            if(v.size()%2 == 0){ /// if this cycle is of even size put it into cycles
                cycles.push_back(v);
            }
            else{ /// if it is of odd size put it here
                oddcycles.push_back(v);
            }
        }
    }
    for(int i = 0; i < oddcycles.size(); i++){ 
        cycles.push_back(oddcycles[i]);
    }
    if(parity%2 == 1){ /// if the permutation is odd it is impossible to sort it using given operations
        cout << "NO\n";
        return;
    }
    else 
    {
        cout << "YES\n";
        return;
    }
    // if(n == 3){ /// base cases, probably not needed
    //     if(b[1] == 1){
    //         cout << "0\n";
    //     }
    //     else if(b[1] == 2){
    //         cout << "1\n";
    //         cout << "1 2 3\n";
    //     }
    //     else{
    //         cout << "1\n";
    //         cout << "1 3 2\n";
    //     }
    //     return;
    // }
    // for(auto f : cycles){ /// from now on we just need the whole list of swaps, that is the vector 'swaps'
    //     for(auto g : f){
    //         if(g.first > g.second){
    //             swap(g.first,g.second);
    //         }
    //         swaps.push_back(g);
    //     }
    // }
    // for(int x = 0; x < swaps.size(); x += 2){ /// we process the swaps two by two
    //     p f = swaps[x],g = swaps[x+1];
    //     int i1 = f.first,j1 = f.second,i2 = g.first,j2 = g.second;
    //     if(i1 > j1){
    //         swap(i1,j1);
    //     }
    //     if(i2 > j2){
    //         swap(i2,j2);
    //     }
    //     /// if any two indices are equal then these two swaps belong to the same cycle and we can do them using one operation
    //     if(i1 == i2){
    //         op(i1,j1,j2);
    //         continue;
    //     }
    //     if(j1 == j2){
    //         op(j1,i1,i2);
    //         continue;
    //     }
    //     if(i1 == j2){
    //         op(i1,j1,i2);
    //         continue;
    //     }
    //     if(i2 == j1){
    //         op(j1,i1,j2);
    //         continue;
    //     }
    //     /// otherwise we have four different indices i1,j1,i2,j2 and we can do them together using two operations
    //     op(i1,j1,j2);
    //     op(i2,j2,i1);
    // }
    // cout << sol.size() << "\n";
    // for(auto f : sol){
    //     cout << f.first.first << " " << f.first.second << " " << f.second << "\n";
    // }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--){
        solve();
    }
    return 0;
}