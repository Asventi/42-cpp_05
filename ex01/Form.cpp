/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:57:40 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/28 10:57:40 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include "Bureaucrat.hpp"

void	Form::beSigned(Bureaucrat const &t_bcrat)
{
	if (m_signed)
		return ;
	if (t_bcrat.getGrade() > m_signGrade)
		throw GradeTooLowException();
	m_signed = true;
}

std::string const &Form::name() const
{
	return (m_name);
}

bool Form::getSigned() const
{
	return (m_signed);
}

int	Form::signGrade() const
{
	return (m_signGrade);
}

int Form::setGrade(int t_grade)
{
	if (t_grade > 150)
		throw GradeTooLowException();
	if (t_grade < 1)
		throw GradeTooHighException();
	return (t_grade);
}


int	Form::execGrade() const
{
	return (m_execGrade);
}

std::ostream	&operator<<(std::ostream &t_os, Form const &t_form)
{
	t_os << t_form.name() << " ";
	if (!t_form.getSigned())
		t_os << "not ";
	t_os << "signed, signGrade: " << t_form.signGrade() << ", execGrade: "
		<< t_form.execGrade() << ".";
	return (t_os);
}

Form::Form(): m_name("default_name"), m_signed(false), m_signGrade(100), m_execGrade(42)
{
}

Form::Form(std::string const &t_name): m_name(t_name), m_signed(false), m_signGrade(100), m_execGrade(42)
{
}

Form::Form(int t_signGrade, int t_execGrade): m_name("default_name"), m_signed(false),
	m_signGrade(t_signGrade), m_execGrade(t_execGrade)
{
}

Form::Form(std::string const &t_name, int t_signGrade, int t_execGrade): m_name(t_name), m_signed(false),
	m_signGrade(setGrade(t_signGrade)), m_execGrade(setGrade(t_execGrade))
{
}

Form::Form(Form const &t_e): m_name(t_e.m_name), m_signed(t_e.m_signed),
	m_signGrade(t_e.m_signGrade), m_execGrade(t_e.m_execGrade)
{
}

Form	&Form::operator=(Form const &t_e)
{
	if (this == &t_e)
		return (*this);
	m_signed = t_e.m_signed;
	return (*this);
}

Form::~Form()
{
}

char const	*Form::GradeTooHighException::what() const throw()
{
	return (GRADE_HIGH_FORM);
}

char const	*Form::GradeTooLowException::what() const throw()
{
	return (GRADE_LOW_FORM);
}
