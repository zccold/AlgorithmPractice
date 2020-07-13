#include <assert.h>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

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
    /*
     * 挺直观的想法：计算两个链表的长度，根据当前长度是否相等同步递归遍历两个链表，
     * 递归函数返回新创建的节点。
     * 
     * 还是直接用栈简单，md。
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int len1, int len2){
        ListNode *cur = nullptr, *next = nullptr;
        int val = 0;
        if(len1 > len2){
            next = addTwoNumbers(l1->next, l2, len1-1, len2);
            val += l1->val;
        }else if(len1 < len2){
            next = addTwoNumbers(l1, l2->next, len1, len2-1);
            val += l2->val;
        }else{
            if(len1 == 1)
                return new ListNode(l1->val + l2->val);
            next = addTwoNumbers(l1->next, l2->next, len1-1, len2-1);
            val += l1->val + l2->val;
        }

        if(next->val >= 10){
            div_t d = div(next->val, 10);
            next->val = d.rem;
            val += d.quot;
        }
        cur = new ListNode(val);
        cur->next = next;
        return cur;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int len1 = 0, len2 = 0;
        ListNode *ptr1 = l1, *ptr2 = l2;
        while(ptr1){
            ptr1 = ptr1->next;
            len1++;
        }
        while(ptr2){
            ptr2 = ptr2->next;
            len2++;
        }
        ListNode* res = addTwoNumbers(l1, l2, len1, len2);
        if(res->val >= 10){
            div_t d = div(res->val, 10);
            res->val = d.rem;
            ListNode* head = new ListNode(d.quot);
            head->next = res;
            return head;
        }
        return res;
    }
};

void trimLeftTrailingSpaces(string &input)
{
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
                    return !isspace(ch);
                }));
}

void trimRightTrailingSpaces(string &input)
{
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(),
                input.end());
}

vector<int> stringToIntegerVector(string input)
{
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim))
    {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode *stringToListNode(string input)
{
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item : list)
    {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode *node)
{
    if (node == nullptr)
    {
        return "[]";
    }

    string result;
    while (node)
    {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        ListNode *l1 = stringToListNode(line);
        getline(cin, line);
        ListNode *l2 = stringToListNode(line);

        ListNode *ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}