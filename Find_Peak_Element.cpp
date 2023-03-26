class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int l = 0, r = a.size()-1;
        if(a.size() == 1) return 0;
        while(l <= r){
            int mid = (l+r)/2;
            if((mid == a.size()-1) && (a[mid] > a[mid-1])) return mid;
            if((mid == 0) && (a[mid] > a[mid+1])) return mid;
            if((mid > 0 && a[mid] > a[mid-1]) && (mid < a.size()-1 && a[mid] > a[mid+1])){
                return mid;
            }else if(mid < a.size()-1 && a[mid+1] > a[mid]) l = mid+1;
            else r = mid-1;
        }
        return -1;
    }
};
