/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** TexturedModel
*/

#include "TexturedModel.hpp"

TexturedModel::TexturedModel(const RawModel &model, sf::Texture &texture, float shineDamper, float reflectivity)
{
    _rawModel = model;
    _texture = &texture;
    _shineDamper = shineDamper;
    _reflectivity = reflectivity;
}

TexturedModel::~TexturedModel()
{
}

RawModel TexturedModel::getModel() const
{
    return (_rawModel);
}

sf::Texture *TexturedModel::getTexturePointer()
{
    return (_texture);
}

float TexturedModel::getShineDamper() const
{
    return (_shineDamper);
}

float TexturedModel::getReflectivity() const
{
    return (_reflectivity);
}

void TexturedModel::setShineDamper(float shineDamper)
{
    _shineDamper = shineDamper;
}

void TexturedModel::setReflectivity(float reflectivity)
{
    _reflectivity = reflectivity;
}

bool TexturedModel::operator==(const TexturedModel &model) const
{
    //std::cout << this->getModel().getVao() << " | " << model.getModel().getVao() << std::endl;
    if (this->getModel().getVao() == model.getModel().getVao())
        return (true);
    return (false);
}

bool TexturedModel::operator<(const TexturedModel &model) const
{
    if (this->getModel().getVao() == model.getModel().getVao())
        return (false);
    return (true);
}