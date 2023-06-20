/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 11:44:49 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/20 11:48:45 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

Class AMateria{

protected:
	std::string _type;
public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(const AMateria &rhs);
	AMateria &operator=(const AMateria &rhs);
	~AMateria(void);
	
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif