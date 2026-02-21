/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:59:30 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 15:39:00 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Enemy.hpp"

Enemy::Enemy(float y, float x) : GameEntity(y, x, "@") {}

Enemy::~Enemy() {}

// void Enemy::update(float dt)
// {
// 	_x -= _speed * dt;
// 	if (_x < 0)
// 		_alive = false;
// }