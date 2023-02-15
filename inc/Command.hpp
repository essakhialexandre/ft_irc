/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:34:19 by aessakhi          #+#    #+#             */
/*   Updated: 2023/02/15 16:24:25 by aessakhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP
# define COMMAND_HPP

#include "main.hpp"

class Command
{
private:
	Command();

	std::string					_cmd_name;
	std::string					_prefix;
	std::vector<std::string>	_params;
public:
	Command(std::string name, std::string prefix, std::vector<std::string> param_list);
	~Command();
};

#endif