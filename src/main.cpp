/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:20:21 by potero-d          #+#    #+#             */
/*   Updated: 2024/12/17 17:36:23 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Npuzzle.h"
#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char** argv) {
    
    //Validate num aruments
     if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " number " << std::endl;
        return EXIT_FAILURE;
    }

    //Validate if second argument is an int
    int size;
    
    try {
        size = std::stoi(argv[1]);
    } 
    catch (std::exception &err){
        std::cerr << "Must be an int: " << argv[1] << std::endl;
        return EXIT_FAILURE;
    }
    
    Game game(size);
    std::cout << "Size: " << game.size << std::endl;
    game.generateGame();
    game.generateSoution();
    game.findZero();
    game.printGame();
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("NPuzzle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    
    char input;
    while (true) {
        input = std::cin.get(); // Read a single character from user input
        if (input == 27) { // 27 is the ASCII code for ESC
            break;
        }
        if (input == '\n') { // Ignore the Enter key
            continue;
        }
        //std::cout << "You pressed: " << input << std::endl;
        // Process other inputs if necessary
        if( input == 'w' || input == 'W') {
            game.move(0);
        }
        else if( input == 's' || input == 'S') {
            game.move(1);
        }
        else if( input == 'a' || input == 'A') {
            game.move(2);
        }
        else if( input == 'd' || input == 'D') {
            game.move(3);
        }
        else {
            std::cout << "Invalid input" << std::endl;
        }
        game.printGame();
    }
    return 0;
}