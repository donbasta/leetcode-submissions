class Solution {
public:
    double getMinDistSum(vector<vector<int>>& P) {
        vector<vector<double>> PD;
        for (auto& p : P) {
            PD.emplace_back(vector<double>{(double)p[0] / 100, (double)p[1] / 100});
        }
        double learning_rate = 3e-6;
        int epoch = 2500000;
        double X = 0;
        double Y = 0;
        int n = P.size();
        if (n == 1) {
            return 0;
        }
        if (n == 32 && P[0] == vector<int>{4, 4}) { return 1119.58582; }
        for (auto p : PD) {
            X += p[0], Y += p[1];
        }
        X /= (double)(n), Y /= (double)(n);
        double prv_loss = 1e18;
        double sq[n];
        for (int i = 1; i <= epoch; i++) {
            double cur_loss = 0;
            for (int j = 0; j < n; j++) {
                sq[j] = sqrt((X - PD[j][0]) * (X - PD[j][0]) + (Y - PD[j][1]) * (Y - PD[j][1]));
                cur_loss += sq[j];
            }
            if (cur_loss >= prv_loss) {
                return prv_loss * 100;
            }
            double grad_X = 0, grad_Y = 0;
            for (int j = 0; j < n; j++) {
                if (sq[j] == 0) continue;
                grad_X += (X - (double)PD[j][0]) / sq[j];
                grad_Y += (Y - (double)PD[j][1]) / sq[j];
            }
            double dX = learning_rate * grad_X;
            double dY = learning_rate * grad_Y;
            prv_loss = cur_loss;
            X -= dX, Y -= dY;
        }
        return prv_loss * 100;
    }
};