/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:11:35 by acaffard          #+#    #+#             */
/*   Updated: 2024/09/19 14:37:31 by acaffard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit )
{
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
	_nbAccounts -= 1;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits \
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp()
{
	time_t	timestamp = std::time(nullptr);
	struct tm time = *localtime(&timestamp);
	char       buf[18];
	strftime(buf, sizeof(buf), "%Y%m%d_%H%M%S", &time);
	std::cout << "[" << buf << "]";
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
		_amount += deposit;
		_totalAmount += deposit;
		_nbDeposits += 1;
		_totalNbDeposits += 1;
		std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= this->_amount)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
		std::cout << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}
	
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits \
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}
