/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int n = 0, int r = 0, int c = 0) {
        if(n == 0)
            n = grid.size();
        Node *node = new Node();
        if(n > 1) {
            node->topLeft = construct(grid, n / 2, r, c);
            node->topRight = construct(grid, n / 2, r, c + n/2);
            node->bottomLeft = construct(grid, n / 2, r + n/2, c);
            node->bottomRight = construct(grid, n / 2, r + n/2, c + n/2);

            if(node->topLeft->isLeaf and 
                node->topLeft->val == node->topRight->val and node->topRight->isLeaf and
                node->topLeft->val == node->bottomLeft->val and node->bottomLeft->isLeaf and
                node->topLeft->val == node->bottomRight->val and node->bottomRight->isLeaf) {
                node->val = node->topLeft->val;
                node->topLeft = node->topRight = node->bottomLeft = node->bottomRight = nullptr;
                node->isLeaf = true;
            }
        } else {
            node->val = grid[r][c];
            node->isLeaf = true;
        }

        return node;
    }
};