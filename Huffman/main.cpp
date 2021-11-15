//
//  main.cpp
//  Huffman
//
//  Created by 高裕淇 on 2021/11/15.
//  Copyright © 2021 高裕淇. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "myPriorityQueue.hpp"
using namespace std;
void readfile(string path){
    ifstream myfile(path);
    string line;
    map<char, int> occ;
    myPriorityQueue<pair<char, int>> priorityQueue;
    int total = 0;
    if (myfile.is_open())
    {
        while (getline (myfile, line)) // line中不包括每行的换行符
        {
            total += line.size();
            for (int i = 0; i < line.size(); ++i) {
                ++occ[line[i]];
            }
            cout << line << endl;
        }
    }else{
        cout << "can not open this file" << endl;
    }
    myfile.close();
}

int main()
{
    //readfile("/Users/gggyq/早稻田ips/面试/Huffman/Huffman/txt文本/article_0.txt");
    string str;
    pair<char, int> p0;
    pair<char, int> p1;
    p0 = make_pair('a', 10);
    p1 = make_pair('b', 1);
    if (p0 > p1) {
        cout<<0<<endl;
    }else{
        cout<<1<<endl;
    }
    return 0;
}
 
