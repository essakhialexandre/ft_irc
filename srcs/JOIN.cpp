#include "main.hpp"
#include <utility>

static std::vector<std::string>	splitTargets(std::string str, std::string delimiter)
{
	std::vector<std::string> result;

	size_t	end = str.find(delimiter);

	while (end != std::string::npos)
	{
		result.push_back(str.substr(0, end));
		str.erase(0, end + delimiter.length());
		end = str.find(delimiter);
	}
	result.push_back(str);
	return (result);
}

void	join(Server *srv, int &userfd, Command &cmd)
{
	std::vector<std::string> channels;
	err_codes	err;

	std::cout << "JOIN func called" << std::endl;
	(void)userfd;
	if (cmd.getParamList().empty())
		std::cout << "Need more params" << std::endl;
	/* Like with PRIVMSG will need to split the targets to send it to each individual targets */
	/* Need verification if the target starts with '#', shouldn't happen with irssi but someone might try it with nc */
	channels = splitTargets(cmd.getParam(0), ",");
	for (std::vector<std::string>::const_iterator it = channels.begin(); it != channels.end(); it++)
	{
		if (srv->getChannel(*it) == NULL)
			srv->getChannelMap()->insert(std::make_pair(*it, new Channel(*it)));
		err = srv->getChannel(*it)->join(srv->getUser(userfd), cmd.getLastParam());
		switch(err)
		{
			case err_badchannelkey:
				std::cout << "Bad chan key" << std::endl;
				break;
			case err_bannedfromchan:
				std::cout << "Banned" << std::endl;
				break;
			case err_channelisfull:
				std::cout << "Chan full" << std::endl;
				break;
			case err_inviteonlychan:
				std::cout << "Invite only Chan" << std::endl;
				break;
			default:
				std::cout << "All good" << std::endl;
				break;
		}
	}
}
