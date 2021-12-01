//
//  Shape.h
//  

#ifndef Shape_h
#define Shape_h

#include <iostream>
#include <string>
using namespace std;

class Shape {
    private:
        string name;                  
        string type;                  
        int x_location;                
        int y_location;              
        int x_size;                    
        int y_size;                    
    public:
        Shape(string n, string t, int x_loc, int y_loc, int x_sz, int y_sz);

        string getType();            
        string getName();             
        int getXlocation();            
        int getYlocation();      
        int getXsize();              
        int getYsize();            

        void setType(string t);       
        void setName(string n);       
        void setXlocation(int x_loc);  
        void setYlocation(int y_loc);  
        void setXsize(int x_sz);      
        void setYsize(int y_sz);       

        void draw();                   
};

#endif 
