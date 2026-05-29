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
        PrefixTree* curr = this;
        for(char i : word){
            if(curr->children[i - 'a']){
                curr = curr->children[i - 'a'];
            }
            else{
                curr->children[i - 'a'] = new PrefixTree();
                curr = curr->children[i - 'a'];
            }
        }
        curr->isend = true;
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
