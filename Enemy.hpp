/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:59:52 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 15:42:49 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "GameEntity.hpp"
# include "ft_shmup.h"

class Enemy : public GameEntity
{
private:
	float	_speed;
	float	_shootTimer;		// tempo rimasto al prossimo sparo
	float	_shootPhaseTimer; // tempo rimasto nello stato attivo
	bool	_canShoot;			// se attualmente sta sparando
public:
	Enemy(float y, float x);
	~Enemy();

	void update(float dt, int maxCols);

	bool shouldShoot() { return _canShoot && _shootTimer <= 0.0f; }
	void resetShootTimer();											
	void startShootingPhase();
	void stopShootingPhase();
	bool isShootingPhase() { return _canShoot; }
};

#endif