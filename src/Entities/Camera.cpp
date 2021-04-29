/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Camera
*/

#include "Camera.hpp"

Camera::Camera()
    : _position(0, 0, 0)
{
    _pitch = 0;
    _yaw = 0;
    _roll = 0;
}

Camera::~Camera()
{
}

void Camera::move(std::vector<bool> keys, sf::RenderWindow *window)
{
    static bool clicked = false;
    static sf::Vector2i mouse_pos;

    if (clicked == false) {
        if (keys[Input::LMouse] == true) {
            mouse_pos = sf::Mouse::getPosition(*window);
            clicked = true;
        }
    }
    if (clicked == true) {
        if (keys[Input::LMouse] == false)
            clicked = false;
        _pitch += (sf::Mouse::getPosition(*window).y - mouse_pos.y) * 0.1;
        _yaw += (sf::Mouse::getPosition(*window).x - mouse_pos.x) * 0.1;
        if (_pitch < -80)
            _pitch = -80;
        if (_pitch > 80)
            _pitch = 80;
        mouse_pos = sf::Mouse::getPosition(*window);
    }

    if (keys[Input::Z])
        _position.z -= 0.2;
    if (keys[Input::S])
        _position.z += 0.2;
    if (keys[Input::Q])
        _position.x -= 0.2;
    if (keys[Input::D])
        _position.x += 0.2;
    if (keys[Input::Space])
        _position.y += 0.2;
    if (keys[Input::LShift])
        _position.y -= 0.2;
}

sf::Vector3f Camera::getPosition() const
{
    return (_position);
}

float Camera::getPitch() const
{
    return (_pitch);
}

float Camera::getYaw() const
{
    return (_yaw);
}

float Camera::getRoll() const
{
    return (_roll);
}