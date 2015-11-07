/* Question here: https://leetcode.com/problems/rotate-array/ */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(nums.size() == 0)
            return;
        int nk = k % n;
        
        re(nums, 0, n-1);
        re(nums, nk, n-1);
        re(nums, 0, nk-1);

    }
    
    void re(vector<int>& nums, int start, int end){
        int tmp;
        
        while(start < end){
            tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start ++;
            end --;
            
        }
    }
    
};
