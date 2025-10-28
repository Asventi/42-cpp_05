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
#include "Form.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

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

TEST_CASE("Form")
{
	CHECK_THROWS_AS(Form f("test", 0, 150), Form::GradeTooHighException);
	CHECK_THROWS_AS(Form f("test", 0, 150), std::exception);
	CHECK_THROWS_AS(Form f("test", 5, -2), Form::GradeTooHighException);
	CHECK_THROWS_AS(Form f("test", 170, 150), Form::GradeTooLowException);
	CHECK_THROWS_AS(Form f("test", 48, 180), Form::GradeTooLowException);
	Bureaucrat	b(20);
	Bureaucrat	b2(50);
	Form		f("form", 20, 10);

	CHECK_THROWS_AS(f.beSigned(b2), Form::GradeTooLowException);
	f.beSigned(b);
	CHECK(f.getSigned());
	CHECK_NOTHROW(f.beSigned(b2));
}
