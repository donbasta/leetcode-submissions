class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> st;
        for (auto e : nums) st.insert(e);
        for (auto e : nums) {
            string se = to_string(e);
            reverse(se.begin(), se.end());
            int re = stoi(se);
            st.insert(re);
        }
        return st.size();
    }
};