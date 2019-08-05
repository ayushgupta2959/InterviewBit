void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int m = A.size();
    int n = A[0].size();
    bool flag = false;
    bool firstcol = false;
    bool firstrow = false;
    if(A[0][0]==0) flag=true;
    if(!flag){
        for(int i=1;i<m;++i) {
            if(A[i][0]==0){
                A[0][0] = 0;
                firstcol = true;
                break;
            }
        }
        for(int i=1;i<n;++i) {
            if(A[0][i]==0){
                A[0][0] = 0;
                firstrow=true;
                break;
            }
        }
    }
    for(int i=1;i<m;++i){
        for(int j=1;j<n;++j){
            if(A[i][j]==0){
                A[i][0]=0;
                A[0][j]=0;
            }
        }
    }
    for(int i=1;i<m;++i){
        if(A[i][0]==0){
            for(int j=1;j<n;++j) A[i][j]=0;
        }
    }
    for(int j=1;j<n;++j){
        if(A[0][j]==0){
            for(int i=1;i<m;++i) A[i][j]=0;
        }
    }
    if(flag){
        for(int i=0;i<n;++i) A[0][i]=0;
        for(int i=0;i<m;++i) A[i][0]=0;
    }
    else{
        A[0][0]=1;
        if(firstrow){
            for(int i=0;i<n;++i) A[0][i]=0;
        }
        if(firstcol){
            for(int i=0;i<m;++i) A[i][0]=0;
        }
    }
}
