/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:45:32 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 18:01:01 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(float y, float x) : GameEntity(y, x, ">") {}

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
	(void)dt; // il player non ha logica autonoma
	(void)maxCols;
}