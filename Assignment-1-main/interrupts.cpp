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
    int time;          // Simulation time
    int save_time;     // Context save/load time
    int activity_time; // Activity execute time for each ISR line
    
    /******************************************************************/

    //parse each line of the input trace file
    while(std::getline(input_file, trace)) {
        auto [activity, duration_intr] = parse_trace(trace);

        /******************ADD YOUR SIMULATION CODE HERE*************************/
        if(activity == "CPU"){



        }else if(activity == "SYSCALL" || activity == "END_IO"){


            
        }
            //Switch to kernal
            //Save/restore context
            //Find ISR
            //Get ISR
            //Execute ISR
            //Execute IRET
        /************************************************************************/

    }

    input_file.close();

    write_output(execution);

    return 0;
}
