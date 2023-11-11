#include <iostream>
#include "Video.h"
#include "Playlist.h"

using namespace std;

int main() {
    Video v1("T2QwBSfagU", "A Turista odamegy a Paraszthoz", 0.44, "KockaSajt", 20150625);
    Video v2("MTY1Kje0yLg", "Gravity Visualized", 9.57, "apbiolghs", 20120310);
    Video v3("tjf-1BxpR9c", "NVIDIA RTX and GameWorks Ray Tracing Technology Demonstration", 8.17, "NVIDIA GeForce",
             20180321);
    Video v4("fHfhorJnAEI",
             "See invisible motion; hear silent sounds. Coolt Creepy? Wo can't decide | Michae1 Rubinstein", 13.22,
             "TED", 20141223);
    Video v5("lwAaI_6b9JE", "Four Dimensional Maths: Things to See and Hear in the Fourth Dimension - with Matt Parker",
             61.39, "The Royal Institution", 20156225);
    Video v6("EekCn4wed1E", "A Hands-on Look at Using Ray Tracing in Games with UE 4,22 | GDc 2019 | Unreal Engine",
             28.35, "UnrealEngine", 29190325);
    Video v7("IUjpoauJcko", "More adventures in replying to spam | James Veitch", 10.20, "TED Archive", 20170127);
    Video v8("Qjt_MqEOcGM", "Tro1l' from Goodbye Kansas and Deep Forest Films | GDC 2019 | Unreal Engine", 1.33,
             "UnrealEngine", 20190320);
    Video v9("6MmiaqK342c", "Evolution of NVIDIA GeForce 1999-2017", 13.59, "Gameforest", 20171107);


    Playlist playlist1(10);
    playlist1.setTitle("Unreal");

    playlist1.append(&v6);
    playlist1.append(&v8);

    cout<<playlist1<<endl;

    return 0;
}
