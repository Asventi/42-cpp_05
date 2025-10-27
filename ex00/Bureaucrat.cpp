/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:09:00 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/24 16:09:00 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

std::string const	&Bureaucrat::getName() const
{
	return (_name);
}

void	Bureaucrat::_set_grade(int grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
}

Bureaucrat &Bureaucrat::operator++()
{
	_set_grade(_grade - 1);
	return (*this);
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat	old = *this;
	operator++();
	return (old);
}

Bureaucrat &Bureaucrat::operator--()
{
	_set_grade(_grade + 1);
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat	old = *this;
	operator--();
	return (old);
}

Bureaucrat::Bureaucrat(): _name("bureaucrat_default_name"), _grade(75)
{
}

Bureaucrat::Bureaucrat(int grade): _name("bureaucrat_default_name")
{
	_set_grade(grade);
}

Bureaucrat::Bureaucrat(std::string const &name): _name(name), _grade(75)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	_set_grade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &e): _name(e._name), _grade(e._grade)
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &e)
{
	if (this == &e)
		return (*this);
	_grade = e._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return (GRADE_HIGH_STR);
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return (GRADE_LOW_STR);
}

