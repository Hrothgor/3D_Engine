/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** StaticShader
*/

#include "StaticShader.hpp"

StaticShader::StaticShader() : ShaderProgram( "src/Shaders/StaticShader/vertexShader.txt", "src/Shaders/StaticShader/fragmentShader.txt")
{
    bindAttribute(0, "position"); // 0 = VAOID des vertex pos, "position" = nom de variable dans le vertexShader.txt
    bindAttribute(1, "textureCoords"); // 1 = VAOID des textures coord, "textureCoords" = nom de variable dans le vertexShader.txt
    bindAttribute(2, "normal"); // 2 = VAOID des textures coord, "textureCoords" = nom de variable dans le vertexShader.txt

    getAllUniformLocation();
}

StaticShader::~StaticShader()
{
}

void StaticShader::getAllUniformLocation()
{
    loc_transformationMatrix = getUniformLocation("transformationMatrix");
    loc_projectionMatrix = getUniformLocation("projectionMatrix");
    loc_viewMatrix = getUniformLocation("viewMatrix");
    loc_lightPosition = getUniformLocation("lightPosition");
    loc_lightColor = getUniformLocation("lightColor");
    loc_shineDamper = getUniformLocation("shineDamper");
    loc_reflectivity = getUniformLocation("reflectivity");
}

void StaticShader::loadTransformationMatrix(std::vector<float> matrix)
{
    loadMatrix(loc_transformationMatrix, matrix);
}

void StaticShader::loadProjectionMatrix(std::vector<float> matrix)
{
    loadMatrix(loc_projectionMatrix, matrix);
}

void StaticShader::loadViewMatrix(std::vector<float> matrix)
{
    loadMatrix(loc_viewMatrix, matrix);
}

void StaticShader::loadLight(Light light)
{
    loadVector3(loc_lightPosition, light.getPosition());
    loadVector3(loc_lightColor, light.getColor());
}

void StaticShader::loadShineVariable(float shineDamper, float reflectivity)
{
    loadFloat(loc_shineDamper, shineDamper);
    loadFloat(loc_reflectivity, reflectivity);
}