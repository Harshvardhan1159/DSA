class Solution {
public:
    int dis(int x, int y, int a, int b) {
        return abs(x - a) + abs(y - b);
    }

    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int ans = -1;
        int ax = -1, ay = -1;

        for (auto &i : towers) {
            int x = i[0];
            int y = i[1];
            int q = i[2];

            if (dis(x, y, center[0], center[1]) <= radius) {
                if (q > ans ||
                   (q == ans && (ax == -1 || x < ax || (x == ax && y < ay)))) {
                    ans = q;
                    ax = x;
                    ay = y;
                }
            }
        }

        return {ax, ay};
    }
};
