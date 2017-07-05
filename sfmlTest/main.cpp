#include <iostream>
#include <vector>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

#define RESOURCE_DIRECTORY "/home/david/Desktop/Programming/C++/sfmlTest/sfmlTest/resources/sounds/piano/"

class mySoundClass
{
public:
    mySoundClass()
    {
        soundID = 0;
        size = 0;
        thread = NULL;
    }

    mySoundClass(vector<String*> paths)
    {
        soundID = 0;

        for (unsigned int i=0;i<paths.size();i++)
            addSound(*paths[i]);
    }

    //public functions
    void addSound(string path)
    {
        SoundBuffer *buffer = new SoundBuffer; //a SoundBuffer preloads a sound, aka gets it ready for use. Here we have an array of them for multiple sound effects.
        Sound *sound = new Sound; //a Sound is given a SoundBuffer so it may be played. Here we have an array of them for multiple sound effects.

        string temp= RESOURCE_DIRECTORY;
        temp=temp+path; //adds the destination folder path ("../resources/") to the front of the file name.

        if (!buffer->loadFromFile(temp)) //ie: load the 1st SoundBuffer using the 1st soundEffectName into the 1st sound
            cout<<"File failed to load!!!"<<endl;
        sound->setBuffer(*buffer);

        buffers.push_back(buffer);
        sounds.push_back(sound);

        ++size;
    }

    void playSound(unsigned int newSoundID)
    {
        if(newSoundID >= sounds.size())
            return;

        soundID = newSoundID;
        thread = new Thread(&mySoundClass::soundThread,this);
        thread->launch();

        thread->wait();
        //sf::sleep(buffers[soundID]->getDuration());

        return;
    }

    unsigned int getSize()
    {
        return size;
    }

    //privates
private:
    //private functions
    void soundThread()
    {
        sounds[soundID]->play();

        return;
    }

    //private member variables
    vector<SoundBuffer*> buffers;
    vector<Sound*> sounds;
    vector<String*> paths;
    Thread *thread;
    unsigned int soundID;
    unsigned int size;
};

int main(int argc, char *argv[])
{
    mySoundClass soundClass;

    soundClass.addSound("AutoMode.wav");
    soundClass.addSound("GoHome.wav");
    soundClass.addSound("Initialized.wav");
    soundClass.addSound("ReadyClaw.wav");
    soundClass.addSound("Rotate.wav");
    soundClass.addSound("SkidSteer.wav");
    soundClass.addSound("Transform.wav");

//    soundClass.addSound("PickUp.wav");
//    soundClass.addSound("GetBlock.wav");
//    soundClass.addSound("GotBlock.wav");
//    soundClass.addSound("GiveUp.wav");
//    soundClass.addSound("DropOff.wav");

    soundClass.playSound(0);
    soundClass.playSound(1);
    soundClass.playSound(2);
    soundClass.playSound(3);
    soundClass.playSound(4);
    soundClass.playSound(5);


    for(unsigned int i = 0; i<UINT32_MAX; ++i)
    {
        cout<<i<<endl;
    }

    return 0;
}
