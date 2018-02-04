#include <iostream>
#include "expression.hpp"

using namespace std;

int main() {
    auto e = new AdditionExpression{
                 new DoubleExpression(1),
                 new AdditionExpression {
                         new DoubleExpression(2),
                         new DoubleExpression(3)
                 }
            };

    ExpressionPrinter ep;
    ep.print(e);
    std::cout<<ep.str()<<std::endl;
}