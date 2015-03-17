#include "MazeGUI.h"
#include "Matrix.h"

#include <gtkmm/main.h>
#include <gtkmm/table.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>

#include <iostream>
using namespace std;

#include <windows.h>

DWORD WINAPI traverseMaze(LPVOID* parameters)
{
   MazeGUI* maze_gui = (MazeGUI*) (parameters[0]);
   maze_gui->solve();
}

void MazeGUI::startMazeThread()
{
   //start a new thread to solve the maze
   LPVOID* params = new LPVOID[1];
   params[0] = this;
   CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE) traverseMaze, params, 0, NULL);
}

MazeGUI::MazeGUI(int w, int h, Maze* mz) : DrawPanel(w, h, mz)
{
   maze = mz;
   maze->addListener(this);
}

MazeGUI::~MazeGUI()
{
   //the maze is deleted in DrawPanel
}

void MazeGUI::update()
{
   render();
}

void MazeGUI::solve()
{
   maze->solve();
}

void MazeGUI::on_maze_button_click_event()
{
   startMazeThread();
}

int main(int argc, char** argv)
{
   Matrix* mat = Matrix::readMatrix("maze.txt");

   Gtk::Main kit(argc, argv);

   Gtk::Window win;
   win.set_title("Maze!");
   win.set_position(Gtk::WIN_POS_CENTER);
   //the size of the window
   int width = 875;
   int height = 445;

   win.set_size_request(width, height);
   win.set_resizable(false);  

   Gtk::Table tbl(10, 1, true);
   int rows = tbl.property_n_rows();
   int button_height = (int) (((double) height)/rows + 0.5);

   Maze* maze = new Maze(mat);
   MazeGUI mg(width, height - button_height, maze);  //needs to know its own dimensions
   Gdk::Color c("#FF0000");
   Gtk::Button btnMaze("Solve!");

   btnMaze.signal_clicked().connect(sigc::mem_fun(mg, &MazeGUI::on_maze_button_click_event));

   tbl.attach(mg, 0, 1, 0, 9, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND, 0, 0);
   tbl.attach(btnMaze, 0, 1, 9, 10, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND, 0, 0);
   win.add(tbl);

   win.show_all_children();
   Gtk::Main::run(win);

   return 0;
}
