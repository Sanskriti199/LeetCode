class Solution {
    public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        while (top <= bottom && left <= right) {
            // Traverse Right (Top boundary)
            for (int j = left; j <= right; ++j) {
                result.push_back(matrix[top][j]);
            }
            top++;

            // Traverse Down (Right boundary)
            if (top <= bottom) {
                for (int i = top; i <= bottom; ++i) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }

            // Traverse Left (Bottom boundary)
            if (top <= bottom && left <= right) {
                for (int j = right; j >= left; --j) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // Traverse Up (Left boundary)
            if (top <= bottom && left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return result;
    }
};