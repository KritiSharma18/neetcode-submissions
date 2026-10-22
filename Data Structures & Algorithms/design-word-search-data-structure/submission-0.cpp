class WordDictionary {
private:
    struct Node {
        Node* next[26] = {};
        bool end = false;
    };
    Node* root;

    bool dfs(const string& w, int i, Node* node) {
        if (!node) return false;
        if (i == (int)w.size()) return node->end;

        if (w[i] == '.') {
            for (int c = 0; c < 26; c++)
                if (node->next[c] && dfs(w, i + 1, node->next[c]))
                    return true;
            return false;
        }
        return dfs(w, i + 1, node->next[w[i] - 'a']);
    }
public:
    WordDictionary() {
         root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for (char ch : word) {
            int c = ch - 'a';
            if (!cur->next[c]) cur->next[c] = new Node();
            cur = cur->next[c];
        }
        cur->end = true;
    }
    
    bool search(string word) {
         return dfs(word, 0, root);
    }
};
