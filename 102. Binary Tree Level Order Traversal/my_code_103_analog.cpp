/*
Time Complexity: O(N)
Space Complexity: O(N)
*/   
class Solution {

private:

vector<vector<int>> ZigzagLevel; // map : height --> nodes at this height

void Visited(TreeNode* node, int Height){

    if(node == nullptr){return;}

    if(Height == ZigzagLevel.size()){
        // ZigzagLevel.push_back({}); // good!
        ZigzagLevel.push_back(vector<int>());
    }

    ZigzagLevel[Height].push_back(node->val);

    Visited(node->left, Height + 1);
    Visited(node->right, Height + 1);

}

public:

    vector<vector<int>> levelOrder(TreeNode* root) {
        
        Visited(root, 0);

        /*for(int i = 1; i < ZigzagLevel.size(); i += 2){

            reverse(ZigzagLevel[i].begin(), ZigzagLevel[i].end());

        }*/

        return ZigzagLevel;
    }
};