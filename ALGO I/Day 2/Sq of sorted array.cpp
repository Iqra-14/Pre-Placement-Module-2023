class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int N = A.size();
        int forward = 0;
        while(forward < N && A[forward] < 0){
            forward++;
        }
        int backward = forward - 1; 
        
        //now A[forward] >=0 and A[backward] < 0
        
        vector<int> ans(N);
        int cursor = 0; 
        
        while(backward >= 0 && forward < N){
            if(A[backward]*A[backward] < A[forward]*A[forward]){
                ans[cursor++] = A[backward]*A[backward];
                backward--;
            } else{
                ans[cursor++] = A[forward]*A[forward];
                forward++;
            }
        }
        
        while(backward >= 0){
            ans[cursor++] = A[backward]*A[backward];
            backward--;
        }
        
        while(forward < N){
            ans[cursor++] = A[forward]*A[forward];
            forward++;
        }
        return ans;
    }
};