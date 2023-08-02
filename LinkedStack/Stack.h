#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Stack {

	public:
		// Constructor
		Stack<T>() 
		{
			int stackSize = 0;
			T presFollower;
			T* stackStart = NULL;
			T* stackEnd = NULL;
			T* fence = NULL;
		};

		// Constructor
		Stack(T& user)
			:presFollower(user) {}

		// Push a new node onto the stack
		void push(T*& node)
		{
			if (this->stackSize == 0)
			{
				this->stackStart = node;				// startStack pointer points at first president
				node->prevNodePtr = this->fence;		// set node's prevPointer to point at stackStart
				this->fence = node;						// Move fence up to node
				this->stackEnd = fence;					// set stackEnd to the last node on the list
			}
			else
			{
				T* whatFencePointsAt = this->fence;		// Access the node that fence is pointing at
				whatFencePointsAt->nextNodePtr = node;	// use the previous node's nextNodePtr and point it at the new node
				node->prevNodePtr = this->fence;		// Point the new node's prevNodePtr at what fence is point to (the previously added node)
				this->fence = node;						// Point fence at the new node
				this->stackEnd = this->fence;			// move the stackEnd pointer up to fence, so it can be at the new end of the list
			}
			this->stackSize += 1;
		}

		// Pop off the top node of the stack
		void pop()
		{
			cout << "Removing: " << this->stackEnd->name << " " << this->stackEnd->state << endl;


			this->fence = this->stackEnd->prevNodePtr;	// Set fence to point at the preceding node

			this->stackEnd->prevNodePtr = NULL;			// Set the pointer pointing to the preceding node to NULL
			delete this->stackEnd;						// Delete what stackEnd points at
			
			this->stackEnd = this->fence;				// Poing stackEnd at fence, to be at the new end of the list

			if (this->stackSize > 1)
			{
				this->stackEnd->nextNodePtr = NULL;			// Set the new top node's nextNodePtr to NULL
			}
			else
			{

				stackStart = NULL;
				//stackEnd = NULL;
				//fence = NULL;
			}
			//this->stackEnd->nextNodePtr = NULL;			// Set the new top node's nextNodePtr to NULL

			this->stackSize -= 1;
		}

		// Check if linked list is empty
		void isEmpty()
		{
			if (this->stackStart != NULL)
			{
				cout << "The stack is NOT empty!" << endl;
			}
			else
			{
				cout << "The stack is empty!" << endl;
			}
		}

		// Remove all nodes from the linked list
		void makeEmpty()
		{
			while (this->stackSize > 0)
			{
				this->pop();
			}
		}

		// Check the top of the stack
		void peek()
		{
			cout << "The President at the top of the stack is: " << this->stackEnd->name << " " << this->stackEnd->state << endl;
		}

		// Print the linked list
		void print()
		{
			this->fence = this->stackStart;		// In case, make sure fence is at the start of the list
			
			for (int i = 0; i < stackSize; i++)
			{
				cout << this->fence->name << " " << this->fence->state << endl;
				this->fence = this->fence->nextNodePtr;		// Follow the nextNodePtr to the next node
			}
		}

	private:
		int stackSize = 0;
		T presFollower;
		T* stackStart = NULL;	// Should always point to the first node on the list
		T* stackEnd = NULL;		// Should always point to the top node on the list
		T* fence = NULL;		// Will move around as necessary, to carry out tasks
};