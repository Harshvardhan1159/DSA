class Solution {
public:
    bool f(vector<vector<char>>& board, string& word, int n, int m, int i, int j, int k) {
        if (k == word.size()) return true;

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '#'; // mark as visited

        bool found = f(board, word, n, m, i - 1, j, k + 1) ||
                     f(board, word, n, m, i + 1, j, k + 1) ||
                     f(board, word, n, m, i, j - 1, k + 1) ||
                     f(board, word, n, m, i, j + 1, k + 1);

        board[i][j] = temp; // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (f(board, word, n, m, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
