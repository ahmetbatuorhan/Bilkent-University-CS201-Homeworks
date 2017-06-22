#include "JukeBox.h"
#include "TrackLinkedList.h"
#include <iostream>

using namespace std;

JukeBox::JukeBox()
{ }

JukeBox::~JukeBox()
{ }

void JukeBox::addTrack(string trackTitle, int releaseYear)
{
      trackLinkedList.addTrack(trackTitle, releaseYear);
}

void JukeBox::removeTrack(string trackTitle)
{
      trackLinkedList.removeTrack(trackTitle);
}

void JukeBox::addMusician(string trackTitle, string musicianFirstName, string musicianLastName, string musicianRole)
{
      trackLinkedList.addMusician(trackTitle, musicianFirstName, musicianLastName, musicianRole);
}

void JukeBox::removeMusician(string trackTitle, string musicianFirstName, string musicianLastName)
{
      trackLinkedList.removeMusician(trackTitle, musicianFirstName, musicianLastName);
}

void JukeBox::showAllTracks()
{
      trackLinkedList.showAllTracks();
}

void JukeBox::showTrack(string trackTitle)
{
      trackLinkedList.showTrack(trackTitle);
}

void JukeBox::showMusicianRoles(string musicianFirstName, string musicianLastName)
{
      trackLinkedList.showMusicianRoles(musicianFirstName, musicianLastName);
}


