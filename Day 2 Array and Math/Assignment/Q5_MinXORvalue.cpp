#include<bits/stdc++.h>
using namespace std;
int findMinXorRecur(vector<int> &A,int b){
    int n = A.size();
    if(n==0||n==1) return INT_MAX;
    if(n==2){
        return A[0]^A[1];
    }
    vector<int> v1;
    vector<int> v0;
    int mask = 1<<b;
    for(int x:A){
        if(x&mask) v1.emplace_back(x);
        else v0.emplace_back(x);
    }
    int t1 = findMinXorRecur(v0,b-1);
    int t2 = findMinXorRecur(v1,b-1);
    return min(t1,t2);
}
int findMinXor(vector<int> &A){
    return findMinXorRecur(A,30);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x;
    vector<int> A;
    while(cin>>x){
        A.emplace_back(x);
    }
    //cout<<findMinXor(A)<<"\n";
    for(auto x:A)cout<<x<<" ";
    return 0;
}
