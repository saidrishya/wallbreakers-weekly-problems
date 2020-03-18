class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> v;
        if(!root) return v;
        pos(root,v);
        return v;
    }
    
    void pos(Node *root, vector<int> &v){
        if(root->children.size()!= 0){
            for(Node *i : root->children){
                pos(i,v);
            }
        }
        v.push_back(root->val);
        
      
    }
};
