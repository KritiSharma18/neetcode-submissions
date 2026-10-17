class PrefixTree {
private:
    struct Node {
        Node* children[26] = {nullptr};
        bool isEnd = false;
    };

    Node* root;

    // Follow the path for s; return the last node, or nullptr if the path breaks
    Node* walk(const string& s) {
        Node* cur = root;
        for (char c : s) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) return nullptr;
            cur = cur->children[idx];
        }
        return cur;
    }
public:
    PrefixTree() {
        root = new Node();

    }
    
    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr)
                cur->children[idx] = new Node();
            cur = cur->children[idx];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = walk(word);
        return node != nullptr && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return walk(prefix) != nullptr;
    }
};
