/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** RawModel
*/

#include "RawModel.hpp"

RawModel::RawModel(int vao, int vertexCount)
{
    _vao = vao;
    _vertexCount = vertexCount;
}

RawModel::~RawModel()
{
}

int RawModel::getVao() const
{
    return (_vao);
}

int RawModel::getVertexCount() const
{
    return (_vertexCount);
}