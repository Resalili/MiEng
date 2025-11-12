#include "Renderer.h"
#include <iostream>

int main(){
    Renderer* win = new Renderer();
    win->init(100,100,"Test Window");
    if(std::getchar() == 'i'){
        win->present();
    }

    return 0;
}