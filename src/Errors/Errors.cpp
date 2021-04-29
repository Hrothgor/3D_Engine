/*
** EPITECH PROJECT, 2021
** Errors
** File description:
** Errors
*/

#include "Errors.hpp"

Errors::Errors(const std::string &message) noexcept : _what(message)
{
}

Errors::~Errors() noexcept
{
}

const char *Errors::what(void) const noexcept
{
	return _what.c_str();
}