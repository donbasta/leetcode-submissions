class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> tmp;
        ListNode* cur = head;
        while (cur) {
            tmp.push_back(cur->val);
            cur = cur->next;
        }
        int n = tmp.size();
        int mx = 0;
        vector<int> ret;
        for (int i = n - 1; i >= 0; i--) {
            if (tmp[i] >= mx) {
                ret.push_back(tmp[i]);
            }
            mx = max(mx, tmp[i]);
        }
        reverse(ret.begin(), ret.end());
        if (ret.empty()) return nullptr;
        ListNode* lmao = new ListNode(ret[0]);
        cur = lmao;
        for (int i = 1; i < (int)ret.size(); i++) {
            cur->next = new ListNode(ret[i]);
            cur = cur->next;
        }
        return lmao;
    }
};
