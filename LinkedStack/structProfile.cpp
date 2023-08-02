#include <iostream>

using namespace std;

struct Profile
{
    string name = "";
    string state = "";
    Profile* prevNodePtr = NULL;	// Pointer to the prev node
    Profile* nextNodePtr = NULL;	// Pointer to the next node

    Profile()
    {
        this->name = "";
        this->state = "";
        this->prevNodePtr = NULL;
        this->nextNodePtr = NULL;
    }

    Profile(string name, string state)
    {
        this->name = name;
        this->state = state;
        this->prevNodePtr = NULL;
        this->nextNodePtr = NULL;
    }

    friend ostream& operator <<(ostream& out, const Profile& profile)
    {
        out << profile.name << " " << profile.state;

        return out;
    }

    friend istream& operator >>(istream& in, Profile& profile)
    {
        string name;
        string state;

        in >> name;
        profile.name = name;

        in >> state;
        profile.state = state;

        return in;
    }

    /*
    friend bool operator ==(const Profile& p1, const string& test)
    {
        return p1.username == test;
    }

    friend bool operator ==(const Profile& p1, const Profile& p2)
    {
        return p1.username == p2.username;
    }

    friend bool operator !=(const Profile& p1, const string& test)
    {
        return p1.username != test;
    }
    */
};