#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <sstream>
#include <memory>
#include <algorithm>
#include <map>
#include <set>
#include <math.h>
#include <queue>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode preHead(0);
        preHead.next = head;
        head = &preHead;
        while (head->next)
        {
            if (head->next->val == val)
            {
                head->next = head->next->next;
            }
            else
            {
                head = head->next;
            }
        }
        return preHead.next;
    }
};

ListNode* stringToListNode(string input) {
    stringstream ss(input.substr(1, input.size() - 2));
    string item;
    char delim(',');
    ListNode preHead(0);
    ListNode* cur = &preHead;
    while(getline(ss, item, delim)) {
        cur->next = new ListNode(stoi(item));
        cur = cur->next;
    }
    return preHead.next;
}

string listNodeToString(ListNode* head) {
    string res = "[";
    while(head) {
        res += to_string(head->val);
        res += ",";
        head = head->next;
    }
    res.erase(res.end() - 1);
    res += "]";
    return res;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode* head = stringToListNode(line);
        
        getline(cin, line);
        int val = stoi(line);

        ListNode* head = Solution().removeElements(head, val);
        string res = listNodeToString(head);

        cout << res << endl;
    }
    return 0;
}