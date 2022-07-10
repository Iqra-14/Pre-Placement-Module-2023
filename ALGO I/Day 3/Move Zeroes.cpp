class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();
        int l = 0, r = 0;
       while(r < n && l < n) {
           while(l < n - 1 && nums[l] != 0) {
               ++l;
           }
            while(r < n- 1 && (r <= l || nums[r] == 0)) {
               ++r;
           }
           swap(nums[l++], nums[r++]);
       }
    }
};