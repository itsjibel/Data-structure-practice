#include <iostream>
#include "../JDS/Tree/binary_tree.hpp"

int main()
{
    BTree<int> *myBTree;
    myBTree = myBTree->create(9);
    myBTree->left = myBTree->create(3);
    myBTree->right = myBTree->create(5);
    myBTree->left->left = myBTree->create(11);
    myBTree->right->left = myBTree->create(2);
    std::cout<<"Hight of tree: "<<myBTree->height(myBTree)<<std::endl;
    std::cout<<"The number of tree nodes: "<<myBTree->numof_nodes(myBTree)<<std::endl;
    myBTree->deleteTree(myBTree);
    return 0;
}