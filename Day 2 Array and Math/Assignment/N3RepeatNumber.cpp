int Solution::repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int a = INT_MAX;
    int b = INT_MAX;
    int ca = 0;
    int cb = 0;
    
    //generating candidates
    for(auto x:A){
        if(x == a) ca++;
        else if(x == b) cb++;
        else if(ca == 0) { a = x; ca = 1;}
        else if(cb == 0) { b = x; cb = 1;}
        else{
            ca--;cb--;
        }
    }
    
    //validating candidates
    ca = 0;cb = 0;
    for(auto x:A){
        if(x == a) ca++;
        else if(x == b)cb++;
    }
    if(ca>(n/3)) return a;
    if(cb>(n/3)) return b;
    return -1;
}
