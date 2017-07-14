/*
 * tftpsm.cpp
 *
 *  Created on: 14 Jul 2017
 *      Author: deghaza1
 */

#include "tftpsm.h"
#include "actions.h"

tftp_sm::tftp_sm(actions& action) {
	// TODO Auto-generated constructor stub

}

tftp_sm::~tftp_sm() {
	// TODO Auto-generated destructor stub
}

state_id tftp_sm::change_state(state_id next)
{
	if (curr_ != next) {
		current()->exit_point();
        curr_ = next;
        change_state(current()->entry_point());
    }
    return curr_;
}

state_id tftp_sm::start(state_id next) {

}

state_id tftp_sm::stop(state_id next) {

}
