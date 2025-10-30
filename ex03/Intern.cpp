/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:06:16 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/30 16:06:16 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static AForm	*shrubberyForm(std::string const &t_target)
{
	return (new ShrubberyCreationForm(t_target));
}

static AForm	*robotomyForm(std::string const &t_target)
{
	return (new RobotomyRequestForm(t_target));
}

static AForm	*presidentialForm(std::string const &t_target)
{
	return (new PresidentialPardonForm(t_target));
}

AForm	*Intern::makeForm(std::string const &t_formName, std::string const &t_target)
{
	AForm	*(*formList[])(std::string const &) = {&shrubberyForm, &robotomyForm, &presidentialForm};
	std::string const	names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*n;

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == t_formName)
		{
			std::cout << "Intern creates " << *(n = formList[i](t_target)) << ".\n";
			return (n);
		}
	}
	std::cout << "Intern could not create a " << t_formName << ", not found.\n";
	return (NULL);
}

Intern::Intern()
{
}

Intern::Intern(Intern const &t_e)
{
	(void)t_e;
}

Intern &Intern::operator=(Intern const &t_e)
{
	(void)t_e;
	return (*this);
}

Intern::~Intern()
{
}
