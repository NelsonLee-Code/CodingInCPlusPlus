//
//  GroupNode.h
//  

#ifndef GroupNode_h
#define GroupNode_h

#include "ShapeList.h"

class GroupNode {
    private:
        string name;                           
        ShapeList* myShapeList;             
        GroupNode* next ;                      
    public:
        GroupNode(string n);                   
    
    ~GroupNode();                         
    string getName() const;               
    ShapeList* getShapeList() const;      
    void setShapeList(ShapeList* ptr);     
    GroupNode* getNext() const;            
    void setNext(GroupNode* ptr);         
    void print() const;                   
};

#endif 
