/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <potero-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:55:50 by potero-d          #+#    #+#             */
/*   Updated: 2024/12/05 14:07:59 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Game.h" 
#include "../include/Npuzzle.h"

// Constructor

Game::Game() :
    size(0)
    // numbers(NULL) 
    {
}

Game::Game(int sizet)
    //numbers(NULL) 
    {
    this->size = sizet;
}

// Destructor
Game::~Game() {
    // Cleaning
    //delete[] this->numbers;
}

// Methods
void Game::generateGame() {
    
    // int cont = 0;
    int max = this->size * this->size;
    std::vector<int> aux;
    for (int i = 0; i < max; i++){
        aux.push_back(i);
    }
    for (auto iter : aux)
    {
        numbers.push_back(iter);
    }
    for(int number : this->numbers) {
        std::cout << number << ", " << std::endl;
    }
}
