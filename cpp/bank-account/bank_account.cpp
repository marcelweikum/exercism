#include "bank_account.h"

#include <stdexcept>

namespace Bankaccount
{

    void Bankaccount::open()
    {
        if (!is_opened_)
        {
            is_opened_ = true;
            return;
        }
        throw std::runtime_error("Account already opened");
    }
    void Bankaccount::close()
    {
        if (is_opened_)
        {
            is_opened_ = false;
            balance_ = 0;
            return;
        }
        throw std::runtime_error("Account already closed");
    }
    int Bankaccount::balance()
    {
        if (is_opened_)
        {
            return balance_;
        }
        throw std::runtime_error("Account closed");
    }
    void Bankaccount::withdraw(int amount)
    {
        std::lock_guard<std::mutex> lock(mutex_);

        if (is_opened_)
        {
            if (amount <= balance_ && amount > 0)
            {
                balance_ -= amount;
                return;
            }
            throw std::runtime_error("Insufficient balance");
        }
        throw std::runtime_error("Account closed");
    }
    void Bankaccount::deposit(int amount)
    {
        std::lock_guard<std::mutex> lock(mutex_);

        if (is_opened_)
        {
            if (amount > 0)
            {
                balance_ += amount;
                return;
            }
            throw std::runtime_error("Insufficient amount");
        }
        throw std::runtime_error("Account closed");
    }

}