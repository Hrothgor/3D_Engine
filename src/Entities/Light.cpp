/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Light
*/

#include "Light.hpp"

Light::Light(sf::Vector3f position, sf::Vector3f color)
{
    _position = position;
    _color = color;
}

Light::~Light()
{
}

sf::Vector3f Light::getPosition() const
{
    return (_position);
}

sf::Vector3f Light::getColor() const
{
    return (_color);
}

void Light::setPosition(sf::Vector3f position)
{
    _position = position;
}

void Light::setColor(sf::Vector3f color)
{
    _color = color;
}