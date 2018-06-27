#ifndef TBINARYTREEITEM
#define TBINARYTREEITEM

#include "Rhomb.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include <memory>

template <class T>
class TBinaryTree;


template <class T>
class TBinaryTreeItem
{
public:
    TBinaryTreeItem();
    TBinaryTreeItem(std::shared_ptr<T> figure);

    int Square();
    std::shared_ptr<T> GetFigure();
    ~TBinaryTreeItem();
    friend TBinaryTree<T>;
private:
    std::shared_ptr<T> figure;
    std::shared_ptr<TBinaryTreeItem<T> > left;
    std::shared_ptr<TBinaryTreeItem<T> > right;
};

#endif