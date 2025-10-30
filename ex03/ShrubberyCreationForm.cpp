/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:00:35 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/30 12:00:35 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

void	ShrubberyCreationForm::executeInternalForm() const
{
	std::ofstream	ofs((name() + "_shrubbery").c_str(), std::ios_base::out
		| std::ios_base::trunc);

	ofs << TREE;
	ofs.close();
}

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("shrubbery_form", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &t_target):
	AForm(t_target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &t_e):
	AForm(t_e)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &t_e)
{
	if (this == &t_e)
		return (*this);
	AForm::operator=(t_e);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
