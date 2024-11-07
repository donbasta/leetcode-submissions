class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int mn = -1;
        int mx = -1;
        long double sum = 0;
        int cnt = 0;
        int mode = -1;
        int mxCnt = 0;
        for (int i = 0; i < 256; i++) {
            cnt += count[i];
            sum += (long double) i * count[i];
            if (mn == -1 && (count[i] > 0)) mn = i;
            if (count[i] > 0) mx = i;
            if (count[i] > mxCnt) {
                mxCnt = count[i];
                mode = i;
            }
        }
        long double mean = sum / cnt;
        int curCount = 0;
        int mid = (cnt + 1) / 2;
        double median;
        for (int i = 0; i < 256; i++) {
            curCount += count[i];
            if (curCount >= mid) {
                if (cnt & 1) {
                    median = i;
                } else {
                    if (curCount == mid) {
                        for (int j = i + 1; j < 256; j++) {
                            if (count[j] > 0) {
                                median = (double) (i + j) / 2;
                                break;
                            }
                        }
                    } else if (curCount > mid) {
                        median = i;
                    }
                }
                break;
            }
        }
        vector<double> ret;
        ret.push_back((double) (mn));
        ret.push_back((double) (mx));
        ret.push_back((double) mean);
        ret.push_back((double) median);
        ret.push_back((double) mode);
        return ret;
    }
};