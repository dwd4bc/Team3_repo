#include <iostream>
#include<string>
#include "HuffmanTree.h"

using namespace std;

HuffmanTree::HuffmanTree(){
  root=NULL;
  
}
void HuffmanTree::insert(int dt, HuffmanTreeNode *h){
  if(dt<h.getWeight()){
    if(h->left!=NULL)
      insert(dt, h->left);
    else
    {
      h->left=new HuffManTreeNode;
      h->left.setWeight(dt);
      h->left->left=NULL;    //Sets the left child of the child node to null
      h->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
    else if(dt>=h.getWeight())
  {
    if(h->right!=NULL)
      insert(dt, leaf->right);
    else
    {
      h->right=new HuffManTreeNode;
      h->right.setWeight(dt);
      h->right->left=NULL;  //Sets the left child of the child node to null
      h->right->right=NULL; //Sets the right child of the child node to null
    }
  }
    }
}
