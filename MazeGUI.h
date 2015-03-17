#ifndef MAZEGUI_H
#define MAZEGUI_H

#include "Maze.h"
#include "DrawPanel.h"

class MazeGUI : public DrawPanel, Update
{

   private:
      Maze* maze;

   public:
      MazeGUI(int width, int height, Maze* maze);
      virtual ~MazeGUI();
      virtual void update();       
      virtual void on_maze_button_click_event();

      void startMazeThread();
      void solve();

};

#endif 
