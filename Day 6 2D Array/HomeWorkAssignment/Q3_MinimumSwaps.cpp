#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &A, int B) {
    int n = A.size();
    int i=0;int j=n-1;
    int c=0;
    while(i<j){
        while(i<j && A[i]<=B) i++;
        while(i<j && A[j]>B) j--;
        if(i<j){
            swap(A[i],A[j]);
            c++;
        }
    }
    for(auto x:A)cout<<x<<" ";
    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,B;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;++i) cin>>A[i];
    cin>>B;
    for(auto x:A)cout<<x<<" ";
    cout<<"\n";
    cout<<solve(A,B);
    return 0;
}
