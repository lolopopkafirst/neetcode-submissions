class PrefixTree {
private:
    array<PrefixTree*, 26> children{};
    bool isend;
public:
    PrefixTree() {
        children.fill(nullptr);
        isend = false;
    }
    
    void insert(string word) {
        insertHelper(word, this);
    }
     void insertHelper(string word, PrefixTree* node) {
        if(word.empty()){
            node->isend = true;
            return;
        }
         if(node->children[word[0] - 'a']){
            insertHelper(word.substr(1), node->children[word[0] - 'a']);
         }
         else{
            node->children[word[0] - 'a'] = new PrefixTree();
            insertHelper(word.substr(1), node->children[word[0] - 'a']);
         }
    }
    bool search(string word) {
        PrefixTree* curr = this;
        for(char i : word){
            if(curr->children[i - 'a']){
                curr = curr->children[i - 'a'];
            }
            else{
                return false;
            }
        }
        if (curr->isend) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
         PrefixTree* curr = this;
        for(char i : prefix){
            if(curr->children[i - 'a']){
                curr = curr->children[i - 'a'];
            }
            else{
                return false;
            }
        }
        return true;
    
    }
};
