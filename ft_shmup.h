/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:35:01 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/22 19:06:09 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHMUP_H
# define FT_SHMUP_H

# include <curses.h>
# include <chrono>
# include <vector>
# include <cstdlib>
# include <ctime>
# include <string>
# include <algorithm>

# define LIVES				3
# define ENEMY_SPEED		10
# define BULLET_SPEED		20
# define SCROLL_SPEED		10
# define NUMBER_TREES		5
# define SHOOT_PHASE_TIMER	1.5f
# define SHOOT_COOLDOWN		0.15f
# define ENEMY_COOLDOWN		1.0f
# define SCENERY_WIDTH		46.0f

#endif