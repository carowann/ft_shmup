/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:45:32 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 15:24:39 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(int y, int x) {
	_symbol = ">";
	_y = y;
	_x = x + 5;
}

void	Player::moveUp() {
	if (_y > 1)
		_y--;
}

void Player::moveDown(int maxRows) {
	if (_y < maxRows -1)
		_y++;
}

Player::~Player() {}

const char	*Player::getSymbol() const { return _symbol; };

int	Player::getY() const { return _y; };

int	Player::getX() const { return _x; };

