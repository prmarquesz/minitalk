/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:06:35 by proberto          #+#    #+#             */
/*   Updated: 2021/10/02 19:49:19 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief This function is responsible for printing the error message.
 * @param message The error message.
 * @return 1 to force the program to exit.
*/
static int	ft_error(char *message)
{
	size_t	len;

	len = 0;
	while (message[len])
		len++;
	write(1, "\033[31;1;4m", 10);
	write(1, "Error\n", 7);
	write(1, message, len);
	write(1, "\033[0m", 5);
	return (1);
}

/**
 * @brief This function is responsible for receiving a signal (response) from 
 * the server.
 * @details The function works as a callback, called whenever the server 
 * receives signals (SIGUSR1/SIGUSR2).
 * @param sig Signal received.
 * @return Void.
*/
static void	sig_handler(int sig)
{
	sig = sig;
	return ;
}

/**
 * @brief This function is responsible for converts the alphanumeric to integer.
 * @param str The string to be converted.
 * @return The converted integer.
*/
int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	res;

	i = 0;
	res = i;
	sign = 1;
	while (*(str + i) == ' ' || *(str + i) == '\f' || *(str + i) == '\n'
		|| *(str + i) == '\r' || *(str + i) == '\t' || *(str + i) == '\v')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (*(str + i++) - '0');
	if (LONG_MIN / 10 >= res && sign == 1)
		return ((int)LONG_MAX);
	else if (LONG_MIN / 10 >= res && sign == -1)
		return ((int)LONG_MIN);
	return ((int)res * sign);
}

/**
 * @brief This function is responsible for sending the message to the server.
 * @details The function will scan all characters of the string and each char 
 * is brushed bits, so that each character is sent to the server bit by bit.
 * @param pid The server's pid.
 * @param message The message to be sent.
 * @return Void.
*/
void	ft_send_message(int pid, char *message)
{
	int	bitshift;

	while (*message)
	{
		bitshift = 0;
		while (bitshift < BYTE)
		{
			signal(SIGUSR1, sig_handler);
			if (*message & (128 >> bitshift++))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			sleep(1);
		}
		message++;
	}
}

/**
 * @brief Main function.
 * @param argc Number of arguments.
 * @param argv Argument array, where argv [1] is expected the pid of the server 
 * and argv [2] is expected the message to be sent to it.
 * @return 0 if everything went well, 1 if an error occured.
*/
int	main(int argc, char **argv)
{
	char	*message;
	int		pid;

	if (argc != 3)
		exit(ft_error("     Invalid arguments\n"
				"		Usage: ./client <server pid> <message>\n"));
	pid = ft_atoi(argv[1]);
	message = argv[2];
	if (pid < 0)
		exit(ft_error("     Invalid pid\n"));
	ft_send_message(pid, message);
	return (0);
}
