/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:45:32 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 14:37:25 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player(int y, int x) {
	_symbol = ">";
	_y = y;
	_x = x + 5;
}

Player::~Player() {}

const char	*Player::getSymbol() const { return _symbol; };

int	Player::getY() const { return _y; };

int	Player::getX() const { return _x; };

