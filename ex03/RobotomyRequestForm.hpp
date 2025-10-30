/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:21:15 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/30 14:21:15 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	virtual void	executeInternalForm() const;
public:
	RobotomyRequestForm();
	explicit RobotomyRequestForm(std::string const &t_target);
	RobotomyRequestForm(RobotomyRequestForm const &t_e);
	RobotomyRequestForm	&operator=(RobotomyRequestForm const &t_e);
	virtual ~RobotomyRequestForm();
};


#endif
