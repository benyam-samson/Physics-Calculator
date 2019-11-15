//Benyam Samson, COSC 1437-58001, October 17, 2019
#include <cstdlib>
#include "Input_Validation_Extended.h"
#include <iostream>
#include <sstream> 
#include <string> 
#include <iomanip>
using namespace std;

void printMenu();
void velocity();
void acceleration();
void motion();
void newton();
void weight();
void momentum();

int main() {
	char input = '\0';
  cout << fixed << setprecision(4);
  cout << "Welcome to the Physics Calculator! " << endl;

  do {
    printMenu();
    input = validateChar(input);

    if (input == 'V' || input == 'v')
      velocity();
    else if (input == 'A' || input == 'a')
      acceleration();
    else if (input == 'M' || input == 'm')
      motion();
    else if (input == 'N' || input == 'n')
      newton();
    else if (input == 'W' || input == 'w')
      weight();
    else if (input == 'P' || input == 'p')
      momentum();
    else if (input == 'E' || input == 'e')
      cout << "Exiting program..." << endl;
    else if (input == 'C' || input == 'c')
      cout << "\033[2J\033[1;1H";
    else
      cout << "Invalid choice. Please try again." << endl;
  } while (input != 'E' && input != 'e');

  return 0;
}

void printMenu() {
  cout << "Enter a character to do that operation:\n\x1b[31;1mV or v: Velocity\n\x1b[32;1mA or a: Acceleration\n\x1b[33;1mM or m: Motion\n\x1b[34;1mN or n: Newton's Second Law\n\x1b[35;1mW or w: Weight\n\x1b[36;1mP or p: Momentum\x1b[0m\n\x1b[38;1mE or e: Exit\nC or c: Clear the screen\x1b[0m" << endl;
}

void velocity() {
  double ds = 0.0, dt = 0.0, v = 0.0;
  string unitS = "", unitT = "";

  cout << "Enter the change in position (ds): ";
  ds = validateDouble(ds);

  cout << "Enter the units for ds: ";
  unitS = validateString(unitS);

  cout << "Enter the change in time (dt): ";
  dt = validateDouble(dt);

  cout << "Enter the units for dt: ";
  unitT = validateString(unitT);

  v = ds/dt;
  cout << ds << " " << unitS << " / " << dt << " " << unitT << " = " << v << " "  << unitS << "/" << unitT << endl;
  cout << "Your velocity is \x1b[31;1m" << v << " " << unitS << "/" << unitT << "\x1b[0m" << endl << endl;
}

void acceleration() {
  double dv = 0.0, dt = 0.0, a = 0.0;
  string unitV = "", unitT = "";

  cout << "Enter the change in velocity (dv): ";
  dv = validateDouble(dv);

  cout << "Enter the units for dv: ";
  unitV = validateString(unitV);

  cout << "Enter the change in time (dt): ";
  dt = validateDouble(dt);

  cout << "Enter the units for dt: ";
  unitT = validateString(unitT);

  a = dv/dt;
  cout << dv << " " << unitV << " / " << dt << " " << unitT << " = " << a << " "  << unitV << "/" << unitT << endl;
  cout << "Your acceleration is \x1b[32;1m" << a << " " << unitV << "/" << unitT << "\x1b[0m" << endl << endl;
}

void motion() {
  double v = 0.0, v0 = 0.0, v_bar = 0.0;
  string unitV = ""; //assuming both are the same units

  cout << "Enter the velocity: ";
  v = validateDouble(v);

  cout << "Enter the initial velocity (v0): ";
  v0 = validateDouble(v0);

  cout << "Enter the units: ";
  unitV = validateString(unitV);

  v_bar = 0.5 * (v + v0);
  cout << "0.5 * (" << v << " " << unitV << " + " << v0 << " " << unitV << ") = " << v_bar << " " << unitV << endl;
  cout << "Your motion is \x1b[33;1m" << v_bar << " " << unitV << "\x1b[0m" << endl << endl;
}

void newton() {
  double m = 0.0, a = 0.0, F = 0.0;
  string unitM = "", unitA = "";

  cout << "Enter the mass: ";
  m = validateDouble(m);

  cout << "Enter the units for the mass: ";
  unitM = validateString(unitM);

  cout << "Enter the acceleration: ";
  a = validateDouble(a);

  cout << "Enter the units for the acceleration: ";
  unitA = validateString(unitA);

  F = m * a;
  cout << m << " " << unitM << " * " << a << " " << unitA << " = " << F << " " << unitM << " * " << unitA << endl;
  cout << "By Newton's 2nd Law, your force is \x1b[34;1m" << F << " " << unitM << " * " << unitA << "\x1b[0m" << endl << endl;
}

void weight() {
  double m = 0.0, g = 0.0, W = 0.0;
  string unitM = "", unitG = "";

  cout << "Enter the mass: ";
  m = validateDouble(m);

  cout << "Enter the units for the mass: ";
  unitM = validateString(unitM);

  cout << "Enter the gravitational field: ";
  g = validateDouble(g);

  cout << "Enter the units for the gravitational field: ";
  unitG = validateString(unitG);

  W = m * g;
  cout << m << " " << unitM << " * " << g << " " << unitG << " = " << W << " " << unitM << " * " << unitG << endl;
  cout << "Your weight is \x1b[35;1m" << W << " " << unitM << " * " << unitG << "\x1b[0m" << endl << endl;
}

void momentum() {
  double m = 0.0, v = 0.0, p = 0.0;
  string unitM = "", unitV = "";

  cout << "Enter the mass: ";
  m = validateDouble(m);

  cout << "Enter the units for the mass: ";
  unitM = validateString(unitM);

  cout << "Enter the velocity: ";
  v = validateDouble(v);

  cout << "Enter the units for the velocity: ";
  unitV = validateString(unitV);

  p = m * v;
  cout << m << " " << unitM << " * " << v << " " << unitV << " = " << p << " " << unitM << " * " << unitV << endl;
  cout << "Your momentum is \x1b[36;1m" << p << " " << unitM << " * " << unitV << "\x1b[0m" << endl << endl;
}