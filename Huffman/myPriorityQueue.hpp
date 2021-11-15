//
//  myPriorityQueue.hpp
//  Huffman
//
//  Created by 高裕淇 on 2021/11/15.
//  Copyright © 2021 高裕淇. All rights reserved.
//

#ifndef myPriorityQueue_hpp
#define myPriorityQueue_hpp

#include <stdio.h>
#include <vector>
#include "TreeNode.hpp"
template<class T>
class myPriorityQueue
{
private:
    int capacity = 100;    //队列容量
    int queueSize = 0;         //队列大小
    std::vector<T> data;   //队列变量

public:
    myPriorityQueue();
    ~myPriorityQueue();
    int size();
    bool empty();
    void push(T val);
    void pop();
    T top();
};
template<class T>
myPriorityQueue<T>::myPriorityQueue()
{
    data = std::vector<T>(capacity);
}
template<class T>
myPriorityQueue<T>::~myPriorityQueue()
{
    while (!empty()){
        pop();
    }
}

template<class T>
bool myPriorityQueue<T>::empty()
{
    if (queueSize > 0){
        return false;
    }
    return true;
}

template<class T>
int myPriorityQueue<T>::size()
{
    return queueSize;
}

template<class T>
void myPriorityQueue<T>::push(T val)
{
    // 空则直接入队  不能省略
    if (empty())
    {
        data[0] = val;
        ++queueSize;
        return;
    }
    ++queueSize;
    data[size() - 1] = val;
    int i = size() - 1;
    int parent = (i - 1) / 2;
    while (parent >= 0 && data[i] < data[parent]) {
        std::swap(data[i], data[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }

}

template<class T>
void myPriorityQueue<T>::pop()
{
    if (empty())
    {
        throw "Priority queue is empty\n";
    }
    data[0] = data[size() - 1];
    --queueSize;
    int i = 0;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    while ((leftChild < size() && data[i] > data[leftChild] ) || (rightChild < size() && data[i] > data[rightChild])) {
        if (data[leftChild] < data[rightChild]) {
            std::swap(data[i], data[leftChild]);
            i = leftChild;
        }else{
            std::swap(data[i], data[rightChild]);
            i = rightChild;
        }
        leftChild = 2 * i + 1;
        rightChild = 2 * i + 2;
    }
}

template<class T>
T myPriorityQueue<T>::top()
{
    if (empty())
    {
        throw "Priority queue is empty\n";
    }
    return data[0];
}

template<>
class myPriorityQueue<TreeNode*>
{
private:
    int capacity = 100;    //队列容量
    int queueSize = 0;         //队列大小
    std::vector<TreeNode*> data;   //队列变量

public:
    myPriorityQueue();
    ~myPriorityQueue();
    int size();
    bool empty();
    void push(TreeNode *val);
    void pop();
    TreeNode* top();
};
myPriorityQueue<TreeNode*>::myPriorityQueue()
{
    data = std::vector<TreeNode*>(capacity,nullptr);
}
myPriorityQueue<TreeNode*>::~myPriorityQueue()
{
    while (!empty()){
        pop();
    }
}
bool myPriorityQueue<TreeNode*>::empty()
{
    if (queueSize > 0){
        return false;
    }
    return true;
}

int myPriorityQueue<TreeNode*>::size()
{
    return queueSize;
}
void myPriorityQueue<TreeNode*>::push(TreeNode *val)
{
    if (empty())
    {
        data[0] = val;
        ++queueSize;
        return;
    }
    ++queueSize;
    data[size() - 1] = val;
    int i = size() - 1;
    int parent = (i - 1) / 2;
    while (parent >= 0 && data[i]->getVal().second < data[parent]->getVal().second) {
        std::swap(data[i], data[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }

}
void myPriorityQueue<TreeNode*>::pop()
{
    if (empty())
    {
        throw "Priority queue is empty\n";
    }
    data[0] = data[size() - 1];
    --queueSize;
    int i = 0;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    while ((leftChild < size() && data[i]->getVal().second > data[leftChild]->getVal().second ) || (rightChild < size() && data[i]->getVal().second > data[rightChild]->getVal().second)) {
        if (data[leftChild]->getVal().second < data[rightChild]->getVal().second) {
            std::swap(data[i], data[leftChild]);
            i = leftChild;
        }else{
            std::swap(data[i], data[rightChild]);
            i = rightChild;
        }
        leftChild = 2 * i + 1;
        rightChild = 2 * i + 2;
    }
}

TreeNode* myPriorityQueue<TreeNode*>::top()
{
    if (empty())
    {
        throw "Priority queue is empty\n";
    }
    return data[0];
}
#endif /* myPriorityQueue_hpp */
