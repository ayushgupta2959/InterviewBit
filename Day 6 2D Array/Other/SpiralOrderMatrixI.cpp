vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> result;
    int l = 0,r=A[0].size()-1,u=0,b=A.size()-1;
    while(l<=r && u<=b){
        for(int i=l;i<=r;i++) result.emplace_back(A[u][i]);
        for(int i=u+1;i<=b;i++) result.emplace_back(A[i][r]);
        if(u!=b) for(int i=r-1;i>=l;i--) result.emplace_back(A[b][i]);
        if(l!=r) for(int i=b-1;i>u;i--) result.emplace_back(A[i][l]);
        l++;
        r--;
        u++;
        b--;
    }
    return result;
}
