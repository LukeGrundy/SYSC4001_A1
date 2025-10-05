/**
 *
 * @file interrupts.cpp
 * @author Sasisekhar Govind
 * @author Luke Grundy - 101268449
 *
 */

#include<interrupts.hpp>

int main(int argc, char** argv) {

    //vectors is a C++ std::vector of strings that contain the address of the ISR
    //delays  is a C++ std::vector of ints that contain the delays of each device
    //the index of these elemens is the device number, starting from 0
    auto [vectors, delays] = parse_args(argc, argv);
    std::ifstream input_file(argv[1]);

    std::string trace;      //!< string to store single line of trace file
    std::string execution;  //!< string to accumulate the execution output

    /******************ADD YOUR VARIABLES HERE*************************/
    int current_time = 0;          // Simulation time
    int context_save_time = 10;     // Context save/load time
    int activity_time = 40; // Activity execute time for each ISR line
    
    /******************************************************************/

    //parse each line of the input trace file
    while(std::getline(input_file, trace)) {
        auto [activity, duration_intr] = parse_trace(trace);

        /******************ADD YOUR SIMULATION CODE HERE*************************/
        if(activity == "CPU"){
            execution += std::to_string(current_time) + ", " + std::to_string(duration_intr) + ", CPU burst \n";
            current_time += duration_intr;


        }else if(activity == "SYSCALL" || activity == "END_IO"){
            //Switch to kernal
            //Save/restore context
            //Find ISR
            //Get ISR
            auto [interupt, add_time] = intr_boilerplate(current_time, duration_intr, context_save_time, vectors);
            execution += interupt;
            current_time = add_time;

            //Execute ISR
            execution += std::to_string(current_time) + ", " + std::to_string(activity_time) + ", " + activity + ": run the ISR (device driver)\n";
            current_time += activity_time;

            //Execute IRET
            execution += std::to_string(current_time) + ", 1, IRET\n";

        }
            
            
            
        /************************************************************************/

    }

    input_file.close();

    write_output(execution);

    return 0;
}
