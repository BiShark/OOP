#ifndef TBINARYTREEITEM
#define TBINARYTREEITEM


#include "TAllocationBlock.h"
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

    void* operator new (size_t size);
    void operator delete(void *p);

    int Square();
    std::shared_ptr<T> GetFigure();
    std::shared_ptr<TBinaryTreeItem<T> > GetLeft();
    std::shared_ptr<TBinaryTreeItem<T> > GetRight();
    ~TBinaryTreeItem();
    friend TBinaryTree<T>;
private:
    std::shared_ptr<T> figure;
    std::shared_ptr<TBinaryTreeItem<T> > left;
    std::shared_ptr<TBinaryTreeItem<T> > right;

    static TAllocationBlock tbinarytreeitem_allocator;
};

#endif
