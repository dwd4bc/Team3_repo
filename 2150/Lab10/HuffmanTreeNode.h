#ifndef HUFFMANTREENODE_H
#define HUFFMANTREENODE_H

class HuffmanTreeNode
{
 private:
  int weight;
  int data;
  HuffmanTreeNode *left;
  HuffmanTreeNode *right;
  friend class HuffmanTree;
 public:
          HuffmanTreeNode();                              // Default constructor
          HuffmanTreeNode(int wt, int da);     // Constructor
         ~HuffmanTreeNode();
          int getWeight();                         // Return item priority
          void setWeight(int wt);               // Set the priority key value
          int getData();                    // Return data item
          void setData(int da);

};

#endif
