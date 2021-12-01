//
//  parser.cpp
//  

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "Shape.h"

//ShapeArray Dynamically Allocated
Shape** shapesArray;

// The Number of Shapes in the Database, to be Incremented 
int shapeCount = 0;

// The Value of the Argument to the maxShapes Command
int max_shapes;

void errorPrint(int i, string j)
{
    if (i == 0) cout << "Error: invalid command" << endl;
    else if (i == 1) cout << "Error: invalid argument" << endl;
    else if (i == 2) cout << "Error: invalid shape name" << endl;
    else if (i == 3) cout << "Error: shape " << j << " exists" << endl;
    else if (i == 4) cout << "Error: shape " << j << " not found" << endl;
    else if (i == 5) cout << "Error: invalid shape type" << endl;
    else if (i == 6) cout << "Error: invalid value" << endl;
    else if (i == 7) cout << "Error: too many arguments" << endl;
    else if (i == 8) cout << "Error: too few arguments" << endl;
    else if (i == 9) cout << "Error: shape array is full" << endl;
}

//Invalid Command
bool checkCommand(string i)
{
    if (i == "maxShapes" || i == "create" || i == "move" || i == "rotate" || i == "draw" || i == "delete")
        return true;
    else
    {
        errorPrint(0, "");
        return false;
    }
}

//Invalid Shape Name
bool shapeInvalidName(string i)
{
    if (i == "maxShapes" || i == "create" || i == "all" || i == "move" || i == "rotate" || i == "draw" || i == "delete" || i == "all" || i == "circle" || i == "ellipse" || i == "rectangle" || i == "triangle")
    {
        return false;
    }
    else
    {
        return true;
    }
}

//Shape Name Exists
bool shapeNameExists(string i)
{
    for (int j = 0; j < max_shapes; j++)
    {
        if (shapesArray[j] == nullptr)
        {
            continue;
        }
        else
        {
            if ((*shapesArray[j]).getName() == i)
                return true;
        }
    }
     
    return false;
}

//Invalid Shape Type
bool shapeTypeTrue(string i)
{
    if (i == "circle" || i == "ellipse" || i == "rectangle" || i == "triangle")
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Invalid Value
bool createValidValues(int locX, int locY, int sizeX, int sizeY, string name)
{
    if (name == "circle")
    {
        if ((locX >= 0) && (locY >= 0) && (sizeX >= 0) && (sizeY >= 0) && (sizeX == sizeY))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if ((locX >= 0) && (locY >= 0) && (sizeX >= 0) && (sizeY >= 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

//If Move is Valid and Positive Integer
bool moveValidValues(int locX, int locY)
{
    if ((locX >= 0) && (locY >= 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//If Rotation Values are Between 0 and 360
bool rotateValidValues(int angle)
{
    if (0 <= angle && angle <= 360)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Check Which Array Value Matches Numbers
int findArrayValue(string i)
{
    for (int j = 0; j < max_shapes; j++)
    {
        if (shapesArray[j] == nullptr)
        {
            continue;
        }
        else
        {
            if ((*shapesArray[j]).getName() == i)
                return j;
        }
    }
     
    return -1;
}

int main() 
{

    string line;
    string command;
    
    shapesArray = NULL;
     
    cout << "> "; // Prompt for Input
    getline(cin, line);
        
    //Checking for MaxShapes
    while (!cin.eof()) {        
        
        stringstream lineStream(line);
        
        if (lineStream.peek() == EOF )
        {
            errorPrint(0, "");
            cout << "> "; // Prompt for Input
            getline(cin, line);
            continue;
        }
      
        // Read from SStream into the command, the only way this can fail is if the EOF is encountered
        lineStream >> command;
        
        //Error 0, Checks if Command Matches
        if (!checkCommand(command))
        {
            lineStream.clear();
            cout << "> "; // Prompt for input
            getline(cin, line);
            continue;
        }
        
        //MaxShapes Command
        if (command == "maxShapes") 
        {
            int numberOfShapes;
            
            lineStream >> numberOfShapes;
            
            //Checks for Too Few Arguments, 8
            if (lineStream.fail() && lineStream.eof())
            {
                errorPrint(8, "");
                lineStream.clear();
                cout << "> "; // Prompt for Input
                getline(cin, line);
                continue;
            }
            
            //Checks for Invalid Argument, 1
            if (lineStream.fail())
            {
                errorPrint(1, "");
                lineStream.clear();
                cout << "> "; // Prompt for Input
                getline(cin, line);
                continue;
            }
            
            //Checks for Invalid Argument, 1
            int temp = lineStream.peek();
            if ((temp != '\t' && temp != ' ' && temp != EOF))
            {
                errorPrint(1, "");
                lineStream.clear();
                cout << "> "; // Prompt for Input
                getline(cin, line);
                continue;
            }
            
            //Checks for Invalid Value, 6
            if (numberOfShapes < 0)
            {
                errorPrint(6, "");
                lineStream.clear();
                cout << "> "; // Prompt for Input
                getline(cin, line);
                continue;
            }
            
            //Checks for Too Many Arguments, 7
            string additionalArguments = "";
            lineStream >> additionalArguments;
            if (additionalArguments != "")
            {
                errorPrint(7, "");
                lineStream.clear();
                cout << "> "; // Prompt for Input
                getline(cin, line);
                continue;
            }
            
            if (shapesArray != NULL) 
            {
                for (int i = 0; i < shapeCount; i++) 
                {
                    delete shapesArray[i];
                    shapesArray[i] = nullptr;
                }
                shapesArray = nullptr;
            }

            max_shapes = numberOfShapes;
            shapesArray = new Shape*[numberOfShapes];
            cout << "New database: max shapes is " << numberOfShapes << endl;
            shapeCount = 0;

        }
        
        //Create Command
        if (command == "create")
        {
            string name, type;
            int locX, locY, sizeX, sizeY;
            
            //NAME, First Argument
            lineStream >> name;
            
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }

                //Check if Shape Uses Invalid Word, 2
                if (shapeInvalidName(name) == false)
                {
                    errorPrint(2, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }

                //Check if Name Exists, 3
                if (shapeNameExists(name) == true)
                {
                    errorPrint(3, name);
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
          
            //TYPE, Second Argument
            lineStream >> type;
            
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Wrong Shape Type, 5
                if (shapeTypeTrue(type) == false)
                {
                    errorPrint(5, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
            //LOCX, Third Argument
            lineStream >> locX;
                
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Invalid Argument, 1
                if (lineStream.fail())
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }

                //Checks for Invalid Argument, 1
                int temp = lineStream.peek();
                if ((temp != '\t' && temp != ' ' && temp != EOF))
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
                if (locX < 0)
                {
                    errorPrint(6, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
            //LOCY, Fourth Argument
            lineStream >> locY;
                
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Invalid Argument, 1
                if (lineStream.fail())
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }

                //Checks for Invalid Argument, 1
                temp = lineStream.peek();
                if ((temp != '\t' && temp != ' ' && temp != EOF))
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
                if (locY < 0)
                {
                    errorPrint(6, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
            //SIZEX, Fifth Argument
            lineStream >> sizeX;
            
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Invalid Argument, 1
                if (lineStream.fail())
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }

                //Checks for Invalid Argument, 1
                temp = lineStream.peek();
                if ((temp != '\t' && temp != ' ' && temp != EOF))
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
                if (sizeX < 0)
                {
                    errorPrint(6, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
            //SIZEY, Last Argument
                lineStream >> sizeY;
                
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Invalid Argument, 1
                if (lineStream.fail())
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }

                //Checks for Invalid Argument, 1
                temp = lineStream.peek();
                if ((temp != '\t' && temp != ' ' && temp != EOF))
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
                if (sizeY < 0)
                {
                    errorPrint(6, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
                if (type == "circle" && sizeX != sizeY)
                {
                    errorPrint(6, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
                //Checks for Too Many Arguments, 7
                string additionalArguments = "";
                lineStream >> additionalArguments;
                if (additionalArguments != "")
                {
                    errorPrint(7, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
                if (shapeCount == max_shapes)
                {
                    errorPrint(9, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            shapesArray[shapeCount] = new Shape(name, type, locX, locY, sizeX, sizeY);
            (*shapesArray[shapeCount]).setName(name);
            (*shapesArray[shapeCount]).setType(type);
            (*shapesArray[shapeCount]).setXlocation(locX);
            (*shapesArray[shapeCount]).setYlocation(locY);
            (*shapesArray[shapeCount]).setXsize(sizeX);
            (*shapesArray[shapeCount]).setYsize(sizeY);

            cout << "Created " << name << ": " << type << " " << locX << " " << locY << " " << sizeX << " " << sizeY << endl;
            shapeCount = shapeCount + 1;
           
        }
        
        //Move Command
        if (command == "move")
        {
            string name;
            int locX, locY;
            
            //NAME, First Name
            lineStream >> name;
            
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                if (name == "maxShapes" || name == "create" || name == "all" || name == "move" || name == "rotate" || name == "draw" || name == "delete" || name == "all" || name == "circle" || name == "ellipse" || name == "rectangle" || name == "triangle")
                {
                    errorPrint(2, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                if(shapeNameExists(name) == false)
                {
                    errorPrint(4, name);
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
            //LOCX, Second Argument
            lineStream >> locX;
            
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Invalid Argument, 1
                if (lineStream.fail())
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }

                //Checks for Invalid Argument, 1
                int temp = lineStream.peek();
                if ((temp != '\t' && temp != ' ' && temp != EOF))
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
                if (locX < 0)
                {
                    errorPrint(6, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
            //LOCY, Last Argument
            lineStream >> locY;
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Invalid Argument, 1
                if (lineStream.fail())
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }

                //Checks for Invalid Argument, 1
                temp = lineStream.peek();
                if ((temp != '\t' && temp != ' ' && temp != EOF))
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
                if (locY < 0)
                {
                    errorPrint(6, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Too Many Arguments, 7
                string additionalArguments = "";
                lineStream >> additionalArguments;
                if (additionalArguments != "")
                {
                    errorPrint(7, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
            int b = findArrayValue(name);
            (*shapesArray[b]).setXlocation(locX);
            (*shapesArray[b]).setYlocation(locY);
            cout << "Moved " << name << " to " << locX << " " << locY << endl;

        }
        
        //Rotate Command
        if (command == "rotate")
        {
            string name;
            int angle;
            
            //NAME, First Argument
            lineStream >> name;
                  
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                if (name == "maxShapes" || name == "create" || name == "all" || name == "move" || name == "rotate" || name == "draw" || name == "delete" || name == "all" || name == "circle" || name == "ellipse" || name == "rectangle" || name == "triangle")
                {
                    errorPrint(2, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                if(shapeNameExists(name) == false)
                {
                    errorPrint(4, name);
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                    
            //ANGLE, Last Argument
            lineStream >> angle;
            
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Invalid Argument, 1
                if (lineStream.fail())
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }

                //Checks for Invalid Argument, 1
                int temp = lineStream.peek();
                if ((temp != '\t' && temp != ' ' && temp != EOF))
                {
                    errorPrint(1, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
                if (!(0 <= angle && angle <= 360))
                {
                    errorPrint(6, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Too Many Arguments, 7
                string additionalArguments = "";
                lineStream >> additionalArguments;
                if (additionalArguments != "")
                {
                    errorPrint(7, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
            int b = findArrayValue(name);
            (*shapesArray[b]).setRotate(angle);
            cout << "Rotated " << name << " by " << angle << " degrees" << endl;
                
        }
        
        if (command == "draw")
        {
            string input;
            
            lineStream >> input;
            
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                if (input == "maxShapes" || input == "create" || input == "move" || input == "rotate" || input == "draw" || input == "delete" || input == "circle" || input == "ellipse" || input == "rectangle" || input == "triangle")
                {
                    errorPrint(2, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                if(shapeNameExists(input) != true && input != "all")
                {
                    errorPrint(4, input);
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Too Many Arguments, 7
                string additionalArguments = "";
                lineStream >> additionalArguments;
                if (additionalArguments != "")
                {
                    errorPrint(7, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
            if (input == "all")
            {
                cout << "Drew all shapes" << endl;
                for (int i = 0; i < max_shapes; i++)
                {
                    if (shapesArray[i] == nullptr)
                    {
                        continue;
                    }
                    else
                    {
                        cout << (*shapesArray[i]).getName() << ": " << (*shapesArray[i]).getType() << " " <<  (*shapesArray[i]).getXlocation() << " " <<  (*shapesArray[i]).getYlocation() << " " <<  (*shapesArray[i]).getXsize() << " " <<  (*shapesArray[i]).getYsize() << endl;
                    }
                }
            }
            else
            {
                int b = findArrayValue(input);
                cout << "Drew " << input << ": " << (*shapesArray[b]).getType() << " " <<  (*shapesArray[b]).getXlocation() << " " <<  (*shapesArray[b]).getYlocation() << " " <<  (*shapesArray[b]).getXsize() << " " <<  (*shapesArray[b]).getYsize() << endl;
            }
           
        }
        
        //Delete Command
        if (command == "delete")
        {
            string input;
            
            lineStream >> input;
            
                //Checks for Too Few Arguments, 8
                if (lineStream.fail() && lineStream.eof())
                {
                    errorPrint(8, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                if (input == "maxShapes" || input == "create" || input == "move" || input == "rotate" || input == "draw" || input == "delete" || input == "circle" || input == "ellipse" || input == "rectangle" || input == "triangle")
                {
                    errorPrint(2, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                if(shapeNameExists(input) != true && input != "all")
                {
                    errorPrint(4, input);
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
            
                //Checks for Too Many Arguments, 7
                string additionalArguments = "";
                lineStream >> additionalArguments;
                if (additionalArguments != "")
                {
                    errorPrint(7, "");
                    lineStream.clear();
                    cout << "> "; // Prompt for Input
                    getline(cin, line);
                    continue;
                }
                
            if (input == "all")
            {
                cout << "Deleted: all shapes" << endl;
                shapeCount = 0;
                for (int i = 0; i < max_shapes; i++)
                {
                    if (shapesArray[i] == nullptr)
                    {
                        continue;
                    }
                    else
                    {
                        delete shapesArray[i];
                        shapesArray[i] = nullptr;
                    }
                }
            }
            else
            {
                int b = findArrayValue(input);
                cout << "Deleted shape " << input << endl;
                delete shapesArray[b];
                shapesArray[b] = nullptr;
            }
        }
        
        lineStream.clear();
        cout << "> "; // Prompt for Input
        getline(cin, line);
        
    }

    return 0;
}
