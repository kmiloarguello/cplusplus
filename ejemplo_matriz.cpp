#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int h = 7;
const int w = 5;
bool show [h] [w], work [h] [w];
int x, y, neighbors, iterations, c, row, col;


//Functions

// Instructions() - describes the game and input
void Instructions()
{
     cout << "Welcome to Conway's Game of Life\n\n\n"
          << "The game is played on a 70 x 20 space grid.\n"
          << "Empty spaces are 'dead' and 1s represent 'life'.\n\n"
          << "There are 3 simple rules:\n"
          << "     If a space is dead, with exactly 3 live neighbors, "
          << "that space\nwill be 'born'.\n"
          << "     If a space is alive, with 2 or 3 live neighbors, "
          << "that space\nwill continue to live.\n"
          << "     If a space is alive with 0, 1, or 4 or more dead "
          << "neighbors, that\nspace will die.\n\n"
          << "Enter an X (1-70) and Y (1-20) coordinate where you would "
          << "like to seed\nLife, with 0, 0 the upper left corner.\n"
          << "To remove life, enter the same coordinate a second time.\n"
          << "Type '-1' as an X to indicate you are done entering and wish "
          << "to start\nthe simulation" <<endl;
}

//Clear() - Clears the arrays
void Clear(bool matrix[h][w])
{
      for(row=0; row<h; row++)
      {
               for(col=0; col<w; col++)
               matrix[row][col] = 0;
      }    
}     

//Display() - prints an Array
void Display(bool matrix[h][w])
{
     for(row=0; row<h; row++)
     {
                for(col=0; col<w; col++)
                {
                           if (col==0)
                           cout << endl << matrix[row][col];
                           else
                           cout << matrix[row][col];
                }
     }
     cout << endl << endl;
}


//InvalidC() - displays an invalid entry message for columns
void InvalidC()
{
     cout << "That is an invalid selection.\n"
          << "Please enter a value between 1 and 70\n"
          << "X  ";
          cin >> x;
}

//InvalidR() - displays an invalid entry message for rows
void InvalidR()
{
     cout << "That is an invalid selection.\n"
          << "Please enter a value between 1 and 20\n"
          << "Y  ";
          cin >> y;
}


//Input() - receives input and populates an array
void Input(bool matrix [h][w])
{
     while (x != -1)
     {
           cout << "X  ";
           cin >> x;
           if (x == -1)
           break;
           while (x < 0 || x > w)
           InvalidC();
           cout << "Y  ";
           cin >> y;
           while (y < 0 || y > h)
           InvalidR();
           if (show[y-1][x-1] == 0)
           show[y-1][x-1] = 1;
           else
           matrix[y-1][x-1] = 0;
           Display (show);
     }

    cout << endl;
    cout << "Enter the number of 'ticks' that you want the\n"
         << "simulation to run" << endl;
         cin >> iterations;
}

//Swtich() - moves array Work into Array Show
void Switch(bool matrixa[h][w], bool matrixb[h][w])
{
    for(row=0; row<h; row++)
     {
                for(col=0; col<w; col++)
                {
                           matrixa[row][col] = matrixb[row][col];
                }
     }
}           
           
//Calculate() - Counts neighbors, and calculates the new array
void Calculate(bool matrixa[h][w], bool matrixb[h][w])
{
     for(row=0; row<h; row++)
     {
                for(col=0; col<w; col++)
                {
                           neighbors=0;
                           // count neighbors
                           if (matrixa [row-1][col-1] == 1) neighbors +=1;
                           if (matrixa [row-1][col] == 1) neighbors +=1;
                           if (matrixa [row-1][col+1] == 1) neighbors +=1;
                           if (matrixa [row][col-1] == 1) neighbors +=1;
                           if (matrixa [row][col+1] == 1) neighbors +=1;
                           if (matrixa [row+1][col-1] == 1) neighbors +=1;
                           if (matrixa [row+1][col] == 1) neighbors +=1;
                           if (matrixa [row+1][col+1] == 1) neighbors +=1;
                           
                           //calculate life
                           if (matrixa [row][col] == 1 && neighbors < 2)
                           matrixb [row][col] = 0;
                           else if (matrixa [row][col] == 1 && neighbors > 3)
                           matrixb [row][col] = 0;
                           else if (matrixa [row][col] == 1 && 
                           (neighbors == 2 || neighbors == 3))
                           matrixb [row][col] = 1;
                           else if (matrixa [row][col] == 0 && neighbors == 3)
                           matrixb [row][col] = 1;
                }
     }                    
}

// declaration of main program

int main()

{
Instructions();
Clear(show);
Clear(work);
Input(show);
Display(show);
for (c=0; c<iterations; c++)
{   
    cout << "show1";
    Display(show);
    Clear(work);
    cout << "work1";
    Display(work);
    Calculate(show, work);
    cout << "show2";
    Display(show);
    cout << "work2";
    Display(work);
    Switch(show, work);
    cout << "show3";
    Display(show);
    cout << "work3";
    Display(work);
}
}
