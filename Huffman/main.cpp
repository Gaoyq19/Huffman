//
//  main.cpp
//  Huffman
//
//  Created by 高裕淇 on 2021/11/15.
//  Copyright © 2021 高裕淇. All rights reserved.
//

#include "HuffmanTree.hpp"

using namespace std;
int main()
{
    string path_head = "/Users/gggyq/早稻田ips/面试/Huffman/Huffman/";
    string compressName;
    string decompressPath;
    cout << "输入需要压缩的文件名: ";
    cin >> compressName;
    HuffmanTree huffman(path_head + compressName +".txt", path_head + compressName + "_compressed.txt");
    HuffmanTree zio(path_head + compressName + "_compressed.txt", path_head + compressName +"_decompressed.txt",true);
    return 0;
}
 
