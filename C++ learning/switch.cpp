//int a = 10;
//int b = 10;
//int c = 20;
//
//switch ( a ) {
//case b:
//  // Code
//  break;
//case c:
//  // Code
//  break;
//default:
//  // Code
//  break;
//}

#include <iostream>

using namespace std;

void playgame()
{
    cout << "Play game called";
}
void loadgame()
{
    cout << "Load game called";
}
void playmultiplayer()
{
    cout << "Play multiplayer game called";
}

int main()
{
  int input;

  cout<<"1. Play game\n";
  cout<<"2. Load game\n";
  cout<<"3. Play multiplayer\n";
  cout<<"4. Exit\n";
  cout<<"Selection: ";
  cin>> input;
  switch ( input ) {
  case 1:            // Note the colon, not a semicolon
    playgame();
    break;
  case 2:            // Note the colon, not a semicolon
    loadgame();
    break;
  case 3:            // Note the colon, not a semicolon
    playmultiplayer();
    break;
  case 4:            // Note the colon, not a semicolon
    cout<<"Thank you for playing!\n";
    break;
  default:            // Note the colon, not a semicolon
    cout<<"Error, bad input, quitting\n";
    break;
  }
  cin.get();
}
