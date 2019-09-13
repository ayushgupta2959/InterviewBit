vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> r(A,vector<int>(A));
    int x = 1;
    int lr = 0,hr = A-1;
    int lc = 0,hc = A-1;
    int i;
    while(lr<=hr && lc<=hc){
        for(i=lc;i<=hc;i++)     r[lr][i] = x++;
        for(i=lr+1;i<=hr;i++)   r[i][hc] = x++;
        for(i=hc-1;i>=lc;i--)   r[hr][i] = x++;
        for(i=hr-1;i>lr;i--)    r[i][lc] = x++;
        lr++;
        lc++;
        hr--;
        hc--;
    }
    return r;
}
