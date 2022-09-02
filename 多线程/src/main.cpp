#include "../include/simplecase.hpp"
#include "../include/thread_condition.hpp"
#include "../include/thread_future.hpp"
#include "../include/thread_mutex.hpp"
#include "../include/thread_atom.hpp"
#include "vector"
#include "unistd.h"
using namespace std;

int main()
{

    
    {
        // cout << "---------simplecase-------------" << endl;
        // test_join_detach();
        // test_hardware_concurrency();
    }


    {
        // cout << "---------condition-------------" << endl;
        // test_condition();
    }


    {
        // cout << "--------mutex-------------" << endl;
        
    }


    {
        // cout << "---------future-------------" << endl;
        // test_doAsyncWorkWhenWait();
        // test_Packaged_task_simplecase();
        // test_packaged_task();
        // test_promise();
    }


    {
        // cout << "---------atom-------------" << endl;
        test_spinlock_byAtomic_flag();
    }

    
    return 0;
}