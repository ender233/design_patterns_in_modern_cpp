#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

struct BankAccount
{
    int balance = 0;
    int overdraft_limit = -500;

    void deposit(int amount) {
        balance += amount;
        cout<<"deposited "<<amount<<", balance is now "<<balance<<"\n";
    }

    void withdraw(int amount){
        if(balance - amount >= overdraft_limit) {
            balance -= amount;
            cout<<"withdraw "<<amount<<", balance is now "<<balance<<"\n";
        }
    }
};

/**************************/
struct Command {
    virtual void call() const = 0;
    virtual void undo() const = 0;
};
struct BankAccountCommand : Command
{
    BankAccount &account;
    enum Action{deposit, withdraw} action;
    int amount;

    BankAccountCommand(BankAccount &account, Action action, int amount) :
            account(account), action(action), amount(amount) {}

    void call() const override {
        switch(action) {
            case deposit:
                account.deposit(amount); break;
            case withdraw:
                account.withdraw(amount); break;
        }
    }

    void undo() const override {
        switch(action) {
            case deposit:
                account.withdraw(amount); break;
            case withdraw:
                account.deposit(amount); break;
        }
    }
};

/************************/
struct CompositeBankAccountCommand : Command
{
private:
    std::vector<BankAccountCommand> commandVecs_;

public:
    CompositeBankAccountCommand(const std::initializer_list<BankAccountCommand> &items):
            commandVecs_(items) {
    }

    void call() const override {
        for(auto &cmd : commandVecs_) {
            cmd.call();
        }
    }
    void undo() const override {
        for(auto it=commandVecs_.rbegin(); it!=commandVecs_.rend(); ++it) {
            it->undo();
        }
    }
};

int main() {
    BankAccount ba;
    Command *cmd = new BankAccountCommand(ba, BankAccountCommand::deposit, 100);
    cmd->call();
    cout<<"current gdp:"<<ba.balance<<std::endl;
    cmd->undo();
    cout<<"current gdp:"<<ba.balance<<std::endl;

    // Transfer Service
    BankAccount from;
    BankAccount to;
    BankAccountCommand fromCmd(from, BankAccountCommand::withdraw, 100);
    BankAccountCommand toCmd(to, BankAccountCommand::deposit, 100);
    Command* cmds = new CompositeBankAccountCommand({fromCmd, toCmd});
    cmds->call();
    std::cout<<"from:"<<from.balance<<" to:"<<to.balance<<endl;
    cmds->undo();
    std::cout<<"after undo:"<<std::endl;
    std::cout<<"from:"<<from.balance<<" to:"<<to.balance<<endl;
}