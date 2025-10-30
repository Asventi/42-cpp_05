/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 16:08:32 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/24 16:08:32 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <fstream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "PresidentialPardonForm.hpp"

TEST_CASE("Bureaucrat Exceptions On Construction")
{
	CHECK_THROWS_AS(Bureaucrat b(789), Bureaucrat::GradeTooLowException);
	CHECK_THROWS_AS(Bureaucrat b(789), std::exception);
	CHECK_THROWS_AS(Bureaucrat b(0), Bureaucrat::GradeTooHighException);
}

TEST_CASE("Bureaucrat increment / decrement")
{
	Bureaucrat	b("DEVANNN", 10);

	CHECK((++b).getGrade() == 9);
	CHECK(b++.getGrade() == 9);
	CHECK(b.getGrade() == 8);
	CHECK((--b).getGrade() == 9);
	CHECK(b--.getGrade() == 9);
	CHECK(b.getGrade() == 10);
}

TEST_CASE("Bureaucrat increment / decrement exception")
{
	Bureaucrat	b("DEVANNN", 150);
	Bureaucrat	b2("DEVANNN", 1);

	CHECK_THROWS_AS(--b, Bureaucrat::GradeTooLowException);
	CHECK(b.getGrade() == 150);
	CHECK_THROWS_AS(++b2, Bureaucrat::GradeTooHighException);
	CHECK(b2.getGrade() == 1);
}

TEST_CASE("Bureaucrat ostream overload")
{
	Bureaucrat b("DEVANNN", 42);
	std::stringstream	s;

	s << b;
	CHECK(s.str() == "DEVANNN, bureaucrat grade 42.");
}

TEST_CASE("Shrubbery Form")
{
	AForm	*form = new ShrubberyCreationForm();
	Bureaucrat				b(136);
	Bureaucrat				b2(145);

	CHECK(form->signGrade() == 145);
	CHECK(form->execGrade() == 137);
	CHECK_THROWS_AS(form->execute(b), AForm::NotSignedException);
	b2.signForm(*form);
	CHECK(form->getSigned());
	b.signForm(*form);
	CHECK(form->getSigned());
	CHECK_THROWS_AS(form->execute(b2), AForm::GradeTooLowException);
	form->execute(b);
	std::ifstream	file((form->name() + "_shrubbery").c_str());
	CHECK(file.is_open());
	std::stringstream strs;
	strs << file.rdbuf();
	CHECK(strs.str() == TREE);
	remove((form->name() + "_shrubbery").c_str());
	delete form;
}

TEST_CASE("Robotomy Form")
{
	AForm	*form = new RobotomyRequestForm();
	Bureaucrat				b(1);
	Bureaucrat				b2(71);

	CHECK(form->signGrade() == 72);
	CHECK(form->execGrade() ==	45);
	CHECK_THROWS_AS(form->execute(b), AForm::NotSignedException);
	b2.signForm(*form);
	CHECK(form->getSigned());
	b.signForm(*form);
	CHECK(form->getSigned());
	CHECK_THROWS_AS(form->execute(b2), AForm::GradeTooLowException);
	form->execute(b);
	delete form;
}

TEST_CASE("Presidential Form")
{
	AForm	*form = new PresidentialPardonForm();
	Bureaucrat				b(1);
	Bureaucrat				b2(25);

	CHECK(form->signGrade() == 25);
	CHECK(form->execGrade() ==	5);
	CHECK_THROWS_AS(form->execute(b), AForm::NotSignedException);
	b2.signForm(*form);
	CHECK(form->getSigned());
	b.signForm(*form);
	CHECK(form->getSigned());
	CHECK_THROWS_AS(form->execute(b2), AForm::GradeTooLowException);

	b2.executeForm(*form);
	b.executeForm(*form);
	delete form;
}

