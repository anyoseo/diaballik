#include <observer.h>
#include <vector>

#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#endif // OBSERVABLE_H
using namespace std;
struct Observable{
    vector<Observer*> obs;

    void addObs(Observer& o){
        obs.push_back(&o);
    }

    void notify(){
        for(Observer* o:obs){
            o->update();
        }
    }
};
