/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:06:16 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/30 16:06:16 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern
{
public:
	AForm	*makeForm(std::string const &t_formName, std::string const &t_target);

	Intern();
	Intern(Intern const &t_e);
	Intern	&operator=(Intern const &t_e);
	~Intern();
};

#endif
