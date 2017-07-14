/*
 * tftpsm.h
 *
 *  Created on: 14 Jul 2017
 *      Author: deghaza1
 */

#ifndef TFTPSM_H_
#define TFTPSM_H_

class tftp_sm {
public:
	tftp_sm();
	virtual ~tftp_sm();
	state_id start(state_id next);
	state_id stop(state_id next);

	state_id cmd();
	state_id pktRcvd();

private:
    void initial_action() { /* what to do when start*/ }
    void final_action  () { /* what to do at the end */ }

          state* current()       { return states_[curr_]; }
    const state* current() const { return states_[curr_]; }

    state_id change_state(state_id next);

  private:
    const state_id pre_;
          state_id curr_;
     actions       action_;
     request_state request_;
     read_state    read_;
     write_state   write_;
     error_state   error_;
     state*        states_[UNDEF_];

};

#endif /* TFTPSM_H_ */
