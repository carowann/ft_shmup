/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:59:30 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 12:49:06 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Enemy.hpp"

Enemy::Enemy(float y, float x) : GameEntity(y, x, "@") {
	_speed = ENEMY_SPEED;
	//_shootTimer = static_cast<float>(rand() % 100) / 100.0f; // timer iniziale casuale 0.0 - 1.0 sec //PROVA
	// inizialmente tutti inattivi
    _canShoot = false;		//prova
    _shootTimer = 0.0f;		//prova
    _shootPhaseTimer = 0.0f;	//prova
}

Enemy::~Enemy() {}


void Enemy::update(float dt, int maxCols)
{
/* 	(void)maxCols;
	if (_x >= 0)
		_x -= _speed * dt;
	else
		_alive = false;

	if (_canShoot) {			//PROVA
    	_shootTimer -= dt;
    	_shootPhaseTimer -= dt;

    	// se finisce il periodo di sparo di 5 secondi
    	if (_shootPhaseTimer <= 0.0f) {
    	    stopShootingPhase();
    	}
    } */
	(void)maxCols;
	if (_x >= 0) _x -= _speed * dt;
    else _alive = false;

    if (_canShoot) {
        _shootTimer -= dt;
        _shootPhaseTimer -= dt;
        if (_shootPhaseTimer <= 0.0f) stopShootingPhase();
    }

	//  // aggiorna timer sparo  //PROVA
    // _shootTimer -= dt;
}

void Enemy::resetShootTimer() {
    _shootTimer = 0.05f + static_cast<float>(rand() % 100) / 1000.0f;
}

void Enemy::startShootingPhase() {
    _canShoot = true;
    _shootPhaseTimer = 1.0f; // fase sparo di 1 secondi
    resetShootTimer();
}

void Enemy::stopShootingPhase() {
    _canShoot = false;
}

// void Enemy::resetShootTimer() {
//     // prossimo sparo randomico rapido: tra 0.1 e 0.5 secondi
//     _shootTimer = 0.1f + static_cast<float>(rand() % 400) / 1000.0f;
// }