//------------------------------------------------------------------------------
//
// This program runs a genetic algorithm for computing task/machine
// schedules.  It is mainly for testing the GA routine on subsequently
// larger and larger pool sizes to see how it compares when run
// serially vs multithreaded.
//
//------------------------------------------------------------------------------

#include "types.hxx"
#include "ga.hxx"
#include "program_options.hxx"

#include <random>
#include <chrono>
#include <iostream>
#include <thread>

//------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
  using namespace std;

  // 1. Create an object of type cs340::program_options. Call it args.
  // Pass into the constructor argc and argv as parameters.
  //
  // TODO: Read and examine the program_options.hxx header file.
  // TODO: Read the documentation about Boost.ProgramOptions here:
  //       http://www.boost.org/doc/libs/1_63_0/doc/html/program_options.html
  // TODO: The program options code has been provided to you. Notice
  //       how it simplifies processing command line arguments.

  /* TODO: WRITE CODE HERE */
	cs340::program_options args(argc, argv);	//create program_options object
  
  // 2. Set up the random number generator. Create an object of type
  // std::seed_seq. Pass in as parameters an iterator pointing to the
  // first element of args.seeds, and an iterator pointing to one
  // past the end of the elements of args.seeds.
  //
  // Once done, create an object of type cs340::random_generator. Call it
  // engine. Pass in your seed sequence as the only parameter to engine's
  // unary constructor.
  //
  // TODO: Read about std::seed_seq in the course textbooks.
  // TODO: Read about random numbers (e.g., <random>) in the course textbooks.

  /* TODO: WRITE CODE HERE */
	std::seed_seq seedseq(args.seeds.begin(), args.seeds.end() + 1);	//create seed_seq object
	cs340::random_generator engine(seedseq);							//create random number generator
  
  // 3. Create an object of type cs340::simulation_parameters. Call it
  // params. Pass in as arguments (in this exact order) to the constructor:
  //
  // 1. The number of generations
  // 2. The min pool size
  // 3. The number of threads.
  //
  // See the program_options.hxx for the correct member variables of your
  // args object.

  /* TODO: WRITE CODE HERE */
	cs340::simulation_parameters params;	//create simulation_parameters object (3)
	params.generations = args.generations;	//assign number of generations
	params.pool_size = args.min_pool_size;	//assign min pool size
	params.threads = args.threads;			//assign number of threads
  
  // 4. Create a matrix object by calling the function
  // cs340::create_random_matrix. Pass in the correct parameters
  // (see types.hxx and types.cxx) for the interface. Use the value
  // 30 for the time_max parameter.

  /* TODO: WRITE CODE HERE */
	auto matrix = cs340::create_random_matrix(args.tasks,args.machines,30,engine);	//create matrix (4)

  cout << "Pool\tResult\tTime (s)\n";
  for( ;
    params.pool_size <= args.max_pool_size;
    params.pool_size += args.pool_size_step
  ){
    // TODO: Read about <chrono> and related time facilities in your
    //       course textbooks.
   
    // 5. Do the following, in order:
    //
    // a. Get the current CPU time. use std::chrono::high_resolution_clock.
    //
    // b. Call the function cs340::run_simulation. Check the header files
    // to make sure you are passing the correct arguments! Store the
    // return value of the function in a variable called result.
    //
    // c. Get the current CPU time the same way you did in step 5a.
    //
    // NOTE: Later you will be subtracting the values obtained in steps
    //       5a and 5c to determine the total elapsed time of the
    //       simulation.

    /* TODO: WRITE CODE HERE */
	  auto startTime = std::chrono::high_resolution_clock::now();	//get start time (5a)
	  auto result = cs340::run_simulation(matrix, params, engine);	//store result (5b)
	  auto endTime = std::chrono::high_resolution_clock::now();		//get end time (5c)
    
    // 6. Output to standard out the following:
    //
    // i. params.pool_size
    // 11. the score of the variable result
    // iii. the number of seconds the simulation took to run. 
    //
    // For (iii), first compute a variable of type chrono::duration<double> 
    // representing the difference between the stop time and the start time. 
    // Then call .count() on it to get the number of seconds it represents.
    //
    // Each field output should be separated by a tab character.
    // The entire output should be flushed via std::endl.

    /* TODO: WRITE CODE HERE */
	  chrono::duration<double> simTime = endTime - startTime;	//calculate the amount of time the simulation took
    
	  std::cout << params.pool_size << '\t' << result.score(matrix) << '\t' << simTime.count() << std::endl;
  }
}

//------------------------------------------------------------------------------
