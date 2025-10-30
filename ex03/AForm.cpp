/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:57:40 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/28 10:57:40 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"

void	AForm::execute(Bureaucrat const &t_bcrat) const
{
	if (not m_signed)
		throw NotSignedException();
	if (t_bcrat.getGrade() > m_execGrade)
		throw GradeTooLowException();
	executeInternalForm();
}

void	AForm::beSigned(Bureaucrat const &t_bcrat)
{
	if (m_signed)
		return ;
	if (t_bcrat.getGrade() > m_signGrade)
		throw GradeTooLowException();
	m_signed = true;
}

std::string const &AForm::name() const
{
	return (m_name);
}

bool AForm::getSigned() const
{
	return (m_signed);
}

int	AForm::signGrade() const
{
	return (m_signGrade);
}

int AForm::setGrade(int t_grade)
{
	if (t_grade > 150)
		throw GradeTooLowException();
	if (t_grade < 1)
		throw GradeTooHighException();
	return (t_grade);
}


int	AForm::execGrade() const
{
	return (m_execGrade);
}

std::ostream	&operator<<(std::ostream &t_os, AForm const &t_form)
{
	t_os << t_form.name() << " ";
	if (!t_form.getSigned())
		t_os << "not ";
	t_os << "signed, signGrade: " << t_form.signGrade() << ", execGrade: "
		<< t_form.execGrade();
	return (t_os);
}

AForm::AForm(): m_name("default_name"), m_signed(false), m_signGrade(100), m_execGrade(42)
{
}

AForm::AForm(std::string const &t_name): m_name(t_name), m_signed(false), m_signGrade(100), m_execGrade(42)
{
}

AForm::AForm(int t_signGrade, int t_execGrade): m_name("default_name"), m_signed(false),
	m_signGrade(setGrade(t_signGrade)), m_execGrade(setGrade(t_execGrade))
{
}

AForm::AForm(std::string const &t_name, int t_signGrade, int t_execGrade): m_name(t_name), m_signed(false),
	m_signGrade(setGrade(t_signGrade)), m_execGrade(setGrade(t_execGrade))
{
}

AForm::AForm(AForm const &t_e): m_name(t_e.m_name), m_signed(t_e.m_signed),
	m_signGrade(t_e.m_signGrade), m_execGrade(t_e.m_execGrade)
{
}

AForm	&AForm::operator=(AForm const &t_e)
{
	if (this == &t_e)
		return (*this);
	m_signed = t_e.m_signed;
	return (*this);
}

AForm::~AForm()
{
}

char const	*AForm::GradeTooHighException::what() const throw()
{
	return (GRADE_HIGH_FORM);
}

char const	*AForm::GradeTooLowException::what() const throw()
{
	return (GRADE_LOW_FORM);
}

char const *AForm::NotSignedException::what() const throw()
{
	return (NOT_SIGNED);
}
