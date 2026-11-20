class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int p=-1,n=A.size();

        for(int i=n-2;i>=0;i--){
            if(A[i]<A[i+1]){
                p=i;
                break;
            }
        }
        if (p==-1){
            reverse(A.begin(), A.end());
            return;
        }
        for(int i=n-1;i>p;i--){
            if(A[i]>A[p]){
                swap(A[i], A[p]);
                break;
            }
        }
        int i=p+1, j=n-1;

        while(i<=j){
            swap(A[i++], A[j--]);
        }
    }
};