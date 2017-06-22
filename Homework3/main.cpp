#include "JukeBox.h"
#include <iostream>
#include <cstdio>


using namespace std;

int main() {

      JukeBox j;

      j.addTrack("HaKaN", 1996);
      j.showAllTracks();
      j.addMusician("Hakan", "Ahmet", "Batu", "Ebesi");
       j.addMusician("Hakan", "AhMeT", "BaTu", "Ebesi");

       j.showTrack("hakan");


      /*
	JukeBox *jukebox = new JukeBox;
	jukebox->showAllTracks();

	jukebox->addTrack("dem song", 1990);
	jukebox->showAllTracks();
	jukebox->showTrack("dem song");
	cout << endl;
	jukebox->addTrack("noys song", 20990);
	jukebox->showAllTracks();
	cout << endl;

	jukebox->removeTrack("dem songgggg");
	jukebox->showAllTracks();
	cout << endl;
	jukebox->showTrack("dem song");
	cout << endl;
	jukebox->removeTrack("dem song");
	jukebox->showAllTracks();
	cout << endl;
	jukebox->removeTrack("dem song");
	jukebox->showAllTracks();
	cout << endl;
	jukebox->removeTrack("noys song");
	jukebox->showAllTracks();
	cout << endl;
	cout << endl;

	jukebox->addTrack("dem song", 1990);
	jukebox->showAllTracks();
	jukebox->addTrack("noys song", 20990);
	jukebox->showAllTracks();
	cout << endl;

	jukebox->addMusician("dem song", "dank", "meister", "meme master");
	jukebox->addMusician("dem song", "dank", "meister", "meme master");
	jukebox->addMusician("dem song", "danker", "meister", "meme masterer");
	jukebox->showTrack("dem song");
	cout << endl;

	jukebox->removeMusician("dem11 song", "dank", "meister");
	jukebox->removeMusician("dem song", "dank22", "meister");
	jukebox->removeMusician("dem song", "dank", "meister");
	jukebox->showTrack("dem song");
	cout << endl;
	jukebox->removeMusician("dem song", "dank", "meister");
	jukebox->showTrack("dem song");
	cout << endl;
	jukebox->removeMusician("dem song", "danker", "meister");
	jukebox->showTrack("dem song");
	cout << endl;

	jukebox->addMusician("dem song", "dank", "meister", "meme master");
	jukebox->addMusician("dem song", "danker", "meister", "meme masterer");
	jukebox->removeMusician("dem song", "danker", "meister");
	jukebox->showTrack("dem song");
	jukebox->addMusician("dem song", "dankest", "meisterest", "meme masterest");
	jukebox->showTrack("dem song");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	jukebox->showTrack("dem 2312song");
	cout << endl;
	cout << endl;
	cout << endl;

	jukebox->addTrack("dEm SoNG", 1990);
	jukebox->addTrack("songee", 19956450);
	jukebox->addTrack("hfgs SoNG", 199450);
	jukebox->addTrack("sadsa SoNG", 222);
	jukebox->addTrack("fsas SoNG", 111);
	jukebox->addTrack("saaadd SoNG", 201);

	jukebox->addMusician("dem song", "dank", "meister", "meme master");
	jukebox->addMusician("songee", "dank", "meister", "memer master");
	jukebox->addMusician("hfgs SoNG", "dank", "meister", "memeee master");
	jukebox->addMusician("saaadd SoNG", "dank", "meister", "meme master");
	jukebox->showAllTracks();
	jukebox->showTrack("DeM sOng");
	cout << endl;
	cout << endl;
	cout << endl;
	jukebox->showMusicianRoles("dank", "meister");

	getchar();

	delete jukebox; */
	return 0;

}
