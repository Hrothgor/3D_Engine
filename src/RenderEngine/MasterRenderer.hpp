/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** MasterRenderer
*/

#ifndef MASTERRENDERER_HPP_
#define MASTERRENDERER_HPP_

#include "../include.hpp"
#include "Renderer.hpp"
#include "../Entities/Camera.hpp"
#include "../Entities/Light.hpp"
#include "../Entities/Entity.hpp"
#include "../Shaders/StaticShader/StaticShader.hpp"

class MasterRenderer {
    public:
        MasterRenderer();
        ~MasterRenderer();

        void render(Light sun, Camera camera);
        void addEntity(const Entity &entity);
        void destroy();

    protected:
    private:
        StaticShader _shader;
        Renderer _renderer;
        std::map<TexturedModel, std::vector<Entity>> _entities;
};

#endif /* !MASTERRENDERER_HPP_ */
