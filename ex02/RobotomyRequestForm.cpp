/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:21:15 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/30 14:21:15 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <sys/time.h>

void	RobotomyRequestForm::executeInternalForm() const
{
	timeval	tv;

	gettimeofday(&tv, NULL);
	long int	ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	std::srand(static_cast<unsigned int>(ms));
	std::cout << "Dzzlzlzzzz\n";
	if (std::rand() / (RAND_MAX / 2 + 1))
		std::cout << "Successfully robotomized " << name() << ".\n";
	else
		std::cout << "Robotomy failed on " << name() << ".\n";
}

RobotomyRequestForm::RobotomyRequestForm():
	AForm("robotomy_form", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &t_target):
	AForm(t_target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &t_e):
	AForm(t_e)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &t_e)
{
	if (this == &t_e)
		return (*this);
	AForm::operator=(t_e);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}
