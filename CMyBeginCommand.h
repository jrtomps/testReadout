#ifndef __MYBEGIN_H
#define __MYBEGIN_H

#include <CBeginCommand.h>

class CTCLInterpreter;
class CTCLObject;

class CMyBeginCommand : public CBeginCommand
{
 
private:

public:
	// Constructors, destructors and other cannonical operations: 
  
  CMyBeginCommand(CTCLInterpreter& interp);              //!< Default constructor.
  ~CMyBeginCommand (); //!< Destructor.
  
private:
  CMyBeginCommand(const CMyBeginCommand& rhs);
  CMyBeginCommand& operator=(const CMyBeginCommand &rhs);
  int operator==(const CMyBeginCommand& rhs) const;
  int operator!=(const CMyBeginCommand& rhs) const;
    
  // Class operations:
public:  
  virtual int ExecutePreFunction();
  virtual int ExecutePostFunction();
  virtual int operator()(CTCLInterpreter& interp,
			 std::vector<CTCLObject>& objv);
 
};
#endif
