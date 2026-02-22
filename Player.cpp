/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:45:32 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 19:24:42 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(float y, float x) : GameEntity(y, x, ">"), _lives(LIVES) {}

void	Player::moveUp() {
	if (_y > 1)
		_y--;
}

void Player::moveDown(int maxRows) {
	if (_y < maxRows -1)
		_y++;
}

Player::~Player() {}

void Player::update(float dt, int maxCols)
{
	(void)dt;
	(void)maxCols;
}

int	Player::getLives() const{
	return (_lives);
}

void	Player::decrementLives() {
	_lives--;
	if (_lives <= 0)
		setAlive(false);
}
