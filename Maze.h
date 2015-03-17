#if !defined (MAZE_H)
#define MAZE_H

#include "Matrix.h"
using CSC2110::Matrix;
#include "Drawable.h"
#include "Update.h"


class Maze : public Drawable
{
   private:
      Matrix* maze;
      Update* gui;

      int WALL;
      int SPACE;
      int TRIED;
      int BACKTRACK;
      int PATH;

      bool traverse(int row, int col);

   public:
      Maze(Matrix* mz);
      virtual ~Maze();
      bool solve();
      virtual void draw(Cairo::RefPtr<Cairo::Context> cr, int width, int height);
      virtual void mouseClicked(int x, int y);
      void addListener(Update* gui);
};

#endif
