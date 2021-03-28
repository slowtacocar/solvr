//
// Created by bobby on 3/27/2021.
//

#include "Logarithm.h"

Expression *Logarithm::simplify() const {
    Expression *simplified = getOperand().simplify();
    Expression *ret;
    if (simplified->symbol() == '0') {
        ret = new Constant(log(((Constant *) simplified)->getValue()));
    } else ret = new Logarithm(simplified->copy());
    delete simplified;
    return ret;
}

std::string Logarithm::toString() const {
    return "ln(" + getOperand().toString() + ")";
}

char Logarithm::symbol() const {
    return 'l';
}

Expression *Logarithm::copy() const {
    return new Logarithm(getOperand().copy());
}

bool Logarithm::isEqual(Expression &expression) const {
    if (expression.symbol() == 'l') {
        Expression &op = ((Logarithm &) expression).getOperand();
        return op.isEqual(getOperand());
    }
}
