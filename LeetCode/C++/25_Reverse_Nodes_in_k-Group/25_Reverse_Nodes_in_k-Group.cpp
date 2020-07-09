#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /*
     * 使用递归处理难以处理的分段链表逆转后首尾相接问题。
     */
    ListNode* reverseKGroup2(ListNode* head, int k) {
        if(!head || k <= 1)
            return head;
        ListNode* cur = head;
        int i = 0;
        while(i < k && cur){
            i++;
            cur = cur->next;
        }
        if(i == k){
            cur = reverseKGroup2(cur, k);
            while(i-- >= 0){
                ListNode* tmp = head->next;
                head->next = cur;
                cur = head;
                head = tmp;
            }
            head = cur;
        }
        return head;
    }
    
    ListNode* reverseKGroup1(ListNode* head, int k) {
        if(!head || k <= 1)
            return head;
        ListNode preHead(0), *first, *second, *pre, *suf;
        int i = 0, j = 0;  
        pre = &preHead;
        suf = head;
        pre->next = suf;
        while(suf){
            while(i-j != k && suf){
                suf = suf->next;
                i++;
            }
            if(i-j == k){
                first = pre->next;
                pre->next = suf;
                while(first != suf){
                    second = first->next;
                    first->next = pre->next;
                    pre->next = first;
                    first = second;
                }
                while(pre->next != suf)
                    pre = pre->next;
                j = i;
            }
        }
        return preHead.next;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        ListNode* ret = Solution().reverseKGroup(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}