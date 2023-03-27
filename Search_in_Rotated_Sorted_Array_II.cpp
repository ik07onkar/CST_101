class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            while(mid >= 0 && l != mid && nums[l] == nums[mid]){
                 mid--;
            }
            if(nums[mid] == target) return true;
            else if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target <= nums[mid]) r = mid - 1;
                else l = mid+1;
            }else{
                if(nums[mid] <= target && target <= nums[r]) l = mid + 1;
                else r = mid-1;
            }
        }
        return false;
    }
};
