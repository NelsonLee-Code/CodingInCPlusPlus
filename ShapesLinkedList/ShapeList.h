//
//  ShapeList.h
//  

#ifndef ShapeList_h
#define ShapeList_h

#include "Shape.h"
#include "ShapeNode.h"

class ShapeList 
{
    private:
        ShapeNode* head;
        
    public:
        ShapeList();                        
        ~ShapeList();                      

        ShapeNode* getHead() const;       
        void setHead(ShapeNode* ptr);       

        ShapeNode* find(string name) const; 

        void insert(ShapeNode* s);        

        ShapeNode* remove(string name);    

        void print() const;             
};

#endif 
