#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    int n1 = A.size();
    int n2 = B.size();
    int i=0;
    int j=n2-1;
    int ri,rj;

    int ans = INT_MAX;
    int diff;
    while(i<n1 && j>=0){
        diff = A[i]+B[j]-C;
        if(abs(diff)<ans){
            //cout<<"Yes\n";
            //cout<<abs(diff)<<"\n";
            ans = abs(diff);
            cout<<ans<<"\n";
            ri = i;
            rj = j;
        }
        else if((abs(diff)==ans) && i<=ri){
                cout<<"updated\n";
                ri = i;
                rj = j;
        }
        else{;}
        if(diff<0) i++;
        else j--; // to handle case when diff==0 we need minimum j for this case
        //break;
    }
    return {A[ri],B[rj]};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n1,n2;
    cin>>n1>>n2;
    vector<int> a,b;
    int x;
    while(n1--){
        cin>>x;
        a.emplace_back(x);
    }
    while(n2--){
        cin>>x;
        b.emplace_back(x);
    }
    int c;
    cin>>c;
    vector<int> result = solve(a,b,c);
    for(auto y:result) cout<<y<<" ";
    cout<<"\n";
    return 0;
}
