/*
void merge(vector<int> &A,int l,int m,int h,vector<int> &B,vector<int> &index){
    int i = l;int j = m+1;
    vector<int> tB;
    vector<int> tI;
    while(i<=m && j<=h){
        if(A[i]>A[j]){
            for(int k=i;k<=m;++k) B[index[k]]++;
            tB.emplace_back(A[j]);
            tI.emplace_back(index[j]);
            j++;
        }
        else{
            tB.emplace_back(A[i]);
            tI.emplace_back(index[i]);
            i++;
        }
    }
    while(i<=m){
        tB.emplace_back(A[i]);
        tI.emplace_back(index[i++]);
    }
    while(j<=h){
        tB.emplace_back(A[j]);
        tI.emplace_back(index[j++]);
    }
    for(i=l;i<=h;++i){
        A[i] = tB[i-l];
        index[i] = tI[i-l];
    }
    return;
}
void mergesort(vector<int> &A,int l,int h,vector<int> &B,vector<int> &index){
    if(l>=h) return;
    int m = (l+h)/2;
    mergesort(A,l,m,B,index);
    mergesort(A,m+1,h,B,index);
    merge(A,l,m,h,B,index);
    return;
}
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> B(n,0);
    vector<int> index(n);
    for(int i=0;i<n;++i) index[i] = i;
    mergesort(A,0,n-1,B,index);
    return B;
}
*/

//A different way to count inversions
struct Node{
    int val;
    int index;
};
void merge(vector<Node> &arr,int l,int m,int h,vector<int> &result){
    int i=l;
    int j = m+1;
    int count = 0;
    vector<Node> temp;
    while(i<=m && j<=h){
        if(arr[i].val > arr[j].val){
            count++;
            temp.emplace_back(arr[j]);
            j++;
        }
        else{
            result[arr[i].index]+=count;
            temp.emplace_back(arr[i]);
            i++;
        }
    }
    while(i<=m){
        result[arr[i].index]+=count;
        temp.emplace_back(arr[i++]);
    }
    while(j<=h){
        temp.emplace_back(arr[j++]);
    }
    for(int k=l;k<=h;++k){
        arr[k] = temp[k-l];
    }
    return;
}
void mergesort(vector<Node> &arr,int l,int h,vector<int> &result){
    if(l>=h) return;
    int m = (l+h)/2;
    mergesort(arr,l,m,result);
    mergesort(arr,m+1,h,result);
    merge(arr,l,m,h,result);
}
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<Node> arr(n);
    for(int i=0;i<n;++i){
        arr[i].val = A[i];
        arr[i].index = i;
    }
    vector<int> result(n,0);
    mergesort(arr,0,n-1,result);
    return result;
}
