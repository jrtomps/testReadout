/* Null trigger */

#include <config.h>
#include <iostream>
#include <fstream>
#include <cmath>
#include "CMyEndCommand.h"
#include "TCLInterpreter.h"
#include <TCLObject.h>
#include <RunState.h>
#include <unistd.h>

#include <stdlib.h>

#ifdef HAVE_STD_NAMESPACE
using namespace std;
#endif

CMyEndCommand::CMyEndCommand(CTCLInterpreter& rInterp) : CEndCommand(rInterp) 
{
}

CMyEndCommand::~CMyEndCommand()
{
}

int CMyEndCommand::ExecutePreFunction() 
{
    
  // Wait for a millisecond and then some
  int slop = rand() % 1000;
  usleep(1000+slop);

  return 0;	
}

int CMyEndCommand::ExecutePostFunction() 
{

  // Wait for a millisecond and then some
  int slop = rand() % 2000;
  usleep(1000+slop);

  return 0;	
}


// Override the end command's function call operator to be sure our stuff
// gets called at the right time.

    int
CMyEndCommand::operator()(CTCLInterpreter& interp,
        std::vector<CTCLObject>& objv)
{
    RunState* pState = RunState::getInstance();

    // To end a run we must have no mor command parameters
    // and the state must be either active or paused:

    bool okToEnd = 
        ((pState->m_state == RunState::active)   ||
         (pState->m_state == RunState::paused))   &&
        (objv.size() ==1);

    if(okToEnd) ExecutePreFunction();
    CEndCommand::operator()(interp,objv);
    if(okToEnd) ExecutePostFunction();


}

