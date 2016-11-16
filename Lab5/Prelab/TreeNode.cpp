// Ashley Nguyen - apn2my
// PreLab05 - TreeNode.cpp:  Tree Node method implementations
// 2.28.16
// CS 2150: Lab 5

#include "TreeNode.h"

//Default Constructor -left and right are NULL, value '?'
TreeNode::TreeNode() {
    value="?";
    left=NULL;
    right=NULL;
}

//Constructor - sets value to val
TreeNode::TreeNode(const string & val) {
    value=val;
    left=NULL;
    right=NULL;
}
