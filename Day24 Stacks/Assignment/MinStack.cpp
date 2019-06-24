typedef pair<int,int> pi;
vector<pi> s;
int n;
MinStack::MinStack() {
    s.clear();
    n=0;
}

void MinStack::push(int x) {
    if(n==0){
        n++;
        s.emplace_back(make_pair(x,n));
    }
    else{
        pi t = s[n-1];
        if(t.first<x){
            s.erase(s.end()-1);
            n++;
            s.emplace_back(make_pair(x,n));
            s.emplace_back(t);
        }
        else{
            n++;
            s.emplace_back(make_pair(x,n));
        }
    }
}

void MinStack::pop() {
    if(n==0) return;
    if(s[n-1].second==n){
        s.erase(s.end()-1);
        n--;
        return;
    }
    else{
        pi t = s[n-1];
        s.erase(s.end()-1);
        s.erase(s.end()-1);
        s.emplace_back(t);
        n--;
        return;
    }
}
int MinStack::top() {
    if(n==0) return -1;
    if(s[n-1].second==n){
        return s[n-1].first;
    }
    else{
        return s[n-2].first;
    }
}
int MinStack::getMin() {
    if(n==0) return -1;
    return s[n-1].first;
}


