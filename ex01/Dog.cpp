#include "Dog.hpp"

Dog::Dog( void ) : Animal(){
	std::cout << "Dog created!\n";
	this->type = "Dog";
	this->attribute = new Brain();
}

Dog::Dog( const Dog &n ) : Animal(n){
	std::cout << "Dog Copy called!\n";
	attribute = new Brain(*n.attribute);
}

Dog& Dog::operator=( const Dog &n ) {
	std::cout << "Dog Copy assigment called!\n";
	if (this == &n)
		return (*this);
	this->type = n.type;
	if(attribute)
		delete this->attribute;
	this->attribute = new Brain( *n.getBrain() );
	return (*this);
}

Dog::~Dog( void ){
	delete this->attribute;
	std::cout << "Dog destroyed!\n";
}

void	Dog::makeSound( void ) const{
	std::cout << "Woof Woof!\n";
}

Brain	*Dog::getBrain( void ) const{
	return (this->attribute);
}
