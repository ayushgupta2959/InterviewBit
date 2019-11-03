int compare_numerically(string &A,string &B){
    int la = A.length();
    int lb = B.length();
    if(la < lb) return -1;
    else if(la > lb) return 1;
    
    int l = A.length();
    for(int i = 0;i < l; ++i){
        if(A[i] < B[i]) return -1;
        else if(A[i] > B[i]) return 1;
    }
    return 0;
}
void recur(string x,string &A, string &B,int &result,vector<pair<string,string>> &mapping){
    if(compare_numerically(x,B)==1) return;
    for(auto &element:mapping){
        recur(element.first + x + element.second,A,B,result,mapping);
    }
    if(compare_numerically(x,A)!=-1){
        if(x[0]!='0') result++;
    }
}
int Solution::solve(string A, string B) {
    int result = 0;
    vector<string> starter = {"0","00","1","11","8","88","69","96"};
    vector<pair<string,string>> mapping = {{"0","0"},{"1","1"},{"8","8"},{"6","9"},{"9","6"}};
    if(A=="0") result++;
    for(auto x:starter){
        recur(x,A,B,result,mapping);
    }
    return result;
}
