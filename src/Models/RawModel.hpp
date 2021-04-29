/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** RawModel
*/

#ifndef RAWMODEL_HPP_
#define RAWMODEL_HPP_

#include "../include.hpp"

class RawModel {
    public:
        RawModel() {};
        RawModel(int vao, int vertexCount);
        ~RawModel();

        int getVao() const;
        int getVertexCount() const;

    protected:
    private:
        int _vao;
        int _vertexCount;
};

#endif /* !RAWMODEL_HPP_ */
