#include "console_window.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>

ConsoleWindow::ConsoleWindow(int timeout): _timeout(timeout) {}

void ConsoleWindow::draw() 
{
    std::for_each(_children.begin(), _children.end(), [](Window::Ptr window) { window->draw(); });
}

void ConsoleWindow::add(Window::Ptr child) { _children.push_back(child); }
void ConsoleWindow::set(int index, Window::Ptr child) { _children.assign(index, child); }

Window::Ptr ConsoleWindow::remove(int index) 
{
    Window::Ptr temp = _children.at(index);
    _children.erase(_children.begin() + index); 
    return temp;
}

void ConsoleWindow::start() 
{
    clear();
    draw();

    while(_start)
    {
        // draw();
        flush();
        sleep(1);

        _timeout--;
        if (_timeout <= 0) _start = false;
    }
}

void ConsoleWindow::clear() { std::cout << "\033[2J\033[H"; }

void ConsoleWindow::flush() { std::cout << std::flush; }

void ConsoleWindow::sleep(int seconds) { std::this_thread::sleep_for(std::chrono::seconds(seconds)); }
