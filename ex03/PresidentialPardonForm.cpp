/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:18:01 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/30 15:18:01 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::executeInternalForm() const
{
	std::cout << name() << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::PresidentialPardonForm():
	AForm("presidential_form", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &t_target):
	AForm(t_target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &t_e):
	AForm(t_e)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &t_e)
{
	if (this == &t_e)
		return (*this);
	AForm::operator=(t_e);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
