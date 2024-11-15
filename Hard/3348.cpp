class Solution {
public:
    string smallestNumber(string num, long long t) {
        int n = num.length();
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                num[i] = '1';
                for (int j = i + 1; j < n; j++) {
                    num[j] = '1';
                }
                break;
            }
        }
        // cout << num << '\n';

        using ll = long long;
        int v2 = 0, v3 = 0, v5 = 0, v7 = 0;
        while (t % 2 == 0) { t /= 2; v2++; }
        while (t % 3 == 0) { t /= 3; v3++; }
        while (t % 5 == 0) { t /= 5; v5++; }
        while (t % 7 == 0) { t /= 7; v7++; }
        if (t > 1ll) return "-1";

        
        vector<int> p2(n), p3(n), p5(n), p7(n);
        vector<int> x2 = {-1, 0, 1, 0, 2, 0, 1, 0, 3, 0};
        vector<int> x3 = {-1, 0, 0, 1, 0, 0, 1, 0, 0, 2};
        vector<int> x5 = {-1, 0, 0, 0, 0, 1, 0, 0, 0, 0};
        vector<int> x7 = {-1, 0, 0, 0, 0, 0, 0, 1, 0, 0};
        for (int i = 0; i < n; i++) {
            int cur = num[i] - '0';
            p2[i] = (i ? p2[i - 1] : 0) + x2[cur];
            p3[i] = (i ? p3[i - 1] : 0) + x3[cur];
            p5[i] = (i ? p5[i - 1] : 0) + x5[cur];
            p7[i] = (i ? p7[i - 1] : 0) + x7[cur];
        }
        if (p2.back() >= v2 && p3.back() >= v3 && p5.back() >= v5 && p7.back() >= v7) return num;
        bool ok1 = false, ok2 = false;
        int idx = -1, dig1 = -1, dig2 = -1;
        for (int i = n - 1; i >= 0; i--) {
            int cur = num[i] - '0';
            int prv2 = (i ? p2[i - 1] : 0);
            int prv3 = (i ? p3[i - 1] : 0);
            int prv5 = (i ? p5[i - 1] : 0);
            int prv7 = (i ? p7[i - 1] : 0);
            for (int j = cur + 1; j <= 9; j++) {
                int rem = n - 1 - i;
                // cout << "itr: " << i << ' ' << j << '\n';
                int tmp2 = prv2 + x2[j];
                int tmp3 = prv3 + x3[j];
                int tmp5 = prv5 + x5[j];
                int tmp7 = prv7 + x7[j];
                int need = max(0, v5 - tmp5) + max(0, v7 - tmp7);
                // cout << need << ' ' << rem << '\n';
                if (need > rem) continue;
                rem -= need;
                if (rem > 0) {
                    int tmp = 0;
                    int rem2 = rem - 1;
                    int tmp2_2 = tmp2 + 1, tmp3_2 = tmp3 + 1;
                    if (v3 > tmp3_2) tmp += max(0, (v3 - tmp3_2 + 1) / 2);
                    if (v2 > tmp2_2) tmp += max(0, (v2 - tmp2_2 + 2) / 3);
                    if (tmp <= rem2) {
                        ok1 = true;
                        idx = i;
                        dig1 = j;
                    }
                }
                {
                    int tmp = 0;
                    if (v3 > tmp3) tmp += max(0, (v3 - tmp3 + 1) / 2);
                    if (v2 > tmp2) tmp += max(0, (v2 - tmp2 + 2) / 3);
                    if (tmp <= rem) {
                        ok2 = true;
                        idx = i;
                        dig2 = j;
                    }
                }
                if (ok1 || ok2) break;
            }
            if (ok1 || ok2) {
                break;
            }
        }
        if (!ok1 && !ok2) { //digits not enough
            string ret;
            // cout << "TES\n";
            for (int i = 0; i < v5; i++) ret.push_back('5');
            for (int i = 0; i < v7; i++) ret.push_back('7');
            for (int i = 0; i < v2 / 3; i++) ret.push_back('8');
            for (int i = 0; i < v3 / 2; i++) ret.push_back('9');
            int r2 = v2 % 3, r3 = v3 % 2;
            if (r2 == 0 && r3 == 1) {
                ret.push_back('3');
            } else if (r2 == 1 && r3 == 0) {
                ret.push_back('2');
            } else if (r2 == 1 && r3 == 1) {
                ret.push_back('6');
            } else if (r2 == 2 && r3 == 0) {
                ret.push_back('4');
            } else if (r2 == 2 && r3 == 1) {
                ret.push_back('2');
                ret.push_back('6');
            }
            while (ret.size() <= n) ret.push_back('1');
            sort(ret.begin(), ret.end());
            return ret;
        }

        // cout << ok1 << ' ' << dig1 << ' ' << ok2 << ' ' << dig2 << ' ' << idx << '\n';

        string ret = "a"; //greater than any number
        if (ok1) {
            int vv2 = (idx > 0 ? p2[idx - 1] : 0) + x2[dig1];
            int vv3 = (idx > 0 ? p3[idx - 1] : 0) + x3[dig1];
            int vv5 = (idx > 0 ? p5[idx - 1] : 0) + x5[dig1];
            int vv7 = (idx > 0 ? p7[idx - 1] : 0) + x7[dig1];

            int n5 = max(0, v5 - vv5);
            int n7 = max(0, v7 - vv7);

            string tmp = num.substr(0, idx);
            tmp.push_back((char)(dig1 + '0'));
            for (int i = 0; i < n5; i++) tmp.push_back('5');
            for (int i = 0; i < n7; i++) tmp.push_back('7');
            tmp.push_back('6');
            int vv2_2 = vv2 + 1, vv3_2 = vv3 + 1;
            if (v2 > vv2_2) {
                int n2 = v2 - vv2_2;
                for (int i = 0; i < n2 / 3; i++) tmp.push_back('8');
                if (n2 % 3 == 1) tmp.push_back('2');
                else if (n2 % 3 == 2) tmp.push_back('4'); 
            }
            if (v3 > vv3_2) {
                for (int i = 0; i < (v3 - vv3_2) / 2; i++) tmp.push_back('9');
                if ((v3 - vv3_2) & 1) tmp.push_back('3');
            }
            while (tmp.size() < n) tmp.push_back('1');
            sort(tmp.begin() + idx + 1, tmp.end());
            ret = min(ret, tmp);
        }
        if (ok2) {
            int vv2 = (idx > 0 ? p2[idx - 1] : 0) + x2[dig2];
            int vv3 = (idx > 0 ? p3[idx - 1] : 0) + x3[dig2];
            int vv5 = (idx > 0 ? p5[idx - 1] : 0) + x5[dig2];
            int vv7 = (idx > 0 ? p7[idx - 1] : 0) + x7[dig2];

            int n5 = max(0, v5 - vv5);
            int n7 = max(0, v7 - vv7);

            string tmp = num.substr(0, idx);
            tmp.push_back((char)(dig2 + '0'));
            for (int i = 0; i < n5; i++) tmp.push_back('5');
            for (int i = 0; i < n7; i++) tmp.push_back('7');
            if (v2 > vv2) {
                int n2 = v2 - vv2;
                for (int i = 0; i < n2 / 3; i++) tmp.push_back('8');
                if (n2 % 3 == 1) tmp.push_back('2');
                else if (n2 % 3 == 2) tmp.push_back('4'); 
            }
            if (v3 > vv3) {
                for (int i = 0; i < (v3 - vv3) / 2; i++) tmp.push_back('9');
                if ((v3 - vv3) & 1) tmp.push_back('3');
            }
            while (tmp.size() < n) tmp.push_back('1');
            sort(tmp.begin() + idx + 1, tmp.end());
            ret = min(ret, tmp);
        }
        assert (ret != "a");
        return ret;
    }
};