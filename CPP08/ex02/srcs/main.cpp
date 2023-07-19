/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:23:28 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/18 09:12:02 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() 
{
    // Create an instance of MutantStack with integers
    MutantStack<int> myStack;

    // Push some elements into the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Use iterators to iterate over the elements of the stack
    std::cout << "Direct traversal of the stack: ";
    for (MutantStack<int>::iterator it = myStack.begin(); it != myStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Reverse traversal of the stack: ";
    for (MutantStack<int>::reverse_iterator rit = myStack.rbegin(); rit != myStack.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}