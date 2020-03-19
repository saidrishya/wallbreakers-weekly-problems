class Solution {
public:
    int longestUnivaluePath(TreeNode *root) {
        int maxPathLen = 0;
        findMaxPathLenForAllNodes(root, maxPathLen);
        return maxPathLen;
    }
    
    void findMaxPathLenForAllNodes(TreeNode *cur, int &maxPathLen) {
        if (cur == NULL) {
            return;
        }
        int curLenSum = maxDepth(cur->right, cur->val) + maxDepth(cur->left, cur->val);
        maxPathLen = max(curLenSum, maxPathLen);
        findMaxPathLenForAllNodes(cur->left, maxPathLen);
        findMaxPathLenForAllNodes(cur->right, maxPathLen);
    }
    
    int maxDepth(TreeNode *cur, int &parentVal) {
        if (cur == NULL || cur->val != parentVal) {
            return 0;
        }
        return 1 + max(maxDepth(cur->left, parentVal), maxDepth(cur->right, parentVal));
    }
};
