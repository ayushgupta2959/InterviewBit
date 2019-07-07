void Solution::reverseWords(string &A) {
    //stack would be better ds in this case
    vector<string> words;
    string word;
    int i=0;
    int l = A.length();
    while(i<l){
        word="";
        while(i<l && A[i]!=' '){word+= A[i]; i++;}
        if(word.length()) words.emplace_back(word);
        while(i<l && A[i]==' ') i++;
    }
    A="";
    int n = words.size();
    for(int i=n-1;i>0;--i){
        A+=words[i];
        A+=" ";
    }
    A+=words[0];
}

