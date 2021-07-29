#include "BinaryTree.h"
#include "cstdlib"

template <class T>
void doubleTree(T& item)
{
    item *= 2;
}

int main() {

    BinaryTree<int> tree;

    srand(time(NULL));
    for(int i=0; i < 10; i++)
    {
        int x = rand() % 100;
        tree.push(x);
    }

    std::cout << "Pre-order: " << std::endl;
    tree.print(BinaryTree<int>::PREORDER);
    std::cout << std::endl;

    std::cout << "Post-order: " << std::endl;
    tree.print(BinaryTree<int>::POSTORDER);
    std::cout << std::endl;

    std::cout << "In-order: " << std::endl;
    tree.print(BinaryTree<int>::INORDER);
    std::cout << std::endl;

    tree.clear();

    BinaryTree<int>::iterator iter = tree.begin();
    for(; iter != tree.end(); ++iter)
    {
        *(*iter) *= 2;
    }

    std::cout << "Pre-order: " << std::endl;
    tree.print(BinaryTree<int>::PREORDER);
    std::cout << std::endl;

    std::cout << "Post-order: " << std::endl;
    tree.print(BinaryTree<int>::POSTORDER);
    std::cout << std::endl;

    std::cout << "In-order: " << std::endl;
    tree.print(BinaryTree<int>::INORDER);
    std::cout << std::endl;


    return 0;
}
