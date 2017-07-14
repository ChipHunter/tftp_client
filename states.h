/*
 * states.h
 *
 *  Created on: 11 Jul 2017
 *      Author: deghaza1
 */

#ifndef STATES_H_
#define STATES_H_

#include <actions.h>

enum state_id   { REQUEST_, SEND_, WAIT_, ERROR_, UNDEF_ };

class triggers
{
public:
	virtual ~triggers() { }
	virtual state_id cmd()     = 0;
    virtual state_id pktRcvd() = 0;
};

class state : public triggers{
public:
    state(state_id sid, actions& action) : sid_(sid), action_(action)  { }

    virtual state_id entry_point()             { return no_transition(); }
    virtual void     exit_point ()                                     { }

  protected:
    state_id request_transition(state_id sid) const       { return sid;  }
    state_id no_transition     ()             const       { return sid_; }

    const state_id sid_;
    actions&       action_;

};

class request_state: public state {
public:
	request_state(actions& action) : state(REQUEST_, action) { }

	state_id entry_point();
	void     exit_point();
	state_id cmd();
	state_id pktRcvd();
};

class write_state: public state {
public:
	write_state(actions& action) : state(REQUEST_, action) { }

	state_id entry_point();
	void     exit_point();
	state_id cmd();
	state_id pktRcvd();
};

class read_state: public state {
public:
	read_state(actions& action) : state(REQUEST_, action) { }

	state_id entry_point();
	void     exit_point();
	state_id cmd();
	state_id pktRcvd();
};

class error_state: public state {
public:
	error_state(actions& action) : state(REQUEST_, action) { }

	state_id entry_point();
	void     exit_point();
	state_id cmd();
	state_id pktRcvd();
};

#endif /* STATES_H_ */
