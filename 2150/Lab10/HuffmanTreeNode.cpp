#include "HuffmanTreeNode.h"

HuffmanTreeNode::HuffmanTreeNode()
{
     weight = 0;
     data = 0;
}
HuffmanTreeNode::HuffmanTreeNode(int wt, int da)
{
     weight = wt;
     data = da;
}
// Destructor

HuffmanTreeNode::~HuffmanTreeNode()
{
}


// Return item priority


int HuffmanTreeNode::getWeight()
{
     return weight;
}
 

// Set the priority key value

void HuffmanTreeNode::setWeight(int wt)
{
  weight = wt;
  /*  if(*this->right!=NULL)
    weight+=*this->right.getWeight();
  
  if(*this->left!=NULL)
  weight+=*this->left.getWeight();*/
}


// Return data item

int HuffmanTreeNode::getData()
{
     return data;
}

// Set the data item value

void HuffmanTreeNode::setData(int dt)
{
    data = dt;
}
