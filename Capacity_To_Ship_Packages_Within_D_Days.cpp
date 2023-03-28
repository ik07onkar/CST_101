class Solution {
public:
    int days_(vector<int> &a, int cap)
    {
        int sum = 0, cnt = 1;
        for(int i=0; i<a.size(); i++){
            sum += a[i];
            if(sum == cap){
                cnt++; sum=0;
                if(i == a.size()-1) cnt--;
            }
            if(sum > cap){
                i--; cnt++; sum=0;
            }
        }
        return cnt;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), r = 0;
        for(auto x: weights) r += x;
        int mini = INT_MAX;
        while(l <= r){
            int mid = l+(r-l)/2;
            int curr_days = days_(weights, mid);
            if(curr_days <= days){
                mini = min(mini, mid);
                r = mid-1;
            }else l = mid+1;
        }
        return mini;
    }
};
