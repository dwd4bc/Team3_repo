#include <iostream>
#include<string>
#include "HuffmanTree.h"

using namespace std;

HuffmanTree::HuffmanTree(){
  root=NULL;
  
}
void HuffmanTree::insert(int key, int da, HuffmanTreeNode *h){
  if(key<h->getWeight()){
    if(h->left!=NULL)
      insert(key,da, h->left);
    else
    {
      h->left=new HuffmanTreeNode;
      h->left->setWeight(key);
      h->left->setData(da);
      h->left->left=NULL;    //Sets the left child of the child node to null
      h->left->right=NULL;   //Sets the right child of the child node to null
    }  
  }
    else if(key>=h->getWeight())
  {
    if(h->right!=NULL)
      insert(key,da, h->right);
    else
    {
      h->right=new HuffmanTreeNode;
      h->right->setWeight(key);
      h->right->setData(da);
      h->right->left=NULL;  //Sets the left child of the child node to null
      h->right->right=NULL; //Sets the right child of the child node to null
    }
  }
    }

string HuffmanTree::assignCode(int key, int data,string a, HuffmanTreeNode *h){
 if(h!=NULL)
    {
      if(data==h->getData())
      	return a;
    else if(key<h->getWeight())
	{
	  a+='0';
	  return assignCode(key,data, a, h->left);
	}
      else{
	a+='1';
	return assignCode(key,data, a, h->right);
      }
    }
 else return a;
}
void HuffmanTree::insert(int key, int da){
  if(root!=NULL)
    insert(key,da,root);
  else{
	 root=new HuffmanTreeNode;
	 root->setData(da);
	 root->setWeight(key);
	 root->left=NULL;
	 root->right=NULL;
	 }
}
string HuffmanTree::assignCode(int key,int data, string a){
  return assignCode(key, data, a, root);
}
