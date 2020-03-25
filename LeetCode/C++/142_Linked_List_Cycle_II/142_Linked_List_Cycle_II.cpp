#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

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
     * 假设两个指针相遇时分别走了k,2k,环长度为r。由2k-k=nr得k=nr。
     * 假设从链头走到环的起点需要s步，指针相遇时距环起点m步。由s=k-m得s=nr-m。
     * 即此时一个指针从链头走到环起点时刚好与继续往前走的步长为1的指针相遇。
     */
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode *oneStep, *twoStep;
        oneStep = twoStep = head;
        do {
            oneStep = oneStep->next;
            twoStep = twoStep->next;
            if(twoStep)
                twoStep = twoStep->next;
        } while(twoStep && oneStep != twoStep);
        
        if(twoStep == nullptr)
            return nullptr;
        
        while(head != oneStep){
            head = head->next;
            oneStep = oneStep->next;
        }
        return head;
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
        int pos = stringToInteger(line);
        
        ListNode* ret = Solution().detectCycle(head);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}