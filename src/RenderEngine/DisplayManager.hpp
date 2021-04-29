/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** DisplayManager
*/

#ifndef DISPLAYMANAGER_HPP_
#define DISPLAYMANAGER_HPP_

#include "../include.hpp"
#include "Loader.hpp"
#include "MasterRenderer.hpp"
#include "OBJLoader.hpp"
#include "../Entities/Camera.hpp"
#include "../Entities/Light.hpp"

class DisplayManager {
    public:
        DisplayManager();
        ~DisplayManager();

        void run();
        void event();
        void updateDisplay();

    protected:
    private:
        sf::RenderWindow *_window;
        std::vector<bool> _keysRough; //for name input for example
        std::vector<bool> _keysSmooth; //for movement
};

#endif /* !DISPLAYMANAGER_HPP_ */
