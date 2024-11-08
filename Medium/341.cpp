/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> elem;
    int ptr = 0;

    NestedIterator(vector<NestedInteger> &nestedList) {
        vector<int> tmp;
        process(nestedList, tmp);
        elem = tmp;
    }

    void process(vector<NestedInteger>& nestedList, vector<int>& tmp) {
        for (auto n : nestedList) {
            if (n.isInteger()) {
                tmp.push_back(n.getInteger());
            } else {
                process(n.getList(), tmp);
            }
        }
    }
    
    int next() {
        return elem[ptr++];
    }
    
    bool hasNext() {
        return (ptr < (int)elem.size());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */