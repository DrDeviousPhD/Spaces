#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "Component.h"
#include <exception>
using namespace std;

class cErrorType : public Component
{
public:

	enum _error_type {unhandled_component};
	string _error_message;

	cErrorType(_error_type et, string msg) : _error_type(et), _error_message(msg) {}
};

/* Probably won't use this file at all, but hey look, I'm learning things. */

struct eAlreadyHasComponent : public exception
{
	virtual const char* what() const throw()
	{
		return "Already has component.";
	}
};

#endif 