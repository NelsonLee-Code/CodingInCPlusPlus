//
//  ShapeNode.cpp
// 

#include "ShapeNode.h"
using namespace std;

ShapeNode::ShapeNode()
{
    Shape* myShape;
    next = NULL;
}

ShapeNode::~ShapeNode()
{
    delete myShape;
}

Shape* ShapeNode::getShape() const
{
    return myShape;
}

void ShapeNode::setShape(Shape* ptr)
{
    myShape = ptr;
}

ShapeNode* ShapeNode::getNext() const
{
    return next;
}

void ShapeNode::setNext(ShapeNode* ptr)
{
    next = ptr;
}

void ShapeNode::print() const
{
    cout << myShape->getName() << ": " << myShape->getType() << " " << myShape->getXlocation() << " " << myShape->getYlocation() << " " << myShape->getXsize() << " " << myShape->getYsize() << endl;
}
