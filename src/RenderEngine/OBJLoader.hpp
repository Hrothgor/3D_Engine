/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** OBJLoader
*/

#ifndef OBJLOADER_HPP_
#define OBJLOADER_HPP_

#include "../include.hpp"
#include "Loader.hpp"
#include "../Models/RawModel.hpp"

class OBJLoader {
    public:
        OBJLoader();
        ~OBJLoader();

        static RawModel loadObjModel(std::string fileName, Loader loader);

    protected:
    private:
};

#endif /* !OBJLOADER_HPP_ */
