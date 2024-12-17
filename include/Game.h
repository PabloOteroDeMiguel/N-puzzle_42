/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:53:33 by potero-d          #+#    #+#             */
/*   Updated: 2024/12/11 12:53:31 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H 
#define GAME_H

#include "../include/Npuzzle.h"

class Game {
    public:
        int                 size;
        int                 zero;
        
        std::vector<int>    numbers;
        std::vector<int>    solution;

    // Constructor
        Game();
        Game(int sizet);

    // Destructor
        ~Game();

    // Methods
        void    generateGame();
        void    printGame();
        void    generateSoution();
        void    findZero();
        int     canMove(int direction);
        void    move(int direction);
    
    private:
    // Methods
    
};

#endif // GAME_H