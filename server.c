/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:28:45 by proberto          #+#    #+#             */
/*   Updated: 2021/10/02 19:14:06 by proberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief This function is responsible for printing the server's pid to the 
 * console
 * @details The function receives the pid from the server, converts it to char 
 * and prints it to the console
 * @param pid The pid of the server.
 * @param fd The file descriptor of the console (1).
 * @return void.
*/
static void	ft_putnbr_fd(int n, int fd)
{
	char	id[12];
	char	*label;
	int		i;

	label = "PID: ";
	i = 0;
	write(1, label, 5);
	while (n)
	{
		id[i++] = (n % 10) + '0';
		n /= 10;
	}
	id[i] = '\0';
	while (i)
		write(fd, &id[--i], 1);
	write(fd, "\n", 2);
}

/**
 * @brief Function responsible for receiving and writing the message from the 
 * client.
 * @details The function works as a callback, called whenever the server 
 * receives signals (SIGUSR1/SIGUSR2). This function receives and prints to the 
 * console character by character so that the message is printed completely. 
 * @b behavior After receiving a signal the variable bits (if it is the first 
 * iteration, or if it is equal to 0) is started with 128 and then the sign is 
 * checked (where SIGUSR1 == 1 and SIGUSR2 == 0), when the bit is positive the 
 * variable chr will be added to the bit equivalent to bits (this will brush all
 * the other bits 64, 32, 16 ...) until the last bit (1), at the end of each 
 * iteration the response is sent to the client so that it can proceed with 
 * sending the bits remaining, if bits equals 0 it means that chr already has 
 * the ascii code of the sent character.
 * @param sig signal received.
 * @param siginfo info about the signal received.
 * @param context context of the signal received.
 * @return void.
*/
static void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	static char	chr;
	static int	bits;

	(void)context;
	if (!bits)
		bits = 128;
	if (sig == SIGUSR1)
		chr += bits;
	else
		chr += 0;
	bits /= 2;
	if (bits == 0)
	{
		write(1, &chr, 1);
		chr = 0;
	}
	kill(siginfo->si_pid, SIGUSR1);
}

/**
 * @brief Main function.
 * @details This sigaction structure is used to capture the SIGUSR1 and SIGUSR2 
 * signals and send them to the sig_handler function. It is also used to capture
 * the client's pid (process id); The sigaction function is used to set the 
 * signal handler; The pause function in the while loop ensures that the server 
 * will continue to function until the client closes the connection.
 * @return 0.
*/
int	main(void)
{
	struct sigaction	sigact;
	int					pid;

	sigact.sa_handler = (void *)sig_handler;
	sigact.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}
