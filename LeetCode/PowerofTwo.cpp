/* Question here: https://leetcode.com/problems/power-of-two/ */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n > 0){
            if(n == 1)
                return true;
            if(n&(n-1)){
                return false;
            }else{
                return true;
            }
        }else{
            return false;
        }
    }
};
