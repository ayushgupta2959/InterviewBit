void Solution::setZeroes(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int flag1 = 0;
    int flag2 = 0;
    for(int i=0;i<m;++i){
        if(A[i][0]==0){
            flag1 = 1;
            break;
        } 
    }
    for(int j=0;j<n;++j){
        if(A[0][j]==0){
            flag2 = 1;
            break;
        }
    }
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            if(A[i][j]==0){
                A[0][j] = -1;
                A[i][0] = -1;
            }
        }
    }
    for(int i=1;i<m;++i){
        if(A[i][0]==-1){
            for(int j=0;j<n;++j) A[i][j]=0;
        }
    }
    for(int j=1;j<n;++j){
        if(A[0][j]==-1){
            for(int i=0;i<m;++i) A[i][j] = 0;
        }
    }
    if(flag1){
        for(int i=0;i<m;++i) A[i][0] = 0;
    }
    if(flag2){
        for(int j=0;j<n;++j) A[0][j] = 0;
    }
}
