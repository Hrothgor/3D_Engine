/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity(const TexturedModel &texturedModel, sf::Vector3f position, sf::Vector3f rotation, float scale)
{
    _texturedModel = texturedModel;
    _position = position;
    _rotation = rotation;
    _scale = scale;
}

Entity::~Entity()
{
}

void Entity::increasePosition(sf::Vector3f vec)
{
    _position.x += vec.x;
    _position.y += vec.y;
    _position.z += vec.z;
}

void Entity::increaseRotation(sf::Vector3f vec)
{
    _rotation.x += vec.x;
    _rotation.y += vec.y;
    _rotation.z += vec.z;
}


TexturedModel Entity::getTexturedModel() const
{
    return (_texturedModel);
}

sf::Vector3f Entity::getPosition() const
{
    return (_position);
}

sf::Vector3f Entity::getRotation() const
{
    return (_rotation);
}

float Entity::getScale() const
{
    return (_scale);
}

void Entity::setTexturedModel(TexturedModel texturedModel)
{
    _texturedModel = texturedModel;
}

void Entity::setPosition(sf::Vector3f position)
{
    _position = position;
}

void Entity::setRotation(sf::Vector3f rotation)
{
    _rotation = rotation;
}

void Entity::setScale(float scale)
{
    _scale = scale;
}