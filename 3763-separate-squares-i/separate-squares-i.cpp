class Solution {
public:
    double func(vector<vector<int>>& squares, double mid) {
        double ba = 0, ta = 0;
        for (auto& i : squares) {
            double x = i[0], y = i[1], l = i[2];
            if ((y + l - mid) < 1e-9) {
                ba += l * l;
            } else if ((y - mid) >= 1e-9) {
                ta += l * l;
            } else {
                ba += l * (mid - y);
                ta += (y + l - mid) * l;
            }
        }
        if (fabs(ta - ba) < 1e-9) return 0.0;
        return (ta - ba < 0) ? -1.0 : 1.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double s = 1e9, e = 0;
        for (auto& i : squares) {
            double y = i[1], l = i[2];
            s = min(s, y);
            e = max(e, y + l);
        }

        double ans = 0;
        while ((e - s) > 1e-5) { 
            double mid = s + (e - s) / 2.0;
            double temp = func(squares, mid);
            if (temp <= 0.0) {
                ans = mid;
                e = mid; 
            } else {
                s = mid;
            }
        }
        return ans;
    }
};
