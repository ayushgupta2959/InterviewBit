int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
vector<int> Solution::solve(vector<int> &A) {
    int n = A.size();
    if(n<=1) return A;
    else if(n==2){
        return {max(A[0],A[1]),min(A[0],A[1])};
    }
    else{
        sort(A.begin(),A.end());
        int i,flag=0;
        //checking gcd ordering condition
        for(i=2;i<n;++i){
            if(A[i]!=(A[i-1] + gcd(A[i-1],A[i-2]))){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            // i.e gcd ordering condition is satisfied then checking if last element can be placed at first position
            if(A[1]!=A[0]+gcd(A[0],A[n-1])) return A;
            else{
                int t = A[n-1];
                A.pop_back();
                A.insert(A.begin(),t);
                return A;
            }
        }
        else{
            // i.e for index i gcd_ordering condition not satisfied
            // then may be we can place A[i] in the beginning if not then gcd_ordering not possible for this array
            if(A[1]!=A[0]+gcd(A[0],A[i])) return {-1};
            else{
                int t = A[i];
                int index = i;
                // means we can place A[i] in beginning but we need to check whether for rest of the array gcd ordering
                // condition is sarisfied or not
                if((i+1)<n && A[i+1]!=A[i-1]+gcd(A[i-1],A[i-2])) return {-1};
                if((i+2)<n && A[i+2]!=A[i+1]+gcd(A[i+1],A[i-1])) return {-1};
                for(i=i+3;i<n;++i){
                    if(A[i]!=(A[i-1] + gcd(A[i-1],A[i-2]))){
                        return {-1};
                    }
                }
                // if for rest of the array gcd_ordering condition is satisfied then return the resultant array as answer
                A.erase(A.begin()+i);
                A.insert(A.begin(),t);
                return A;
            }
        }
    }
}
