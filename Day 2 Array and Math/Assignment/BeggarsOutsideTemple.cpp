vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    //Difference Array Concept
    vector<int> D(A,0);
    for(auto x:B){
        D[x[0]-1] += x[2];
        if(x[1]<(A)) D[x[1]] -= x[2];
    }
    for(int i=1;i<A;++i){
        D[i] += D[i-1];
    }
    return D;
}
