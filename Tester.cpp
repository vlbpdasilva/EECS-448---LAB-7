/**
*	@author  Victor Berger
*	@date  April 27, 2016
*	@brief CPP file for Tester class --- tests the linked list/ node functionality
*/

#include "Tester.h"

Tester::Tester()
{
    
        std::cout << " # # # # # # # # # # # # " << std::endl;
        std::cout << " " << std::endl;
	std::cout << "Beginning testing of Linked List class:" << std::endl;
        std::cout << " " << std::endl;
        
        ConstructorTest();
        DestructorTest();
        EmptyTest();
        SizeTest();
        SearchTest();
        addFrontTest();
        addBackTest();
        removeFrontTest();
        removeBackTest();
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
                std::cout << "          VALUE RETURNED BY size(): " << list->size() << std::endl;
        }
    
        list->addBack(10);
        if(list->size() == 1)
        {
                std::cout<< "       size() returned a value of 1 on a list containing one element... PASS" << std::endl;
        }
        else
        {
                std::cout << "      size() did NOT return a value of 1 on a list containing one element... FAIL." << std::endl;
                std::cout << "          VALUE RETURNED BY size(): " << list->size() << std::endl;
        }       
    
        list->addFront(20);
        if(list->size() == 2)
        {
                std::cout<< "       size() returned a value of 2 on a list containing two elements... PASS" << std::endl;
        }
        else
        {
                std::cout << "      size() did NOT return a value of 2 on a list containing two elements... FAIL." << std::endl;
                std::cout << "          VALUE RETURNED BY size(): " << list->size() << std::endl;
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
                std::cout << "          VALUE RETURNED BY size(): " << list->size() << std::endl;
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
                        break;
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

        if(list->search(5))
        {
            std::cout << "      search() returned true for values added with addFront()... PASS." << std::endl;
        }
        else
        {
            std::cout << "      search() did NOT return true for values added with addFront()... FAIL." << std::endl;                
        }
        
        list->addBack(10);
        if(list->search(10))
        {
            std::cout << "      Attempting to search after using addBack()... PASS." << std::endl;
        }
        else
        {
            std::cout << "      search() did NOT return true for values added with addBack()... FAIL." << std::endl;                
        }
        
        list->removeFront();
        list->removeBack();
        
        if(!list->search(5) && !list->search(10) && !list->search(15))
        {
            std::cout << "      search() returned false for values that did not exist on the list... PASS." << std::endl;
        }
        else
        {
            std::cout << "      search() did NOT return false for values that  did not exist on the list... FAIL." << std::endl;                
        }
        
        std::cout << " " << std::endl;
        
        delete list;
}

void Tester::addBackTest()
{
        std::cout << "7. Testing addBack() method..." << std::endl;
    
        LinkedList<int>* list = new LinkedList<int>();
    
        bool BackPass = 1;
        
        list->addBack(12);
        
        if(list->size() == 1)
        {
                std::cout << "      Correct size returned after one node added with addBack()... PASS." << std::endl;
        }
        else
        {
                BackPass = 0;
                std::cout << "      Incorrect size returned after one node added with addBack()... FAIL." << std::endl;
        }
    
        if(list->search(12))
        {
                std::cout << "      search() returned true for a value added with addBack()... PASS." << std::endl;
        }
        else
        {
                BackPass = 0;
                std::cout << "      search() did NOT return true for a value added with addBack()... FAIL." << std::endl;
        }
        std::cout<< " " << std::endl;
        std::cout << "      Attempting to test addBack() on multiple iterations... " << std::endl;
        for(int i = -5; i <= 5; i++) // 11 iterations
        {
                list->addBack(i);
        }
    
        bool multiplePass = 1;
        for(int i = -5; i <= 5; i++) // 11 iterations
        {
                if(!(list->search(i)))
                {
                        multiplePass = 0;
                        BackPass = 0;
                        std::cout << "      search() did NOT return true for multiple nodes added with addBack()... FAIL." << std::endl;
                        break;
                }
        }
        
        if(multiplePass)
        {
            std::cout << "      search() succesfully returned true for multiple nodes added with addBack()... PASS." << std::endl;
        }
        
        if(list->size() == 12)
        {
                std::cout << "      size() returned the correct value after multiple nodes added with addBack()... PASS. " << std::endl;
        }
        else
        {
            std::cout << "      size() did NOT return the correct value after multiple nodes added with addBack()... FAIL. " << std::endl;
        }
        
        std::cout<< " " <<std::endl;
        
        if(!(BackPass))
        {
                std::cout << "      Errors were found with the testing of addBack()."<<std::endl;
        }
        else
        {
                std::cout << "      No errors were found with the testing of addBack()."<<std::endl;
        }
    
        delete list;
        std::cout << " " << std::endl;
}

void Tester::addFrontTest()
{
        std::cout << "6. Testing addFront() method..." << std::endl;
    
        LinkedList<int>* list = new LinkedList<int>();
    
        bool FrontPass = 1;
        
        list->addFront(12);
        
        if(list->size() == 1)
        {
                std::cout << "      Correct size returned after one node added with addFront()... PASS." << std::endl;
        }
        else
        {
                FrontPass = 0;
                std::cout << "      Incorrect size returned after one node added with addFront()... FAIL." << std::endl;
        }
    
        if(list->search(12))
        {
                std::cout << "      search() returned true for a value added with addFront()... PASS." << std::endl;
        }
        else
        {
                FrontPass = 0;
                std::cout << "      search() did NOT return true for a value added with addFront()... FAIL." << std::endl;
        }
        std::cout<< " " << std::endl;
        std::cout << "      Attempting to test addFront() on multiple iterations... " << std::endl;
        for(int i = -5; i <= 5; i++) // 11 iterations
        {
                list->addFront(i);
        }
    
        bool multiplePass = 1;
        for(int i = -5; i <= 5; i++) // 11 iterations
        {
                if(!(list->search(i)))
                {
                        multiplePass = 0;
                        FrontPass = 0;
                        std::cout << "      search() did NOT return true for multiple nodes added with addFront()... FAIL." << std::endl;
                        break;
                }
        }
        
        if(multiplePass)
        {
            std::cout << "      search() succesfully returned true for multiple nodes added with addFront()... PASS." << std::endl;
        }
        
        if(list->size() == 12)
        {
                std::cout << "      size() returned the correct value after multiple nodes added with addFront()... PASS. " << std::endl;
        }
        else
        {
            std::cout << "      size() did NOT return the correct value after multiple nodes added with addFront()... FAIL. " << std::endl;
        }
        
        std::cout<< " " <<std::endl;
        
        if(!(FrontPass))
        {
                std::cout << "      Errors were found with the testing of addFront()."<<std::endl;
        }
        else
        {
                std::cout << "      No errors were found with the testing of addFront()."<<std::endl;
        }
    
        delete list;
        std::cout << " " << std::endl;                
    
}

void Tester::removeBackTest()
{
        std::cout << "9. Testing removeBack() method..." << std::endl;
    
        LinkedList<int>* list = new LinkedList<int>();
        
        std::cout<<"      Testing removeBack() on empty list, should return false..." << std::endl;
        
        if(!(list->removeBack()))
        {
                std::cout<< "      removeBack() returned false, as expected... PASS. " << std::endl;
        }
        else
        {
                std::cout<< "      removeBack() did NOT return false... FAIL." << std::endl;
        }
    
        std::cout<<" " << std::endl;
        std::cout<<"      Testing removeBack() on list with one node added with addBack()..." << std::endl;
        
        list->addBack(20);
        if(list->removeBack())
        {
                std::cout<<"      removeBack() returned true on a list with one node... PASS." << std::endl;
        }
        else
        {
                std::cout<< "     removeBack() did NOT return true on a list with one node... FAIL" << std::endl;
        }
        
        std::cout<<" " << std::endl;
                
        std::cout<<"      Testing removeBack() on list with multiple nodes added with addBack()..." << std::endl;
        
        for(int i = -5; i <= 5; i++) 
        {
               list->addBack(i);
        }
        
        bool removeBackPass = 1;
        
        for(int i = -5; i <= 5; i++) 
        {
            if(!(list->removeBack()))
            {
                std::cout<< "     removeBack() did NOT return true on list with multiple nodes... FAIL." << std::endl;
                removeBackPass = 0;
                break;                
            }
        }
        
        if(removeBackPass)
        {
                std::cout<<"      removeBack() returned true for all values on list with multiple nodes... PASS." << std::endl;
        }
        
        std::cout<<" " << std::endl;
        
        delete list;
        
        //////////////////////////////////////////////////////////////////////////////////////
        
        LinkedList<int>* list2 = new LinkedList<int>();
        
        std::cout<<"      Testing removeBack() on list with one node added with addFront()..." << std::endl;
        
        list->addFront(20);
        if(list->removeBack())
        {
                std::cout<<"      removeBack() returned true on a list with one node... PASS." << std::endl;
        }
        else
        {
                std::cout<< "     removeBack() did NOT return true on a list with one node... FAIL" << std::endl;
        }
        
        std::cout<<" " << std::endl;
                
        std::cout<<"      Testing removeBack() on list with multiple nodes added with addFront()..." << std::endl;
        
        for(int i = -5; i <= 5; i++) 
        {
               list->addFront(i);
        }
        
        bool removeBackPass2 = 1;
        
        for(int i = -5; i <= 5; i++) 
        {
            if(!(list->removeBack()))
            {
                std::cout<< "     removeBack() did NOT return true on list with multiple nodes... FAIL." << std::endl;
                removeBackPass2 = 0;
                break;                
            }
        }
        
        if(removeBackPass2)
        {
                std::cout<<"      removeBack() returned true for all values on list with multiple nodes... PASS." << std::endl;
        }
        
        std::cout<< " " << std::endl;
        delete list2;
        
        //////////////////////////////////////////////////////////////////////////////////////
        
        std::cout<<"      Searching for values after using removeBack()..." << std::endl;
        
        LinkedList<int>* list3 = new LinkedList<int>();
        
        list3->addFront(1);
        list3->addBack(2);
        list3->removeBack();
        
        if(!(list3->search(2)))
        {
                std::cout << "      Value that should have been removed (BACK) was not found by search()... PASS." << std::endl;
        }
        
        else
        {
                std::cout<< "       Value that should have been removed (BACK) was still found by search()... FAIL." << std::endl;
        }
        
        if(list3->search(1))
        {
                std::cout << "      Value that should have been kept (FRONT) was found... PASS." << std::endl;
        }
        
        else
        {
                std::cout<< "       Value that should have been kept (FRONT) was never found... FAIL." << std::endl;
        }
        
        delete list3;
        
        std::cout << " " << std::endl;
}

 void Tester::removeFrontTest()
{
        std::cout << "8. Testing removeFront() method..." << std::endl;
    
        LinkedList<int>* list = new LinkedList<int>();
        
        std::cout<<"      Testing removeFront() on empty list, should return false..." << std::endl;
        
        if(!(list->removeFront()))
        {
                std::cout<< "      removeFront() returned false, as expected... PASS. " << std::endl;
        }
        else
        {
                std::cout<< "      removeFront() did NOT return false... FAIL." << std::endl;
        }
    
        std::cout<<" " << std::endl;
        std::cout<<"      Testing removeFront() on list with one node added with addBack()..." << std::endl;
        
        list->addBack(20);
        if(list->removeFront())
        {
                std::cout<<"      removeFront() returned true on a list with one node... PASS." << std::endl;
        }
        else
        {
                std::cout<< "     removeFront() did NOT return true on a list with one node... FAIL" << std::endl;
        }
        
        std::cout<<" " << std::endl;
                
        std::cout<<"      Testing removeFront() on list with multiple nodes added with addBack()..." << std::endl;
        
        for(int i = -5; i <= 5; i++) 
        {
               list->addBack(i);
        }
        
        bool removeFrontPass = 1;
        
        for(int i = -5; i <= 5; i++) 
        {
            if(!(list->removeFront()))
            {
                std::cout<< "     removeFront() did NOT return true on list with multiple nodes... FAIL." << std::endl;
                removeFrontPass = 0;
                break;                
            }
        }
        
        if(removeFrontPass)
        {
                std::cout<<"      removeFront() returned true for all values on list with multiple nodes... PASS." << std::endl;
        }
        
        std::cout<<" " << std::endl;
        
        delete list;
        
        //////////////////////////////////////////////////////////////////////////////////////
        
        LinkedList<int>* list2 = new LinkedList<int>();
        
        std::cout<<"      Testing removeFront() on list with one node added with addFront()..." << std::endl;
        
        list->addFront(20);
        if(list->removeFront())
        {
                std::cout<<"      removeFront() returned true on a list with one node... PASS." << std::endl;
        }
        else
        {
                std::cout<< "     removeFront() did NOT return true on a list with one node... FAIL" << std::endl;
        }
        
        std::cout<<" " << std::endl;
                
        std::cout<<"      Testing removeFront() on list with multiple nodes added with addFront()..." << std::endl;
        
        for(int i = -5; i <= 5; i++) 
        {
               list->addFront(i);
        }
        
        bool removeFrontPass2 = 1;
        
        for(int i = -5; i <= 5; i++) 
        {
            if(!(list->removeFront()))
            {
                std::cout<< "     removeFront() did NOT return true on list with multiple nodes... FAIL." << std::endl;
                removeFrontPass2 = 0;
                break;                
            }
        }
        
        if(removeFrontPass2)
        {
                std::cout<<"      removeFront() returned true for all values on list with multiple nodes... PASS." << std::endl;
        }
        
        std::cout<< " " << std::endl;
        
        delete list2;
        
        //////////////////////////////////////////////////////////////////////////////////////
        
        std::cout<<"      Searching for values after using removeFront()..." << std::endl;
        
        LinkedList<int>* list3 = new LinkedList<int>();
        
        list3->addFront(1);
        list3->addBack(2);
        list3->removeFront();
        
        if(!(list3->search(1)))
        {
                std::cout << "      Value that should have been removed (FRONT) was not found by search()... PASS." << std::endl;
        }
        
        else
        {
                std::cout<< "      Value that should have been removed (FRONT) was still found by search()... FAIL." << std::endl;
        }
        
        if(list3->search(2))
        {
                std::cout << "     Value that should have been kept (BACK) was found... PASS." << std::endl;
        }
        
        else
        {
                std::cout<< "      Value that should have been kept (BACK) was never found... FAIL." << std::endl;
        }
        
        delete list3;
        
        std::cout << " " << std::endl;
        
}