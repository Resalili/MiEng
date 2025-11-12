#pragma once
#include <GLFW/glfw3.h>

class Renderer{
    public:
        ~Renderer();
        Renderer();
        
        bool init(int width,int height,const char* name);
        void clear();
        void draw();
        void present();

    private:
        int scrWidth,scrHeight;
        char* scrName;
        GLFWwindow* window;
};