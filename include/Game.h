/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <potero-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:53:33 by potero-d          #+#    #+#             */
/*   Updated: 2024/12/05 14:00:11 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H 
#define GAME_H

#include "../include/Npuzzle.h"

class Game {
    public:
        int             size;
        std::vector<int>  numbers;

    // Constructor
        Game();
        Game(int sizet);

    // Destructor
        ~Game();

    // Methods
        void    generateGame();
    
    private:
    // Methods
    
};

#endif // GAME_H