#ifndef __MYEND_H
#define __MYEND_H

#include <CEndCommand.h>

class CTCLInterpreter;
class CTCLObject;

class CMyEndCommand : public CEndCommand
{
 
private:

public:
	// Constructors, destructors and other cannonical operations: 
  
  CMyEndCommand(CTCLInterpreter& interp);              //!< Default constructor.
  ~CMyEndCommand (); //!< Destructor.
  
private:
  CMyEndCommand(const CMyEndCommand& rhs);
  CMyEndCommand& operator=(const CMyEndCommand &rhs);
  int operator==(const CMyEndCommand& rhs) const;
  int operator!=(const CMyEndCommand& rhs) const;
    
  // Class operations:
public:  
  virtual int ExecutePreFunction();
  virtual int ExecutePostFunction();
  virtual int operator()(CTCLInterpreter& interp,
			 std::vector<CTCLObject>& objv);
 
};
#endif
