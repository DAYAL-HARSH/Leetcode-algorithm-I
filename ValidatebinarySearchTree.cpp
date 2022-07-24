class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, NULL,NULL);
    }
    public:
    bool isValidBST(TreeNode* root,int* lower,int* upper){
        if(root == NULL) return true;
        if(upper && root->val >= *upper)
            return false;
        if(lower && root->val <= *lower)
            return false;
        return isValidBST(root->left, lower, &(root->val)) && isValidBST(root->right , &(root->val), upper);
    }
};
