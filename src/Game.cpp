/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <potero-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:55:50 by potero-d          #+#    #+#             */
/*   Updated: 2024/12/09 13:00:11 by potero-d         ###   ########.fr       */
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
    while (c < (this->size / 2) || number < max)
    {
        std::cout << "c --> " << c << std::endl;
        //first row
        int row = c * this->size;
        for (int i = 0 + c; i < (this->size + row) - c; i++) {
            this->solution[i + row] = number++;
        }
        
        //last column
        for (int i = ((this->size * (c + 2)) - c - 1); i < max - (this->size * c); i += this->size){
            //std::cout << i << std::endl;
            this->solution[i] = number++;
        }
        
        //last row
        for (int i = max - 2; i > max - this->size - 1; i--){
            this->solution[i] = number++;
        }
        //first column
        for (int i = max - (this->size * 2); i >= this->size - 1 ; i-= this->size){
            this->solution[i] = number++;
        }
        
        for(int s : this->solution) {
            std::cout << s << "\t";
            if (cont % this->size == 0){
                std::cout << std::endl;
            }
            cont++;
        }
        std::cout << std::endl;
        
        c++;
    }
    
    // //first row
    // for (int i = 0; i < this->size; i++) {
    //     this->solution[i] = number++;
    // }
    
    // //last column
    // for (int i = (this->size * 2) - 1; i < max; i += this->size){
    //     this->solution[i] = number++;
    // }
    
    // //last row
    // for (int i = max - 2; i > max - this->size - 1; i--){
    //     this->solution[i] = number++;
    // }
    // //first column
    // for (int i = max - (this->size * 2); i >= this->size - 1 ; i-= this->size){
    //     this->solution[i] = number++;
    // }
    
    for(int s : this->solution) {
        std::cout << s << "\t";
        if (cont % this->size == 0){
            std::cout << std::endl;
        }
        cont++;
    }
    std::cout << std::endl;
}