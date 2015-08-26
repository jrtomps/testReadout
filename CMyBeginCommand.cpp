/* Null trigger */

#include <config.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "CMyBeginCommand.h"
#include "TCLInterpreter.h"
#include <TCLObject.h>
#include <RunState.h>
#include <unistd.h>
#include <time.h>

#include <stdlib.h>

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

CMyBeginCommand::CMyBeginCommand(CTCLInterpreter& rInterp) : CBeginCommand(rInterp) 
{
}

CMyBeginCommand::~CMyBeginCommand()
{
}

int CMyBeginCommand::ExecutePreFunction() 
{
//  srand(time(NULL)); 
//  // Wait for a millisecond and then some
//  int slop = rand() % 5000000;
//  usleep(1000+slop);
//
//  std::cout << "Before: slept for " << (1000+slop)/1.0e6 << std::endl;

  return 0;	
}

int CMyBeginCommand::ExecutePostFunction() 
{

//  srand(time(NULL)); 
//  // Wait for a millisecond and then some
//  int slop = rand() % 5000000;
//  usleep(1000+slop);
//
//  std::cout << "After: slept for " << (1000+slop)/1.0e6 << std::endl;
  return 0;	
}


// Override the end command's function call operator to be sure our stuff
// gets called at the right time.

    int
CMyBeginCommand::operator()(CTCLInterpreter& interp,
        std::vector<CTCLObject>& objv)
{
    RunState* pState = RunState::getInstance();

    // To end a run we must have no mor command parameters
    // and the state must be either active or paused:

    bool okToBegin = 
        ((pState->m_state == RunState::paused)   ||
         (pState->m_state == RunState::inactive))   &&
        (objv.size() ==1);

    if(okToBegin) ExecutePreFunction();
    CBeginCommand::operator()(interp,objv);
    if(okToBegin) ExecutePostFunction();


}

