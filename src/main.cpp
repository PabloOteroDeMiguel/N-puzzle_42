/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:20:21 by potero-d          #+#    #+#             */
/*   Updated: 2024/12/17 12:04:52 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Npuzzle.h"

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
    std::cout << "\033[32mSize: " << game.size << "\033[0m" << std::endl;
    game.generateGame();
    game.generateSoution();
    game.findZero();
    game.printGame();
    
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