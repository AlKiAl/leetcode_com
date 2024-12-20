/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
Time complexity : O(n)
Space complexity : O(h)
*/   
class Solution {

TreeNode* LCA = nullptr;

bool Found_P = false;
bool Found_Q = false;

void Travel(TreeNode* node, TreeNode* P, TreeNode* Q){

    // (Found_P && Found_Q) -- не обязатнльо!
    if(node == nullptr || (Found_P && Found_Q)){return;}

    // LCA == node, которая является максимальны по высоте родителем (считая сверху) как P, так и Q
    // node, которая является ребенком P or Q не может быть родителем P and Q
    const bool MayBeLCA = (!Found_P) && (!Found_Q); // Нода W рассматривается как родитель ноды W, поэтому этот аргумент находится перед нижинми if

    if(node == P){Found_P = true;}
    if(node == Q){Found_Q = true;}

    Travel(node->left,P,Q);
    Travel(node->right,P,Q);

    // postorder проходит снизу-вверх, это гарантирует наименьшее (наибольшее по глубине) MayBeLCA
    // зашли в postorder раздел и предше-е ему ноды уже помечены в preorder разделе
    if(LCA == nullptr && /*это необходимо чтобы единожды обновить LCA*/
    MayBeLCA && /*услвоие, свойственное для LCA*/
    Found_P && Found_Q /* без этой строки будет ошибка: Input root = [3,5,1,6,2,0,8,null,null,7,4] p = 5 q = 1  Output 5 Expected 3*/
        ){
        LCA = node;
    }
}

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        Travel(root, p, q);

        return LCA;
    }
};
