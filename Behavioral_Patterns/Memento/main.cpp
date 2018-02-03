#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Memento {
    int balance;
public:
    Memento(int balance) : balance(balance) {}
    friend class BankAccount;
};
class BankAccount {
    int balance;
    vector<shared_ptr<Memento>> changes;
    int curPos;

public:
    BankAccount(int balance) : balance(balance) {
        changes.emplace_back(make_shared<Memento>(balance));
        curPos = 0;
    }
    friend ostream &operator<<(ostream &os, const BankAccount &account) {
        os << "balance: " << account.balance;
        return os;
    }

    shared_ptr<Memento> deposit(int amount){
        balance += amount;
        auto m = make_shared<Memento>(balance);
        changes.push_back(m);
        ++curPos;
        return m;
    }
    void restore(const shared_ptr<Memento> &m) {
        if(m) {
            balance = m->balance;
            changes.push_back(m);
            curPos = changes.size() - 1;
        }
    }

    // undo
    shared_ptr<Memento> undo() {
        if(curPos > 0) {
            --curPos;
            auto m = changes[curPos];
            balance = m->balance;
            return m;
        }
        return nullptr;
    }
    // redo
    shared_ptr<Memento> redo() {
        if(curPos + 1 < changes.size()) {
            ++curPos;
            auto m = changes[curPos];
            balance = m->balance;
            return m;
        }
        return nullptr;
    }
};



int main() {
    BankAccount ba(100);

    ba.deposit(50);
    ba.deposit(25);

    ba.undo();
    cout<<"Undo 1:"<<ba<<endl;
    ba.undo();
    cout<<"Undo 2:"<<ba<<endl;
    ba.redo();
    cout<<"Redo 1:"<<ba<<endl;
    ba.undo();
    cout<<"Undo 3:"<<ba<<endl;
}
