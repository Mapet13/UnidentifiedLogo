#include <iostream>

#include "Window/Window.hpp"

int main()
{
    UnLOGO::Window win; // temp
    win.create(sf::VideoMode(500, 500));
    while (win.isOpen()) {
       win.update();
    }
 
    return 0;
}