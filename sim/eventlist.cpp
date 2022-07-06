// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-        

#include "eventlist.h"

void
EventList::setEndtime(simtime_picosec endtime)
{
    _endtime = endtime;
}

bool
EventList::doNextEvent()
{
    if (_sim.empty())
        return false;
    _sim.step();
    return true;
}


simcpp20::event<simtime_picosec>
EventList::sourceIsPending(EventSource &src, simtime_picosec when)
{
    auto ev = _sim.event();
    if (_endtime == 0 || when < _endtime) {
        ev.add_callback([&src](const auto &) { src.doNextEvent(); });
        _sim.schedule(ev, when - now());
    } else ev.abort();
    return ev;
}
