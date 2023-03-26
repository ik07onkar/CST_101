class Solution {
public:
    int search(vector<int>& a, int target) {
        int n = a.size(), l = 0, r = n-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(a[mid] == target) return mid;
            if(a[mid] >= a[l]){
                if(target >= a[l] && target < a[mid]) r = mid-1;
                else l = mid+1;
            }else{
                if(target > a[mid] && target <= a[r]) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};
