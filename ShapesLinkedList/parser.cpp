//
//  parser.cpp
//  


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"
#include "ShapeNode.h"
#include "GroupNode.h"
#include "ShapeList.h"
#include "GroupList.h"

GroupList* gList;

//Check Name is Valid Function
bool checkNameIsValid(string i)
{
    if (i == "shape" || i == "group" || i == "move" || i == "draw" || i == "delete" || i == "pool" || i == "ellipse" || i == "rectangle" || i == "triangle")
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Check if a Name Already Exists as a Group or a Shape Name
bool checkNameExists(string i)
{
    GroupNode* tptr = gList -> getHead();
    
    //Traverse Group List
    while (tptr != NULL)
    {
        if (tptr->getName() == i)
        {
            return true;
        }
        else
        {
            ShapeList* sptr = tptr->getShapeList();
            ShapeNode* snptr = sptr->getHead();
            
            if (snptr == NULL)
            {
                tptr = tptr->getNext();
                continue;
            }
            
            //Traverse Shape List
            while (snptr != nullptr)
            {
                if(snptr->getShape()->getName() == i)
                {
                    return true;
                }
                else
                {
                    snptr = snptr->getNext();
                }
            }
            
            tptr = tptr->getNext();
        }
    }
    
    return false;
}

//Checks if there is a Shape with the SAME NAME
bool shapeNameExists(string i)
{
    GroupNode* tptr = gList -> getHead();
    
    //Traverse Group List
    while (tptr != NULL)
    {
        ShapeList* sptr = tptr->getShapeList();
        ShapeNode* snptr = sptr->getHead();

        if (snptr == NULL)
        {
            tptr = tptr->getNext();
            continue;
        }

        //Traverse Shape List
        while (snptr != nullptr)
        {
            if(snptr->getShape()->getName() == i)
            {
                return true;
            }
            else
            {
                snptr = snptr->getNext();
            }
        }
        tptr = tptr->getNext();
    }
    return false;
}

//Checks if there is a group with the SAME NAME
bool groupNameExists(string i)
{
    GroupNode* tptr = gList -> getHead();
    
    //Traverse Group List
    while (tptr != NULL)
    {
        if (tptr->getName() == i)
        {
            return true;
        }
        
        tptr = tptr->getNext();
    }
    return false;
}

//Retrieves the Pointer to the GROUP!
GroupNode* givingGroupPointer(string i)
{
    GroupNode* tptr = gList -> getHead();
    
    //Traverse Group List
    while (tptr != NULL)
    {
        if (tptr->getName() == i)
        {
            return tptr;
        }
        
        ShapeList* sptr = tptr->getShapeList();
        ShapeNode* snptr = sptr->getHead();

        if (snptr == NULL)
        {
            tptr = tptr->getNext();
            continue;
        }

        //Traverse Shape List
        while (snptr != nullptr)
        {
            if(snptr->getShape()->getName() == i)
            {
                return tptr;
            }
            else
            {
                snptr = snptr->getNext();
            }
        }
        tptr = tptr->getNext();
    }
    
    return nullptr;
}

int main() {
    //Create Main List
    gList = new GroupList();
    
    // Create the Pool Group and Add It to the Group List
    GroupNode* poolGroup = new GroupNode("pool");
    gList->insert(poolGroup);
    
    string line;
    string command;
    
    cout << "> ";        
    getline(cin, line);    

    while ( !cin.eof () ) 
    {
        
        stringstream lineStream (line);
        
        //Check for Empty Input
        if (lineStream.peek() == EOF)
        {
            cout << "> "; // Prompt for input
            getline(cin, line);
            continue;
        }
        
        lineStream >> command;
        
        //Shape Command
        if (command == "shape")
        {
            //Initialize Variables
            string name, type;
            int locX, locY, sizeX, sizeY;
            
            lineStream >> name >> type >> locX >> locY >> sizeX >> sizeY;
            
            if (checkNameIsValid(name) == true)
            {
                if (checkNameExists(name) == false)
                {
                    Shape* createShapeI = new Shape(name, type, locX, locY, sizeX, sizeY);
                    ShapeNode* createShapeII = new ShapeNode();
                    createShapeII->setShape(createShapeI);
                    gList->getHead()->getShapeList()->insert(createShapeII);
                    
                    createShapeI->draw();
                }
                else
                {
                    cout << "error: name " << name << " exists" << endl;
                    cout << "> ";          
                    getline(cin, line);
                    continue;
                }
            }
            else
            {
                cout << "error: invalid name" << endl;
                cout << "> ";          
                getline(cin, line);
                continue;
            }
        }
        
        //Group Command
        if (command == "group")
        {
            string group;
            
            lineStream >> group;
            
            if (checkNameIsValid(group) == true)
            {
                if (checkNameExists(group) == false)
                {
                    GroupNode* createGroup = new GroupNode(group);
                    gList->insert(createGroup);
                    cout << group << ": group" << endl;
                }
                else
                {
                    cout << "error: name " << group << " exists" << endl;
                    cout << "> ";          
                    getline(cin, line);
                    continue;
                }
            }
            else
            {
                cout << "error: invalid name" << endl;
                cout << "> ";          
                getline(cin, line);
                continue;
            }
        }
        
        //Draw Command
        if (command == "draw")
        {
            cout << "drawing:" << endl;
            gList->print();
        }
        
        //Move Command
        if (command == "move")
        {
            string name1, name2;
            
            lineStream >> name1 >> name2;
            
            if (checkNameIsValid(name1) == false)
            {
                cout << "error: invalid name" << endl;
                cout << "> ";          
                getline(cin, line);
                continue;
            }
            
            if (checkNameIsValid(name2) == false)
            {
                cout << "error: invalid name" << endl;
                cout << "> ";          
                getline(cin, line);
                continue;
            }
            
            if (shapeNameExists(name1) == true)
            {
                if (groupNameExists(name2) == true)
                {
                    GroupNode* initialPtr = givingGroupPointer(name1);
                    GroupNode* finalPtr = givingGroupPointer(name2);
                    ShapeNode* temporaryPtr = initialPtr->getShapeList()->remove(name1);
                    finalPtr->getShapeList()->insert(temporaryPtr);
                    cout << "moved " << name1 << " to " << name2 << endl;
                }
                else
                {
                    cout << "error: group " << name2 << " not found" << endl;
                    cout << "> ";          
                    getline(cin, line);
                    continue;
                }
            }
            else
            {
                cout << "error: shape " << name1 << " not found" << endl;
                cout << "> ";          
                getline(cin, line);
                continue;
            }
        }
        
        //Delete Command
        if (command == "delete")
        {
            string name;
            
            lineStream >> name;
            
            if (checkNameIsValid(name) == false)
            {
                cout << "error: invalid name" << endl;
                cout << "> ";          
                getline(cin, line);
                continue;
            }
            
            if (shapeNameExists(name) == true)
            {
                GroupNode* groupPtr = givingGroupPointer(name);
                ShapeNode* tPtr = groupPtr->getShapeList()->getHead();
                ShapeNode* pPtr = NULL;
                
                while (tPtr != NULL)
                {
                    if (tPtr->getShape()->getName() == name) break;
                   
                    pPtr = tPtr;
                    tPtr = tPtr->getNext();
                }
                
                if (tPtr == groupPtr->getShapeList()->getHead())
                {
                    groupPtr->getShapeList()->setHead(tPtr->getNext());
                    delete tPtr->getShape();
                    tPtr->setShape(nullptr);
                    delete tPtr;
                    tPtr = nullptr;
                    cout << name << ": deleted" << endl;
                }
                else
                {
                    pPtr->setNext(tPtr->getNext());
                    delete tPtr->getShape();
                    tPtr->setShape(nullptr);
                    delete tPtr;
                    tPtr = nullptr;
                    cout << name << ": deleted" << endl;
                }
            }
            else if (groupNameExists(name) == true)
            {
                GroupNode* tPtr = gList->getHead();
                GroupNode* pPtr = NULL;
                
                while(tPtr != NULL)
                {
                    if (tPtr->getName() == name) break;
                    
                    pPtr = tPtr;
                    tPtr = tPtr->getNext();
                }
                
                pPtr->setNext(tPtr->getNext());
                
                if (tPtr->getShapeList()->getHead() == NULL)
                {
                    delete tPtr;
                    cout << name << ": deleted" << endl;
                }
                else
                {
                    ShapeNode* ttPtr = tPtr->getShapeList()->getHead();
                    while (ttPtr != NULL)
                    {
                        Shape* createShapeI = new Shape(ttPtr->getShape()->getName(), ttPtr->getShape()->getType(), ttPtr->getShape()->getXlocation(), ttPtr->getShape()->getYlocation(), ttPtr->getShape()->getXsize(), ttPtr->getShape()->getYsize());
                        ShapeNode* createShapeII = new ShapeNode();
                        createShapeII->setShape(createShapeI);
                        poolGroup->getShapeList()->insert(createShapeII);
                        
                        ttPtr = ttPtr->getNext();
                    }
                    
                    
                    ShapeNode* rPtr = tPtr->getShapeList()->getHead();
                    ShapeNode* rrPtr = NULL;
                    while (rPtr != NULL)
                    {
                        rrPtr = rPtr->getNext();
                        delete rPtr->getShape();
                        rPtr->setShape(nullptr);
                        delete rPtr;
                        rPtr = rrPtr;
                    }
                                        
                    tPtr->getShapeList()->setHead(NULL);
                    pPtr->setNext(tPtr->getNext());
                    delete tPtr;
                    cout << name << ": deleted" << endl;
                }
            }
            else if (shapeNameExists(name) == false)
            {
                cout << "error: shape " << name << " not found" << endl;
                cout << "> ";          
                getline(cin, line);
                continue;
            }
            else
            {
                cout << "error: group " << name << " not found" << endl;
                cout << "> ";          
                getline(cin, line);
                continue;
            }
        }
        
        cout << "> ";          
        getline(cin, line);
        continue;
    }
    
    return 0;
}
