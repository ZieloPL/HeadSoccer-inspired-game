// This game was made for non-commercial use
// -----------------------------------------------------------------------------
// Credits
// -----------------------------------------------------------------------------
// Game assets used in this project:"
//   Author: Toke Game Art
//   Source: https://tokegameart.net/item/tiny-soccer-head-game-asset/
//
// Please ensure all assets are used within the bounds of their respective licenses.
// -----------------------------------------------------------------------------
#include <iostream>
#include "header.h"
using namespace std;
int main()
{
    //Initializing game engine
    Gra Game;

    //game loop
    while (Game.running()) {


        //update
        Game.update();

        //render
        Game.render();
    }

    //End of the game
    return 0;
}
