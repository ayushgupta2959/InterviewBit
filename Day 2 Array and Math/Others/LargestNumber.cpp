bool comparator(string x,string y){
    string a = x+y;
    string b = y+x;
    int l = a.length();
    int i = 0;
    while(i<l){
        if(a[i]<b[i]) return false;
        else if(a[i]>b[i]) return true;
        else i++;
    }
    return true;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string> s;
    int count=0;
    for(auto x:A){
        if(x==0) count++;
        s.emplace_back(to_string(x));
    }
    sort(s.begin(),s.end(),comparator);
    string result = "";
    for(auto x:s) result += x;
    if(count==result.length()) return "0";
    else return result;
}
