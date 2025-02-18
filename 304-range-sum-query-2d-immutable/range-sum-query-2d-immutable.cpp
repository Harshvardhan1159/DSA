#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> v; // Store prefix sum

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        v = matrix; // Copy the original matrix

        // Compute prefix sum
        for (int i = 1; i < m; i++) { // Fix: First row prefix sum
            v[0][i] += v[0][i - 1];
        }
        for (int i = 1; i < n; i++) { // Fix: First column prefix sum
            v[i][0] += v[i - 1][0];
        }
        for (int i = 1; i < n; i++) { // Fix: Prefix sum for entire matrix
            for (int j = 1; j < m; j++) {
                v[i][j] += v[i - 1][j] + v[i][j - 1] - v[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = v[row2][col2];
        int extra1 = (row1 > 0) ? v[row1 - 1][col2] : 0;
        int extra2 = (col1 > 0) ? v[row2][col1 - 1] : 0;
        int extra3 = (row1 > 0 && col1 > 0) ? v[row1 - 1][col1 - 1] : 0;
        
        return total - extra1 - extra2 + extra3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
