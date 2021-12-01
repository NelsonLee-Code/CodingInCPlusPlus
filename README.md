<h1>
  Coding In C++
</h1>

This repository contains my C++ Projects, which include a TicTacToe game, a Shape Declaration project using Object-Oriented Programming and Dynamically Allocated Objects and Arrays, and a Shape Declaration project using Linked Lists.

If you like to learn more about my Projects, feel free to email me at nelson.nx.lee@gmail.com. 

<h2>
  Project: TicTacToe Game
</h2>

This TicTaeToe project uses classes, objects, and methods to build a basic TieTacToe game that allows users to play the game with the program implementing the logic and determining a winner.

- Inside the GameState class, we store the current gamestate of the TicTacToe in an object that is created, initialized, and then destroyed by the controller
- Inside the playMove function, the program will update the board, turn, validMove, and determine if the game is over, who wins, and which wincode was used to win
- Inside the GameController file, we create and initialize the game board, prompt the user for input with error-checking, and then call the playMove function and print the GameState class
<br>
<p align="center">
  <img width="700" alt="Screen Shot 2021-12-01 at 4 20 11 PM" src="https://user-images.githubusercontent.com/85120900/144315737-d9340550-46f6-45c3-aebb-8afdfaee52d7.png">
</p>
<div align="center">
  <i>
    Figure 1. A Sample Run of the TicTacToe Game
  </i> 
</div>
<br>
<h2>
  Project: Shape with Dynamically Allocated Objects and Arrays
</h2>

This Shape with Dynamically Allocated Objects and Arrays Project, hereafter referred to as the Dynamic Shape Project, uses C++ I/O streams (including error handling), constructors, accessors, mutators, and the dynamic allocation and de-allocation of arrays and objects. 

- Inside the Parser file, we use stringstream to check for errors from the user input (errors are checked word for word, from left to right, in priority order as seen in Figure 2), cin functions such as peek, clear, fail flags, and EOF flags, and then dynamically allocates objects and arrays to create Shapes
- Inside the Shape class, we hold the properties of a shape, such as name, type, location, and more 
<br>
<p align="center">
  <img width="700" alt="Screen Shot 2021-12-01 at 4 43 52 PM" src="https://user-images.githubusercontent.com/85120900/144318875-cfb20ca0-8885-4faa-9565-f42cdd62f0c8.png">
</p>
<div align="center">
  <i>
    Figure 2. Error Handling Priorities for the User Input done through StringStream
  </i> 
</div>
<br>
<br>
<p align="center">
  <img width="700" alt="Screen Shot 2021-12-01 at 4 42 32 PM" src="https://user-images.githubusercontent.com/85120900/144318689-cb71a368-05cf-4cc8-b853-c06ae9ca85da.png">
</p>
<div align="center">
  <i>
    Figure 3. A Sample Run of the Dynamic Shape Project
  </i> 
</div>
<br>
<h2>
  Project: Shape with Linked Lists
</h2>

This Shape with Linked Lists Project uses, creates, and maniuplates linked lists with constructors and destructors done with dynamic allocation and de-allocation without any memory leaks, which is checked with Valgrind. The structure of the linked list can be seen in Figure 4.

- Inside the Parser file, we collect user input (we assume input contains little to no errors), dynamically allocates and de-allocates linked lists, and more
- Inside the GroupList class, we create a linked list of GroupNodes containing head and numerous GroupNodes
- Inside the ShapeList class, we create a linked list of ShapeNodes containing head and numerous ShapeNodes
- Inside the GroupNode class, we create a node in a linked list of GroupNodes with name, myShapeList, and next
- Inside the ShapeNode class, we create a node in a linked list of ShapeNodes with the shape myShape (points to a Shape object) and next
- Inside the Shape class, we hold thhe properties of a shape, such as its name, type, location, and size

<p align="center">
  <img width="700" alt="Screen Shot 2021-12-01 at 4 59 41 PM" src="https://user-images.githubusercontent.com/85120900/144320971-9a5567fc-b1fa-48ce-ab40-1d8fde3d1130.png">
</p>
<div align="center">
  <i>
    Figure 4. A Visualization of the Structure of the Linked List
  </i> 
</div>
<br>

<p align="center">
  <img width="700" alt="Screen Shot 2021-12-01 at 5 00 35 PM" src="https://user-images.githubusercontent.com/85120900/144321087-1d56ab3a-579f-4e25-bc19-f730c8036e63.png">
</p>
<div align="center">
  <i>
    Figure 5. A Sample Run of the Shape Linked Lists Project
  </i> 
</div>
