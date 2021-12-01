//
//  ShapeList.cpp
//  

#include "Shape.h"
#include "ShapeNode.h"
#include "ShapeList.h"
using namespace std;

ShapeList::ShapeList()
{
    head = nullptr;
}

ShapeList::~ShapeList()
{
    ShapeNode* tPtr = head;
    ShapeNode* pPtr = NULL;
    
    while (tPtr != NULL)
    {
        pPtr = tPtr;
        tPtr = tPtr->getNext();
        delete pPtr;
    }
}

ShapeNode* ShapeList::getHead() const
{
    return head;
}

void ShapeList::setHead(ShapeNode* ptr)
{
    head = ptr;
}

ShapeNode* ShapeList::find(string name) const
{
    ShapeNode* tptr = head;
    while (tptr != NULL)
    {
        if (tptr->getShape()->getName() == name) 
            return tptr;
        tptr = tptr->getNext();
    }
    return nullptr;
}

void ShapeList::insert(ShapeNode* s)
{
    if (head == NULL)
    {
        head = s;
        s->setNext(nullptr);
    }
    else
    {
        ShapeNode* tptr = head;
        
        while(tptr->getNext() != NULL)
            tptr = tptr->getNext();
        
        tptr->setNext(s);
        s->setNext(nullptr);
    }
}

ShapeNode* ShapeList::remove(string name)
{
    if (head == NULL) return nullptr;
    ShapeNode* tptr = head;
    ShapeNode* pptr = NULL;
    
    if ((head->getShape()->getName() == name) && (head->getNext() == NULL))
    {
        head = nullptr;
        return tptr;
    }
    
    if ((head->getShape()->getName() == name) && (head->getNext() != NULL))
    {
        head = head->getNext();
        return tptr;
    }
    
    while (tptr != NULL)
    {
        if (tptr->getShape()->getName() == name)
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

void ShapeList::print() const
{
    ShapeNode* tptr = head;
    while (tptr != NULL)
    {
        tptr->print();
        tptr = tptr->getNext();
    }
}
