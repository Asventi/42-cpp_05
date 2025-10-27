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

# include <string>

class Bureaucrat
{
private:
	std::string const	_name;
	int					_grade;

	void				_set_grade(int grade);
public:
	std::string const	&getName() const;
	int					getGrade() const;
	Bureaucrat			&operator++();
	Bureaucrat			operator++(int);
	Bureaucrat			&operator--();
	Bureaucrat			operator--(int);

	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(std::string const &name);
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &e);
	Bureaucrat	&operator=(Bureaucrat const &e);
	~Bureaucrat();

	class GradeTooHighException: public std::exception
	{
	public:
		char const	*what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
	public:
		char const	*what() const throw();
	};
};

#endif