#include <iostream>
#include <conio.h>

using namespace std;

void draw(char (*array)[3])
{
  // inconvéient: pas dynamique
  cout << " " << array[0][0] << " | " << array[0][1] << " | " << array[0][2] << endl;
  cout << "-----------" << endl;
  cout << " " << array[1][0] << " | " << array[1][1] << " | " << array[1][2] << endl;
  cout << "-----------" << endl;
  cout << " " << array[2][0] << " | " << array[2][1] << " | " << array[2][2] << endl;
}

bool up(int x, int y, char (*array)[3])
{
  if (x > 0 && array[x - 1][y] == ' ')
  {
    array[x - 1][y] = '.';
    array[x][y] = ' ';
    return true;
  }
  return false;
}

bool down(int x, int y, char (*array)[3])
{
  if (x < 2 && array[x + 1][y] == ' ')
  {
    array[x + 1][y] = '.';
    array[x][y] = ' ';
    return true;
  }
  return false;
}

bool left(int x, int y, char (*array)[3])
{
  if (y > 0 && array[x][y - 1] == ' ')
  {
    array[x][y - 1] = '.';
    array[x][y] = ' ';
    return true;
  }
  return false;
}

bool right(int x, int y, char (*array)[3])
{
  if (y < 2 && array[x][y + 1] == ' ')
  {
    array[x][y + 1] = '.';
    array[x][y] = ' ';
    return true;
  }
  return false;
}

void playerTurn(char (*array)[3])
{
  bool done = false;
  char input;
  int x = 1;
  int y = 1;
  while (!done)
  {
    input = _getch();
    switch (input)
    {
    case 'z':
      if (up(x, y, array))
      {
        x--;
      }
      break;
    case 's':
      if (down(x, y, array))
      {
        x++;
      }
      break;
    case 'q':
      if (left(x, y, array))
      {
        y--;
      }
      break;
    case 'd':
      if (right(x, y, array))
      {
        y++;
      }
      break;
    default:
      cout << "Invalid command";
      break;
    }
    draw(array);
  }
}

int main()
{
  bool end = false;
  char array[3][3] = {{'X', ' ', ' '}, {' ', ' ', 'O'}, {' ', ' ', ' '}};
  draw(array);
  playerTurn(array);
}