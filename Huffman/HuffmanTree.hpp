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
    std::string path;
    std::string outPath;
    std::map<char, int> occ;
    myPriorityQueue<TreeNode*> priorityQueue;
    TreeNode *head;
    std::map<char, std::string> encodeMap;
    std::map<std::string, char> decodeMap;
public:
    void encode(TreeNode *p, std::string str){
        if(p){
            if (p->getVal().first != '\0') {
                encodeMap[p->getVal().first] = str;
            }
            encode(p->getLeftChild(), str + "0");
            encode(p->getRightChild(), str + "1");
        }
    }
    void decode(){
        for (auto i : encodeMap) {
            decodeMap[i.second] = i.first;
        }
    }
    void decompress(){
        std::ifstream myfile(path);
        std::ofstream outFile(outPath, std::ios::out);
        std::string line;
        std::string inputLine;
        if (!outFile.is_open()) {
            throw "error";
        }
        int s = 0;
        getline (myfile, line);
        s = std::atoi(line.c_str());
        for (int i = 0 ; i < s; ++i) {
            getline (myfile, line);
        }
        if (myfile.is_open())
        {
            while (getline (myfile, line)) // line中不包括每行的换行符
            {
                std::string c = "";
                std::string input = "";
                for (int i = 0; i < line.size(); ++i) {
                    c += line[i];
                    if(decodeMap.count(c)){
                        input += decodeMap[c];
                        c = "";
                    }
                }
                outFile << input << std::endl;
            }
        }else{
            throw "can not open this file";
        }
        outFile.close();
        myfile.close();
    }
    void compress(){
        std::ifstream myfile(path);
        std::ofstream outFile(outPath, std::ios::out);
        std::string line;
        std::string inputLine;
        if (!outFile.is_open()) {
            throw "error";
        }
        outFile << std::to_string(occ.size()) << std::endl;
        for (auto i : occ) {
            outFile << i.first << " " << std::to_string(i.second) << std::endl;
        }
        if (myfile.is_open())
        {
            while (getline (myfile, line)) // line中不包括每行的换行符
            {
                std::string inputLine = "";
                for (int i = 0; i < line.size(); ++i) {
                    inputLine += encodeMap[line[i]];
                }
                outFile << inputLine << std::endl;
            }
        }else{
            throw "can not open this file";
        }
        outFile.close();
        myfile.close();
    }
    TreeNode* buildTree(){
        if (priorityQueue.empty()) {
            throw "空哈夫曼树";
        }
        while (priorityQueue.size() > 1) {
            TreeNode *left = priorityQueue.top();
            priorityQueue.pop();
            TreeNode *right = priorityQueue.top();
            priorityQueue.pop();
            TreeNode *parent = new TreeNode(std::make_pair('\0', left->getVal().second +    right->getVal().second));
            parent->setLeftChild(left);
            parent->setRightChild(right);
            priorityQueue.push(parent);
        }
        return priorityQueue.top();
    }
    HuffmanTree(std::string path, std::string outPath, bool status){
        this->outPath = outPath;
        this->path = path;
        std::ifstream myfile(path);
        std::string line;
        if (myfile.is_open()){
            int s = 0;
            getline (myfile, line);
            s = std::atoi(line.c_str());
            for (int i = 0 ; i < s; ++i) {
                getline (myfile, line);
                occ[line[0]] = std::atoi(line.substr(2).c_str());
            }
            for (auto i  : occ) {
                priorityQueue.push(new TreeNode(i));
            }
        }else{
            throw "can not open this file";
        }
        myfile.close();
        head = buildTree();
        encode(head, "");
        decode();
        decompress();
    }
    HuffmanTree(std::string path, std::string outPath){
        this->outPath = outPath;
        this->path = path;
        std::ifstream myfile(path);
        std::string line;
        int total = 0;
        if (myfile.is_open()){
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
        head = buildTree();
        encode(head, "");
        compress();
    }
};
#endif /* HuffmanTree_hpp */
