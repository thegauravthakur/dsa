#include <bits/stdc++.h>

using namespace std;
const int ArraySize = 26;

struct Node {
    Node *alphabets[ArraySize]{nullptr};
    bool isEnd = false;
};

class Trie {
    Node *root = new Node;

public:
    void add(const string &string) {
        Node *current = root;
        for (int i = 0; i < string.length(); i++) {
            Node *temp = new Node;
            if (i == string.length() - 1) {
                temp->isEnd = true;
            }
            current->alphabets[string[i] - 'a'] = temp;
            current = temp;
        }
    }

//    void printAllWords() {
//        stack<Node *> stack;
//        for (auto i : root->alphabets) {
//            if (i) stack.push(i);
//        }
//        vector<char> aa;
//        while (not stack.empty()) {
//            Node* top = stack.top();
//            stack.pop();
//            if (top->isEnd) {
//                for (auto i : aa) cout << i;
//                cout << endl;
//            }
//            for (auto i : top->alphabets) {
//                if (i) stack.push(i);
//            }
//        }
//    }

};

int main() {
    Trie trie;
    trie.add("gaurav");
    trie.add("gauri");
    trie.add("gaurv");
    cout << "done work" << endl;
}
