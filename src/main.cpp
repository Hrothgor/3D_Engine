/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "include.hpp"
#include "RenderEngine/DisplayManager.hpp"

int main(void)
{
    srand(time(NULL));
    DisplayManager win;
    win.run();
    return (0);
}