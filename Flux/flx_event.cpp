#include "flx_event.h"

FLX_Event::FLX_Event(FLX_ObjectConfig &&config) :
    FLX_Object(std::move(config)),
    _event({0}) {}

SDL_Event &FLX_Event::event() {
    return _event;
}
