class TrieNode{
    public:
        unordered_map<int,TrieNode*> links;
        int endsWith;
        
        //default constructor
        TrieNode(){
            endsWith=0;
        }
        bool doesExist(int h){
            if(links[h]!=NULL) return true;
            else return false;
        }
        void setEnd(){
            endsWith++;
        }
        void put(TrieNode* node, int h){
            links[h]=node;
        }
        TrieNode* getNext(int h){
            return links[h];
        }
        int getC(){
            return endsWith;
        }
        
    
};
class Solution {
    
public:
    TrieNode* root;
    Solution(){
        root=new TrieNode();
    }
    int matchAndInsert(string &s){
        int count=0;
        int n=s.length();
        TrieNode* node=root;
        for(int l=0;l<n;l++){
            char c1=s[l]; char c2=s[n-l-1];
            // cout<<c1<<"  "<<c2<<endl;
            int hash=(c1-'a')*26+(c2-'a');
            if(!node->doesExist(hash)){
                TrieNode* temp=new TrieNode();
                node->put(temp,hash);
                
            }
            node=node->getNext(hash);
            count+=node->getC();

        }
        node->setEnd();
        // cout<<count<<" at "<<s<<endl;
        return count;
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long tcount=0;
        int n=words.size();
        for(string &s:words){
            tcount+=matchAndInsert(s);
        }
        return tcount;
    }
};