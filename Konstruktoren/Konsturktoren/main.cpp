#include <iostream>

#include "strasse.h"
#include "haus.h"

using namespace std;

int main()
{
    Strasse hauptstrasse{"Hauptstrasse", {1,2,3,5,6} };
    Strasse nebenstrasse{"Nebenstrasse", {10,12,53,45,26} };
    Strasse drittestrasse{"Drittestrasse", {38,93,2,834,120} };
    hauptstrasse.write();
    nebenstrasse.write();
    drittestrasse.write();
    return 0;
}
