void leaf(TreeNode* r , vector<int> &res)
{
if(!r) return;     
if(!r->left && !r->right) { res.push_back(r->val); return;}
if(r->left) leaf(r->left,res);
    
if(r->right)leaf(r->right,res);

}    



class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
 vector<int> r1;
 leaf(root1, r1);        
vector<int> r2;
 leaf(root2, r2);        
int i=0,j=0;
if(r1.size()!=r2.size()) return false;
while(i<r1.size() && j<r1.size()){
 if(r1[i]!=r2[j]) return false;    
 i++;
 j++;  

}    
        
return true;

        
    }
};
