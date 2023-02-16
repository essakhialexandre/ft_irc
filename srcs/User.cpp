/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:42:29 by aessakhi          #+#    #+#             */
/*   Updated: 2023/02/16 15:33:10 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "User.hpp"

User::User(int fd): _fd(fd), _pwd(0),_authenticated(0)
{}

User::~User()
{}

bool	User::getAuth()
{
	return (this->_authenticated);
}

bool	User::getPwd()
{
	return (this->_pwd);
}

void	User::setAuth(bool state)
{
	this->_authenticated = state;
}

void	User::setPwd(bool state)
{
	this->_pwd = state;
}
