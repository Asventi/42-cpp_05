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

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("Bureaucrat")
{
	try
	{
		Bureaucrat b(789);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << "\n";
	}
}
