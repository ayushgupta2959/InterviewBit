int lexCompare(string x,string y){
    int lx = x.length();
    int ly = y.length();
    if(lx>ly) return 1;
    else if(ly>lx) return -1;
    else{
        int i=0;
        while(i<lx){
            if(x[i]>y[i]) return 1;
            else if(y[i]>x[i]) return -1;
            i++;
        }
    }
    return 0;
}
int Solution::compareVersion(string A, string B) {
    int la = A.length();
    int lb = B.length();
    string parseA,parseB;
    int i=0,j=0;
    int result;
    while(i<la || j<lb){
        parseA = "";
        parseB = "";
        //removing 0 prefix from both strings
        while(i<la && A[i]=='0') i++;
        while(j<lb && B[j]=='0') j++;

        while(i<la && A[i]!='.'){
            parseA+=A[i];
            i++;
        }
        while(j<lb && B[j]!='.'){
            parseB+=B[j];
            j++;
        }
        int result = lexCompare(parseA,parseB);
        if(result!=0) return result;
        i++;j++;
    }
    return 0;
}
