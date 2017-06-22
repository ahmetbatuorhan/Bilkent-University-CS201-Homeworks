#include "MusicianLinkedList.h"
#include <bits/stdc++.h>
#include <cctype>
#include <string>

// CONSTRUCTORS
// Constructor
MusicianLinkedList::MusicianLinkedList() : size(0), head(NULL), tail(NULL)
{

}
// Destructor
MusicianLinkedList::~MusicianLinkedList()
{
      while(!isEmpty())
      {
            removeFromHead();
      }
}
// Copy Constructor
MusicianLinkedList::MusicianLinkedList(const MusicianLinkedList& copyList) : size(copyList.size), head(NULL), tail(NULL)
{
      if(copyList.head != NULL)
      {
            head = new MusicianNode;
            head->musicianFirstName = copyList.head->musicianFirstName;
            head->musicianLastName = copyList.head->musicianLastName;
            head->musicianRole = copyList.head->musicianRole;
            head->next = NULL;
            head->prev = NULL;

            MusicianNode* origNode = copyList.head->next;

            while(origNode != NULL)
            {
                  tail->next = new MusicianNode;
                  tail->next->musicianFirstName = origNode->musicianFirstName;
                  tail->next->musicianLastName = origNode->musicianLastName;
                  tail->next->musicianRole = origNode->musicianRole;
                  tail->next->next = NULL;
                  tail->next->prev = tail;

                  tail = tail->next;
                  origNode = origNode->next;
            }
      }
}



// METHODS
void MusicianLinkedList::addLast(string musicianFirstName, string musicianLastName, string musicianRole)
{
      if(isEmpty())
      {
            head = new MusicianNode;
            head->musicianFirstName = musicianFirstName;
            head->musicianLastName = musicianLastName;
            head->musicianRole = musicianRole;
            head->next = NULL;
            head->prev = NULL;

            tail = head;

            size++;
      }
      else
      {
            if( checkMusician(musicianFirstName, musicianLastName))
            {
                  cout << "There is a musician with the same name \"" << musicianFirstName << " " << musicianLastName << "\".(Case Insensitive) " << endl;
                  return;
            }

            tail->next = new MusicianNode;
            (tail->next)->musicianFirstName = musicianFirstName;
            (tail->next)->musicianLastName = musicianLastName;
            (tail->next)->musicianRole = musicianRole;
            (tail->next)->next = NULL;
            (tail->next)->prev = tail;

            tail = tail->next;

            size++;
      }
}

void MusicianLinkedList::removeMusician(string musicianFirstName, string musicianLastName)
{
      if(!checkMusician(musicianFirstName, musicianLastName))
      {
            cout << "There is no musician with the name \"" << musicianFirstName << " " << musicianLastName << "\" " << endl;
      }
      else
      {
            MusicianNode* temp = NULL;
            findMusician(musicianFirstName, musicianLastName, temp);

            if(size == 1)
            {
                  head = NULL;
                  tail = NULL;

                  delete temp;
                  size--;
                  return;
            }

            if(temp->prev != NULL)
            {
                  (temp->prev)->next = temp->next;
            }
            else
            {
                  head = head->next;
                  head->prev = NULL;
            }

            if(temp->next != NULL)
            {
                  (temp->next)->prev = temp->prev;
            }
            else
            {
                  tail = tail->prev;
                  tail->next = NULL;
            }

            temp->next = NULL;
            temp->prev = NULL;

            delete temp;

            size--;
      }
}

void MusicianLinkedList::showAll()
{
      if(isEmpty())
      {
            cout << "------- NONE -------" << endl;
            return;
      }

      MusicianNode* temp = head;

      while(temp != NULL)
      {
            cout << temp->musicianFirstName << " " << temp->musicianLastName << ", " << temp->musicianRole << endl;
            temp = temp->next;
      }
}

void MusicianLinkedList::musicianRoles(string trackTitle, int releaseYear, string musicianFirstName, string musicianLastName, bool& check)
{
      MusicianNode* temp = NULL;
      findMusician(musicianFirstName, musicianLastName, temp);

      if(temp != NULL)
      {
            cout << temp->musicianRole << ", " << trackTitle << ", " << releaseYear << endl;
            check = true;
      }
}

// PRIVATE METHODS
// This method is from here : http://stackoverflow.com/questions/11635/case-insensitive-string-comparison-in-c/4119881#4119881
bool MusicianLinkedList::equals(const string& a, const string& b)
{
    unsigned int sz = a.size();
    if (b.size() != sz)
        return false;
    for (unsigned int i = 0; i < sz; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

bool MusicianLinkedList::checkMusician(string musicianFirstName, string musicianLastName)
{
      MusicianNode* temp = head;

      while(temp != NULL)
      {
            if( equals(temp->musicianFirstName, musicianFirstName) && equals(temp->musicianLastName, musicianLastName))
            {
                  return true;
            }
            temp = temp->next;
      }
      return false;
}

void MusicianLinkedList::findMusician(string musicianFirstName, string musicianLastName, MusicianNode*& result)
{
      MusicianNode* temp = head;

      while(temp != NULL)
      {
            if(equals(temp->musicianFirstName, musicianFirstName) && equals(temp->musicianLastName, musicianLastName))
            {
                  result = temp;
                  return;
            }
            temp = temp->next;
      }
}

bool MusicianLinkedList::isEmpty() const
{
      return size == 0;
}

void MusicianLinkedList::removeFromHead()
{
      MusicianNode* temp = head;
      head = head->next;
      temp->next = NULL;
      temp->prev = NULL;

      delete temp;

      size --;
}













