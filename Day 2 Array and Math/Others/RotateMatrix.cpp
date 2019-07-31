void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            swap(A[i][j],A[j][i]);
        }
    }
    /*
    for(auto x:A){
        for(auto y:x) cout<<y<<" ";
        cout<<"\n";
    }
    */
    
    int i=0;
    int j=n-1;
    while(i<=j){
        for(int r=0;r<n;++r){
            swap(A[r][i],A[r][j]);
        }
        i++;
        j--;
    }
    
}
