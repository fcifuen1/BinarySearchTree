/* 
 * File:   ItemError.h
 * Author: Federico Cifuentes-Urtubey
 * 
 * Definition of the ItemError class, which is used for exception messages. 
 */

#ifndef ITEMERROR_H
#define ITEMERROR_H

#include <iostream>
#include <string>

class ItemError
{
	public:
		ItemError(string m) : message(m) {}
		string getMessage() { return message; }

	private:
		string message;
};

#endif