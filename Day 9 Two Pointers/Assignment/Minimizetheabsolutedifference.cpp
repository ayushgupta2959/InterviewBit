int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0;
    int j = 0;
    int k = 0;
    int n1 = A.size();
    int n2 = B.size();
    int n3 = C.size();
    int d = INT_MAX;
    while(i<n1 && j<n2 && k<n3){
        d = min(d,abs(max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k]))));
        if(A[i]<=B[j] && A[i]<=C[k]){
            i++;
        }
        else if(B[j]<=A[i] && B[j]<=C[k]){
            j++;
        }
        else{
            k++;
        }
    }
    return d;
}
