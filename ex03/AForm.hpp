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

#ifndef AFORM_HPP
# define AFORM_HPP

# define GRADE_LOW_FORM "Grade is too low."
# define GRADE_HIGH_FORM "Grade is too high."
# define NOT_SIGNED "Grade is not signed."

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
private:
	std::string const	m_name;
	bool				m_signed;
	int const			m_signGrade;
	int const			m_execGrade;

	static int			setGrade(int t_grade);
	virtual void		executeInternalForm() const = 0;

public:
	void	execute(Bureaucrat const &t_bcrat) const;
	void	beSigned(Bureaucrat const &t_bcrat);

	std::string const	&name() const;
	bool				getSigned() const;
	int					signGrade() const;
	int					execGrade() const;

	AForm();
	explicit AForm(std::string const &t_name);
	AForm(int t_signGrade, int t_execGrade);
	AForm(std::string const &t_name, int t_signGrade, int t_execGrade);
	AForm(AForm const &t_e);
	AForm	&operator=(AForm const &t_e);
	virtual ~AForm();

	class GradeTooHighException: public std::exception
	{
	public:
		virtual char const	*what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
		virtual char const	*what() const throw();
	};

	class NotSignedException: public std::exception
	{
		virtual char const	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &t_os, AForm const &t_form);

#endif
