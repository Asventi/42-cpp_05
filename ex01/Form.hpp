/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 10:57:40 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/28 10:57:40 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define GRADE_LOW_FORM "Form grade is too low."
# define GRADE_HIGH_FORM "Form grade is too high."

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
private:
	std::string const	m_name;
	bool				m_signed;
	int const			m_signGrade;
	int const			m_execGrade;
	static int			setGrade(int t_grade);
public:
	void	beSigned(Bureaucrat const &t_bcrat);

	std::string const	&name() const;
	bool				getSigned() const;
	int					signGrade() const;
	int					execGrade() const;

	Form();
	explicit Form(std::string const &t_name);
	Form(int t_signGrade, int t_execGrade);
	Form(std::string const &t_name, int t_signGrade, int t_execGrade);
	Form(Form const &t_e);
	Form	&operator=(Form const &t_e);
	~Form();

	class GradeTooHighException: public std::exception
	{
		virtual char const	*what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		virtual char const	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &t_os, Form const &t_form);

#endif
