#include"game.hpp"
int main(){
    game.init();
    game.mode();
    while(game.move()!=0){
        game.init();
        game.mode();
    }
    return 0;
}
