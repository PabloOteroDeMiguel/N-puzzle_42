/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <potero-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:53:33 by potero-d          #+#    #+#             */
/*   Updated: 2024/12/09 11:01:57 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H 
#define GAME_H

#include "../include/Npuzzle.h"

class Game {
    public:
        int                 size;
        std::vector<int>    numbers;
        std::vector<int>    solution;

    // Constructor
        Game();
        Game(int sizet);

    // Destructor
        ~Game();

    // Methods
        void    generateGame();
        void    generateSoution();
    
    private:
    // Methods
    
};

#endif // GAME_H