/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:55:50 by potero-d          #+#    #+#             */
/*   Updated: 2024/12/10 11:49:10 by pablo            ###   ########.fr       */
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
    std::vector<int> s( sizet * sizet, 0);
    solution = s;
}

// Destructor
Game::~Game() {
    // Cleaning
    //delete[] this->numbers;
}

// Methods
void Game::generateGame() {
    //Create a random board.
    
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
        std::cout << number << "\t";
        if (cont % this->size == 0){
            std::cout << std::endl;
        }
        cont++;
    }
    std::cout << std::endl;
}

void Game::generateSoution() {
    //Create a solved board with the right size.
    
    int cont = 1;
    int number = 1;
    int max = this->size * this->size;
    int c = 0;
    std::cout << "--> " << (this->size / 2) << std::endl;
    while (c < (this->size / 2) && number < max)
    {
        //first row
        int row = c * this->size;
        for (int i = row + c; i < (this->size + row) - c; i++) {
            if (number < max) {
                this->solution[i] = number++;
            }
        }
        
        //last column
        for (int i = ((this->size * (c + 2)) - c - 1); i < max - row; i += this->size){
            if (number < max) {
                this->solution[i] = number++;
            }
        }
        
        //last row
        for (int i = max - row - (2 + c); i > (max - row - this->size - 1 + c); i--){
            if (number < max) {
                this->solution[i] = number++;
            }
        }
        //first column
        for (int i = max - (this->size * 2) - ((this->size - 1) * c); i >= this->size + row; i-= this->size){
            if (number < max) {
                this->solution[i] = number++;
            }
        }
        c++;
    }

    
    for(int s : this->solution) {
        std::cout << s << "\t";
        if (cont % this->size == 0){
            std::cout << std::endl;
        }
        cont++;
    }
    std::cout << std::endl;
}