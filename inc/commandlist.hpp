#ifndef COMMANDLIST_HPP
# define COMMANDLIST_HPP

#include "main.hpp"

class Server;

void	cap(Server *srv, int &userfd, Command &cmd);
void	pass(Server *srv, int &userfd, Command &cmd);
void	nick(Server *srv, int &userfd, Command &cmd);
void	user(Server *srv, int &userfd, Command &cmd);
void	ping(Server *srv, int &userfd, Command &cmd);
void	privmsg(Server *srv, int &userfd, Command &cmd);
void	mode(Server *srv, int &userfd, Command &cmd);
void	away(Server *srv, int &userfd, Command &cmd);
void	join(Server *srv, int &userfd, Command &cmd);

#endif
