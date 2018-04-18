/* Part of Cosmos by OpenGenus Foundation */
/* Contributed by Vaibhav Jain (vaibhav29498) */
/* Refactored by Adeen Shukla (adeen-s) */
#include <iostream>
#include <stddef.h>
#include <cassert>
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
  void sort();
 public:
  Polynomial(){}
  void insert_term(int, int);
  void print();
  friend Polynomial * operator+(Polynomial, Polynomial);
};


void Polynomial::insert_term(int c, int p) {
  bool found = false;
  for(int i = 0; i < poly.size(); i++) {
    if (poly[i].pow == p) {
      poly[i].coeff += c;
      found = true;
      break;
    }
  }
  if (!found) {
    poly.push_back(term(c,p));
  }
  sort();
}

void Polynomial::print() {
  for(int i = 0; i < poly.size(); i++) {
    if (i == 0) {
      cout << poly[i].coeff << "x^" << poly[i].pow << " ";
    } else if (i < poly.size() -1) {
      cout << poly[i].coeff << "x^" << poly[i].pow << " + ";
    } else {
      cout << poly[i].coeff << "x^" << poly[i].pow;
    }
  }
  cout << endl;
}

Polynomial * operator+(Polynomial p1, Polynomial p2) {
  int i = 0, j = 0;
  vector<term> poly1 = p1.poly;
  vector<term> poly2 = p2.poly;
  const int SIZE1 = poly1.size();
  const int SIZE2 = poly2.size();
  Polynomial * poly = new Polynomial;
  assert(poly);
  while (i < SIZE1 && j < SIZE2) {
    if (poly1[i].pow > poly2[j].pow) {
      poly->insert_term(poly1[i].coeff,poly1[i].pow);
      i++;
    } else if (poly1[i].pow < poly2[j].pow) {
      poly->insert_term(poly2[j].coeff,poly2[j].pow);
      j++;
    } else {
      poly->insert_term(poly1[i].coeff + poly2[j].coeff,poly2[j].pow);
      i++;
      j++;
    }
  }

  if (i < SIZE1) {
    for (i; i < SIZE1; i++) {
      poly->insert_term(poly1[i].coeff,poly1[i].pow);
    }
  } else if (j < SIZE2) {
    for (j; j < SIZE1; j++) {
      poly->insert_term(poly2[j].coeff,poly2[j].pow);
    }
  }

  return poly;

}

void Polynomial::sort() {
  int tmp;
  for (int i=0; i < poly.size(); i++) {
    for (int j=i+1; j < poly.size(); j++) {
      if (poly[i].pow < poly[j].pow) {
          tmp = poly[i].pow;
          poly[i].pow = poly[j].pow;
          poly[j].pow = tmp;
      }
    }
  }
}

int main() {
  Polynomial p1, p2;
  p1.insert_term(10, 0);
  p1.insert_term(7, 4);
  p1.insert_term(4, 5);
  p1.insert_term(9, 2);
  cout << "First polynomial:";
  p1.print();
  p2.insert_term(6, 5);
  p2.insert_term(3, 2);
  p2.insert_term(5, 0);
  p2.insert_term(7, 0);
  
  cout << "Second polynomial:";
  p2.print();
  Polynomial * p3 = p1 + p2;
  cout << "Sum:";
  p3->print();
  return 0;
}
