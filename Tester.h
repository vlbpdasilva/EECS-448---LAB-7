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
	*   @post A Tester instance is created 
	*/
	Tester();

	/** @pre None
	*   @post Destructor for Tester instance
	*/
	~Tester();
        
        /** @pre Existing Tester instance
	*   @post Prints information about tests
        *   @return Void
	*/
        void ConstructorTest();
        
        /** @pre Existing Tester instance
	*   @post Prints information about tests
        *   @return Void
	*/
        void DestructorTest();
        
        /** @pre Existing Tester instance
	*   @post Prints information about tests
        *   @return Void
	*/
        void EmptyTest();
        
        /** @pre Existing Tester instance
	*   @post Prints information about tests
        *   @return Void
	*/
        void SizeTest();
        
        /** @pre Existing Tester instance
	*   @post Prints information about tests
        *   @return Void
	*/
        void SearchTest();
        
        /** @pre Existing Tester instance
	*   @post Prints information about tests
        *   @return Void
	*/
        void addBackTest();
        
        /** @pre Existing Tester instance
	*   @post Prints information about tests
        *   @return Void
	*/
        void addFrontTest();
        
        /** @pre Existing Tester instance
	*   @post Prints information about tests
        *   @return Void
	*/
        void removeBackTest();
        
        /** @pre Existing Tester instance
	*   @post Prints information about tests
        *   @return Void
	*/
        void removeFrontTest();

};

#endif