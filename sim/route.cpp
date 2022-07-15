// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-  
#include <climits>
#include "route.h"
#include "network.h"
#include "queue.h"


#define MAXQUEUES 10

void
Route::add_endpoints(PacketSink *src, PacketSink* dst) {
    _sinklist.push_back(dst);
    if (_reverse) {
	_reverse->push_back(src);
    }
}

void Route::non_null() {
    int fail = 0;
    for (unsigned int i = 1; i < size() - 1; i += 2)
        if (at(i) == nullptr) {
            fail = 1;
            break;
        }
    if (fail) {
        //    cout <<"Null queue in route"<<endl;
        for (unsigned int i = 1; i < size() - 1; i += 2)
            myprintf("%p ", at(i));
        cout << endl;
        assert(0);
    }
}

Route::~Route() {
//    delete _reverse;
//    for (auto &packet_sink: _sinklist) {
//        delete packet_sink;
//    }
}
