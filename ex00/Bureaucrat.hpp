/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:09:00 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/24 16:09:00 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define GRADE_LOW_STR "Grade is to low."
# define GRADE_HIGH_STR "Grade is to high."

# include <iostream>
# include <string>

class Bureaucrat
{
private:
	std::string const	m_name;
	int					m_grade;

	void				setGrade(int t_grade);
public:
	std::string const	&getName() const;
	int					getGrade() const;
	Bureaucrat			&operator++();
	Bureaucrat			operator++(int);
	Bureaucrat			&operator--();
	Bureaucrat			operator--(int);

	Bureaucrat();
	explicit Bureaucrat(int t_grade);
	explicit Bureaucrat(std::string const &t_name);
	Bureaucrat(std::string const &t_name, int t_grade);
	Bureaucrat(Bureaucrat const &t_e);
	Bureaucrat	&operator=(Bureaucrat const &t_e);
	~Bureaucrat();

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
};

std::ostream	&operator<<(std::ostream &t_os, Bureaucrat const &t_b);

#endif
