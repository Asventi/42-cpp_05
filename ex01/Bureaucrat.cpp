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
	return (m_grade);
}

std::string const	&Bureaucrat::getName() const
{
	return (m_name);
}

void	Bureaucrat::setGrade(int t_grade)
{
	if (t_grade > 150)
		throw GradeTooLowException();
	if (t_grade < 1)
		throw GradeTooHighException();
	m_grade = t_grade;
}

Bureaucrat &Bureaucrat::operator++()
{
	setGrade(m_grade - 1);
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
	setGrade(m_grade + 1);
	return (*this);
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat	old = *this;
	operator--();
	return (old);
}

Bureaucrat::Bureaucrat(): m_name("bureaucrat_default_name"), m_grade(75)
{
}

Bureaucrat::Bureaucrat(int t_grade): m_name("bureaucrat_default_name")
{
	setGrade(t_grade);
}

Bureaucrat::Bureaucrat(std::string const &t_name): m_name(t_name), m_grade(75)
{
}

Bureaucrat::Bureaucrat(std::string const &t_name, int t_grade): m_name(t_name)
{
	setGrade(t_grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &t_e): m_name(t_e.m_name), m_grade(t_e.m_grade)
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &t_e)
{
	if (this == &t_e)
		return (*this);
	m_grade = t_e.m_grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return (GRADE_HIGH_BUREAU);
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return (GRADE_LOW_BUREAU);
}

std::ostream	&operator<<(std::ostream &t_os, Bureaucrat const &t_b)
{
	t_os << t_b.getName() << ", bureaucrat grade " << t_b.getGrade() << ".";
	return (t_os);
}
