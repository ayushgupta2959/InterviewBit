int Solution::solve(vector<int> &A, int B) {
    //if B>(n/2) s1 will be maximum B elements and s2 will be rest of the elements
    // if B<=(n/2) s2 will be minimum B elements s1 will be rest maximum elements
    sort(A.begin(),A.end());
    int n = A.size();
    B = min(B,n-B);
    long long s1 = 0;
    int i=0;
    for(;i<B;++i){
        s1+=A[i];
    }
    for(;i<n;++i){
        s1-=A[i];
    }
    return abs(s1);
}
