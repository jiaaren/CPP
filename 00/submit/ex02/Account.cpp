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
	std::cout << buffer;
}

void Account::makeDeposit(int deposit)
{
	if (deposit <= 0)
		return;
	(this->_nbDeposits)++;
	this->_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
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
	return;
}