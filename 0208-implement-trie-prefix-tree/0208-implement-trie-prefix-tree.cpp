class TrieNode {
public:
    TrieNode* links[26];
    bool isLeaf = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for(char ch:word) {
            if(!node->links[ch-97]) {
                node->links[ch-97] = new TrieNode();
            }
            node = node->links[ch-97];
        }
        node->isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char ch:word) {
            if(!node->links[ch-97]) return false;
            node = node->links[ch-97];
        }
        return node->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch:prefix) {
            if(!node->links[ch-97]) return false;
            node = node->links[ch-97];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */