/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:59:30 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 16:43:39 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Enemy.hpp"

Enemy::Enemy(float y, float x) : GameEntity(y, x, "@") {
	_speed = ENEMY_SPEED;
	_canShoot = false;
	_shootTimer = 0.0f;
	_shootPhaseTimer = 0.0f;
}

Enemy::~Enemy() {}

void Enemy::update(float dt, int maxCols) {
	(void)maxCols;
	if (_x >= 0)
		_x -= _speed * dt;
	else
		_alive = false;

	if (_canShoot)
	{
		_shootTimer -= dt;
		_shootPhaseTimer -= dt;
		if (_shootPhaseTimer <= 0.0f)
			stopShootingPhase();
	}
}

void Enemy::resetShootTimer() {
	_shootTimer = 0.1f + static_cast<float>(rand() % 400) / 1000.0f;
}

void Enemy::startShootingPhase() {
	_canShoot = true;
	_shootPhaseTimer = SHOOT_PHASE_TIMER;
	resetShootTimer();
}

void Enemy::stopShootingPhase() {
	_canShoot = false;
}
