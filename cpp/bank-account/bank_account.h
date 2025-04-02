#if !defined(BANK_ACCOUNT_H)
#define BANK_ACCOUNT_H

#include <mutex>

namespace Bankaccount
{
    class Bankaccount
    {
    public:
        Bankaccount() : is_opened_{false}, balance_{} {};
        void open();
        void close();
        int balance();
        void withdraw(int amount);
        void deposit(int amount);

    private:
        bool is_opened_;
        int balance_;
        std::mutex mutex_;
    }; // class Bankaccount

} // namespace Bankaccount

#endif // BANK_ACCOUNT_H