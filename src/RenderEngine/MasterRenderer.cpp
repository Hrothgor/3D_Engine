/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** MasterRenderer
*/

#include "MasterRenderer.hpp"

MasterRenderer::MasterRenderer() : _renderer(_shader)
{
}

MasterRenderer::~MasterRenderer()
{
}

void MasterRenderer::render(Light sun, Camera camera)
{
    _renderer.prepare();
    _shader.start();
    _shader.loadLight(sun);
    _shader.loadViewMatrix(Maths::createViewMatrix(
                camera.getPosition(),
                camera.getPitch(),
                camera.getYaw(),
                camera.getRoll()));
    _renderer.render(_entities);
    _shader.stop();
}

void MasterRenderer::addEntity(const Entity &entity)
{
    TexturedModel entityModel = entity.getTexturedModel();
    for (auto &list : _entities) {
        if (list.first == entityModel) {
            list.second.push_back(entity);
            return;
        }
    }
    _entities[entityModel] = std::vector<Entity> { entity };
}

void MasterRenderer::destroy()
{
    _shader.destroy();
    _entities.clear();
}