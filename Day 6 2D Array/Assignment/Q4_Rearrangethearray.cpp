#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &A) {
    int n = A.size();
    //To keep track of which numbers have been visited
    for(int i=0;i<n;++i) A[i]++; //To handle zero
    int index,val,j,t;
    for(int i=1;i<=n;++i){
        if(A[i-1]>0){
            val = i;
            index = A[i-1];
            while(A[index-1]>0){
                t = A[index-1];
                A[index-1] = -val;
                val = index;
                index = t;
            }
        }
    }
    for(int i=0;i<n;++i){
        A[i] = -A[i];
        A[i]--;
    }
    return A;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> A;
    int x;
    while(cin>>x) A.emplace_back(x);
    A = solve(A);
    for(auto x:A) cout<<x<<" ";
    return 0;
}
