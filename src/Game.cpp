/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:55:50 by potero-d          #+#    #+#             */
/*   Updated: 2024/12/17 13:04:44 by pablo            ###   ########.fr       */
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
    this->zero = 0;
}

// Destructor
Game::~Game() {
    // Cleaning
    //delete[] this->numbers;
}

// Methods
void Game::generateGame() {
    //Create a random board.
    
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
    
}

void    Game::printGame(){
    //Print the board
    int cont = 1;
    for(int number : this->numbers) {
        if (number == 0) {
            std::cout << "\033[1;36m" << number << "\033[0m\t";
        }
        else {
            std::cout << number << "\t";
        }

        if (cont % this->size == 0){
            std::cout << "\033[1;33m" << "||\t\033[0";
            for (int i = cont - this->size; i < cont; i++) {
                if (this->solution[i] == this->numbers[i]) {
                    std::cout << "\033[1;32m" << this->solution[i] << "\033[0m\t";
                }
                else {
                    std::cout << "\033[1;31m" << this->solution[i] << "\033[0m\t";

                }
            }
            std::cout << std::endl;
        }
        cont++;
    }
    std::cout << std::endl;
}
void Game::generateSoution() {
    //Create a solved board with the right size.

    int number = 1;
    int max = this->size * this->size;
    int c = 0;

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
        for (int i = max - (this->size * 2) - ((this->size - 1) * c); i >= this->size + row; i -= this->size){
            if (number < max) {
                this->solution[i] = number++;
            }
        }
        c++;
    }
}

void Game::findZero() {
    //Locate zero in vector
    for (int i = 0; i < this->size * this->size; i++) {
        if (this->numbers[i] == 0) {
            this->zero = i;
            break;
        }
    }
}

int Game::canMove(int direction) {
    //Check if zero can move in the direction

    //UP
    if (direction == 0 && this->zero - this->size >= 0) {
        return 1;
    }

    //DOWN
    else if (direction == 1 && this->zero + this->size < this->size * this->size) {
        return 1;
    }

    //LEFT
    else if (direction == 2 && this->zero % this->size != 0) {
        return 1;
    }
    //RIGHT
    else if (direction == 3 && (this->zero + 1) % this->size != 0) {
        return 1;
    }
    return 0;
}

void Game::move(int direction) {
    //Move zero in the direction
    int temp;
    if (this->canMove(direction)) {
        //UP
        if (direction == 0) {
            temp = this->numbers[this->zero - this->size];
            this->numbers[this->zero - this->size] = 0;
            this->numbers[this->zero] = temp;
            this->zero = this->zero - this->size;
        }
        //DOWN
        else if (direction == 1) {
            temp = this->numbers[this->zero + this->size];
            this->numbers[this->zero + this->size] = 0;
            this->numbers[this->zero] = temp;
            this->zero = this->zero + this->size;
        }
        //LEFT
        else if (direction == 2) {
            temp = this->numbers[this->zero - 1];
            this->numbers[this->zero - 1] = 0;
            this->numbers[this->zero] = temp;
            this->zero = this->zero - 1;
        }
        //RIGHT
        else if (direction == 3) {
            temp = this->numbers[this->zero + 1];
            this->numbers[this->zero + 1] = 0;
            this->numbers[this->zero] = temp;
            this->zero = this->zero + 1;
        }
    }
}