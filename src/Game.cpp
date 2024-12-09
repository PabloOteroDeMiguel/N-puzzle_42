/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <potero-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:55:50 by potero-d          #+#    #+#             */
/*   Updated: 2024/12/09 10:44:34 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Game.h" 
#include "../include/Npuzzle.h"
#include <bits/stdc++.h>
#include <random>

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
    
    int cont = 1;
    int max = this->size * this->size;
    std::vector<int> aux;
    for (int i = 0; i < max; i++){
        this->numbers.push_back(i);
    }
    
    // Shuffle a vector (random)
    // Initialize random number generator --> https://www.geeksforgeeks.org/how-to-shuffle-a-vector-in-cpp/
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(numbers.begin(), numbers.end(), g);
    
    for(int number : this->numbers) {
        std::cout << number << "  ";
        if (cont % this->size == 0){
            std::cout << std::endl;
        }
        cont++;
    }
}
