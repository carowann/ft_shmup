/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:59:30 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 18:32:15 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Enemy.hpp"

Enemy::Enemy(float y, float x) : GameEntity(y, x, "@") {
	_speed = SPEED;
}

Enemy::~Enemy() {}


void Enemy::update(float dt, int maxCols)
{
	(void)maxCols;
	if (_x >= 0)
		_x -= _speed * dt;
	else
		_alive = false;
}