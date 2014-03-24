#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanTreeNode.h"
#include<iostream>
#include<stdio.h>
using namespace std;

class HuffmanTree
{               
         
     public:

  HuffmanTree();
  string assignCode(int key, int data, string a); 
  void insert(int key, int da);
	  //  HuffmanTreeNode *search(int key);
	 
 private:
  string assignCode(int key, int data, string a, HuffmanTreeNode *h);
    void insert(int key, int da, HuffmanTreeNode *h);
	  HuffmanTreeNode *root;
	  

};

#endif
