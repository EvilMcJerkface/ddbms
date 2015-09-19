#ifndef _CLIENT_THREAD_H_
#define _CLIENT_THREAD_H_

#include "global.h"

class workload;

class Client_thread_t {
public:
//	thread_t();
//	~thread_t();
	uint64_t _thd_id;
	uint64_t _node_id;
	workload * _wl;

	uint64_t 	get_thd_id();
	uint64_t 	get_node_id();

	uint64_t 	get_host_cid();
	void 	 	set_host_cid(uint64_t cid);

	uint64_t 	get_cur_cid();
	void 		set_cur_cid(uint64_t cid);

	void 		init(uint64_t thd_id, uint64_t node_id, workload * workload);
	// the following function must be in the form void* (*)(void*)
	// to run with pthread.
	// conversion is done within the function.
	RC 			run();
	RC 			run_remote();
	RC 			run_send();
	RC 			run_pool_txn();
private:
	uint64_t 	_host_cid;
	uint64_t 	_cur_cid;
	ts_t 		_curr_ts;
	//ts_t 		get_next_ts();

	RC	 		runTest(txn_man * txn);
};

#endif
