/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Renderer
*/

#include "Renderer.hpp"

Renderer::Renderer(const StaticShader &shader)
{
    _shader = shader;
    _shader.start();
    _shader.loadProjectionMatrix(Maths::createProjectionMatrix());
    _shader.stop();
}

Renderer::~Renderer()
{
}

void Renderer::prepare() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 0, 0, 1);
}

void Renderer::render(std::map<TexturedModel, std::vector<Entity>> entities)
{
    for (std::pair<TexturedModel, std::vector<Entity>> list : entities) {
        RawModel model = list.first.getModel();
        prepareTextureModel(list.first);
        for (Entity entity : list.second) {
            prepareInstance(entity);
            glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);
        }
        unbindTextureModel();
    }
}

void Renderer::prepareTextureModel(TexturedModel texturedModel)
{
    RawModel model = texturedModel.getModel();

    glBindVertexArray(model.getVao());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glActiveTexture(GL_TEXTURE0);
    sf::Texture::bind(texturedModel.getTexturePointer());
    _shader.loadShineVariable(texturedModel.getShineDamper(), texturedModel.getReflectivity());
}

void  Renderer::unbindTextureModel()
{
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    sf::Texture::bind(0);
    glBindVertexArray(0);
}

void Renderer::prepareInstance(Entity entity)
{
    _shader.loadTransformationMatrix(\
        Maths::createTransformationMatrix(\
            entity.getPosition(), \
            entity.getRotation(), \
            entity.getScale()));
}

void Renderer::disableCulling() const
{
    glDisable(GL_CULL_FACE);
}

void Renderer::enableCulling() const
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}