#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Renderer.h"


Renderer::Renderer() {}

bool Renderer::init(int width, int height, const char* name) {
    scrWidth = width;
    scrHeight = height;
    scrName = new char[strlen(name) + 1];
    strcpy(scrName, name);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif
    
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    window = glfwCreateWindow(scrWidth, scrHeight, scrName, nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return false;
    }

    return true;
}
void Renderer::draw(){
    glFlush();
}
void Renderer::clear(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Renderer::present(){
    glfwShowWindow(window);
}   

Renderer::~Renderer() {
    delete[] scrName;

    glfwTerminate();
}
