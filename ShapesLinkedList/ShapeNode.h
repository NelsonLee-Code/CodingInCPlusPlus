//
//  ShapeNode.h
//  

#ifndef ShapeNode_h
#define ShapeNode_h

#include "Shape.h"

class ShapeNode 
{
    private:
        Shape* myShape;
        ShapeNode* next;
        
    public:
        ShapeNode();         
        ~ShapeNode();                 
        Shape* getShape() const;  
        void setShape(Shape* ptr);    
        ShapeNode* getNext() const;  
        void setNext(ShapeNode* ptr);  
        void print() const;          
};

#endif 
