/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjarnac <pjarnac@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:18:01 by pjarnac           #+#    #+#             */
/*   Updated: 2025/10/30 15:18:01 by pjarnac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	virtual void	executeInternalForm() const;
public:
	PresidentialPardonForm();
	explicit PresidentialPardonForm(std::string const &t_target);
	PresidentialPardonForm(PresidentialPardonForm const &t_e);
	PresidentialPardonForm	&operator=(PresidentialPardonForm const &t_e);
	virtual ~PresidentialPardonForm();
};

#endif

