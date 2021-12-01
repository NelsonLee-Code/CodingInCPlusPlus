//
//  GroupList.h
//  

#ifndef GroupList_h
#define GroupList_h

#include "GroupNode.h"

class GroupList 
{
    private:
        GroupNode* head;                
    public:
        GroupList();                     
        ~GroupList();                  
    
    GroupNode* getHead() const;      
    void setHead(GroupNode* ptr);     
    void insert(GroupNode* s);      
    
    GroupNode* remove(string name);   
    
    void print() const;              
};

#endif 
