/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 14:59:52 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 12:31:06 by pdessant         ###   ########.fr       */
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
	float _shootTimer;  // tempo rimasto al prossimo sparo  //PROVA
	float _shootPhaseTimer; // tempo rimasto nello stato attivo //PROVA
    bool  _canShoot;        // se attualmente sta sparando  //PROVA
public:
	Enemy(float y, float x);
	~Enemy();

	void update(float dt, int maxCols);
	
	bool shouldShoot() { return _canShoot && _shootTimer <= 0.0f; }  //PROVA
    void resetShootTimer();     // prossimo sparo breve (0.1-0.5s)   //PROVA
    void startShootingPhase();  // inizia fase sparo di 5 sec    //PROVA
    void stopShootingPhase();   // fine fase sparo    //PROVA
    bool isShootingPhase() { return _canShoot; }    //PROVA
};

#endif