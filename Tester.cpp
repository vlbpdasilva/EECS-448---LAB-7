/**
*	@author  Victor Berger
*	@date  April 27, 2016
*	@brief CPP file for Tester class --- tests the linked list/ node functionality
*/

#include "Tester.h"

Tester::Tester()
{
        std::cout << " " << std::endl;
	std::cout << "Beginning testing of Linked List class:" << std::endl;
        std::cout << " " << std::endl;
        
        ConstructorTest();
        DestructorTest();
        EmptyTest();
        SizeTest();
        SearchTest();
}

Tester::~Tester()
{
	
}

void Tester::ConstructorTest()
{
        std::cout << "1. Testing constructor for linked list..." << std::endl;
        
        LinkedList<int>* list = new LinkedList<int>();
        
        delete list;

        std::cout << "      Empty linked list succesfully created and deleted. PASS." << std::endl;
        
        std::cout << " " << std::endl;
}

void Tester::DestructorTest()
{
        std::cout << "2. Testing destructor for linked list containing nodes..." << std::endl;
        
        LinkedList<int>* list = new LinkedList<int>();
        
        list->addBack(5);
        list->addBack(10);
        list->addFront(15);
        list->addFront(20);
        
        delete list;
        
        std::cout << "      Non-empty linked list succesfully created and deleted. PASS." << std::endl;
        
        std::cout << " " << std::endl;
}

void Tester::EmptyTest()
{
        std::cout << "3. Testing isEmpty() method..." << std::endl;
        
        LinkedList<int>* list = new LinkedList<int>();
        
        if (list->isEmpty())
        {
            std::cout << "      isEmpty() returns true for the initial empty list... PASS."<< std::endl;
        }
        else
        {
            std::cout << "      isEmpty() does NOT return true for the initial empty list... FAIL." << std::endl;
        }
        
        bool EmptyTest = 1;
        
        list->addBack(5);
        if (!list->isEmpty())
        {
            std::cout << "      isEmpty() returns false for the non-empty list... PASS."<< std::endl;
        }
        else 
        {
            EmptyTest = 0;
        }
        
        delete list;
        
        LinkedList<int>* list2 = new LinkedList<int>();
        
        list2->addFront(10);
    
        if (!list2->isEmpty())
        {
            std::cout << "      isEmpty() returns false for the non-empty list... PASS."<< std::endl;
        }
        else
        {
            EmptyTest = 0;
        }
        
        list2->addBack(15);
        list2->addFront(20);
        
        if (!list2->isEmpty())
        {
            std::cout << "      isEmpty() returns false for list with multiple nodes... PASS."<< std::endl;
        }
        else
        {
            EmptyTest = 0;
        }
        
        if(!(EmptyTest))
        {
                std::cout << "      isEmpty() returned true for a list containing nodes... FAIL." << std::endl;
        }
        
        std::cout << " " << std::endl;
        
        delete list2;    
}

void Tester::SizeTest()
{
        std::cout << "4. Testing size() method..." << std::endl;
        
        LinkedList<int>* list = new LinkedList<int>();
    
        if(list->size() == 0)
        {
                std::cout<< "       size() returned a value of 0 on an initial empty list... PASS" << std::endl;
        }
        else
        {
                std::cout << "      size() did NOT return a value of 0 on an initial empty list... FAIL." << std::endl;
                std::cout << "          VALUE RETURNED BY SIZE: " << list->size() << std::endl;
        }
    
        list->addBack(10);
        if(list->size() == 1)
        {
                std::cout<< "       size() returned a value of 1 on a list containing one element... PASS" << std::endl;
        }
        else
        {
                std::cout << "      size() did NOT return a value of 1 on a list containing one element... FAIL." << std::endl;
                std::cout << "          VALUE RETURNED BY SIZE: " << list->size() << std::endl;
        }       
    
        list->addFront(20);
        if(list->size() == 2)
        {
                std::cout<< "       size() returned a value of 2 on a list containing two elements... PASS" << std::endl;
        }
        else
        {
                std::cout << "      size() did NOT return a value of 2 on a list containing two elements... FAIL." << std::endl;
                std::cout << "          VALUE RETURNED BY SIZE: " << list->size() << std::endl;
        }   
    
        list->removeFront();
        list->removeBack();
        
        if(list->size() == 0)
        {
                std::cout<< "       size() returned a value of 0 on an empty list... PASS" << std::endl;
        }
        else
        {
                std::cout << "      size() did NOT return a value of 0 on an empty list... FAIL." << std::endl;
                std::cout << "          VALUE RETURNED BY SIZE: " << list->size() << std::endl;
        }
    
        std::cout << " " << std::endl;
    
        delete list;  
}

void Tester::SearchTest()
{
        std::cout << "5. Testing search() method..." << std::endl;
    
        LinkedList<int>* list = new LinkedList<int>();
        
        bool emptySearch = 0;
        
        for (int i = -5; i <= 5; i++)
        {
                if(list->search(i))
                {
                        emptySearch = 1;
                }
        }
        
        if(!(emptySearch))
        {
                std::cout << "      search() returned false on an empty list... PASS." << std::endl;
        }
        else
        {
                std::cout<< "       search() did NOT return false on an empty list... FAIL." << std::endl;
        }
        
        list->addFront(5);
        list->addBack(10);
        list->addFront(15);
        
        if(list->search(5) && list->search(10) && list->search(15))
        {
            std::cout << "      search() returned true for values that existed on the list... PASS." << std::endl;
        }
        else
        {
            std::cout << "      search() did NOT return true for values that existed on the list... FAIL." << std::endl;                
        }
        
        list->removeFront();
        list->removeBack();
        
        if(!list->search(5) && !list->search(10) && !list->search(50))
        {
            std::cout << "      search() returned false for values that did not exist on the list... PASS." << std::endl;
        }
        else
        {
            std::cout << "      search() did NOT return false for values that  did not exist on the list... FAIL." << std::endl;                
        }
}