#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* recursive(ListNode* pre, ListNode* suffix, ListNode* ptr, int m, int n, int i){
        if(ptr){
            if(i < m-1){
                recursive(pre, suffix, ptr->next, m, n, i+1);
            }else if(i == m-1){
                pre = ptr;
                recursive(pre, suffix, ptr->next, m, n, i+1);
            }else if(i == m){
                suffix = ptr;
                recursive(pre, suffix, ptr->next, m, n, i+1)->next = ptr;
            }else if(i < n){
                recursive(pre, suffix, ptr->next, m, n, i+1)->next = ptr;
            }else if(i == n){
                suffix->next = ptr->next;
                pre->next = ptr;
            }
        }
        return ptr;
    }

    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if(m == n) return head;
        ListNode preHead(0), *pre = NULL, *suffix = NULL, *ptr = &preHead;
        preHead.next = head;
        recursive(pre, suffix, ptr, m, n, 0);
        return preHead.next;
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
                })
                    .base(),
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

int stringToInteger(string input)
{
    return stoi(input);
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
        ListNode *head = stringToListNode(line);
        getline(cin, line);
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);

        ListNode *ret = Solution().reverseBetween(head, m, n);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}