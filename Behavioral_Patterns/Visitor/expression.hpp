//
// Created by ender on 2/4/18.
//
#ifndef VISITOR_EXPRESSION_HPP
#define VISITOR_EXPRESSION_HPP
#include <sstream>
#include <string>

struct Expression
{
    virtual ~Expression() {}
};
struct DoubleExpression : Expression
{
    double value_;
    explicit DoubleExpression(const double value) : value_(value) {}
};
struct AdditionExpression : Expression
{
    Expression *left, *right;

    AdditionExpression(Expression *left, Expression *right) : left(left), right(right) {}
    virtual ~AdditionExpression() {
        delete  left; delete right;
    }
};

struct ExpressionPrinter
{
    /*
     *
    void print(DoubleExpression *de, std::ostringstream &oss) const {
        oss << de->value_;
    }
    void print(AdditionExpression *de, std::ostringstream &oss) const {
        oss << "(";
        print((DoubleExpression*)de->left, oss);
        //print(de->left, oss);
        //print(de->right, oss);
        oss << ")";
    }
     */
    void print(Expression *e) {
        if(auto de = dynamic_cast<DoubleExpression *>(e)) {
            oss << de->value_;
        }
        else if(auto ae = dynamic_cast<AdditionExpression *>(e)) {
            oss << "(";
            print(ae->left);
            oss << "+";
            print(ae->right);
            oss << ")";
        }
    }
    std::string str() const { return oss.str();}

private:
    std::ostringstream oss;
};

#endif //VISITOR_EXPRESSION_HPP
