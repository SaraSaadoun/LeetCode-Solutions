class TrieNode {
public:
    bool isCompleteWord;
    TrieNode *children[26];

    TrieNode() {
        isCompleteWord = false;
        for(int i = 0 ; i < 26 ; i++)
            children[i] = nullptr;
        
    }
};
class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode(); 
        // a -> p -> p -> l -> e
        //   -> l ->
    }
    void _insert(TrieNode *node, string& word, int i) {
        if(i == word.size()) {
            node->isCompleteWord = true;
            return;
        }
        int idx = word[i] - 'a';
        if(!node->children[idx])
            node->children[idx] = new TrieNode();
        
         _insert(node->children[idx], word, i+1);
    }
    void insert(string word) {
        _insert(root, word, 0);
    }
    bool _search(TrieNode *node, string& word, int i) {
        if(i == word.size())
            return node->isCompleteWord;

        int idx = word[i] - 'a';

        if(node->children[idx]) 
            return _search(node->children[idx], word, i+1);
        return false;
    }
    bool search(string word) {
        return _search(root, word, 0);
    }
        bool _startsWith(TrieNode *node, string& word, int i) {
        if(i == word.size())
            return true;

        int idx = word[i] - 'a';

        if(node->children[idx]) 
            return _startsWith(node->children[idx], word, i+1);
        return false;
    }
    bool startsWith(string prefix) {
        return _startsWith(root, prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */