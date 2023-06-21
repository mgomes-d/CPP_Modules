/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:27:59 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/21 12:32:27 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMateriaSource
# define IMateriaSource

#include "IMateriaSource"

class MateriaSource{

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &rhs);
	MateriaSource &operator=(const MateriaSource &rhs);
	~MateriaSource(void);

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};

#endif