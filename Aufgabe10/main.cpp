#include <iostream>
#include <time.h>
#include <cstdlib>

#include "radar.h"
#include "plane.h"
#include "ufo.h"
#include "air.h"

#include "unkonwnexceptionouput.h"

using namespace std;

int main()
{
    std::srand( time(NULL));
    try {
        Air airspace;
        Radar myRadar;
        airspace.registerObserver(&myRadar);

        airspace.addAircraft(new Plane(3));
        airspace.addAircraft(new Plane(10));

        int i = 10;
        do{
            airspace.nextRound();
        }while (i--);
        airspace.addAircraft(new Ufo());


        i = 10;
        do{
            airspace.nextRound();
        }while (i--);

    }catch (const std::exception& ex){
        std::cerr<<"std::exception handler"<<std::endl;
        std::cerr<< ex.what()<<std::endl;
    } catch (...) {
        std::cerr<<"allException handler"<<std::endl;
        std::cerr<< ::unkonwnExceptionOutput<<std::endl;
    }
    return 0;
}
