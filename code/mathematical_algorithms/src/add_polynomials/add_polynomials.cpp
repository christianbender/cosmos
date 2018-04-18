/* Part of Cosmos by OpenGenus Foundation */
/* Contributed by Vaibhav Jain (vaibhav29498) */
/* Refactored by Adeen Shukla (adeen-s) */
#include <iostream>
#include <stddef.h>
#include <vector>

using namespace std;

struct term {
  int coeff;
  int pow;
  term* next;
  term(int, int);
};

term::term(int c, int p) {
  coeff = c;
  pow = p;
  next = NULL;
}

class Polynomial {
  vector<term> poly;

 public:
  Polynomial(){}
  void insert_term(int, int);
  void print();
  friend Polynomial operator+(Polynomial, Polynomial);
};


void Polynomial::insert_term(int c, int p) {
  bool found = false;
  for(int i = 0; i < poly.size(); i++) {
    if (poly[i].pow == p) {
      poly[i].coeff = c;
      found = true;
      break;
    }
  }
  if (!found) {
    poly.push_back(term(c,p));
  }
}

void Polynomial::print() {
  for(int i = 0; i < poly.size(); i++) {
    if (i == 0) {
      cout << poly[i].coeff << "x^" << poly[i].pow;
    } else if (i < poly.size() -1) {
      cout << poly[i].coeff << "x^" << poly[i].pow << " + ";
    } else {
      cout << poly[i].coeff << "x^" << poly[i].pow;
    }
  }
}

Polynomial operator+(Polynomial p1, Polynomial p2) {
  vector<term> poly1 = p1.poly;
  vector<term> poly2 = p2.poly;

}

int main() {
  Polynomial p1, p2;
  p1.insert_term(4, 5);
  p1.insert_term(7, 4);
  p1.insert_term(9, 2);
  p1.insert_term(10, 0);
  cout << "First polynomial:";
  p1.print();
  p2.insert_term(6, 5);
  p2.insert_term(3, 2);
  p2.insert_term(5, 0);
  p2.insert_term(7, 0);
  
  cout << "Second polynomial:";
  p2.print();
  Polynomial p3 = p1 + p2;
  cout << "Sum:";
  p3.print();
  return 0;
}
