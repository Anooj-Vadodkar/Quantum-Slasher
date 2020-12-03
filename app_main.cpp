#include "App.h"


int main(int argc, char** argv) {
    GlutApp* app = new App(argc, argv, 800, 600, "Quantum Slasher");

    app->run();

}
