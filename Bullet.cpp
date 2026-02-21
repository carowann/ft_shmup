/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 16:31:42 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 19:20:23 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet(float y, float x, const char *b, int direction) : GameEntity(y, x, b) {
	_speed = BULLET_SPEED;
	_direction = direction;
}

void Bullet::update(float dt, int maxCols)
{
	_x += _speed * dt * _direction;
	if (_x < 0 || _x > maxCols)
		_alive = false;
}

Bullet::~Bullet() {}
