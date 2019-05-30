#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//Brute Force Time O(n), Space O(n)
/*vector<int> repeatedNumber(const vector<int> &A) {
    unordered_map<int,int> freq;
    int n = A.size();
    for(int i=1;i<=n;++i)   freq[i] = 0;
    for(auto x:A)           freq[x]++;
    vector<int> sol(2);
    for(auto x:freq){
        if(x.second==2)     sol[0]=x.first;
        else if(x.second==0)sol[1]=x.first;
    }
    return sol;
}
*/
//Optimized Time O(n), Space O(1)
vector<int> repeatedNumber(const vector<int> &A) {
    ll n = A.size();
    ll S = (n*(n+1))/2;
    ll SS = (n*(n+1)*(2*n+1))/6;
    ll SA = 0;
    ll SSA = 0;
    for(ll x:A){
        SA += x;
        SSA += (x*x);
    }
    ll X = SA-S;
    ll Y = (SSA-SS)/X;
    vector<int> sol(2);
    sol[0] = (X+Y)/2;
    sol[1] = sol[0]-X;
    return sol;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;++i) cin>>A[i];
    vector<int> sol = repeatedNumber(A);
    cout<<sol[0]<<" "<<sol[1];
    return 0;
}
