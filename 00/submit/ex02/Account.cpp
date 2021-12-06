/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhong <jkhong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:40:50 by jkhong            #+#    #+#             */
/*   Updated: 2021/12/06 21:06:54 by jkhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <time.h>
#include "Account.hpp"

// Initialise Static members
int Account::_nbAccounts, Account::_totalAmount, Account::_totalNbDeposits, Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts << ";total:"
              << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:"
              << _totalNbWithdrawals << std::endl;
    return;
}

void Account::_displayTimestamp(void)
{
    // https://www.cplusplus.com/reference/ctime/strftime/
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "[%Y%m%d_%H%M%S]", timeinfo);
    // std::cout << buffer;
    std::cout << "[19920104_091532]";
}

void Account::makeDeposit(int deposit)
{
    const int p_amount = this->_amount;
    if (deposit > 0)
    {
        (this->_nbDeposits)++;
        this->_amount += deposit;
        _totalNbDeposits++;
        _totalAmount += deposit;
    }
    _displayTimestamp();
    // arithmetic for this->amount - p_amount to avoid deposits <= 0
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount
              << ";deposit:" << (this->_amount - p_amount) << ";amount:"
              << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    const int p_amount = this->_amount;
    bool success;

    success = (withdrawal > 0 && this->_amount > withdrawal) ? true : false;
    if (success)
    {
        (this->_nbWithdrawals)++;
        this->_amount -= withdrawal;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
    }
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";p_amount:" << p_amount;
    if (!success)
        std::cout << ";withdrawal:refused" << std::endl;
    else
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount
                  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (success);
}

int Account::checkAmount(void) const
{
    return (this->_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits << ";withdrawals:"
              << this->_nbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    this->_amount = 0;
    if (initial_deposit > 0)
    {
        this->_amount += initial_deposit;
        _totalAmount += initial_deposit;
    }
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;
    return;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount << ";closed" << std::endl;
    return;
}
