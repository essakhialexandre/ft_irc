/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessakhi <aessakhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:34:19 by aessakhi          #+#    #+#             */
/*   Updated: 2023/02/16 14:07:18 by aessakhi         ###   ########.fr       */
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
	std::string					_param;
	std::vector<std::string>	_paramList;
public:
	Command(std::string name, std::string param, std::vector<std::string> param_list);

	~Command();

	std::string getCmd() const;
	std::string getParam() const;
	std::vector<std::string>	getParamList() const;
};

#endif
