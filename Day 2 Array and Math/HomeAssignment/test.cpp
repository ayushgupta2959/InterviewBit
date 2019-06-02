#include<bits/stdc++.h>
using namespace std;
vector<int> solve(){
    vector<int> A;
    A.emplace_back(1);
    A.emplace_back(1);
    A.emplace_back(1);
    A.emplace_back(1);
    A.emplace_back(1);
    A.emplace_back(1);
    return {A.begin(),A.begin()+3};
}
void solve2(){
    vector<int> A = {1,2,3,4,5,6};
    for(auto x:vector<int>(A.rbegin(),A.rend())){
        cout<<x<<" ";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    /*
    vector<int> x = solve();
    for(auto y:x) cout<<y<<" ";
    cout<<"\n";
    cout<<INT_MAX<<"\n";
    cout<<"3507897352";
    */
    //solve2();
    cout<<(5%0);
    return 0;
}
