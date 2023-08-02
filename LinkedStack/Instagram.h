#pragma once

#include <string>
#include "Stack.h"

using namespace std;

template <typename T>
class Instagram {

	public:

		Stack<T>& addFollower(Stack<T>& followerNode)
		{

			this->followerList = followerList.push(followerNode);


		}

		void removeFollower();

		void printFollowers()
		{

		}

		void latestFollower();

		void resetFollowers();

		void checklist();

		int returnFollowerNum() const
		{
			return numOfFollowers;
		}

	private:
		int numOfFollowers = 0;
		string user = "Popular User";
		Stack<T> followerList;			// Head of the list
};