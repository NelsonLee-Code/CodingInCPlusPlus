//
//  GroupList.cpp
//  

#include "GroupList.h"
using namespace std;

GroupList::GroupList()
{
    head = NULL;
}

GroupList::~GroupList()
{
    GroupNode* tPtr = head;
    GroupNode* pPtr = NULL;
    
    while (tPtr != NULL)
    {
        pPtr = tPtr;
        tPtr = tPtr->getNext();
        delete pPtr;
    }
}

GroupNode* GroupList::getHead() const
{
    return head;
}

void GroupList::setHead(GroupNode* ptr)
{
    head = ptr;
}

void GroupList::insert(GroupNode* s)
{
    if (head == NULL)
    {
        head = s;
        s->setNext(nullptr);
    }
    else
    {
        GroupNode* tptr = head;
        while(tptr->getNext() != NULL)
            tptr = tptr->getNext();
        tptr->setNext(s);
        s->setNext(nullptr);
    }
}

GroupNode* GroupList::remove(string name)
{
    if (head == NULL) return nullptr;
    GroupNode* tptr = head;
    GroupNode* pptr = NULL;
    
    if ((head->getShapeList()->getHead()->getShape()->getName() == name) && (head->getNext() == NULL))
    {
        head = nullptr;
        return tptr;
    }
    
    if ((head->getShapeList()->getHead()->getShape()->getName() == name) && (head->getNext() != NULL))
    {
        head = head->getNext();
        return tptr;
    }
    
    while (tptr->getNext() != NULL)
    {
        if (tptr->getShapeList()->getHead()->getShape()->getName() == name)
        {
            pptr->setNext(tptr->getNext());
            tptr->setNext(nullptr);
            return tptr;
        }
        
        pptr = tptr;
        tptr = tptr->getNext();
    }
    
    return nullptr;
}

void GroupList::print() const
{
    GroupNode* tptr = head;
    while (tptr != NULL)
    {
        tptr->print();
        tptr = tptr->getNext();
    }
}
