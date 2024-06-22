#include "Polynomial.hpp"

Polynomial::Polynomial() {
    // Does nothing.
}

Polynomial::Polynomial(std::string expression) {
    // expression = (c_1)x^n_1 + (c_2)x^n_2 + ... + (c_k)x^n_k
    // c's are integer coefficients, n's are non-negative integer exponents.

    std::string delimiter = " + ";

    std::string term;
    std::string coefficient;
    std::string exponent;
    size_t pos = 0;

    while (true) {
        pos = expression.find(delimiter);

        bool breakTheLoop = (pos == std::string::npos);

        term = expression.substr(0, pos);
        expression.erase(0, pos + delimiter.length());

        pos = term.find("x");

        coefficient = term.substr(1, pos - 2);
        exponent = term.substr(pos + 2, term.length() - pos);

        terms.insertAtTheEnd(Term(std::atoi(coefficient.c_str()), std::atoi(exponent.c_str())));

        if (breakTheLoop) break;
    }
}

void Polynomial::printPolynomial() {
    // prints the polynomial in expression format.
    // expression = (c_1)x^n_1 + (c_2)x^n_2 + ... + (c_k)x^n_k

    Node<Term> *node = terms.getFirstNode();

    while (node) {
        std::cout << "(" << node->element.getCoefficient() << ")x^" << node->element.getExponent();
        if (node->next) std::cout << " + ";
        node = node->next;
    }

    std::cout << std::endl;
}

void Polynomial::simplifyByExponents() {
    /* TODO */
    Node<Term> *node = terms.getFirstNode();
    Node<Term> *tmp1 = node;
    Node<Term> *tmp2 = node;
    Node<Term>  *t;
    Node<Term> *a;
    while(tmp1){
        while(tmp2){
            if((tmp2!=tmp1)&&(tmp1->element.getExponent() == tmp2->element.getExponent())){
                tmp1->element.setCoefficient(tmp1->element.getCoefficient() + tmp2->element.getCoefficient());
                if((tmp2->prev == NULL)&&(tmp2->next!=NULL)){    
                    t = tmp2->next;
                    tmp2->next->prev = NULL;
                    node = tmp2->next;
                    delete tmp2;
                    tmp2 = t;
                }
                else if((tmp2->prev != NULL)&&(tmp2->next!=NULL)){
                    t = tmp2->next;
                    tmp2->next->prev = tmp2->prev;
                    tmp2->prev->next = tmp2->next;
                    delete tmp2;
                    tmp2 = t;
                }
                else if((tmp2->prev != NULL)&&(tmp2->next==NULL)){
                    tmp2->prev->next = NULL;
                    delete tmp2;
                    tmp2 = NULL;
                }
            }
            else{
                tmp2 = tmp2->next;
            } 
        }
        if(tmp1->element.getCoefficient() == 0){
            if(tmp1->next){
            a = tmp1->next;
            terms.removeNode(tmp1);
            tmp1 = a;
            }
            else{
                terms.removeNode(tmp1);
                tmp1 = NULL;
            }
        }
        else{
            tmp1 = tmp1->next;
        }
        tmp2 = tmp1;
    }

}

Polynomial Polynomial::operator+(const Polynomial &rhs) const {
    /* TODO */
    Polynomial result;
    Node<Term> * a = this->terms.getFirstNode();
    Node<Term> * b = rhs.terms.getFirstNode();
    while(a){
        result.terms.insertAtTheEnd(a->element);
        a = a->next;
    }
    while(b){
        result.terms.insertAtTheEnd(b->element);
        b = b->next;
    }
    return result;
}
