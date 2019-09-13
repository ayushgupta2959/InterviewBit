int Solution::singleNumber(const vector<int> &A) {
    int t = A[0];
    int n=A.size();
    for(int i=1;i<n;++i) t^=A[i];
    return t;
}
