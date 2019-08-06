string Solution::convertToTitle(int A) {
    string result = "";
    while(A>0){
        A--;
        int rem = A%26;
        result+= ('A'+rem);
        A/=26;
    }
    reverse(result.begin(),result.end());
    return result;
}
