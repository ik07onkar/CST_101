class Solution {
public:
    int n, m;
    pair<int, int> getindex(int ind)
    {
        int row = ind/m, col = ind%m;
        return {row, col};
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        n = matrix.size(), m = matrix[0].size();
        int l = 0, r = (n*m)-1;
        while(l <= r){
            int mi = (r+l)/2;
            auto mid = getindex(mi);
            if(matrix[mid.first][mid.second] == target) return true;
            else if(matrix[mid.first][mid.second] > target) r = mi-1;
            else l = mi+1;
        }
        return false;
    }
};
