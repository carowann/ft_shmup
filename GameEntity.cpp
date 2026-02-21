/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:37:29 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 18:14:16 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"

GameEntity::GameEntity(float y, float x, const char *symbol) : _y(y), _x(x), _symbol(symbol), _alive(true) {}

GameEntity::~GameEntity() {}

const char	*GameEntity::getSymbol() const { return _symbol; };

float		GameEntity::getY() const { return _y; };

float		GameEntity::getX() const { return _x; };

bool		GameEntity::getAlive() const { return _alive; };
