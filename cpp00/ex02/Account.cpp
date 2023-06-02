#include "Account.hpp"
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	std::time_t time = std::time(NULL);
	char buff[80];
	std::strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S]", std::localtime(&time));
	std::cout << buff; 
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_nbAccounts++;
	this->_accountIndex = getNbAccounts() - 1;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:"
	<< _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:"
	<< checkAmount() << ";closed" << std::endl;
}

int Account::getNbAccounts(void) {
	return (_nbAccounts); }

int Account::getTotalAmount(void) {
	return (_totalAmount); }

int Account::getNbDeposits(void) {
	return (_totalNbDeposits); }	

int Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos(void)
{ 
	_displayTimestamp();
	std::cout << " accounts;" << getNbAccounts() << ";total:" << getTotalAmount() 
	<< ";deposits:" << getNbDeposits() << ";withdrawals:" 
	<< getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout <<" index:"<< this->_accountIndex << ";p_amount:" 
	<< checkAmount() << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits += this->_nbDeposits;
	this->_totalAmount += checkAmount();
	std::cout << ";amount:" << checkAmount() << ";nb_deposits:" 
	<< this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout <<" index:"<< this->_accountIndex << ";p_amount:" 
	<< checkAmount() << ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals += this->_nbWithdrawals;
	std::cout << withdrawal <<";amount:" << checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);	
}

int		Account::checkAmount(void) const {
	return (this->_amount); }

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << checkAmount()
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" 
	<< this->_nbWithdrawals << std::endl;
	return ;
}