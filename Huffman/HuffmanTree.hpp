//
//  HuffmanTree.hpp
//  Huffman
//
//  Created by 高裕淇 on 2021/11/15.
//  Copyright © 2021 高裕淇. All rights reserved.
//

#ifndef HuffmanTree_hpp
#define HuffmanTree_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "TreeNode.hpp"
#include "myPriorityQueue.hpp"
class HuffmanTree{
    std::map<char, int> occ;
    myPriorityQueue<TreeNode*> priorityQueue;
    TreeNode *head;
    std::map<char, std::string> code;
public:
    std::string getCode(char c){
        return code[c];
    }
    void encode(TreeNode *p, std::string str){
        if(p){
            if (p->getVal().first != '\0') {
                code[p->getVal().first] = str;
            }
            encode(p->getLeftChild(), str + "0");
            encode(p->getRightChild(), str + "1");
        }
    }
    HuffmanTree(std::string path){
        std::ifstream myfile(path);
        std::string line;
        int total = 0;
        if (myfile.is_open())
        {
            while (getline (myfile, line)) // line中不包括每行的换行符
            {
                total += line.size();
                for (int i = 0; i < line.size(); ++i) {
                    ++occ[line[i]];
                }
            }
            for (auto i  : occ) {
                priorityQueue.push(new TreeNode(i));
            }
        }else{
            throw "can not open this file";
        }
        myfile.close();
        if (priorityQueue.empty()) {
            throw "空哈夫曼树";
        }
        while (priorityQueue.size() > 1) {
            TreeNode *left = priorityQueue.top();
            priorityQueue.pop();
            TreeNode *right = priorityQueue.top();
            priorityQueue.pop();
            TreeNode *parent = new TreeNode(std::make_pair('\0', left->getVal().second + right->getVal().second));
            parent->setLeftChild(left);
            parent->setRightChild(right);
            priorityQueue.push(parent);
        }
        head = priorityQueue.top();
        encode(head, "");
    }
};
#endif /* HuffmanTree_hpp */
