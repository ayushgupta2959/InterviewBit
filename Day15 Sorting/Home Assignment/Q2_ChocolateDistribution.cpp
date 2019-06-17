int Solution::solve(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int diff = INT_MAX;
    int n = A.size();
    for(int i=0;i<=(n-B);++i){
        diff = min(diff,A[i+B-1]-A[i]);
    }
    if(n==0||B==0||B>n) diff = 0;
    return diff;
}

