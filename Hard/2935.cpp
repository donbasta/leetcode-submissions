struct Trie {
    const int B = 20;
    struct Node {
        Node* ve[2];
        int cnt;
        Node() {
            ve[0] = ve[1] = nullptr;
            cnt = 0;
        }
    };
    
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int x) {
        Node* cur = root;
        for (int i = B - 1; i >= 0; i--) {
            cur->cnt++;
            int dig = (x >> i) & 1;
            if (!cur->ve[dig]) cur->ve[dig] = new Node();
            cur = cur->ve[dig];
        }
        cur->cnt++;
    }
    void erase(int x) {
        Node* cur = root;
        for (int i = B - 1; i >= 0; i--) {
            cur->cnt--;
            int dig = (x >> i) & 1;
            cur = cur->ve[dig];
        }
        cur->cnt--;
    }
    int que(int x) {
        int ret = 0;
        Node* cur = root;
        for (int i = B - 1; i >= 0; i--) {
            int dig = (x >> i) & 1;
            if (cur->ve[dig ^ 1] && cur->ve[dig ^ 1]->cnt > 0) {
                ret += (1 << i);
                cur = cur->ve[dig ^ 1];
            } else {
                cur = cur->ve[dig];
            }
        }
        return ret;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int le = 0;
        
        Trie t;
        for (int i = 0; i < n; i++) {
            t.insert(nums[i]);
            ans = max(ans, t.que(nums[i]));
            if (i < n - 1) {
                while (le < n && nums[le] * 2 < nums[i + 1]) {
                    t.erase(nums[le]);
                    le++;
                }
            }
        }
        return ans;
    }
};