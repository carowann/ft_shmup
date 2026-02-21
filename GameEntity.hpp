/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEntity.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwannhed <cwannhed@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:35:56 by cwannhed          #+#    #+#             */
/*   Updated: 2026/02/21 12:38:42 by cwannhed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENTITY_HPP
# define  GAMEENTITY_HPP

class GameEntity
{
private:
	/* data */
protected:
	int	x;
	int y;
public:
	GameEntity(/* args */);
	~GameEntity();
};


#endif