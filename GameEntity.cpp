/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:37:29 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 15:48:45 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEntity.hpp"

GameEntity::GameEntity(float y, float x, const char *symbol) : _y(y), _x(x), _symbol(symbol), _alive(true) {}

GameEntity::~GameEntity() {}

const char	*GameEntity::getSymbol() const { return _symbol; };

int			GameEntity::getY() const { return _y; };

int			GameEntity::getX() const { return _x; };

bool		GameEntity::getAlive() const { return _alive; };

void		GameEntity::setAlive(bool alive) {
	_alive = alive;
}
