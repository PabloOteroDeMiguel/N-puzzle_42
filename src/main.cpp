/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <potero-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:20:21 by potero-d          #+#    #+#             */
/*   Updated: 2024/12/09 11:13:27 by potero-d         ###   ########.fr       */
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
    std::cout << "Size: " << game.size << std::endl;
    game.generateGame();
    game.generateSoution();
}