#include "Maze.h"
#include "Color.h"
#include "Rect.h"

#include <windows.h>
#include <iostream>
using namespace std;

Maze::Maze(Matrix* mz)
{
   maze = mz;

   WALL = 0;
   SPACE = 1;
   TRIED = 2;
   BACKTRACK = 3;
   PATH = 4;
}

Maze::~Maze()
{
   delete maze;
}

void Maze::addListener(Update* g)
{
   gui = g;
}

bool Maze::solve()
{
   bool done = traverse(1, 1);
   return done;
}

bool Maze::traverse(int row, int col)
{
   bool done = false; //assume we are not done unless proven otherwise

   //DO THIS
   //test that the current grid location is a space (i.e. not a wall or already tried)
   if (                                   )
   {

      //DO THIS
      //now it has been tried so mark it as tried




      Sleep(75);  //slow down the maze traversal
      gui->update();

      //DO THIS
      //check to see if we have arrived at the bottom right corner of the maze
      int height = maze->getNumRows();
      int width = maze->getNumCols();

      if (                     )
      {
         done = true;
      }
      else
      {

         //DO THIS
         //make recursive calls that consider all four orthogonal directions
         //basically, we will try all possible paths until a solution is found

         //IMPORTANT!!
         //don't use row++ or column++ use row + 1 or col + 1, etc.
         //IMPORTANT: make use of the boolean that is returned every time you call traverse
















      }

      //if we are done, on the way back recursively we must mark the path that we took as the solution path
      if (done)
      {
         //DO THIS
         //mark the path taken as the solution path



         gui->update();
      }
      //backtrack
      else
      {
         //DO THIS



         Sleep(75);
         gui->update();
      }
   }

   return done;
}

void Maze::mouseClicked(int x, int y)
{}

void Maze::draw(Cairo::RefPtr<Cairo::Context> cr, int width, int height)
{
   int rows = maze->getNumRows();
   int cols = maze->getNumCols();
   int cell_width = (int) (((double) width)/cols + 0.5);
   int cell_height = (int) (((double) height)/rows + 0.5);

   Color red(1.0, 0.0, 0.0);
   Rect redRect(&red, cell_width, cell_height);

   Color green(0.0, 1.0, 0.0);
   Rect greenRect(&green, cell_width, cell_height);

   Color blue(0.0, 0.0, 1.0);
   Rect blueRect(&blue, cell_width, cell_height);

   Color white(1.0, 1.0, 1.0);
   Rect whiteRect(&white, cell_width, cell_height);

   Color black(0.0, 0.0, 0.0);
   Rect blackRect(&black, cell_width, cell_height);
 
   for (int i = 1; i <= rows; i++)
   {
      for (int j = 1; j <= cols; j++)
      {
         int val = (int) maze->getElement(i, j);
         int x_pixel = (j - 1) * cell_width + cell_width/2;
         int y_pixel = (i - 1) * cell_height + cell_height/2;

         if (val == WALL)
         {
            blackRect.draw(cr, x_pixel, y_pixel);
         }
         else if (val == SPACE)
         {
            whiteRect.draw(cr, x_pixel, y_pixel);
         }
         else if (val == TRIED)
         {
            blueRect.draw(cr, x_pixel, y_pixel);
         }
         else if (val == BACKTRACK)
         {
            redRect.draw(cr, x_pixel, y_pixel);
         }
         else if (val == PATH)
         {
            greenRect.draw(cr, x_pixel, y_pixel);
         }
      }
   }
}
