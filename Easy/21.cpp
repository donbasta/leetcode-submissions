/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        set<pair<int, ListNode*>> curHead;
        vector<ListNode*> lists = {list1, list2};
        for (auto list: lists) {
            if (list != NULL) {
                curHead.insert(make_pair(list->val, list));
            }
        }

        ListNode* ret = NULL;
        ListNode* curRet = NULL;
        while (!curHead.empty()) {
            auto nx = *curHead.begin();
            curHead.erase(curHead.begin());
            if (curRet == NULL) {
                ret = new ListNode(nx.first);
                curRet = ret;
            } else {
                curRet->next = new ListNode(nx.first);
                curRet = curRet->next;
            }
            if (nx.second->next != NULL) {
                curHead.insert(make_pair(nx.second->next->val, nx.second->next));
            }
        }

        return ret;
    }
};