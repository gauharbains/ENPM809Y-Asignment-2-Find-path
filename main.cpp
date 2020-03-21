#include <array>
#include <vector> 
#include <iostream>    
 
/**
 * @file main.cpp
 * @author Gauhar Bains <gbains@umd.edu>
 * @version 1.0
 * @section  LICENSE
 *  This program is free software, you can redistributeit and/or modify it
 *  under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option) any version.
 * 
 * @section DESCRIPTION
 * This program uses a recursive function called FindPath to navigate path from a start 
 * location to a goal location in the given maze.
 *  
 */
  
 // Prototype for the FindPath function
 bool FindPath(int, int );
 
 
  
  //create the maze
  std::array<std::array<std::string,6>,6> maze =
    {{{".","#","#","#","#","#"},
     {".",".",".","#",".","#"},
     {"#",".","#","#",".","#"},
     {"#",".","#","#",".","#"},
     {".",".","#",".",".","."},
     {"#",".",".",".","#","#"}}};
     
    
 // define FindPath function
 /**
  * @brief Recursive funtion to find path between the start and goal location of the maze
  * @param x coordinate of the start position
  * @param y coordinate of the start position
  * @return true or false depending on various base conditions
  */
 bool FindPath(int x, int y ){ 
    
     /* FindPath function uses a recursion algorithm
        to find path from a start point to goal  
        in the given maze. The function ends
        when one of the following base conditions(defined
        in the next couple of lines) are reached */
        
        
     
    // check whether the poition is outside the maze 
    if(x >5 || x<0){
        return false;
         }
         
    if(y >5 || y<0){
        return false;
         }    

    
     
    // check if goal position has been reached    
    if(maze[x][y]=="G"){
        std:: cout << "\n";
        
        // Output the final path
        for(int i =0; i<=5; i++){
            for(int j=0;j<=5; j++){
                std:: cout<< maze[i][j];
            }
        std:: cout << "\n"; 
        }
       return true;
    }
    
      
    // check whether there is an obstacle   
    if(maze[x][y]=="#"){
             return false;
         }
         
    if(maze[x][y]=="+"){
             return false;
         }          
 
 
 
    maze[x][y]="+" ;
    
    // check north of the current position     
    if (FindPath(x-1,y) == true ){
             return true;
         } 
     
    // check east of the current position   
    if (FindPath(x,y+1) == true ){
             return true;
         }
         
    // check south of the current position     
    if (FindPath(x+1,y) == true ){
             return true;
         }
     
    // check west of the current position    
    if (FindPath(x,y-1) == true ){
             return true;
         }
         
         
    maze[x][y]=".";     
    return false;       
         
     }
     
     
 // main function  
 
  /**
  * @brief main function   
  * @return Executes the main function
  */
int main(int argc, char **argv)
{
    // print the maze
    for(int i =0; i<=5; i++) {
        for(int j=0;j<=5; j++){
            std:: cout<< maze[i][j];
        }
        std:: cout << "\n"; 
    } 
    std::cout<< "\n";
    
    /* initialize the variables used 
      to store the start the goal position*/
      
    int sx,sy,gx,gy;
    std:: vector<int> start;    
    
    /* Prompt user to enter the coordinates of the start position.
       Then check whether the input is valid, for example - if the position
       lies within the maze or if there's an obstacle present at that location*/  
      
    bool valid_inp=false;
    while(valid_inp==false ){
        std::cout<< "Enter Valid Integer Cartesian Coordinates for Start Position \n";
        std::cin>>sx>>sy;
        if(sx <=5 && sx >=0 && sy <=5 && sy >=0 && maze[5-sy][sx]=="." ){
            valid_inp=true;
            start.push_back(5-sy);
            start.push_back(sx);   
            std:: cout<< "Start Coordinates are : " << sx<<" "<< sy<<"\n";
            maze[5-sy][sx]="S";
        }
    }
    
       /* Prompt user to enter the coordinates of the goal position.
       Then check whether the input is valid, for example - if the position
       lies within the maze or if there's an obstacle present or if the goal
        position is similar to the start position*/
 
    std:: vector<int> goal;    
    valid_inp=false;
    while(valid_inp==false ){
        std::cout<< "Enter Valid Integer Cartesian Coordinates for the goal position \n";
        std::cin>>gx>>gy;
        // check if the input is valid        
        if(gx <=5 && gx >=0 && gy <=5 && gy >=0 && maze[5-gy][gx]=="." ){
            valid_inp=true;            
            goal.push_back(5-gy);
            goal.push_back(gx);   
            std:: cout<< "Goal Coordinates are : " << gx<<" "<< gy<<"\n";
            maze[5-gy][gx]="G";
        }
    }  
         
    
   bool result;
   // call FindPath funtion at the start location
   result = FindPath(5-sy,sx);
   if(result == false){
       std::cout<< "Solution Doesnot Exist";
   }
   std:: cout << "\n End \n";     
     
}