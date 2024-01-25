#ifndef TYPETOOL_HPP_
# define TYPETOOL_HPP_

typedef unsigned int uint;

class Base;

Base* generate();
void identify(Base* ptr);
void identify(Base& ptr);

#endif
