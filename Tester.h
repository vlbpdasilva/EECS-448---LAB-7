/**
*	@author  Victor Berger
*	@date  April 27, 2016
*	@brief Header file for Tester class --- tests the linked list/ node functionality
*/

#ifndef TESTER_H
#define TESTER_H



#include "LinkedList.h"

class Tester
{
public:

	/** @pre None
	*   @post A Test istance is created 
	*/
	Tester();

	/** @pre None
	*   @post Destructor for Test instance
	*/
	~Tester();
        
        void ConstructorTest();
        
        void DestructorTest();
        
        void EmptyTest();
        
        void SizeTest();
        
        void SearchTest();
        
        void addBackTest();
        
        void addFrontTest();

};

#endif