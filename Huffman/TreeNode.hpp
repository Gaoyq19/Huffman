//
//  TreeNode.hpp
//  Huffman
//
//  Created by 高裕淇 on 2021/11/15.
//  Copyright © 2021 高裕淇. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include <vector>
class TreeNode{
    std::pair<char, int> val;
    TreeNode *left;
    TreeNode *right;
public:
    std::pair<char, int> getVal(){
        return val;
    }
    TreeNode* getLeftChild(){
        return left;
    }
    TreeNode* getRightChild(){
        return right;
    }
    void setLeftChild(TreeNode *p){
        left = p;
    }
    void setRightChild(TreeNode *p){
        right = p;
    }
    TreeNode(std::pair<char, int> val){
        this->val.first = val.first;
        this->val.second = val.second;
    };
};
#endif /* TreeNode_hpp */
